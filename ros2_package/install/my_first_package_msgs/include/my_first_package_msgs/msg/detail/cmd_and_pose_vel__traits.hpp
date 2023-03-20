// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_first_package_msgs:msg/CmdAndPoseVel.idl
// generated code does not contain a copyright notice

#ifndef MY_FIRST_PACKAGE_MSGS__MSG__DETAIL__CMD_AND_POSE_VEL__TRAITS_HPP_
#define MY_FIRST_PACKAGE_MSGS__MSG__DETAIL__CMD_AND_POSE_VEL__TRAITS_HPP_

#include "my_first_package_msgs/msg/detail/cmd_and_pose_vel__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const my_first_package_msgs::msg::CmdAndPoseVel & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: cmd_vel_linear
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cmd_vel_linear: ";
    value_to_yaml(msg.cmd_vel_linear, out);
    out << "\n";
  }

  // member: cmd_vel_angular
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cmd_vel_angular: ";
    value_to_yaml(msg.cmd_vel_angular, out);
    out << "\n";
  }

  // member: pose_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose_x: ";
    value_to_yaml(msg.pose_x, out);
    out << "\n";
  }

  // member: pose_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose_y: ";
    value_to_yaml(msg.pose_y, out);
    out << "\n";
  }

  // member: linear_vel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "linear_vel: ";
    value_to_yaml(msg.linear_vel, out);
    out << "\n";
  }

  // member: angular_vel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angular_vel: ";
    value_to_yaml(msg.angular_vel, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const my_first_package_msgs::msg::CmdAndPoseVel & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<my_first_package_msgs::msg::CmdAndPoseVel>()
{
  return "my_first_package_msgs::msg::CmdAndPoseVel";
}

template<>
inline const char * name<my_first_package_msgs::msg::CmdAndPoseVel>()
{
  return "my_first_package_msgs/msg/CmdAndPoseVel";
}

template<>
struct has_fixed_size<my_first_package_msgs::msg::CmdAndPoseVel>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<my_first_package_msgs::msg::CmdAndPoseVel>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<my_first_package_msgs::msg::CmdAndPoseVel>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MY_FIRST_PACKAGE_MSGS__MSG__DETAIL__CMD_AND_POSE_VEL__TRAITS_HPP_
