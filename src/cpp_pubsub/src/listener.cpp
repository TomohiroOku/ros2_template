#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class MinimalSubscriber : public rclcpp::Node
{
public:
  MinimalSubscriber() : Node("minimal_subscriber")
  {
    auto listener_callback = [this](std_msgs::msg::String::UniquePtr msg) {
      RCLCPP_INFO(this->get_logger(), "I heard: %s", msg->data.c_str());
    };
    subscription_ = this->create_subscription<std_msgs::msg::String>(
        "chatter", 10, listener_callback);
  }

private:
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char* argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}
