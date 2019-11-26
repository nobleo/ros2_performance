#include <iostream>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <static_executor/executors/static_single_threaded_executor.hpp>

/*
 * Same as ros.cc, except that it does not publish or subscribe.
 * It goes give a considerable load already.
 */

int main(int argc, char **argv) {
  using namespace std::chrono_literals;
  rclcpp::init(0, nullptr);

  int create = argc > 1 ? std::atoi(argv[1]) : 10;
  std::chrono::milliseconds loop_interval(argc > 2 ? std::atoi(argv[2]) : 20);
  std::cout << "ROS-no publishers create " << create << " nodes @ " << loop_interval.count() << "ms"
            << std::endl;

  rclcpp::executors::StaticExecutor exec;
  std::vector<rclcpp::Node::SharedPtr> node_refs;
  std::vector<rclcpp::TimerBase::SharedPtr> timer_refs;

  for (int n = 0; n < create; ++n) {
    auto node = std::make_shared<rclcpp::Node>("node_" + std::to_string(n));
    node_refs.push_back(node);
    exec.add_node(node);

    auto timer = node->create_wall_timer(loop_interval, [=]() {
      std_msgs::msg::String msg;
      msg.data = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    });
    timer_refs.push_back(timer);
  }

  exec.spin();
  rclcpp::shutdown();
  return 0;
}
