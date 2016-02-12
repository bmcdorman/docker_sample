FROM ros:indigo

RUN apt-get update && apt-get install -y build-essential

# Add the project to the container's /app directory
ADD . /catkin_ws/src/docker_sample

# Build our catkin workspace from the /catkin_ws directory
WORKDIR /catkin_ws
RUN /ros_entrypoint.sh catkin_make

CMD /catkin_ws/devel/lib/docker_sample/docker_sample_node
