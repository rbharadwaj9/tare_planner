#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include <rcl/time.h>
#include <rclcpp/publisher.hpp>
#include <rclcpp/utilities.hpp>

class GoHomeCallerNode : public rclcpp::Node
{
public:
  GoHomeCallerNode(): Node("go_home_node")
  {
    // Declare the parameter with default value false
    this->declare_parameter<bool>("etGoHome", false);

    int delay_sec = 30;  // change as needed

    RCLCPP_INFO(this->get_logger(), "Will set 'etGoHome' to true after %d seconds.", delay_sec);
    timer_ = this->create_wall_timer(std::chrono::seconds(delay_sec),std::bind(&GoHomeCallerNode::timer_callback, this));
  }

private:

  void timer_callback()
  {
    // Set the parameter to true
    rclcpp::Parameter param("etGoHome", true);
    this->set_parameter(param);

    RCLCPP_INFO(this->get_logger(), "Parameter 'etGoHome' has been set to true.");

    // Stop the timer so it doesn't repeat
    timer_->cancel();
  }

  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv){

  rclcpp::init(argc, argv);
  auto node = std::make_shared<GoHomeCallerNode>();
  rclcpp::spin(node);
  rclcpp::shutdown();

  return 0;
}


