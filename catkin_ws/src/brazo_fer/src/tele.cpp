  #include "ros/ros.h"
  #include "brazo_fer/Servos.h"
  #include "brazo_fer/WriteServos.h"  
  #include "brazo_fer/ReadServos.h"
  #include "brazo_fer/brazo_fer.h"  
  #include "geometry_msgs/Point.h"
  #include "std_msgs/Int16.h"
  #include "std_msgs/String.h"  
  #include <signal.h>
  #include <termios.h>
  #include <stdio.h>
  #include <ros_tut/servo.h>
 
  #define KEYCODE_Xmas 0x43
  #define KEYCODE_Xmenos 0x44
  #define KEYCODE_Ymas 0x41
  #define KEYCODE_Ymenos 0x42
  #define KEYCODE_Zmas 0x77
  #define KEYCODE_Zmenos 0x73
  #define KEYCODE_Pabrir 0x61
  #define KEYCODE_Pcerrar 0x64
  #define KEYCODE_PinclinarMas 0x65
  #define KEYCODE_PinclinarMenos 0x71  

 int getch()
	{
	  static struct termios oldt, newt;
	  tcgetattr( STDIN_FILENO, &oldt);           // save old settings
	  newt = oldt;
	  newt.c_lflag &= ~(ICANON);                 // disable buffering      
	  tcsetattr( STDIN_FILENO, TCSANOW, &newt);  // apply new settings

	  int c = getchar();  // read character (non-blocking)

	  tcsetattr( STDIN_FILENO, TCSANOW, &oldt);  // restore old settings
	  return c;
	}

  int main(int argc, char **argv)
  {
 
        ros::init(argc, argv, "tele");  
 
        ros::NodeHandle tele_node;
       
        ros::Publisher tele =tele_node.advertise<ros_tut::servo>("tele", 1000);  

	ros::Rate loop_rate(100);
	ros_tut::servo msg;
	
	char c;


	
/*
	  // get the console in raw mode                                                              
	  tcgetattr(0, &cooked);
	  memcpy(&raw, &cooked, sizeof(struct termios));
	  raw.c_lflag &=~ (ICANON | ECHO);
	  // Setting a new line, then end of file                        
	  raw.c_cc[VEOL] = 1;
	  raw.c_cc[VEOF] = 2;
	  tcsetattr(0, TCSANOW, &raw);
*/
	  puts("");
	  puts("#####################################################");
	  puts("                      ARM CONTROLS");
	  puts("#####################################################");
	  puts("");  
	  puts("Up arrow:___________ Move up gripper");
	  puts("Down arrow:_________ Move down gripper");
	  puts("Left arrow:_________ Move left gripper");
	  puts("Right arrow:________ Move right gripper");
	  puts("W key:______________ Move forward gripper");
	  puts("S key:______________ Move backward gripper");
	  puts("A key:______________ Open gripper");
	  puts("D key:______________ Close gripper");
	  puts("Q key:______________ Tilt up gripper");
	  puts("E key:______________ Tilt down gripper");                
             

       
    while (ros::ok())
    {
                               
      int c = getch(); 
      if (c == KEYCODE_Xmas)
      {
          msg.first += 20;
          ROS_INFO("Xmas key: first %d second %d third %d",msg.first,msg.second,msg.third);  
      }
      if (c == KEYCODE_Xmenos)
      {
          msg.first -= 20;
          ROS_INFO("Xmenos key: first %d second %d third %d",msg.first,msg.second,msg.third);  
      }
      if (c == KEYCODE_Ymas)
      {
          msg.second += 20;
          ROS_INFO("Ymas key: first %d second %d third %d",msg.first,msg.second,msg.third);  
                                            
      }
      if (c == KEYCODE_Ymenos)
      {
          msg.second -= 20;
          ROS_INFO("Ymenos key: first %d second %d third %d",msg.first,msg.second,msg.third);  
                                             
      }
      if (c == KEYCODE_Zmas)
      {
          msg.third += 20;
          ROS_INFO("Zmas key: first %d second %d third %d",msg.first,msg.second,msg.third);  
                                     
      }
      if (c == KEYCODE_Zmenos)
      {
          msg.third -= 20;
          ROS_INFO("Zmenos key: first %d second %d third %d",msg.first,msg.second,msg.third);  
                            
      }
      if (c == KEYCODE_Pabrir)
      {
          
      }
      if (c == KEYCODE_Pcerrar)
      {

      }
      if (c == KEYCODE_PinclinarMas)
      {
         
      }
      if (c == KEYCODE_PinclinarMenos)
      {
        
      }                                    
 
    tele.publish(msg);
    ros::spinOnce();  
    loop_rate.sleep();
    }

    return 0;
}
