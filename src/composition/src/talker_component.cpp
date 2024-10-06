#include "composition/talker_component.hpp"
#include <chrono>
#include <iostream>
#include <string>

using namespace std::chrono_literals;

namespace composition
{
Talker::Talker(const rclcpp ::NodeOptions& options)
    : Node("talker", options), count_(0)
{
  publisher_ = this->create_publisher<std_msgs::msg::String>("chatter", 10);

  auto timer_callback = [this]() {
    auto msg = std::make_unique<std_msgs::msg::String>();
    msg->data = "Hello, world! " + std::to_string(count_++);
    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", msg->data.c_str());
    std::flush(std::cout);
    publisher_->publish(std::move(msg));
  };
  timer_ = this->create_wall_timer(1s, timer_callback);
}
} // namespace composition

#include "rclcpp_components/register_node_macro.hpp"
RCLCPP_COMPONENTS_REGISTER_NODE(composition::Talker)