#include <ros/ros.h>
#include <std_msgs/String.h>
#include <iostream>
#include <cstdlib>

namespace
{
  void test_sub(const std_msgs::String::ConstPtr &msg)
  {
    std::cout << "Got message: " << msg->data << std::endl;
  }
}

int main(int argc, char *argv[])
{
  ros::init(argc, argv, "test");

  ros::NodeHandle nh;
  auto test_sub_handle = nh.subscribe("/test", 1, &test_sub);

  ros::spin();
  return EXIT_SUCCESS;
}
