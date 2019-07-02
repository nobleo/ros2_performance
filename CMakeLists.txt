cmake_minimum_required(VERSION 3.5)
project(ros_performance VERSION 1.0.0)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rmw_fastrtps_cpp REQUIRED)

add_executable(ros src/ros.cc)
ament_target_dependencies(ros rclcpp std_msgs)
install(TARGETS ros DESTINATION lib/${PROJECT_NAME})

add_executable(nopub src/nopub.cc)
ament_target_dependencies(nopub rclcpp)
install(TARGETS nopub DESTINATION lib/${PROJECT_NAME})

add_executable(noros src/noros.cc)
ament_target_dependencies(noros std_msgs rclcpp)
install(TARGETS noros DESTINATION lib/${PROJECT_NAME})

add_executable(rtps src/rtps.cc src/HelloWorld.cxx src/HelloWorldPubSubTypes.cxx)
ament_target_dependencies(rtps rmw_fastrtps_cpp)
install(TARGETS rtps DESTINATION lib/${PROJECT_NAME})

ament_package()
