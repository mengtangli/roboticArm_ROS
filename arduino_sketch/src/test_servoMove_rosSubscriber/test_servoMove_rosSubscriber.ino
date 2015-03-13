#include <ros.h>
#include <std_msgs/Int16.h>
#include <Servo.h> 
 
Servo servo1;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
 
ros::NodeHandle nh;
 
 
void mover( const std_msgs::Int16& giro){
 
  servo1.write(giro.data);
 
}
 
ros::Subscriber<std_msgs::Int16> sub("giro", &mover );
 
void setup()
{
  nh.initNode();
  nh.subscribe(sub);
  servo1.attach(2);
  delay(1000);
}
 
void loop()
{
  nh.spinOnce();
  delay(10);
}
