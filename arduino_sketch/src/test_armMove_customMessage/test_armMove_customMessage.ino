#include <ros.h>
#include <std_msgs/Int16.h>
#include <ros_tut/servo.h>
#include <Servo.h> 
 
Servo servo1;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created
Servo servo2;
Servo servo3;
 
ros::NodeHandle nh;
 
void mover1( const ros_tut::servo& pub1){
  servo1.write(pub1.first);
  servo2.write(pub1.second);
  servo3.write(pub1.third);
}
ros::Subscriber<ros_tut::servo> sub1("pub1", &mover1 );

void setup()
{
  nh.initNode();
  nh.subscribe(sub1);
  servo1.attach(2);
  servo2.attach(3);
  servo3.attach(4);
  delay(1000);
}
 
void loop()
{
  nh.spinOnce();
  delay(10);
}
