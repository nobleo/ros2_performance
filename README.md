# ros2_performance
## Package goal
Highlight the CPU overhead introduced by using ROS 2 versus Fast RTPS directly. 
Provide data from profiling tools to point where most of the CPU overhead is coming from.
Possibly start a discussion on the ROS 2 middleware design decisions.
## Package summary
This package provides different publisher subscriber setups that generate the same traffic.
ros, rosonenode and rtps all create 20 topics where each topic has 1 publisher and 10 subscribers.
noros and nopub are added for comparison to get an initial idea of overhead generated by different aspects of the ROS 2 stack.

| Binary  | publishers | subscribers | ROS | ROS nodes | ROS timers | DDS participants |
| ------------- | ------------- |------------- |------------- |------------- |------------- |------------- |
| ros | 20  | 200 | yes | 10 | 10 | 10 |
| rosonenode | 20 | 200 | yes | 1 | 1 | 1 |
| nopub | 0  | 0 | yes | 10 | 10 | 10 |
| rtps | 20 | 200 | no | 0 | 0 | 1 |
| noros | 20&ast;  | 200&ast; | no | 0 | 0| 0 |

&ast;C++ implementation no network publishing/subscribing.

Running all examples in isolated docker containers gives the following result:
![Alt text](/images/docker_comparison.png?raw=true "Docker comparison of binaries")

## Recreating the issue using Docker
It is possible to git clone this repository, build the workspace using colcon build and inspecting the CPU usage with top or a similar program for each binary individually. It is however much easier to give each binary its own container (make sure to separate their networks or give them a unique ROS_DOMAIN_ID) and measure the usage of each container.
If you don't have docker and docker compose installed first follow online tutorials on how to install these: https://docs.docker.com/install/ https://docs.docker.com/compose/install/ .

1. Clone this repository
```
git clone https://github.com/scgroot/ros2_performance.git
```
2. cd into the folder 
```
cd ros2_performance
```
3. Build the docker image [requires you to have docker installed properly following the links above] (this will take a while)
```
docker build -t ros2_performance:dashing .
```
*you can name the image differently by replacing "ros2_performance:dashing" by something else, but this will require you to change the docker-compose.yml file accordingly.*

4. Run a compose file
```
cd compose_files
```
here you have 2 options, each folder contains a docker-compose.yml. The "all" folder will start all the binaries listed in the table above. The "pubs_subs" folder will only start "rtps", "ros" and "rosonenode".
```
cd all
```
or
```
cd pubs_subs
```
then 
```
docker-compose up
```
5. Inspect the CPU usage
In a new terminal (ctrl+alt+t) do:
```
docker stats
```
It is possible to specify the format of the output to show more or less information for example:
```
docker stats --format "table {{.Name}}\t{{.CPUPerc}}\t{{.MemUsage}}\t{{.PIDs}}"
```
This will only display the container Name, the CPU percentage, Memory usage and PIDS.
You should now see a terminal similar to the image above. 

## Perf results
