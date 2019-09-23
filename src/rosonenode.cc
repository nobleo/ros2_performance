#include <iostream>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

/*
 * Create 1 node which publishes on twenty different topics.
 * Each topic has 10 subscribers.
 */

static const rclcpp::QoS qos = rclcpp::QoS(10)
                                   .reliability(RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT)
                                   .durability(RMW_QOS_POLICY_DURABILITY_VOLATILE);

int main(int argc, char **argv) {
  using namespace std::chrono_literals;
  using namespace std_msgs::msg;
  rclcpp::init(0, nullptr);

  int create = argc > 1 ? std::atoi(argv[1]) : 1;
  std::chrono::milliseconds interval(argc > 2 ? std::atoi(argv[2]) : 20);
  std::cout << "ROS create " << create << " nodes @ " << interval.count() << "ms" << std::endl;

  rclcpp::executors::SingleThreadedExecutor exec;
  auto node = std::make_shared<rclcpp::Node>("node",rclcpp::NodeOptions().use_intra_process_comms(true) );

  auto pub0 = node->create_publisher<String>("topic_0", qos);
  auto pub1 = node->create_publisher<String>("topic_1", qos);
  auto pub2 = node->create_publisher<String>("topic_2", qos);
  auto pub3 = node->create_publisher<String>("topic_3", qos);
  auto pub4 = node->create_publisher<String>("topic_4", qos);
  auto pub5 = node->create_publisher<String>("topic_5", qos);
  auto pub6 = node->create_publisher<String>("topic_6", qos);
  auto pub7 = node->create_publisher<String>("topic_7", qos);
  auto pub8 = node->create_publisher<String>("topic_8", qos);
  auto pub9 = node->create_publisher<String>("topic_9", qos);
  auto pub10 = node->create_publisher<String>("topic_10", qos);
  auto pub11 = node->create_publisher<String>("topic_11", qos);
  auto pub12 = node->create_publisher<String>("topic_12", qos);
  auto pub13 = node->create_publisher<String>("topic_13", qos);
  auto pub14 = node->create_publisher<String>("topic_14", qos);
  auto pub15 = node->create_publisher<String>("topic_15", qos);
  auto pub16 = node->create_publisher<String>("topic_16", qos);
  auto pub17 = node->create_publisher<String>("topic_17", qos);
  auto pub18 = node->create_publisher<String>("topic_18", qos);
  auto pub19 = node->create_publisher<String>("topic_19", qos);
  auto timer = node->create_wall_timer(interval, [=]() {
    String msg;
    msg.data = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    pub0->publish(msg);
    pub1->publish(msg);
    pub2->publish(msg);
    pub3->publish(msg);
    pub4->publish(msg);
    pub5->publish(msg);
    pub6->publish(msg);
    pub7->publish(msg);
    pub8->publish(msg);
    pub9->publish(msg);
    pub10->publish(msg);
    pub11->publish(msg);
    pub12->publish(msg);
    pub13->publish(msg);
    pub14->publish(msg);
    pub15->publish(msg);
    pub16->publish(msg);
    pub17->publish(msg);
    pub18->publish(msg);
    pub19->publish(msg);
    });

  auto sub00= node->create_subscription<String>("topic_0", qos, [](String::SharedPtr) {});
  auto sub01= node->create_subscription<String>("topic_0", qos, [](String::SharedPtr) {});
  auto sub02= node->create_subscription<String>("topic_0", qos, [](String::SharedPtr) {});
  auto sub03= node->create_subscription<String>("topic_0", qos, [](String::SharedPtr) {});
  auto sub04= node->create_subscription<String>("topic_0", qos, [](String::SharedPtr) {});
  auto sub05= node->create_subscription<String>("topic_0", qos, [](String::SharedPtr) {});
  auto sub06= node->create_subscription<String>("topic_0", qos, [](String::SharedPtr) {});
  auto sub07= node->create_subscription<String>("topic_0", qos, [](String::SharedPtr) {});
  auto sub08= node->create_subscription<String>("topic_0", qos, [](String::SharedPtr) {});
  auto sub09= node->create_subscription<String>("topic_0", qos, [](String::SharedPtr) {});

  auto sub10= node->create_subscription<String>("topic_1", qos, [](String::SharedPtr) {});
  auto sub11= node->create_subscription<String>("topic_1", qos, [](String::SharedPtr) {});
  auto sub12= node->create_subscription<String>("topic_1", qos, [](String::SharedPtr) {});
  auto sub13= node->create_subscription<String>("topic_1", qos, [](String::SharedPtr) {});
  auto sub14= node->create_subscription<String>("topic_1", qos, [](String::SharedPtr) {});
  auto sub15= node->create_subscription<String>("topic_1", qos, [](String::SharedPtr) {});
  auto sub16= node->create_subscription<String>("topic_1", qos, [](String::SharedPtr) {});
  auto sub17= node->create_subscription<String>("topic_1", qos, [](String::SharedPtr) {});
  auto sub18= node->create_subscription<String>("topic_1", qos, [](String::SharedPtr) {});
  auto sub19= node->create_subscription<String>("topic_1", qos, [](String::SharedPtr) {});

  auto sub20= node->create_subscription<String>("topic_2", qos, [](String::SharedPtr) {});
  auto sub21= node->create_subscription<String>("topic_2", qos, [](String::SharedPtr) {});
  auto sub22= node->create_subscription<String>("topic_2", qos, [](String::SharedPtr) {});
  auto sub23= node->create_subscription<String>("topic_2", qos, [](String::SharedPtr) {});
  auto sub24= node->create_subscription<String>("topic_2", qos, [](String::SharedPtr) {});
  auto sub25= node->create_subscription<String>("topic_2", qos, [](String::SharedPtr) {});
  auto sub26= node->create_subscription<String>("topic_2", qos, [](String::SharedPtr) {});
  auto sub27= node->create_subscription<String>("topic_2", qos, [](String::SharedPtr) {});
  auto sub28= node->create_subscription<String>("topic_2", qos, [](String::SharedPtr) {});
  auto sub29= node->create_subscription<String>("topic_2", qos, [](String::SharedPtr) {});

  auto sub30= node->create_subscription<String>("topic_3", qos, [](String::SharedPtr) {});
  auto sub31= node->create_subscription<String>("topic_3", qos, [](String::SharedPtr) {});
  auto sub32= node->create_subscription<String>("topic_3", qos, [](String::SharedPtr) {});
  auto sub33= node->create_subscription<String>("topic_3", qos, [](String::SharedPtr) {});
  auto sub34= node->create_subscription<String>("topic_3", qos, [](String::SharedPtr) {});
  auto sub35= node->create_subscription<String>("topic_3", qos, [](String::SharedPtr) {});
  auto sub36= node->create_subscription<String>("topic_3", qos, [](String::SharedPtr) {});
  auto sub37= node->create_subscription<String>("topic_3", qos, [](String::SharedPtr) {});
  auto sub38= node->create_subscription<String>("topic_3", qos, [](String::SharedPtr) {});
  auto sub39= node->create_subscription<String>("topic_3", qos, [](String::SharedPtr) {});

  auto sub40= node->create_subscription<String>("topic_4", qos, [](String::SharedPtr) {});
  auto sub41= node->create_subscription<String>("topic_4", qos, [](String::SharedPtr) {});
  auto sub42= node->create_subscription<String>("topic_4", qos, [](String::SharedPtr) {});
  auto sub43= node->create_subscription<String>("topic_4", qos, [](String::SharedPtr) {});
  auto sub44= node->create_subscription<String>("topic_4", qos, [](String::SharedPtr) {});
  auto sub45= node->create_subscription<String>("topic_4", qos, [](String::SharedPtr) {});
  auto sub46= node->create_subscription<String>("topic_4", qos, [](String::SharedPtr) {});
  auto sub47= node->create_subscription<String>("topic_4", qos, [](String::SharedPtr) {});
  auto sub48= node->create_subscription<String>("topic_4", qos, [](String::SharedPtr) {});
  auto sub49= node->create_subscription<String>("topic_4", qos, [](String::SharedPtr) {});

  auto sub50= node->create_subscription<String>("topic_5", qos, [](String::SharedPtr) {});
  auto sub51= node->create_subscription<String>("topic_5", qos, [](String::SharedPtr) {});
  auto sub52= node->create_subscription<String>("topic_5", qos, [](String::SharedPtr) {});
  auto sub53= node->create_subscription<String>("topic_5", qos, [](String::SharedPtr) {});
  auto sub54= node->create_subscription<String>("topic_5", qos, [](String::SharedPtr) {});
  auto sub55= node->create_subscription<String>("topic_5", qos, [](String::SharedPtr) {});
  auto sub56= node->create_subscription<String>("topic_5", qos, [](String::SharedPtr) {});
  auto sub57= node->create_subscription<String>("topic_5", qos, [](String::SharedPtr) {});
  auto sub58= node->create_subscription<String>("topic_5", qos, [](String::SharedPtr) {});
  auto sub59= node->create_subscription<String>("topic_5", qos, [](String::SharedPtr) {});

  auto sub60= node->create_subscription<String>("topic_6", qos, [](String::SharedPtr) {});
  auto sub61= node->create_subscription<String>("topic_6", qos, [](String::SharedPtr) {});
  auto sub62= node->create_subscription<String>("topic_6", qos, [](String::SharedPtr) {});
  auto sub63= node->create_subscription<String>("topic_6", qos, [](String::SharedPtr) {});
  auto sub64= node->create_subscription<String>("topic_6", qos, [](String::SharedPtr) {});
  auto sub65= node->create_subscription<String>("topic_6", qos, [](String::SharedPtr) {});
  auto sub66= node->create_subscription<String>("topic_6", qos, [](String::SharedPtr) {});
  auto sub67= node->create_subscription<String>("topic_6", qos, [](String::SharedPtr) {});
  auto sub68= node->create_subscription<String>("topic_6", qos, [](String::SharedPtr) {});
  auto sub69= node->create_subscription<String>("topic_6", qos, [](String::SharedPtr) {});

  auto sub70= node->create_subscription<String>("topic_7", qos, [](String::SharedPtr) {});
  auto sub71= node->create_subscription<String>("topic_7", qos, [](String::SharedPtr) {});
  auto sub72= node->create_subscription<String>("topic_7", qos, [](String::SharedPtr) {});
  auto sub73= node->create_subscription<String>("topic_7", qos, [](String::SharedPtr) {});
  auto sub74= node->create_subscription<String>("topic_7", qos, [](String::SharedPtr) {});
  auto sub75= node->create_subscription<String>("topic_7", qos, [](String::SharedPtr) {});
  auto sub76= node->create_subscription<String>("topic_7", qos, [](String::SharedPtr) {});
  auto sub77= node->create_subscription<String>("topic_7", qos, [](String::SharedPtr) {});
  auto sub78= node->create_subscription<String>("topic_7", qos, [](String::SharedPtr) {});
  auto sub79= node->create_subscription<String>("topic_7", qos, [](String::SharedPtr) {});

  auto sub80= node->create_subscription<String>("topic_8", qos, [](String::SharedPtr) {});
  auto sub81= node->create_subscription<String>("topic_8", qos, [](String::SharedPtr) {});
  auto sub82= node->create_subscription<String>("topic_8", qos, [](String::SharedPtr) {});
  auto sub83= node->create_subscription<String>("topic_8", qos, [](String::SharedPtr) {});
  auto sub84= node->create_subscription<String>("topic_8", qos, [](String::SharedPtr) {});
  auto sub85= node->create_subscription<String>("topic_8", qos, [](String::SharedPtr) {});
  auto sub86= node->create_subscription<String>("topic_8", qos, [](String::SharedPtr) {});
  auto sub87= node->create_subscription<String>("topic_8", qos, [](String::SharedPtr) {});
  auto sub88= node->create_subscription<String>("topic_8", qos, [](String::SharedPtr) {});
  auto sub89= node->create_subscription<String>("topic_8", qos, [](String::SharedPtr) {});

  auto sub90= node->create_subscription<String>("topic_9", qos, [](String::SharedPtr) {});
  auto sub91= node->create_subscription<String>("topic_9", qos, [](String::SharedPtr) {});
  auto sub92= node->create_subscription<String>("topic_9", qos, [](String::SharedPtr) {});
  auto sub93= node->create_subscription<String>("topic_9", qos, [](String::SharedPtr) {});
  auto sub94= node->create_subscription<String>("topic_9", qos, [](String::SharedPtr) {});
  auto sub95= node->create_subscription<String>("topic_9", qos, [](String::SharedPtr) {});
  auto sub96= node->create_subscription<String>("topic_9", qos, [](String::SharedPtr) {});
  auto sub97= node->create_subscription<String>("topic_9", qos, [](String::SharedPtr) {});
  auto sub98= node->create_subscription<String>("topic_9", qos, [](String::SharedPtr) {});
  auto sub99= node->create_subscription<String>("topic_9", qos, [](String::SharedPtr) {});

  auto sub100= node->create_subscription<String>("topic_10", qos, [](String::SharedPtr) {});
  auto sub101= node->create_subscription<String>("topic_10", qos, [](String::SharedPtr) {});
  auto sub102= node->create_subscription<String>("topic_10", qos, [](String::SharedPtr) {});
  auto sub103= node->create_subscription<String>("topic_10", qos, [](String::SharedPtr) {});
  auto sub104= node->create_subscription<String>("topic_10", qos, [](String::SharedPtr) {});
  auto sub105= node->create_subscription<String>("topic_10", qos, [](String::SharedPtr) {});
  auto sub106= node->create_subscription<String>("topic_10", qos, [](String::SharedPtr) {});
  auto sub107= node->create_subscription<String>("topic_10", qos, [](String::SharedPtr) {});
  auto sub108= node->create_subscription<String>("topic_10", qos, [](String::SharedPtr) {});
  auto sub109= node->create_subscription<String>("topic_10", qos, [](String::SharedPtr) {});

  auto sub110= node->create_subscription<String>("topic_11", qos, [](String::SharedPtr) {});
  auto sub111= node->create_subscription<String>("topic_11", qos, [](String::SharedPtr) {});
  auto sub112= node->create_subscription<String>("topic_11", qos, [](String::SharedPtr) {});
  auto sub113= node->create_subscription<String>("topic_11", qos, [](String::SharedPtr) {});
  auto sub114= node->create_subscription<String>("topic_11", qos, [](String::SharedPtr) {});
  auto sub115= node->create_subscription<String>("topic_11", qos, [](String::SharedPtr) {});
  auto sub116= node->create_subscription<String>("topic_11", qos, [](String::SharedPtr) {});
  auto sub117= node->create_subscription<String>("topic_11", qos, [](String::SharedPtr) {});
  auto sub118= node->create_subscription<String>("topic_11", qos, [](String::SharedPtr) {});
  auto sub119= node->create_subscription<String>("topic_11", qos, [](String::SharedPtr) {});

  auto sub120= node->create_subscription<String>("topic_12", qos, [](String::SharedPtr) {});
  auto sub121= node->create_subscription<String>("topic_12", qos, [](String::SharedPtr) {});
  auto sub122= node->create_subscription<String>("topic_12", qos, [](String::SharedPtr) {});
  auto sub123= node->create_subscription<String>("topic_12", qos, [](String::SharedPtr) {});
  auto sub124= node->create_subscription<String>("topic_12", qos, [](String::SharedPtr) {});
  auto sub125= node->create_subscription<String>("topic_12", qos, [](String::SharedPtr) {});
  auto sub126= node->create_subscription<String>("topic_12", qos, [](String::SharedPtr) {});
  auto sub127= node->create_subscription<String>("topic_12", qos, [](String::SharedPtr) {});
  auto sub128= node->create_subscription<String>("topic_12", qos, [](String::SharedPtr) {});
  auto sub129= node->create_subscription<String>("topic_12", qos, [](String::SharedPtr) {});

  auto sub130= node->create_subscription<String>("topic_13", qos, [](String::SharedPtr) {});
  auto sub131= node->create_subscription<String>("topic_13", qos, [](String::SharedPtr) {});
  auto sub132= node->create_subscription<String>("topic_13", qos, [](String::SharedPtr) {});
  auto sub133= node->create_subscription<String>("topic_13", qos, [](String::SharedPtr) {});
  auto sub134= node->create_subscription<String>("topic_13", qos, [](String::SharedPtr) {});
  auto sub135= node->create_subscription<String>("topic_13", qos, [](String::SharedPtr) {});
  auto sub136= node->create_subscription<String>("topic_13", qos, [](String::SharedPtr) {});
  auto sub137= node->create_subscription<String>("topic_13", qos, [](String::SharedPtr) {});
  auto sub138= node->create_subscription<String>("topic_13", qos, [](String::SharedPtr) {});
  auto sub139= node->create_subscription<String>("topic_13", qos, [](String::SharedPtr) {});

  auto sub140= node->create_subscription<String>("topic_14", qos, [](String::SharedPtr) {});
  auto sub141= node->create_subscription<String>("topic_14", qos, [](String::SharedPtr) {});
  auto sub142= node->create_subscription<String>("topic_14", qos, [](String::SharedPtr) {});
  auto sub143= node->create_subscription<String>("topic_14", qos, [](String::SharedPtr) {});
  auto sub144= node->create_subscription<String>("topic_14", qos, [](String::SharedPtr) {});
  auto sub145= node->create_subscription<String>("topic_14", qos, [](String::SharedPtr) {});
  auto sub146= node->create_subscription<String>("topic_14", qos, [](String::SharedPtr) {});
  auto sub147= node->create_subscription<String>("topic_14", qos, [](String::SharedPtr) {});
  auto sub148= node->create_subscription<String>("topic_14", qos, [](String::SharedPtr) {});
  auto sub149= node->create_subscription<String>("topic_14", qos, [](String::SharedPtr) {});

  auto sub150= node->create_subscription<String>("topic_15", qos, [](String::SharedPtr) {});
  auto sub151= node->create_subscription<String>("topic_15", qos, [](String::SharedPtr) {});
  auto sub152= node->create_subscription<String>("topic_15", qos, [](String::SharedPtr) {});
  auto sub153= node->create_subscription<String>("topic_15", qos, [](String::SharedPtr) {});
  auto sub154= node->create_subscription<String>("topic_15", qos, [](String::SharedPtr) {});
  auto sub155= node->create_subscription<String>("topic_15", qos, [](String::SharedPtr) {});
  auto sub156= node->create_subscription<String>("topic_15", qos, [](String::SharedPtr) {});
  auto sub157= node->create_subscription<String>("topic_15", qos, [](String::SharedPtr) {});
  auto sub158= node->create_subscription<String>("topic_15", qos, [](String::SharedPtr) {});
  auto sub159= node->create_subscription<String>("topic_15", qos, [](String::SharedPtr) {});

  auto sub160= node->create_subscription<String>("topic_16", qos, [](String::SharedPtr) {});
  auto sub161= node->create_subscription<String>("topic_16", qos, [](String::SharedPtr) {});
  auto sub162= node->create_subscription<String>("topic_16", qos, [](String::SharedPtr) {});
  auto sub163= node->create_subscription<String>("topic_16", qos, [](String::SharedPtr) {});
  auto sub164= node->create_subscription<String>("topic_16", qos, [](String::SharedPtr) {});
  auto sub165= node->create_subscription<String>("topic_16", qos, [](String::SharedPtr) {});
  auto sub166= node->create_subscription<String>("topic_16", qos, [](String::SharedPtr) {});
  auto sub167= node->create_subscription<String>("topic_16", qos, [](String::SharedPtr) {});
  auto sub168= node->create_subscription<String>("topic_16", qos, [](String::SharedPtr) {});
  auto sub169= node->create_subscription<String>("topic_16", qos, [](String::SharedPtr) {});

  auto sub170= node->create_subscription<String>("topic_17", qos, [](String::SharedPtr) {});
  auto sub171= node->create_subscription<String>("topic_17", qos, [](String::SharedPtr) {});
  auto sub172= node->create_subscription<String>("topic_17", qos, [](String::SharedPtr) {});
  auto sub173= node->create_subscription<String>("topic_17", qos, [](String::SharedPtr) {});
  auto sub174= node->create_subscription<String>("topic_17", qos, [](String::SharedPtr) {});
  auto sub175= node->create_subscription<String>("topic_17", qos, [](String::SharedPtr) {});
  auto sub176= node->create_subscription<String>("topic_17", qos, [](String::SharedPtr) {});
  auto sub177= node->create_subscription<String>("topic_17", qos, [](String::SharedPtr) {});
  auto sub178= node->create_subscription<String>("topic_17", qos, [](String::SharedPtr) {});
  auto sub179= node->create_subscription<String>("topic_17", qos, [](String::SharedPtr) {});

  auto sub180= node->create_subscription<String>("topic_18", qos, [](String::SharedPtr) {});
  auto sub181= node->create_subscription<String>("topic_18", qos, [](String::SharedPtr) {});
  auto sub182= node->create_subscription<String>("topic_18", qos, [](String::SharedPtr) {});
  auto sub183= node->create_subscription<String>("topic_18", qos, [](String::SharedPtr) {});
  auto sub184= node->create_subscription<String>("topic_18", qos, [](String::SharedPtr) {});
  auto sub185= node->create_subscription<String>("topic_18", qos, [](String::SharedPtr) {});
  auto sub186= node->create_subscription<String>("topic_18", qos, [](String::SharedPtr) {});
  auto sub187= node->create_subscription<String>("topic_18", qos, [](String::SharedPtr) {});
  auto sub188= node->create_subscription<String>("topic_18", qos, [](String::SharedPtr) {});
  auto sub189= node->create_subscription<String>("topic_18", qos, [](String::SharedPtr) {});

  auto sub190= node->create_subscription<String>("topic_19", qos, [](String::SharedPtr) {});
  auto sub191= node->create_subscription<String>("topic_19", qos, [](String::SharedPtr) {});
  auto sub192= node->create_subscription<String>("topic_19", qos, [](String::SharedPtr) {});
  auto sub193= node->create_subscription<String>("topic_19", qos, [](String::SharedPtr) {});
  auto sub194= node->create_subscription<String>("topic_19", qos, [](String::SharedPtr) {});
  auto sub195= node->create_subscription<String>("topic_19", qos, [](String::SharedPtr) {});
  auto sub196= node->create_subscription<String>("topic_19", qos, [](String::SharedPtr) {});
  auto sub197= node->create_subscription<String>("topic_19", qos, [](String::SharedPtr) {});
  auto sub198= node->create_subscription<String>("topic_19", qos, [](String::SharedPtr) {});
  auto sub199= node->create_subscription<String>("topic_19", qos, [](String::SharedPtr) {});

  exec.add_node(node);
  exec.spin();
  rclcpp::shutdown();
  return 0;
}
