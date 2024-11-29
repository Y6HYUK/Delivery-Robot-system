import sqlite3
from datetime import datetime, timedelta
import time

# 공용 함수: 현재 타임스탬프 반환
def get_current_timestamp():
    return datetime.now().strftime('%Y-%m-%d %H:%M:%S')

# 데이터베이스 연결 관리 함수
def db_connection():
    return sqlite3.connect('restaurant_db.db')

# 데이터베이스 초기화 함수
def create_db():
    with db_connection() as conn:
        cursor = conn.cursor()

        # 테이블 생성: 테이블 정보
        cursor.execute('''
        CREATE TABLE IF NOT EXISTS tables (
            table_id INTEGER PRIMARY KEY,
            x FLOAT NOT NULL,
            y FLOAT NOT NULL
        );
        ''')

        # 테이블 생성: 메뉴 정보
        cursor.execute('''
        CREATE TABLE IF NOT EXISTS menu (
            menu_item_id INTEGER PRIMARY KEY,
            name VARCHAR(50),
            price INTEGER,
            availability INTEGER,
            category VARCHAR(100),
            description TEXT,
            image_path TEXT
        );
        ''')

        # 테이블 생성: 주문 정보
        cursor.execute('''
        CREATE TABLE IF NOT EXISTS orders (
            order_id INTEGER PRIMARY KEY AUTOINCREMENT,
            table_id INTEGER,
            order_time TIMESTAMP,
            status VARCHAR(50),
            total_amount INTEGER,
            FOREIGN KEY (table_id) REFERENCES tables(table_id)
        );
        ''')

        # 테이블 생성: 주문 상세 정보
        cursor.execute('''
        CREATE TABLE IF NOT EXISTS order_items (
            order_item_id INTEGER PRIMARY KEY AUTOINCREMENT,
            order_id INTEGER,
            menu_item_id INTEGER,
            quantity INTEGER,
            FOREIGN KEY (order_id) REFERENCES orders(order_id),
            FOREIGN KEY (menu_item_id) REFERENCES menu(menu_item_id)
        );
        ''')

        # 테이블 생성: 서빙 상세 정보
        cursor.execute('''
        CREATE TABLE IF NOT EXISTS deliver_log (
            deliver_id INTEGER PRIMARY KEY AUTOINCREMENT,
            order_id INTEGER,
            start_time TIMESTAMP,
            end_time TIMESTAMP,
            FOREIGN KEY (order_id) REFERENCES orders(order_id)
        );
        ''')

        conn.commit()

# 데이터 삽입 함수들
def insert_table(table_id, x, y):
    with db_connection() as conn:
        cursor = conn.cursor()
        cursor.execute('''
        INSERT INTO tables (table_id, x, y)
        VALUES (?, ?, ?)
        ''', (table_id, x, y))
        conn.commit()

def insert_menu(name, price):
    with db_connection() as conn:
        cursor = conn.cursor()
        cursor.execute('''
        INSERT INTO menu (name, price)
        VALUES (?, ?)
        ''', (name, price))
        conn.commit()

def insert_order_with_items(table_id, items):
    """
    :param table_id: 주문이 발생한 테이블 ID
    :param items: 주문 항목의 리스트 (menu_item_id, quantity)
    :return: 생성된 order_id
    """
    with db_connection() as conn:
        cursor = conn.cursor()

        # 주문 추가 (초기 상태는 Received, 금액은 0)
        order_time = get_current_timestamp()
        cursor.execute('''
        INSERT INTO orders (table_id, order_time, status, total_amount)
        VALUES (?, ?, ?, 0)
        ''', (table_id, order_time, "Received"))
        order_id = cursor.lastrowid

        # 주문 항목 추가 및 총액 계산
        total_amount = 0
        for menu_item_id, quantity in items:
            cursor.execute('''
            INSERT INTO order_items (order_id, menu_item_id, quantity)
            VALUES (?, ?, ?)
            ''', (order_id, menu_item_id, quantity))

            # 메뉴 가격 조회
            cursor.execute('''
            SELECT price FROM menu WHERE menu_item_id = ?
            ''', (menu_item_id,))
            price = cursor.fetchone()[0]
            total_amount += price * quantity

        # 총액 업데이트
        cursor.execute('''
        UPDATE orders
        SET total_amount = ?
        WHERE order_id = ?
        ''', (total_amount, order_id))

        conn.commit()
        return order_id

def insert_delivery_log(order_id, end=False):
    """
    배달 시작 및 종료 시 delivery_log와 orders 상태 업데이트
    :param order_id: 배달과 연결된 주문 ID
    :param end: True이면 배달 완료, False이면 배달 시작
    """
    with db_connection() as conn:
        cursor = conn.cursor()
        if end:
            # 배달 완료: end_time 업데이트 및 orders 상태를 "Delivered"로 변경
            end_time = get_current_timestamp()
            cursor.execute('''
            UPDATE deliver_log
            SET end_time = ?
            WHERE order_id = ? AND end_time IS NULL
            ''', (end_time, order_id))
            cursor.execute('''
            UPDATE orders
            SET status = "Delivered"
            WHERE order_id = ?
            ''', (order_id,))
        else:
            # 배달 시작: start_time 추가 및 orders 상태를 "Delivering"으로 변경
            start_time = get_current_timestamp()
            cursor.execute('''
            INSERT INTO deliver_log (order_id, start_time)
            VALUES (?, ?)
            ''', (order_id, start_time))
            cursor.execute('''
            UPDATE orders
            SET status = "Delivering"
            WHERE order_id = ?
            ''', (order_id,))
        conn.commit()

# 총액 계산 함수
def calculate_total_amount(order_id):
    with db_connection() as conn:
        cursor = conn.cursor()
        cursor.execute('''
        SELECT SUM(oi.quantity * m.price)
        FROM order_items oi
        JOIN menu m ON oi.menu_item_id = m.menu_item_id
        WHERE oi.order_id = ?
        ''', (order_id,))
        result = cursor.fetchone()
        return result[0] if result[0] is not None else 0

# 데이터 확인 함수
def check_db():
    with db_connection() as conn:
        cursor = conn.cursor()

        # 모든 테이블 조회
        tables = ["tables", "menu", "orders", "order_items", "deliver_log"]
        for table in tables:
            print(f"--- {table} ---")
            try:
                cursor.execute(f"SELECT * FROM {table}")
                rows = cursor.fetchall()

                # 출력
                for row in rows:
                    print(row)
            except sqlite3.OperationalError as e:
                print(f"Error accessing table {table}: {e}")
            print()

def update_menu_table():
    with db_connection() as conn:
        cursor = conn.cursor()

        # 기존 메뉴 테이블 삭제
        cursor.execute('DROP TABLE IF EXISTS menu')

        # 새로운 테이블 생성
        cursor.execute('''CREATE TABLE menu (
                            menu_item_id INTEGER PRIMARY KEY,
                            name VARCHAR(50),
                            price INTEGER,
                            availability INTEGER,
                            category VARCHAR(100),
                            description TEXT,
                            image_path TEXT
                          )''')

        conn.commit()

def insert_sample_menu_data():
    sample_data = [
        ('Pasta', 12000, 1, 'FOOD', '매콤하고 고소한 맛이 어우러진 파스타입니다.', ""),
        ('Pizza', 35000, 1, 'FOOD', '풍부한 치즈와 신선한 재료들이 조화를 이루는 클래식한 피자입니다.', ""),
        ('Steak', 50000, 1, 'FOOD', '육즙이 풍부한 스테이크, 부드럽고 깊은 맛을 자랑하는 고급스러운 한 끼를 선사합니다.', ""),
        ('Salad', 10000, 1, 'FOOD', '신선한 채소와 함께하는 상큼하고 건강한 샐러드, 다른 음식과 깔끔하게 어우러집니다.', ""),
        ('Chicken', 25000, 1, 'FOOD', '겉은 바삭하고 속은 촉촉한 치킨, 최고급 무항생제 닭을 사용해 건강한 한 끼를 즐길 수 있습니다.', ""),
        ('Hamburger', 8000, 1, 'FOOD', '두툼한 패티와 신선한 채소가 어우러진 풍미 가득한 햄버거입니다.', ""),
        ('Coke', 2000, 1, 'DRINK', '시원하고 청량한 콜라, 한 모금 마시면 입 안 가득 상쾌함이 퍼져나갑니다.', ""),
        ('Sprite', 2000, 1, 'DRINK', '상큼하고 기분 좋은 청량감을 주는 스프라이트, 목을 시원하게 적셔줍니다.', ""),
        ('House Wine', 6000, 1, 'DRINK', '부드럽고 우아한 향이 돋보이는 하우스 와인, 입 안에서 길게 여운이 남습니다.', ""),
        ('Beer', 5000, 1, 'DRINK', '차가운 맥주 한 잔, 깊고 풍부한 맛이 목을 타고 넘어갑니다.', "")
    ]

    with db_connection() as conn:
        cursor = conn.cursor()

        # 새 메뉴 데이터 삽입
        cursor.executemany('''
        INSERT INTO menu (name, price, availability, category, description, image_path)
        VALUES (?, ?, ?, ?, ?, ?)
        ''', sample_data)

        conn.commit()

if __name__ == "__main__":
    # # 데이터베이스 초기화
    # create_db()

    # # 테이블 데이터 삽입
    # insert_table(1, 0, 0)
    # insert_table(2, 10, 0)
    # insert_table(3, 20, 0)
    # insert_table(4, 0, 10)
    # insert_table(5, 10, 10)
    # insert_table(6, 20, 10)
    # insert_table(7, 0, 20)
    # insert_table(8, 10, 20)
    # insert_table(9, 20, 20)

    # # 메뉴 데이터 삽입
    # insert_menu("Pasta", 12000)
    # insert_menu("Pizza", 35000)
    # insert_menu("Steak", 50000)
    # insert_menu("Salad", 10000)
    # insert_menu("Chicken", 25000)
    # insert_menu("Hamburger", 8000)
    # insert_menu("Waffle", 3000)

    # order1 = insert_order_with_items(1, [(1, 2), (2, 1)])
    # time.sleep(10)
    # order2 = insert_order_with_items(2, [(3, 2), (6, 1), (5, 2)])
    # time.sleep(5)
    # order3 = insert_order_with_items(3, [(1, 1), (5, 1), (4, 2)])

    # # 배달 로그 추가
    # insert_delivery_log(order1)      # 배달 시작
    # time.sleep(3)
    # insert_delivery_log(order2)      # 배달 시작
    # time.sleep(10)
    # insert_delivery_log(order1, end=True)  # 배달 완료
    # time.sleep(2)
    # insert_delivery_log(order2, end=True)  # 배달 완료

    # 최근 12시간 내 주문 확인
    check_db()

    update_menu_table()

    insert_sample_menu_data()

    check_db()
