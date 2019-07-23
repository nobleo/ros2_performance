FROM ubuntu:18.04

# Inform scripts that no questions should be asked
RUN echo 'debconf debconf/frontend select Noninteractive' | debconf-set-selections

# Allow installing resolvconf (https://stackoverflow.com/a/45908415)
RUN echo "resolvconf resolvconf/linkify-resolvconf boolean false" | debconf-set-selections

# Install commands used in our scripts and standard present on a clean ubuntu installation
RUN apt-get update -qq && apt-get install -qq --assume-yes --no-install-recommends sudo apt-utils git wget curl python-psutil ssh locales locales-all udev vim gnupg2 lsb-release

# Set Locales
ENV LANG en_US.UTF-8
ENV LANGUAGE en_US:en
ENV LC_ALL en_US.UTF-8

# Make ssh dir
RUN mkdir /root/.ssh/

# Add noblean user
RUN adduser --disabled-password --gecos "" noblean
RUN adduser noblean sudo
RUN echo '%sudo ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers
USER noblean
WORKDIR /home/noblean

#RUN git config --global http.sslVerify false

# Remove interactive check from bashrc, otherwise bashrc refuses to execute
RUN sed -e s/return//g -i ~/.bashrc

RUN curl http://repo.ros2.org/repos.key | sudo apt-key add -
RUN sudo sh -c 'echo "deb [arch=amd64,arm64] http://packages.ros.org/ros2/ubuntu `lsb_release -cs` main" > /etc/apt/sources.list.d/ros2-latest.list'

RUN sudo apt-get update -qq && sudo apt-get install -qq --assume-yes --no-install-recommends ros-dashing-desktop python3-argcomplete

RUN echo "source /opt/ros/dashing/setup.bash" >> ~/.bashrc

RUN sudo apt-get update -qq && sudo apt-get install -qq --assume-yes --no-install-recommends \
  build-essential \
  cmake \
  git \
  python3-colcon-common-extensions \
  python3-pip \
  python-rosdep \
  python3-vcstool \
  wget
# install some pip packages needed for testing
RUN python3 -m pip install -U \
  argcomplete \
  flake8 \
  flake8-blind-except \
  flake8-builtins \
  flake8-class-newline \
  flake8-comprehensions \
  flake8-deprecated \
  flake8-docstrings \
  flake8-import-order \
  flake8-quotes \
  pytest-repeat \
  pytest-rerunfailures \
  pytest \
  pytest-cov \
  pytest-runner \
  setuptools
# install Fast-RTPS dependencies
RUN sudo apt-get update -qq && sudo apt-get install -qq --assume-yes --no-install-recommends \
  libasio-dev \
  libtinyxml2-dev

#RUN git clone https://github.com/scgroot/ros2_performance.git

COPY src /home/noblean/ros2_performance/src
COPY CMakeLists.txt /home/noblean/ros2_performance
COPY package.xml /home/noblean/ros2_performance
RUN sudo chown -R noblean /home/noblean/ros2_performance

RUN cd ros2_performance/ && sudo rosdep init
RUN rosdep update
RUN cd ros2_performance/ && rosdep install --from-paths src --ignore-src --rosdistro dashing -y --skip-keys "console_bridge fastcdr fastrtps libopensplice67 libopensplice69 rti-connext-dds-5.3.1 urdfdom_headers"

RUN bash -c 'cd ros2_performance/ && source /opt/ros/dashing/setup.bash && colcon build --symlink-install'

# Entrypoint setup
COPY ./ros_entrypoint.sh /
RUN sudo chmod a+x /ros_entrypoint.sh
ENTRYPOINT ["/ros_entrypoint.sh"]
CMD ["bash"]
