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
	h = 3;
	l1 = 2;
	l2 =3;
	controller_publisher = arm_node.advertise<arm_control::servo>("arm_command", 100);
	gazebo_publisher1 = arm_node.advertise<std_msgs::Float64>("/arm/elbow1_1_controller/command",100);
	gazebo_publisher2 = arm_node.advertise<std_msgs::Float64>("/arm/elbow1_2_controller/command",100);
	gazebo_publisher3 = arm_node.advertise<std_msgs::Float64>("/arm/elbow2_1_controller/command",100);
	gazebo_publisher4 = arm_node.advertise<std_msgs::Float64>("/arm/elbow2_2_controller/command",100);
	gazebo_publisher5 = arm_node.advertise<std_msgs::Float64>("/arm/elbow3_1_controller/command",100);
}

/**
 * get_position() - get the coordinate of a servo with respect to base-joint
 *
 * @servo_number:	The number of servo to get position
 *
 * Multiply matrices to get position of the servos. Based mostly on the forward
 * kinematics
 */
geometry_msgs::Point RobotArm::get_position(int servo_number)
{
	geometry_msgs::Point result;
	switch(servo_number){
	case 1:	result.x = 0;
		result.y = 0;
		result.z = 0;
		return result;
	case 2:	result.x = 0;
		result.y = 0;
		result.z = h;
		return result;
	case 3: result.x = l1*cos(theta0)*cos(theta1);
		result.y = l1*sin(theta0)*cos(theta1);
		result.z = h + l1*sin(theta1);
		return result;
	case 4: result.x = h*cos(theta0)*sin(theta1) + l1*cos(theta0)*cos(theta1);
		result.y = h*sin(theta0)*sin(theta1) + l1*sin(theta0)*cos(theta1);
		result.z = h - h*cos(theta1) + l1*sin(theta1);
		return result;
	case 5: result.x = h*cos(theta0)*sin(theta1) + l1*cos(theta0)*cos(theta1) + l2*cos(theta3)*(cos(theta0)*cos(theta1)*cos(theta2) + sin(theta0)*sin(theta2)) - l2*cos(theta0)*sin(theta1)*sin(theta3);
		result.y = h*sin(theta0)*sin(theta1) + l1*sin(theta0)*cos(theta1) + l2*cos(theta3)*(sin(theta0)*cos(theta1)*cos(theta2) - cos(theta0)*sin(theta2)) - l2*sin(theta0)*sin(theta1)*sin(theta3);
		result.z = h - h*cos(theta1) + l1*sin(theta1) + l2*(sin(theta1)*cos(theta2)*cos(theta3) - cos(theta1)*sin(theta3));
		return result;
	}
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
		theta0 = data;
    		ros::spinOnce();
		break;
	case 2:
		controller_msg.second = data;
    		controller_publisher.publish(controller_msg);
		gazebo_msg.data = (float)data*3.14/180;
		gazebo_publisher2.publish(gazebo_msg);
		ROS_INFO("Second: %d", controller_msg.second);
		theta1 = data;
    		ros::spinOnce();
		break;
	case 3:
		controller_msg.third = data;
    		controller_publisher.publish(controller_msg);
		gazebo_msg.data = (float)data*3.14/180;
		gazebo_publisher3.publish(gazebo_msg);
		ROS_INFO("Third: %d", controller_msg.third);
		theta2 = data;
    		ros::spinOnce();
		break;
	case 4:
		controller_msg.forth = data;
    		controller_publisher.publish(controller_msg);
		gazebo_msg.data = (float)data*3.14/180;
		gazebo_publisher4.publish(gazebo_msg);
		ROS_INFO("Forth: %d", controller_msg.forth);
		theta3 = data;
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
