#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  // initialize ROS and become a node
  ros::init(argc,argv, "publish_velocity");
  ros::NodeHandle nh;
  
  // create a publisher object
  ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000);
  
  // seed random number generator
  srand(time(0));
  
  // loop at 2Hz until node is shut down 
  ros::Rate rate(2);
  while(ros::ok()) {
    
    // create and fill in the message
    // the other messages (ignored by turtlesim) are defaulted to zero
    geometry_msgs::Twist msg;
    msg.linear.x = double(rand())/double(RAND_MAX);
    msg.angular.z = 2*double(rand())/double(RAND_MAX) - 1;
    
    // publish the message
    pub.publish(msg);
    
    // send a message to rosout with the details of the published data
    ROS_INFO_STREAM("Sending random velocity command: "
      << "linear=" << msg.linear.x
      << "angular=" << msg.angular.z);
    
    rate.sleep();
    
  } //end while
  
} //end main