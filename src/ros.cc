#include <iostream>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

/*
 * Create 10 nodes who all publish on two different topics.
 * They subscribe to all 20 topics.
 */

static const rclcpp::QoS qos = rclcpp::QoS(10)
                                   .reliability(RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT)
                                   .durability(RMW_QOS_POLICY_DURABILITY_TRANSIENT_LOCAL);

int main(int argc, char **argv) {
  using namespace std::chrono_literals;
  using namespace std_msgs::msg;
  rclcpp::init(0, nullptr);

  int create = argc > 1 ? std::atoi(argv[1]) : 10;
  std::chrono::milliseconds interval(argc > 2 ? std::atoi(argv[2]) : 20);
  std::cout << "ROS create " << create << " nodes @ " << interval.count() << "ms" << std::endl;

  rclcpp::executors::SingleThreadedExecutor exec;
  std::vector<rclcpp::Node::SharedPtr> node_refs;
  std::vector<rclcpp::Subscription<String>::SharedPtr> sub_refs;
  std::vector<rclcpp::TimerBase::SharedPtr> timer_refs;

  auto options = rclcpp::PublisherOptions().use_intra_process_comm(true);
  for (int n = 0; n < create; ++n) {
    auto node = std::make_shared<rclcpp::Node>("node_" + std::to_string(n));
    node_refs.push_back(node);
    exec.add_node(node);

    auto pub1 = node->create_publisher<String>("topic_" + std::to_string(n), qos, options);
    auto pub2 = node->create_publisher<String>("topic_" + std::to_string(n + create), qos, options);
    auto timer = node->create_wall_timer(interval, [=]() {
      String msg;
      msg.data = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
      pub1->publish(msg);
      pub2->publish(msg);
    });
    timer_refs.push_back(timer);

    for (int s = 0; s < 2 * create; ++s) {
      auto sub = node->create_subscription<String>("topic_" + std::to_string(s), qos,
                                                   [](String::SharedPtr) {}, options);
      sub_refs.push_back(sub);
    }
  }

  exec.spin();
  rclcpp::shutdown();
  return 0;
}
