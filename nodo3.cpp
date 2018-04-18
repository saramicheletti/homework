#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>
#include <cstring>
#include <string>

int comando;


void filteredPubblica(const std_msgs::String::ConstPtr& msg){

if(comando !='0'){

  char * cstr = new char [msg->data.length()+1];
  std::strcpy (cstr, msg->data.c_str());

switch (comando)
{
	case 'a': 
		std::cout << cstr << '\n';
	break;
	
	case 'n': 
		{char * p = std::strtok (cstr," "); //p punta alla prima sottostringa del messaggio 
		std::cout << p << '\n';
    		}
	break;
	

	case 'e': 
		{char * p = std::strtok (cstr," ");
		p = std::strtok(NULL," "); //p punta alla seconda sottostringa 
		std::cout << p << '\n';
		}
	break;
	
	case 'c': 
		{char * p = std::strtok (cstr," ");
		p = std::strtok(NULL," "); //p punta alla seconda sottostringa 
		p = std::strtok(NULL," "); //p punta alla terza sottostringa
		std::cout << p << '\n';
		}
	break;
}


  delete[] cstr;
}
  
}


/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */
// %Tag(CALLBACK)%
void chatterComando(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
	
	comando=msg->data[0];
}
// %EndTag(CALLBACK)%


int main(int argc, char **argv){

	
  /**
   * The ros::init() function needs to see argc and argv so that it can perform
   * any ROS arguments and name remapping that were provided at the command line.
   * For programmatic remappings you can use a different version of init() which takes
   * remappings directly, but for most command-line programs, passing argc and argv is
   * the easiest way to do it.  The third argument to init() is the name of the node.
   *
   * You must call one of the versions of ros::init() before using any other
   * part of the ROS system.
   */
  ros::init(argc, argv, "listener");

  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */
  ros::NodeHandle n;

  /**
   * The subscribe() call is how you tell ROS that you want to receive messages
   * on a given topic.  This invokes a call to the ROS
   * master node, which keeps a registry of who is publishing and who
   * is subscribing.  Messages are passed to a callback function, here
   * called chatterCallback.  subscribe() returns a Subscriber object that you
   * must hold on to until you want to unsubscribe.  When all copies of the Subscriber
   * object go out of scope, this callback will automatically be unsubscribed from
   * this topic.
   *
   * The second parameter to the subscribe() function is the size of the message
   * queue.  If messages are arriving faster than they are being processed, this
   * is the number of messages that will be buffered up before beginning to throw
   * away the oldest ones.
   */


// %Tag(SUBSCRIBER) con nodo2% 
  ros::Subscriber sub = n.subscribe("filtered", 1000, filteredPubblica);
// %EndTag(SUBSCRIBER)%

// %Tag(SUBSCRIBER) con nodo1% 
  ros::Subscriber s = n.subscribe("chatter", 1000, chatterComando);
// %EndTag(SUBSCRIBER)%



  /**
   * ros::spin() will enter a loop, pumping callbacks.  With this version, all
   * callbacks will be called from within this thread (the main one).  ros::spin()
   * will exit when Ctrl-C is pressed, or the node is shutdown by the master.
   */
// %Tag(SPIN)%
  ros::spin();
// %EndTag(SPIN)%

  return 0;
}
// %EndTag(FULLTEXT)%

