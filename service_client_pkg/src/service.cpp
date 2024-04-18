 #include "ros/ros.h"
 #include "service_client_pkg/AddTwoInts.h"

bool call_back_func(service_client_pkg::AddTwoInts::Request &req, service_client_pkg::AddTwoInts::Response &res)

{
	res.sum = req.a + req.b;
	return true;
}

int main(int argc, char **argv)
	{
	ros::init(argc, argv, "service_name");
	ros::NodeHandle n;

	ros::ServiceServer service = n.advertiseService("service_name", call_back_func);
 
	ros::spin();
	return 0;

}
