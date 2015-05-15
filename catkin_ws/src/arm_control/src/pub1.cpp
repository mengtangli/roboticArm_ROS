#include "ros/ros.h"
#include "arm_control/servo.h"
#include "std_msgs/Int16.h"

/**
 * Global variables and defines
 */
#define FIRST 1
#define SECOND 2
#define THIRD 3
#define FORTH 4
#define FIFTH 5
arm_control::servo msg;

/**
 * Functions
 */
void move(int servo_number, int data, ros::Publisher publisher);
bool sleep(ros::Rate sleep_rate, long no_ms);


/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{
  /**
   * The ros::init() function needs to see argc and argv so that it can perform
   * any ROS arguments and name remapping that were provided at the command line. For programmatic
   * remappings you can use a different version of init() which takes remappings
   * directly, but for most command-line programs, passing argc and argv is the easiest
   * way to do it.  The third argument to init() is the name of the node.
   *
   * You must call one of the versions of ros::init() before using any other
   * part of the ROS system.
   */
  ros::init(argc, argv, "pub1");

  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */
  ros::NodeHandle pub1_node;

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
  ros::Publisher pub1 = pub1_node.advertise<arm_control::servo>("pub1", 1000);

  ros::Rate loop_rate(1000);

  /**
   * A count of how many messages we have sent. This is used to create
   * a unique string for each message.  */
  int count = 0;
  int move_direction = 1; //1 = anti-clockwise, -1 = cw
  while (ros::ok())
  {
    /**
     * This is a message object. You stuff it with data, and then publish it.
     */
/*
    msg.first = count;
    ROS_INFO("First: %d", msg.first);

    pub1.publish(msg);
    ros::spinOnce(); loop_rate.sleep();

    msg.second = count;
    ROS_INFO("Second: %d", msg.second);

    msg.third = count;
    ROS_INFO("Third: %d", msg.third);

    msg.forth = count;
    ROS_INFO("Forth: %d", msg.forth);

    msg.fifth = count;
    ROS_INFO("Fifth: %d", msg.fifth);
*/
 
    /**
     * The publish() function is how you send messages. The parameter
     * is the message object. The type of this object must agree with the type
     * given as a template parameter to the advertise<>() call, as was done
     * in the constructor above.
     */
/*    pub1.publish(msg);
    ros::spinOnce();

    loop_rate.sleep();
    count+=10*move_direction;
    if(count>179){
	move_direction =-1;
    }
    else if(count<30){
	move_direction = 1;
    }
  }
*/
	count+=10*move_direction;
    	if(count>179){
		move_direction = -1;
    	} else if(count<30){
		move_direction = 1;
    	}
	move(FIRST,count,pub1);
	move(SECOND,count,pub1);
	move(THIRD,count,pub1);
	move(FORTH,count,pub1);
	move(FIFTH,count,pub1);
	sleep(loop_rate,1000);
  }
  return 0;
}

/**
 * Move servo an angle
 */
void move(int servo_number, int data, ros::Publisher publisher)
{
	switch(servo_number){
	case 1:
		msg.first = data;
		ROS_INFO("First: %d", msg.first);
    		publisher.publish(msg);
    		ros::spinOnce();
		break;
	case 2:
		msg.second = data;
		ROS_INFO("Second: %d", msg.second);
    		publisher.publish(msg);
    		ros::spinOnce();
		break;
	case 3:
		msg.third = data;
		ROS_INFO("Third: %d", msg.third);
    		publisher.publish(msg);
    		ros::spinOnce();
		break;
	case 4:
		msg.forth = data;
		ROS_INFO("Forth: %d", msg.forth);
    		publisher.publish(msg);
    		ros::spinOnce();
		break;
	case 5:
		msg.fifth = data;
		ROS_INFO("Fifth: %d", msg.fifth);
    		publisher.publish(msg);
    		ros::spinOnce();
		break;
	default:
		break;
	}
}

/**
 * Sleep function
 * unit: miliseconds
 * return: true if sleep duration ends
 */
bool sleep(ros::Rate sleep_rate, long no_of_loops)
{
	for(long i=0; i<no_of_loops; i++)
		sleep_rate.sleep();
	return true;
}
