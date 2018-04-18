#include "ros/ros.h"

#include "std_msgs/String.h"


#include <sstream>


int main(int argc, char **argv){
 
  ros::init(argc, argv, "talker");

  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("filtered", 1000);

  ros::Rate loop_rate(1);


  while (ros::ok())
  {

    std_msgs::String message;

    std::stringstream ss;
    ss << "Sara" << "21" << "Bioinformatica";


    message.data = ss.str();


    ROS_INFO("%s", message.data.c_str());

    
    chatter_pub.publish(message);
// %EndTag(PUBLISH)%

// %Tag(SPINONCE)%
    ros::spinOnce();
// %EndTag(SPINONCE)%

// %Tag(RATE_SLEEP)%
    loop_rate.sleep();

  }

}


