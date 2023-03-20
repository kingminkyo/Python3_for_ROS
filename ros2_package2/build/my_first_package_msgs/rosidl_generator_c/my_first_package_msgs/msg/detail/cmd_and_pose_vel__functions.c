// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from my_first_package_msgs:msg/CmdAndPoseVel.idl
// generated code does not contain a copyright notice
#include "my_first_package_msgs/msg/detail/cmd_and_pose_vel__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
my_first_package_msgs__msg__CmdAndPoseVel__init(my_first_package_msgs__msg__CmdAndPoseVel * msg)
{
  if (!msg) {
    return false;
  }
  // cmd_vel_linear
  // cmd_vel_angular
  // pose_x
  // pose_y
  // linear_vel
  // angular_vel
  return true;
}

void
my_first_package_msgs__msg__CmdAndPoseVel__fini(my_first_package_msgs__msg__CmdAndPoseVel * msg)
{
  if (!msg) {
    return;
  }
  // cmd_vel_linear
  // cmd_vel_angular
  // pose_x
  // pose_y
  // linear_vel
  // angular_vel
}

bool
my_first_package_msgs__msg__CmdAndPoseVel__are_equal(const my_first_package_msgs__msg__CmdAndPoseVel * lhs, const my_first_package_msgs__msg__CmdAndPoseVel * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // cmd_vel_linear
  if (lhs->cmd_vel_linear != rhs->cmd_vel_linear) {
    return false;
  }
  // cmd_vel_angular
  if (lhs->cmd_vel_angular != rhs->cmd_vel_angular) {
    return false;
  }
  // pose_x
  if (lhs->pose_x != rhs->pose_x) {
    return false;
  }
  // pose_y
  if (lhs->pose_y != rhs->pose_y) {
    return false;
  }
  // linear_vel
  if (lhs->linear_vel != rhs->linear_vel) {
    return false;
  }
  // angular_vel
  if (lhs->angular_vel != rhs->angular_vel) {
    return false;
  }
  return true;
}

bool
my_first_package_msgs__msg__CmdAndPoseVel__copy(
  const my_first_package_msgs__msg__CmdAndPoseVel * input,
  my_first_package_msgs__msg__CmdAndPoseVel * output)
{
  if (!input || !output) {
    return false;
  }
  // cmd_vel_linear
  output->cmd_vel_linear = input->cmd_vel_linear;
  // cmd_vel_angular
  output->cmd_vel_angular = input->cmd_vel_angular;
  // pose_x
  output->pose_x = input->pose_x;
  // pose_y
  output->pose_y = input->pose_y;
  // linear_vel
  output->linear_vel = input->linear_vel;
  // angular_vel
  output->angular_vel = input->angular_vel;
  return true;
}

my_first_package_msgs__msg__CmdAndPoseVel *
my_first_package_msgs__msg__CmdAndPoseVel__create()
{
  my_first_package_msgs__msg__CmdAndPoseVel * msg = (my_first_package_msgs__msg__CmdAndPoseVel *)malloc(sizeof(my_first_package_msgs__msg__CmdAndPoseVel));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_first_package_msgs__msg__CmdAndPoseVel));
  bool success = my_first_package_msgs__msg__CmdAndPoseVel__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
my_first_package_msgs__msg__CmdAndPoseVel__destroy(my_first_package_msgs__msg__CmdAndPoseVel * msg)
{
  if (msg) {
    my_first_package_msgs__msg__CmdAndPoseVel__fini(msg);
  }
  free(msg);
}


bool
my_first_package_msgs__msg__CmdAndPoseVel__Sequence__init(my_first_package_msgs__msg__CmdAndPoseVel__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  my_first_package_msgs__msg__CmdAndPoseVel * data = NULL;
  if (size) {
    data = (my_first_package_msgs__msg__CmdAndPoseVel *)calloc(size, sizeof(my_first_package_msgs__msg__CmdAndPoseVel));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_first_package_msgs__msg__CmdAndPoseVel__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_first_package_msgs__msg__CmdAndPoseVel__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
my_first_package_msgs__msg__CmdAndPoseVel__Sequence__fini(my_first_package_msgs__msg__CmdAndPoseVel__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      my_first_package_msgs__msg__CmdAndPoseVel__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

my_first_package_msgs__msg__CmdAndPoseVel__Sequence *
my_first_package_msgs__msg__CmdAndPoseVel__Sequence__create(size_t size)
{
  my_first_package_msgs__msg__CmdAndPoseVel__Sequence * array = (my_first_package_msgs__msg__CmdAndPoseVel__Sequence *)malloc(sizeof(my_first_package_msgs__msg__CmdAndPoseVel__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = my_first_package_msgs__msg__CmdAndPoseVel__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
my_first_package_msgs__msg__CmdAndPoseVel__Sequence__destroy(my_first_package_msgs__msg__CmdAndPoseVel__Sequence * array)
{
  if (array) {
    my_first_package_msgs__msg__CmdAndPoseVel__Sequence__fini(array);
  }
  free(array);
}

bool
my_first_package_msgs__msg__CmdAndPoseVel__Sequence__are_equal(const my_first_package_msgs__msg__CmdAndPoseVel__Sequence * lhs, const my_first_package_msgs__msg__CmdAndPoseVel__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_first_package_msgs__msg__CmdAndPoseVel__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_first_package_msgs__msg__CmdAndPoseVel__Sequence__copy(
  const my_first_package_msgs__msg__CmdAndPoseVel__Sequence * input,
  my_first_package_msgs__msg__CmdAndPoseVel__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(my_first_package_msgs__msg__CmdAndPoseVel);
    my_first_package_msgs__msg__CmdAndPoseVel * data =
      (my_first_package_msgs__msg__CmdAndPoseVel *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_first_package_msgs__msg__CmdAndPoseVel__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          my_first_package_msgs__msg__CmdAndPoseVel__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_first_package_msgs__msg__CmdAndPoseVel__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
