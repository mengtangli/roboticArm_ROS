#include "arm_control.h"

/**
 * move() - Move servo an angle(in degrees) both on real life and gazebo
 * simulation
 *
 * @servo_number:	The number of servo to be moved.
 * @data:		Angle to move the servo (in degrees).
 * @publisher:		Publisher to publish the data to servo
 * @gazebo_publisher:	Publisher to publish the data to gazebo
 *
 * Choose which servo to move using switch(). First, assign data to msg
 * variables. Second, queue (publish) msg of both real-life and
 * simulation. Third, print debug info with ROS_INFO. Finally,
 * spinOnce() to execute the publish.
 *
 */
void move(int servo_number, int data, ros::Publisher publisher, ros::Publisher gazebo_publisher)
{
	switch(servo_number){
	case 1:
		msg.first = data;
		publisher.publish(msg);
		gazebo_msg.data = data;
		gazebo_publisher.publish(gazebo_msg);
		ROS_INFO("First: %d", msg.first);
    		ros::spinOnce();
		break;
	case 2:
		msg.second = data;
    		publisher.publish(msg);
		gazebo_msg.data = data;
		gazebo_publisher.publish(gazebo_msg);
		ROS_INFO("Second: %d", msg.second);
    		ros::spinOnce();
		break;
	case 3:
		msg.third = data;
    		publisher.publish(msg);
		gazebo_msg.data = data;
		gazebo_publisher.publish(gazebo_msg);
		ROS_INFO("Third: %d", msg.third);
    		ros::spinOnce();
		break;
	case 4:
		msg.forth = data;
    		publisher.publish(msg);
		gazebo_msg.data = data;
		gazebo_publisher.publish(gazebo_msg);
		ROS_INFO("Forth: %d", msg.forth);
    		ros::spinOnce();
		break;
	case 5:
		msg.fifth = data;
    		publisher.publish(msg);
		gazebo_msg.data = data;
		gazebo_publisher.publish(gazebo_msg);
		ROS_INFO("Fifth: %d", msg.fifth);
    		ros::spinOnce();
		break;
	default:
		break;
	}
}

/**
 * sleep() - Sleep the ROS system a given time(ms).
 *
 * @sleep_rate:	Standard rate(Hz) defined in the main function.
 * 		default: 1KHz
 * @no_of_loops:Number of times the sleep_rate will be repeated.
 *
 */
void sleep(ros::Rate sleep_rate, long no_of_loops)
{
	for(long i=0; i<no_of_loops; i++)
		sleep_rate.sleep();
}
