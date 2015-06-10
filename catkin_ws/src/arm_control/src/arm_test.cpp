#include "arm_control.h"

/**
 * This file demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{
  /**
   * The ros::init() function needs to see argc and argv so that it can 
   * perform any ROS arguments and name remapping that were provided at the
   * command line. For programmatic remappings you can use a different
   * version of init() which takes remappings directly, but for most
   * command-line programs, passing argc and argv is the easiest way to do
   * it.  The third argument to init() is the name of the node.
   *
   * You must call one of the versions of ros::init() before using any other
   * part of the ROS system.
   */
	ros::init(argc, argv, "arm_test");

  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */
	ros::NodeHandle arm_test_node;

  /**
   * The advertise() function is how you tell ROS that you want to
   * publish on a given topic name. This invokes a call to the ROS
   * master node, which keeps a registry of who is publishing and who
   * is subscribing. After this advertise() call is made, the master
   * node will notify anyone who is trying to subscribe to this topic name,
   * and they will in turn negotiate a peer-to-peer connection with this
   * node.  advertise() returns a Publisher object which allows you to
   * publish messages on that topic through a call to publish().  Once
   * all copies of the returned Publisher object are destroyed, the topic
   * will be automatically unadvertised.
   *
   * The second parameter to advertise() is the size of the message queue
   * used for publishing messages.  If messages are published more quickly
   * than we can send them, the number here specifies how many messages to
   * buffer up before throwing some away.
   */

	RobotArm robot_arm(arm_test_node);

  /**
   * Main program
   */
	while (ros::ok())
	{
		robot_arm.cnt+=10*robot_arm.move_direction;
		if(robot_arm.cnt>179){
			robot_arm.move_direction = -1;
		} else if(robot_arm.cnt<30){
			robot_arm.move_direction = 1;
		}
		robot_arm.move(FIRST,robot_arm.cnt);
		robot_arm.move(SECOND,robot_arm.cnt);
		robot_arm.move(THIRD,robot_arm.cnt);
		robot_arm.move(FORTH,robot_arm.cnt);
		robot_arm.move(FIFTH,robot_arm.cnt);
		robot_arm.sleep(3000);
	}
	return 0;
}
