#include <ros/ros.h>

int main(int argc, char** argv) {
  
  //announce this program to ROS master as a node called hello_world_node"
  ros::init(argc, argv, "hello_world_node");
  
  //start node resource managers (comm, time, etc)
  ros::start();
  
  //broadcast a simple log message
  ROS_INFO_STREAM("Hello world!!");
  
  //process ROS callbacks until a SIGINT (CTRL-C)
  ros::spin();
  
  //stop node's resources
  ros::shutdown();
  
  //exit
  return 0;
}

//to compile:
//g++ hello_world_tutorial.cpp -o hello_world_node -I/opt/ros/indigo/include -L/opt/ros/indigo/lib -Wl,-rpath,/opt/ros/indigo/lib -lroscpp -lrosconsole -lrostime

//running
//in one console, roscore
//in second, ./hello_world_node