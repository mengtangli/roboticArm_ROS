#include <ros.h>
#include <std_msgs/Int16.h>
#include <arm_control/servo.h>
#include <Servo.h> 
 
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
const float scale = 133;
float pos = 0;    // variable to store the servo position 
int real_angle;

ros::NodeHandle nh;
 
void mover1( const arm_control::servo& pub1){
  real_angle = pub1.first/180*scale;
  servo1.write(pub1.first);
  servo2.write(pub1.second);
  servo3.write(pub1.third);
  servo4.write(pub1.forth);
  servo5.write(pub1.fifth);
}
ros::Subscriber<arm_control::servo> sub1("pub1", &mover1 );

void setup()
{
  nh.initNode();
  nh.subscribe(sub1);
  servo1.attach(2);
  servo2.attach(3);
  servo3.attach(4);
  servo4.attach(5);
  servo5.attach(6);
  delay(1000);
}
 
void loop()
{
  nh.spinOnce();
  delay(10);
}
