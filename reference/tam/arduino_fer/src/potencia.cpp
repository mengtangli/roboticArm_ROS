#include <ros.h> 
#include <std_msgs/Int16.h> 
 
ros::NodeHandle nh; 
int pot; 
 
void potencia( const std_msgs::Int16& cifra){ 
 
::pot = cifra.data*cifra.data; 
} 
 
ros::Subscriber<std_msgs::Int16> sub("cifra", &potencia ); 
std_msgs::Int16 res; 
 
ros::Publisher pub("resultado", &res); 
 
void setup() 
{ 
  nh.initNode(); 
  nh.subscribe(sub);  
  nh.advertise(pub); 
} 
 
void loop() 
{ 
  res.data = ::pot; 
  pub.publish( &res ); 
  nh.spinOnce(); 
  delay(1000); 
}
