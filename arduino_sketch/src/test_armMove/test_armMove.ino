#include <Servos.h>
#include <WriteServos.h>
#include <ReadServos.h>

#include <ros.h>
#include <std_msgs/Bool.h>
#include <math.h>
 
#include <DynamixelSerial1.h>
 
ros::NodeHandle nh;
 
void mover(const WriteServos& brazo){
 
  Servos par = brazo.par;
 
  Servos vel = brazo.velocidad;
 
  Servos move = brazo.posicion;
 
  int posicion[4];
 
  if (par.base == 0){
    Dynamixel.torqueStatus(1,OFF);
  }
  else {
    Dynamixel.torqueStatus(1,ON);
 
    Dynamixel.moveSpeed(1,move.base,vel.base);  
  }
 
  if (par.arti1 == 0){
    Dynamixel.torqueStatus(2,OFF);
  }
  else {
    Dynamixel.torqueStatus(2,ON);
 
    Dynamixel.moveSpeed(2,move.arti1,vel.arti1);  
  }
 
  if (par.arti2 == 0){
    Dynamixel.torqueStatus(3,OFF);
  }
  else {
    Dynamixel.torqueStatus(3,ON);
 
    Dynamixel.moveSpeed(3,move.arti2,vel.arti2);  
  }
 
  if (par.arti3 == 0){
    Dynamixel.torqueStatus(4,OFF);
  }
  else {
    Dynamixel.torqueStatus(4,ON);    
 
    Dynamixel.moveSpeed(4,move.arti3,vel.arti3);  
  }
 
}
 
void pinza(const WriteServos& pinza){
 
  Servos par = pinza.par;
 
  Servos vel = pinza.velocidad;
 
  Servos move = pinza.posicion;
 
  int posicion;
 
  if (par.pinza == 0){
    Dynamixel.torqueStatus(5,OFF);
  }
  else {
    Dynamixel.torqueStatus(5,ON);    
 
    Dynamixel.moveSpeed(5,move.pinza,vel.pinza);  
  }
 
}
 
ros::Subscriber<WriteServos> move_sub("move_arm", &mover );
ros::Subscriber<WriteServos> hand_sub("hand_arm", &pinza );
 
ReadServos pec;
std_msgs::Bool pulsador;
 
ros::Publisher pose_pub("pose_arm", &pec);
 
 
void setup()
{
  nh.initNode();
  nh.subscribe(move_sub);
  nh.subscribe(hand_sub);  
  nh.advertise(pose_pub);
 
  Dynamixel.begin(1000000,2);
 
}
 
void loop()
{
  Servos pos;
  Servos est;
  Servos cor; 
 
  pos.base = Dynamixel.readPosition(1);
  pos.arti1 = Dynamixel.readPosition(2);
  pos.arti2 = Dynamixel.readPosition(3);
  pos.arti3 = Dynamixel.readPosition(4);
  pos.pinza = Dynamixel.readPosition(5);
 
  est.base = Dynamixel.moving(1);
  est.arti1 = Dynamixel.moving(2);
  est.arti2 = Dynamixel.moving(3);
  est.arti3 = Dynamixel.moving(4);
  est.pinza = Dynamixel.moving(5);      
 
  cor.base = Dynamixel.readLoad(1);
  cor.arti1 = Dynamixel.readLoad(2);
  cor.arti2 = Dynamixel.readLoad(3);
  cor.arti3 = Dynamixel.readLoad(4);
  cor.pinza = Dynamixel.readLoad(5);    
 
  pec.posicion = pos;
  pec.estado = est;
  pec.corriente = cor;  
 
  pose_pub.publish( &pec );
 
  nh.spinOnce();
 
}
