# Docker Sample

This is an example ROS indigo/catkin application that is packaged using docker. Simply copy the Dockerfile to your own ROS indigo project and modify the relevant paths to be applicable to your project.

*Note:* All commands are to be executed from project root directory.

## Filesystem Structure

This container copies the project folder to `/catkin_ws/src/docker_sample`. `catkin_make` is
then called from `/catkin_ws` to build the project. After the build successfully completes, the application executable is located in `/catkin_ws/devel/lib/docker_sample/docker_sample_node`.

## Building

To build a docker container, type `docker build -t expeditions/docker_sample .`.

## Running

To run the ROS node, type `docker run -i -t --net=host expeditions/docker_sample`.

## Force Stopping

In rare cases, the docker terminal can become unresponsive. To stop all running containers, run `docker stop $(docker ps -ql)`.

## Development

To develop using docker, simply replace the pre-existing `/catkin_ws/src/docker_sample` directory with a filesystem mountpoint and start a shell rather than the ROS node (`docker run -i -t --net=host -v $(pwd):/catkin_ws/src/ expeditions/docker_sample /bin/bash`). You may now use a system editor to modify the project and the docker terminal to compile/test your code.
