#ifndef ADD_H
#define ADD_H

#include "ros/ros.h"
#include "arm_control/servo.h"
#include "std_msgs/Float64.h"

#define FIRST	1
#define SECOND	2
#define THIRD	3
#define FORTH	4
#define FIFTH	5

class RobotArm
{
	ros::Rate ros_rate;
	ros::Publisher controller_publisher;	//publisher to publish message to controller
	ros::Publisher gazebo_publisher1;	//publisher(s) to publish message to gazebo
	ros::Publisher gazebo_publisher2;
	ros::Publisher gazebo_publisher3;
	ros::Publisher gazebo_publisher4;
	ros::Publisher gazebo_publisher5;
	arm_control::servo controller_msg;	//message to publish to controller
	std_msgs::Float64 gazebo_msg;		//message to publish to gazebo
public:
	RobotArm (ros::NodeHandle);
	int cnt;		//general variable to count something
	int move_direction; 	//direction the arm's moving, 1 = anti-clockwise, -1 = cw
	void move(int servo_number, int data);
	void sleep(long no_of_ms);
};

#endif
