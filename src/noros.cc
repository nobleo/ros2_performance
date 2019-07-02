#include <chrono>
#include <thread>
#include <vector>
#include <map>
#include <string>
#include <functional>
#include <iostream>
#include <queue>

#include <std_msgs/msg/string.hpp>

/*
 * Cpp only version that not include any middleware.
 */

int main(int argc, char **argv) {
  using namespace std::chrono_literals;

  int create = argc > 1 ? std::atoi(argv[1]) : 10;
  std::chrono::milliseconds loop_interval(20);

  std::queue<std::function<void()>> queue;
  std::vector<std::function<void()>> timer_cb;
  std::map<std::string, std::function<void(const std_msgs::msg::String&)>> topics;


  for (int n = 0; n < create; ++n) {
    auto cb = [&, n]() {
      auto pub1 = topics["topic_" + std::to_string(n)];
      auto pub2 = topics["topic_" + std::to_string(n + create)];

      std_msgs::msg::String msg;
      msg.data = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
      queue.push(std::bind(pub1, msg));
      queue.push(std::bind(pub2, msg));
    };
    timer_cb.push_back(cb);

    for (int s = 0; s < 2 * create; ++s) {
      topics["topic_" + std::to_string(s)] = [](const std_msgs::msg::String&) {};
    }
  }

  while (1) {
    auto start = std::chrono::system_clock::now();
    for (auto cb : timer_cb) {
      cb();
    }

    while (!queue.empty()) {
      auto callable = queue.front();
      callable();
      queue.pop();
    }
    auto end = std::chrono::system_clock::now();

    std::this_thread::sleep_for(loop_interval - (end - start));
  }

}
