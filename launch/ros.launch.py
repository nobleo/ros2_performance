import os
import pathlib

import launch
import launch_ros.actions
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription


def generate_launch_description():

    ros = launch_ros.actions.Node(
        package="ros2_performance", node_executable="ros", output="screen"
    )

    return LaunchDescription([ros])
