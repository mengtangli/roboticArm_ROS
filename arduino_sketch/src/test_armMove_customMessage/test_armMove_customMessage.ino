#include <ros.h>
#include <std_msgs/Int16.h>
#include <arm_control/servo.h>
#include <Servo.h> 

#define RDS3115; //comment this line if you're not using RDS3115

const int servo_step = 7; //step to run in 100ms

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
int last_final_angle_first;
int last_final_angle_second;
int last_final_angle_third;
int last_final_angle_forth;
int last_final_angle_fifth;
int pos = 0;    // variable to store the servo position
#ifdef RDS3115
const float angle_scale = 133;
#endif

ros::NodeHandle nh;
 
void mover1( const arm_control::servo& pub1){
  
  //Save the last angle
  last_final_angle_first = final_angle_first;
  last_final_angle_second = final_angle_second;
  last_final_angle_third = final_angle_third;
  last_final_angle_forth = final_angle_forth;
  last_final_angle_fifth = final_angle_fifth;
  
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
  move_servo(servo1, final_angle_first, last_final_angle_first);
  move_servo(servo2, final_angle_second, last_final_angle_second);
  move_servo(servo3, final_angle_third, last_final_angle_third);
  move_servo(servo4, final_angle_forth, last_final_angle_forth);
  move_servo(servo5, final_angle_fifth, last_final_angle_fifth);
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

//Move servo with modified speed
//Right now, move 5 degrees each 100ms
// Return 0 if there's no change in angle
// Return 1 if changed
boolean move_servo(Servo servo_no, int dest_angle, int last_angle)
{
  if (last_angle==dest_angle){
    return 0;
  }
  else{
    int temp_angle = last_angle;
    signed int diff = dest_angle - last_angle;
    if (diff >0){
      while(temp_angle < dest_angle - servo_step){
        temp_angle += servo_step;
        servo_no.write(temp_angle);
        delay(100);
      }
    } else{
      while(temp_angle > dest_angle + servo_step){
        temp_angle -= servo_step;
        servo_no.write(temp_angle);
        delay(100);
      }
    }
    servo_no.write(dest_angle);
    return 1;
  }
}
