#include "arm_control.h"
#include "math.h"

/**
 * RobotArm() - Initialize a RobotArm class
 *
 * @arm_node_handl:	The handler for the working node.
 *
 * Initialize a class object to has a global rate of 1kHz. The publisher of
 * each servo should be registered to the its respective topic as well. Change
 * this if there are any change in the design or add more servos to the robot. 
 * Note that this method(constructor) has no type, not even void.
 *
 */
RobotArm::RobotArm(ros::NodeHandle arm_node): ros_rate(1000)
{
	cnt = 0;
	controller_publisher = arm_node.advertise<arm_control::servo>("arm_command", 100);
	gazebo_publisher1 = arm_node.advertise<std_msgs::Float64>("/arm/elbow1_1_controller/command",100);
	gazebo_publisher2 = arm_node.advertise<std_msgs::Float64>("/arm/elbow1_2_controller/command",100);
	gazebo_publisher3 = arm_node.advertise<std_msgs::Float64>("/arm/elbow2_1_controller/command",100);
	gazebo_publisher4 = arm_node.advertise<std_msgs::Float64>("/arm/elbow2_2_controller/command",100);
	gazebo_publisher5 = arm_node.advertise<std_msgs::Float64>("/arm/elbow3_1_controller/command",100);
}

/**
 * move() - Move servo an angle(in degrees) both on real life and gazebo
 * simulation
 *
 * @servo_number:	The number of servo to be moved.
 * @data:		Angle to move the servo (in degrees).
 *
 * Choose which servo to move using switch(). First, assign data to msg
 * variables. Second, queue (publish) msg of both real-life and
 * simulation. Third, print debug info with ROS_INFO. Finally,
 * spinOnce() to execute the publish.
 *
 */
void RobotArm::move(int servo_number, int data)
{
	switch(servo_number){
	case 1: controller_msg.first = data;
		controller_publisher.publish(controller_msg);
		gazebo_msg.data = (float)data*3.14/180;
		gazebo_publisher1.publish(gazebo_msg);
		ROS_INFO("First: %d", controller_msg.first);
    		ros::spinOnce();
		break;
	case 2:
		controller_msg.second = data;
    		controller_publisher.publish(controller_msg);
		gazebo_msg.data = (float)data*3.14/180;
		gazebo_publisher2.publish(gazebo_msg);
		ROS_INFO("Second: %d", controller_msg.second);
    		ros::spinOnce();
		break;
	case 3:
		controller_msg.third = data;
    		controller_publisher.publish(controller_msg);
		gazebo_msg.data = (float)data*3.14/180;
		gazebo_publisher3.publish(gazebo_msg);
		ROS_INFO("Third: %d", controller_msg.third);
    		ros::spinOnce();
		break;
	case 4:
		controller_msg.forth = data;
    		controller_publisher.publish(controller_msg);
		gazebo_msg.data = (float)data*3.14/180;
		gazebo_publisher4.publish(gazebo_msg);
		ROS_INFO("Forth: %d", controller_msg.forth);
    		ros::spinOnce();
		break;
	case 5:
		controller_msg.fifth = data;
    		controller_publisher.publish(controller_msg);
		gazebo_msg.data = (float)data*3.14/180;
		gazebo_publisher5.publish(gazebo_msg);
		ROS_INFO("Fifth: %d", controller_msg.fifth);
    		ros::spinOnce();
		break;
	default:
		break;
	}
}

/**
 * sleep() - Sleep the ROS system a given time(ms).
 *
 * @no_of_ms: Number of times the ros_rate will be repeated by miliseconds
 *
 */
void RobotArm::sleep(long no_of_ms)
{
	for(long i=0; i<no_of_ms; i++)
		ros_rate.sleep();
}
