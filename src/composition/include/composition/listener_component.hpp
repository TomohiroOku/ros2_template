#pragma once

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_components/visibility_control.hpp"
#include "std_msgs/msg/string.hpp"

namespace composition
{
class Listener : public rclcpp::Node
{
public:
  RCLCPP_COMPONENTS_PUBLIC
  explicit Listener(const rclcpp::NodeOptions& options);

private:
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

} // namespace composition