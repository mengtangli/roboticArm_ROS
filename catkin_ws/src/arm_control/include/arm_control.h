#include "ros/ros.h"
#include "arm_control/servo.h"
#include "std_msgs/Float64.h"

#define FIRST	1
#define SECOND	2
#define THIRD	3
#define FORTH	4
#define FIFTH	5
arm_control::servo msg;
std_msgs::Float64 gazebo_msg;

void move(int servo_number, int data, ros::Publisher publisher, ros::Publisher gazebo_publisher);
void sleep(ros::Rate sleep_rate, long no_ms);

