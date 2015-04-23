#include <ros.h>
#include <std_msgs/Int16.h>
#include <arm_control/servo.h>
#include <Servo.h> 
 
Servo servo1;
Servo servo2;
Servo servo3;
const float scale = 133;
float pos = 0;    // variable to store the servo position 
int real_angle;

ros::NodeHandle nh;
 
void mover1( const arm_control::servo& pub1){
  real_angle = pub1.first/180*scale;
  servo1.write(pub1.first);
  
  servo2.write(pub1.second);
  servo3.write(pub1.third);
}
ros::Subscriber<arm_control::servo> sub1("pub1", &mover1 );

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
