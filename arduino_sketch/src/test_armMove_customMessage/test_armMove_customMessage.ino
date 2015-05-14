#include <ros.h>
#include <std_msgs/Int16.h>
#include <arm_control/servo.h>
#include <Servo.h> 

#define RDS3115; //comment this line if you're not using RDS3115

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
int final_angle_first;
int final_angle_second;
int final_angle_third;
int final_angle_forth;
int final_angle_fifth;
int pos = 0;    // variable to store the servo position
#ifdef RDS3115
const float angle_scale = 133;
#endif

ros::NodeHandle nh;
 
void mover1( const arm_control::servo& pub1){
  
  //Change angle according to RDS3115
  #ifdef RDS3115
  Serial.println("Using RDS");
  final_angle_first = (float)pub1.first/180*angle_scale;
  final_angle_second = (float)pub1.second/180*angle_scale;
  final_angle_third = (float)pub1.third/180*angle_scale;
  final_angle_forth = (float)pub1.forth/180*angle_scale;
  final_angle_fifth = (float)pub1.fifth/180*angle_scale;
  #else
  Serial.println("Not using RDS");
  final_angle_first = pub1.first;
  final_angle_second = pub1.second;
  final_angle_third = pub1.third;
  final_angle_forth = pub1.forth;
  final_angle_fifth = pub1.fifth;
  #endif
  
  //command servo to rotate
  servo1.write(final_angle_first);
  servo2.write(final_angle_second);
  servo3.write(final_angle_third);
  servo4.write(final_angle_forth);
  servo5.write(final_angle_fifth);
}
ros::Subscriber<arm_control::servo> sub1("pub1", &mover1 );

void setup()
{
  Serial.begin(57600);
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
