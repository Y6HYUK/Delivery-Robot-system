// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from menu_order_interfaces:srv/MenuUpdate.idl
// generated code does not contain a copyright notice
#include "menu_order_interfaces/srv/detail/menu_update__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `result_message`
#include "rosidl_runtime_c/string_functions.h"

bool
menu_order_interfaces__srv__MenuUpdate_Request__init(menu_order_interfaces__srv__MenuUpdate_Request * msg)
{
  if (!msg) {
    return false;
  }
  // result_message
  if (!rosidl_runtime_c__String__init(&msg->result_message)) {
    menu_order_interfaces__srv__MenuUpdate_Request__fini(msg);
    return false;
  }
  return true;
}

void
menu_order_interfaces__srv__MenuUpdate_Request__fini(menu_order_interfaces__srv__MenuUpdate_Request * msg)
{
  if (!msg) {
    return;
  }
  // result_message
  rosidl_runtime_c__String__fini(&msg->result_message);
}

bool
menu_order_interfaces__srv__MenuUpdate_Request__are_equal(const menu_order_interfaces__srv__MenuUpdate_Request * lhs, const menu_order_interfaces__srv__MenuUpdate_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // result_message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->result_message), &(rhs->result_message)))
  {
    return false;
  }
  return true;
}

bool
menu_order_interfaces__srv__MenuUpdate_Request__copy(
  const menu_order_interfaces__srv__MenuUpdate_Request * input,
  menu_order_interfaces__srv__MenuUpdate_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // result_message
  if (!rosidl_runtime_c__String__copy(
      &(input->result_message), &(output->result_message)))
  {
    return false;
  }
  return true;
}

menu_order_interfaces__srv__MenuUpdate_Request *
menu_order_interfaces__srv__MenuUpdate_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  menu_order_interfaces__srv__MenuUpdate_Request * msg = (menu_order_interfaces__srv__MenuUpdate_Request *)allocator.allocate(sizeof(menu_order_interfaces__srv__MenuUpdate_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(menu_order_interfaces__srv__MenuUpdate_Request));
  bool success = menu_order_interfaces__srv__MenuUpdate_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
menu_order_interfaces__srv__MenuUpdate_Request__destroy(menu_order_interfaces__srv__MenuUpdate_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    menu_order_interfaces__srv__MenuUpdate_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
menu_order_interfaces__srv__MenuUpdate_Request__Sequence__init(menu_order_interfaces__srv__MenuUpdate_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  menu_order_interfaces__srv__MenuUpdate_Request * data = NULL;

  if (size) {
    data = (menu_order_interfaces__srv__MenuUpdate_Request *)allocator.zero_allocate(size, sizeof(menu_order_interfaces__srv__MenuUpdate_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = menu_order_interfaces__srv__MenuUpdate_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        menu_order_interfaces__srv__MenuUpdate_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
menu_order_interfaces__srv__MenuUpdate_Request__Sequence__fini(menu_order_interfaces__srv__MenuUpdate_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      menu_order_interfaces__srv__MenuUpdate_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

menu_order_interfaces__srv__MenuUpdate_Request__Sequence *
menu_order_interfaces__srv__MenuUpdate_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  menu_order_interfaces__srv__MenuUpdate_Request__Sequence * array = (menu_order_interfaces__srv__MenuUpdate_Request__Sequence *)allocator.allocate(sizeof(menu_order_interfaces__srv__MenuUpdate_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = menu_order_interfaces__srv__MenuUpdate_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
menu_order_interfaces__srv__MenuUpdate_Request__Sequence__destroy(menu_order_interfaces__srv__MenuUpdate_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    menu_order_interfaces__srv__MenuUpdate_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
menu_order_interfaces__srv__MenuUpdate_Request__Sequence__are_equal(const menu_order_interfaces__srv__MenuUpdate_Request__Sequence * lhs, const menu_order_interfaces__srv__MenuUpdate_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!menu_order_interfaces__srv__MenuUpdate_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
menu_order_interfaces__srv__MenuUpdate_Request__Sequence__copy(
  const menu_order_interfaces__srv__MenuUpdate_Request__Sequence * input,
  menu_order_interfaces__srv__MenuUpdate_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(menu_order_interfaces__srv__MenuUpdate_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    menu_order_interfaces__srv__MenuUpdate_Request * data =
      (menu_order_interfaces__srv__MenuUpdate_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!menu_order_interfaces__srv__MenuUpdate_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          menu_order_interfaces__srv__MenuUpdate_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!menu_order_interfaces__srv__MenuUpdate_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
menu_order_interfaces__srv__MenuUpdate_Response__init(menu_order_interfaces__srv__MenuUpdate_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
menu_order_interfaces__srv__MenuUpdate_Response__fini(menu_order_interfaces__srv__MenuUpdate_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
}

bool
menu_order_interfaces__srv__MenuUpdate_Response__are_equal(const menu_order_interfaces__srv__MenuUpdate_Response * lhs, const menu_order_interfaces__srv__MenuUpdate_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
menu_order_interfaces__srv__MenuUpdate_Response__copy(
  const menu_order_interfaces__srv__MenuUpdate_Response * input,
  menu_order_interfaces__srv__MenuUpdate_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

menu_order_interfaces__srv__MenuUpdate_Response *
menu_order_interfaces__srv__MenuUpdate_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  menu_order_interfaces__srv__MenuUpdate_Response * msg = (menu_order_interfaces__srv__MenuUpdate_Response *)allocator.allocate(sizeof(menu_order_interfaces__srv__MenuUpdate_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(menu_order_interfaces__srv__MenuUpdate_Response));
  bool success = menu_order_interfaces__srv__MenuUpdate_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
menu_order_interfaces__srv__MenuUpdate_Response__destroy(menu_order_interfaces__srv__MenuUpdate_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    menu_order_interfaces__srv__MenuUpdate_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
menu_order_interfaces__srv__MenuUpdate_Response__Sequence__init(menu_order_interfaces__srv__MenuUpdate_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  menu_order_interfaces__srv__MenuUpdate_Response * data = NULL;

  if (size) {
    data = (menu_order_interfaces__srv__MenuUpdate_Response *)allocator.zero_allocate(size, sizeof(menu_order_interfaces__srv__MenuUpdate_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = menu_order_interfaces__srv__MenuUpdate_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        menu_order_interfaces__srv__MenuUpdate_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
menu_order_interfaces__srv__MenuUpdate_Response__Sequence__fini(menu_order_interfaces__srv__MenuUpdate_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      menu_order_interfaces__srv__MenuUpdate_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

menu_order_interfaces__srv__MenuUpdate_Response__Sequence *
menu_order_interfaces__srv__MenuUpdate_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  menu_order_interfaces__srv__MenuUpdate_Response__Sequence * array = (menu_order_interfaces__srv__MenuUpdate_Response__Sequence *)allocator.allocate(sizeof(menu_order_interfaces__srv__MenuUpdate_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = menu_order_interfaces__srv__MenuUpdate_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
menu_order_interfaces__srv__MenuUpdate_Response__Sequence__destroy(menu_order_interfaces__srv__MenuUpdate_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    menu_order_interfaces__srv__MenuUpdate_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
menu_order_interfaces__srv__MenuUpdate_Response__Sequence__are_equal(const menu_order_interfaces__srv__MenuUpdate_Response__Sequence * lhs, const menu_order_interfaces__srv__MenuUpdate_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!menu_order_interfaces__srv__MenuUpdate_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
menu_order_interfaces__srv__MenuUpdate_Response__Sequence__copy(
  const menu_order_interfaces__srv__MenuUpdate_Response__Sequence * input,
  menu_order_interfaces__srv__MenuUpdate_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(menu_order_interfaces__srv__MenuUpdate_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    menu_order_interfaces__srv__MenuUpdate_Response * data =
      (menu_order_interfaces__srv__MenuUpdate_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!menu_order_interfaces__srv__MenuUpdate_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          menu_order_interfaces__srv__MenuUpdate_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!menu_order_interfaces__srv__MenuUpdate_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
