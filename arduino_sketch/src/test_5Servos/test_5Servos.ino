/**
  *  Test RDS3115 servos
  *  Use the "scale" variable to overrun
  *  the difference between RDS3115 and normal servos
  **/

#include <stdio.h>
#include <Servo.h> 
 
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

const float scale = 133;
float pos = 0;    // variable to store the servo position 
int real_angle;

void setup() 
{ 
  Serial.begin(9600);
  servo1.attach(2);  // attaches the servo on pin 9 to the servo object 
  servo2.attach(3);
  servo3.attach(4);
  servo4.attach(5);
  servo5.attach(6);
} 
 
 
void loop() 
{ 
    real_angle = pos/180*scale;
    
    Serial.println(real_angle);
    servo1.write(real_angle);             
    delay(15);
    servo2.write(real_angle);             
    delay(15);
    servo3.write(real_angle);             
    delay(15);
    servo4.write(real_angle);             
    delay(15);
    servo5.write(real_angle);             
    delay(15);
  /*for(pos = 0; pos < 180; pos += 2)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    servo1.write(pos);             
    delay(15);
    servo2.write(pos);             
    delay(15);
    servo3.write(pos);             
    delay(15);
    servo4.write(pos);             
    delay(15);
    servo5.write(pos);             
    delay(15);    
  } 
  for(pos = 180; pos>=1; pos-=2)     // goes from 180 degrees to 0 degrees 
  {                                
    servo1.write(pos);             
    delay(15);
    servo2.write(pos);             
    delay(15);
    servo3.write(pos);             
    delay(15);
    servo4.write(pos);             
    delay(15);
    servo5.write(pos);             
    delay(15); 
  } */
} 

void setPwmFrequency(int pin, int divisor) {
  byte mode;
  if(pin == 5 || pin == 6 || pin == 9 || pin == 10) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 64: mode = 0x03; break;
      case 256: mode = 0x04; break;
      case 1024: mode = 0x05; break;
      default: return;
    }
    if(pin == 5 || pin == 6) {
      TCCR0B = TCCR0B & 0b11111000 | mode;
    } else {
      TCCR1B = TCCR1B & 0b11111000 | mode;
    }
  } else if(pin == 3 || pin == 11) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 32: mode = 0x03; break;
      case 64: mode = 0x04; break;
      case 128: mode = 0x05; break;
      case 256: mode = 0x06; break;
      case 1024: mode = 0x7; break;
      default: return;
    }
    TCCR2B = TCCR2B & 0b11111000 | mode;
  }
}

