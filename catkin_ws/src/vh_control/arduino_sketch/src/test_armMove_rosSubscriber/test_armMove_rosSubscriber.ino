#include <ros.h>
#include <std_msgs/Int16.h>
#include <Servo.h> 
 
Servo servo1;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created
Servo servo2;
Servo servo3;
 
ros::NodeHandle nh;
 
void mover1( const std_msgs::Int16& pub1){
  servo1.write(pub1.data);
}
ros::Subscriber<std_msgs::Int16> sub1("pub1", &mover1 );

void mover2( const std_msgs::Int16& pub2){
 
  servo2.write(pub2.data);
 
}
ros::Subscriber<std_msgs::Int16> sub2("pub2", &mover2 );

void mover3( const std_msgs::Int16& pub3){
 
  servo3.write(pub3.data);
 
}
ros::Subscriber<std_msgs::Int16> sub3("pub3", &mover3 );
 
void setup()
{
  nh.initNode();
  nh.subscribe(sub1);
  nh.subscribe(sub2);
  nh.subscribe(sub3);
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
