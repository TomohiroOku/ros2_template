#pragma once

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_components/visibility_control.hpp"
#include "std_msgs/msg/string.hpp"

namespace composition
{
class Talker : public rclcpp::Node
{
public:
  RCLCPP_COMPONENTS_PUBLIC
  explicit Talker(const rclcpp::NodeOptions& options);

private:
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
  size_t count_;
};
} // namespace composition
