
#include "ros/ros.h"

#include "std_msgs/String.h"

#include <sstream>
#include <iostream>

 
int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "talker");

  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

  ros::Rate loop_rate(10);


  
  char l;
  while (ros::ok())
  {

    std_msgs::String msg; //CREO UNA STRINGA CHE CONTERRA' LA MIA LETTERA
   
    std::cout << "Enter a letter: "; //CHIEDO DI INSERIRE LA LETTERA
    std::cin >> l; //INSERISCO LA LETTERA l

    msg.data = l; //METTO LA LETTERA IN msg.data


    ROS_INFO("%s", msg.data.c_str());

// %Tag(PUBLISH)%
    chatter_pub.publish(msg); 
// %EndTag(PUBLISH)%

// %Tag(SPINONCE)%
    ros::spinOnce();
// %EndTag(SPINONCE)%

// %Tag(RATE_SLEEP)%
    loop_rate.sleep();
// %EndTag(RATE_SLEEP)%
    
  }


  return 0;
}
// %EndTag(FULLTEXT)%

