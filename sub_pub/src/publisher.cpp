#include "ros/ros.h"
#include "std_msgs/String.h"


int main(int argc, char** argv)
{
    
	ros::init(argc, argv, "publisher");    
    	ros::NodeHandle n;

   	ros::Publisher pub = n.advertise<std_msgs::String>("topic", 10);
	

	while(ros::ok()){

	std_msgs::String msg;

	msg.data = "publishing data";
	
	pub.publish(msg);

	}


	ros::spin();

	return 0;
}
