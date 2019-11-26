cmake_minimum_required(VERSION 3.5)
project(ros2_performance VERSION 1.0.0)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rmw_fastrtps_cpp REQUIRED)
find_package(static_executor REQUIRED)

add_executable(ros src/ros.cc)
ament_target_dependencies(ros rclcpp std_msgs static_executor)
install(TARGETS ros DESTINATION lib/${PROJECT_NAME})

add_executable(rosonenode src/rosonenode.cc)
ament_target_dependencies(rosonenode rclcpp std_msgs static_executor)
install(TARGETS rosonenode DESTINATION lib/${PROJECT_NAME})

add_executable(nopub src/nopub.cc)
ament_target_dependencies(nopub rclcpp std_msgs static_executor)
install(TARGETS nopub DESTINATION lib/${PROJECT_NAME})

add_executable(noros src/noros.cc)
ament_target_dependencies(noros std_msgs rclcpp)
install(TARGETS noros DESTINATION lib/${PROJECT_NAME})

ament_package()
