#include <ros/ros.h>

int main(int argc, char** argv) {
  
  //announce this program to ROS master as a node called "tmill_ROS_hello"
  ros::init(argc, argv, "tmill_ROS_hello");
  
  //Establish as a ROS node
  ros::NodeHandle nh;
  
  //start node resource managers (comm, time, etc)
  ros::start();
  
  //broadcast a simple log message
  ROS_INFO_STREAM("Hello TMILL!");
  
  //process ROS callbacks until a SIGINT (CTRL-C)
  ros::spin();
  
  //stop node's resources
  ros::shutdown();
  
  //exit
  return 0;
}