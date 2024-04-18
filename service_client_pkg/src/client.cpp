 #include "ros/ros.h"
 #include "service_client_pkg/AddTwoInts.h"

int main(int argc, char **argv)
	{
	ros::init(argc, argv, "client_node");
	ros::NodeHandle n;

	ros::ServiceClient client = n.serviceClient<service_client_pkg::AddTwoInts>("service_name");

	service_client_pkg::AddTwoInts srv;
	srv.request.a = 2;
	srv.request.b = 4;

	if (client.call(srv)){
	ROS_INFO("The sum of the numbers is: %ld", srv.response.sum);
	}
	else{
	ROS_INFO("FAILED");
	return 1;
	}
 
	return 0;

}
