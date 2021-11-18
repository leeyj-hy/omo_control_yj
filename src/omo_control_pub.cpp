#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "fiducial_msgs/FiducialTransformArray.h"


void marker_3d_t_r(const fiducial_msgs::FiducialTransformArray &msg);


int main(int ac, char **av)
{
	ros::init(ac, av, "omo_control_pub");

	ros::NodeHandle n;
	ros::Publisher chatter_pub = n.advertise<geometry_msgs::Twist>("/cmd_vel", 100);
	ros::Subscriber sub = n.subscribe("/fiducial_transforms", 10, marker_3d_t_r);

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


void marker_3d_t_r(const fiducial_msgs::FiducialTransformArray &msg)
{
  for(int i=0; i<msg.transforms.size() ; i++)
  {
    ROS_INFO("MARKER_ID : %d", msg.transforms[i].fiducial_id);
    ROS_INFO("TRANS_X : %f", msg.transforms[i].transform.translation.x);
    ROS_INFO("TRANS_Y : %f", msg.transforms[i].transform.translation.y);
    ROS_INFO("TRANS_Z : %f", msg.transforms[i].transform.translation.z);
    ROS_INFO("QUATER_X : %f", msg.transforms[i].transform.rotation.x);
    ROS_INFO("QUATER_Y : %f", msg.transforms[i].transform.rotation.y);
    ROS_INFO("QUATER_Z : %f", msg.transforms[i].transform.rotation.z);
    ROS_INFO("QUATER_W : %f", msg.transforms[i].transform.rotation.w);
    ROS_INFO("====================");

  }

}
