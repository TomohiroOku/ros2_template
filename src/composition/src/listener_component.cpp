#include "composition/listener_component.hpp"
#include <iostream>
#include <memory>
#include <string>

namespace composition
{
Listener ::Listener(const rclcpp::NodeOptions& options)
    : Node("listener", options)
{
  auto callback = [this](std_msgs::msg::String::ConstSharedPtr msg) {
    RCLCPP_INFO(this->get_logger(), "I heard: %s", msg->data.c_str());
    std::flush(std::cout);
  };

  using std::placeholders::_1;
  subscription_ =
      create_subscription<std_msgs::msg::String>("chatter", 10, callback);
}
} // namespace composition

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(composition::Listener)