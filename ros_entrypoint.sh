#!/bin/bash
set -e

# setup ros environment
source "/opt/ros/dashing/setup.bash"
source "/home/noblean/ros2_performance/install/local_setup.bash"
exec "$@"
