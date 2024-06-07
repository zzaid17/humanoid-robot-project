// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from nav2_msgs:msg/CostmapFilterInfo.idl
// generated code does not contain a copyright notice

#ifndef NAV2_MSGS__MSG__DETAIL__COSTMAP_FILTER_INFO__FUNCTIONS_H_
#define NAV2_MSGS__MSG__DETAIL__COSTMAP_FILTER_INFO__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "nav2_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "nav2_msgs/msg/detail/costmap_filter_info__struct.h"

/// Initialize msg/CostmapFilterInfo message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * nav2_msgs__msg__CostmapFilterInfo
 * )) before or use
 * nav2_msgs__msg__CostmapFilterInfo__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__msg__CostmapFilterInfo__init(nav2_msgs__msg__CostmapFilterInfo * msg);

/// Finalize msg/CostmapFilterInfo message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
void
nav2_msgs__msg__CostmapFilterInfo__fini(nav2_msgs__msg__CostmapFilterInfo * msg);

/// Create msg/CostmapFilterInfo message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * nav2_msgs__msg__CostmapFilterInfo__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
nav2_msgs__msg__CostmapFilterInfo *
nav2_msgs__msg__CostmapFilterInfo__create();

/// Destroy msg/CostmapFilterInfo message.
/**
 * It calls
 * nav2_msgs__msg__CostmapFilterInfo__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
void
nav2_msgs__msg__CostmapFilterInfo__destroy(nav2_msgs__msg__CostmapFilterInfo * msg);

/// Check for msg/CostmapFilterInfo message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__msg__CostmapFilterInfo__are_equal(const nav2_msgs__msg__CostmapFilterInfo * lhs, const nav2_msgs__msg__CostmapFilterInfo * rhs);

/// Copy a msg/CostmapFilterInfo message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__msg__CostmapFilterInfo__copy(
  const nav2_msgs__msg__CostmapFilterInfo * input,
  nav2_msgs__msg__CostmapFilterInfo * output);

/// Initialize array of msg/CostmapFilterInfo messages.
/**
 * It allocates the memory for the number of elements and calls
 * nav2_msgs__msg__CostmapFilterInfo__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__msg__CostmapFilterInfo__Sequence__init(nav2_msgs__msg__CostmapFilterInfo__Sequence * array, size_t size);

/// Finalize array of msg/CostmapFilterInfo messages.
/**
 * It calls
 * nav2_msgs__msg__CostmapFilterInfo__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
void
nav2_msgs__msg__CostmapFilterInfo__Sequence__fini(nav2_msgs__msg__CostmapFilterInfo__Sequence * array);

/// Create array of msg/CostmapFilterInfo messages.
/**
 * It allocates the memory for the array and calls
 * nav2_msgs__msg__CostmapFilterInfo__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
nav2_msgs__msg__CostmapFilterInfo__Sequence *
nav2_msgs__msg__CostmapFilterInfo__Sequence__create(size_t size);

/// Destroy array of msg/CostmapFilterInfo messages.
/**
 * It calls
 * nav2_msgs__msg__CostmapFilterInfo__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
void
nav2_msgs__msg__CostmapFilterInfo__Sequence__destroy(nav2_msgs__msg__CostmapFilterInfo__Sequence * array);

/// Check for msg/CostmapFilterInfo message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__msg__CostmapFilterInfo__Sequence__are_equal(const nav2_msgs__msg__CostmapFilterInfo__Sequence * lhs, const nav2_msgs__msg__CostmapFilterInfo__Sequence * rhs);

/// Copy an array of msg/CostmapFilterInfo messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__msg__CostmapFilterInfo__Sequence__copy(
  const nav2_msgs__msg__CostmapFilterInfo__Sequence * input,
  nav2_msgs__msg__CostmapFilterInfo__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // NAV2_MSGS__MSG__DETAIL__COSTMAP_FILTER_INFO__FUNCTIONS_H_
