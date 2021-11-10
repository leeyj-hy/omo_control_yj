#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

int main(int ac, char **av)
{
	ros::init(ac, av, "omo_control_pub");
	ros::NodeHandle n;
	ros::Publisher chatter_pub = n.advertise<geometry_msgs::Twist>("/cmd_vel", 100);
	ros::Rate loop_rate(10);


	while(ros::ok())
	{

		geometry_msgs::Twist move;

		move.linear.x = 0.1;

		chatter_pub.publish(move);
		ROS_INFO("%f", move.linear.x);
		ros::spinOnce();


		loop_rate.sleep();

	}
}