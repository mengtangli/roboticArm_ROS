  #include "ros/ros.h"
  #include "brazo_fer/Servos.h"
  #include "brazo_fer/WriteServos.h"  
  #include "brazo_fer/ReadServos.h"
  #include "geometry_msgs/Point.h"
  #include "math.h"
 
  #define PI 3.14159265
  #define L1 104
  #define L2 104
  #define Lp 60
 
 
  brazo_fer::Servos move, vel, p, e, c;
 
  void posicion(const brazo_fer::ReadServos& pose)
  {
 
    ::p = pose.posicion;
    ::e = pose.estado;
    ::c = pose.corriente;
 
  }
 
  void punto(const geometry_msgs::Point& point)
  {    
        ros::NodeHandle n;
 
        ros::Publisher move_pub_=n.advertise<brazo_fer::WriteServos>("move_arm", 1);  
 
        double x = point.x;
        double y = point.y;
        double z = point.z;
       
        y = y + z*tan(atan2(45,250));
 
        int coordenadas_correctas = 1;
 
        double alfa, beta, beta_a, beta_p, beta_pp, gamma, delta, delta_a, delta_p, epsilon;
        double z_p;
        double L_a, L;
 
        epsilon = 0;
 
        alfa = (atan2(x,z)*180)/PI;
 
        z_p = sqrt(pow(z,2)+pow(x,2));
 
        L = sqrt(pow(z_p,2)+pow(y,2));
 
        L_a = sqrt(pow(y+(Lp*sin(epsilon)),2)+pow(z_p-(Lp*cos(epsilon)),2));
 
        beta_p = atan2(y+(Lp*sin(epsilon)),z_p-(Lp*cos(epsilon)));
       
        beta_pp = atan2(y,z_p);
 
        beta_a = acos((pow(L1,2)+pow(L_a,2)-pow(L2,2))/(2*L1*L_a));
 
        beta = ((beta_p+beta_a)*180)/PI;
 
        gamma = acos((pow(L1,2)+pow(L2,2)-pow(L_a,2))/(2*L1*L2));
 
        delta_a = PI-(beta_a+gamma);
 
        gamma = (gamma*180)/PI;
 
        delta_p = acos((pow(L_a,2)+pow(Lp,2)-pow(L,2))/(2*L_a*Lp));      
 
        if (beta_pp > beta_p) {
                delta = ((2*PI-(delta_p-delta_a))*180)/PI;
        }
        else {
                delta = ((delta_p+delta_a)*180)/PI;
 
                if (isnan(delta)) {
                        delta = ((PI+delta_a)*180)/PI;
                }
        }
 
        if (isnan(gamma)) // si no hay solución
        {
                coordenadas_correctas = 0;
        }
 
        ::move.base = ((alfa+150)*1023)/300;
        ::move.arti1 = ((beta+60)*1023)/300;
        ::move.arti2 = ((gamma-30)*1023)/300;
        ::move.arti3 = ((delta-30)*1023)/300;
        ::move.pinza = 511;

        ::vel.base = abs(::move.base - ::p.base)/5;
        ::vel.arti1 = abs(::move.arti1 - ::p.arti1)/5;
        ::vel.arti2 = abs(::move.arti2 - ::p.arti2)/5;
        ::vel.arti3 = abs(::move.arti3 - ::p.arti3)/5;
        ::vel.pinza = abs(::move.pinza - ::p.pinza);
 
        if (coordenadas_correctas == 1 && (205 <= ::move.base && ::move.base <= 818) && (120 <= ::move.arti1 && ::move.arti1 <= 920) && ::move.arti2 >= 50  && ::move.arti3 <= 828) {
 
                brazo_fer::WriteServos mover;
 
                mover.posicion = ::move;                
                 
                mover.velocidad = ::vel;
                               
                mover.par.base = 1;
                mover.par.arti1 = 1;
                mover.par.arti2 = 1;
                mover.par.arti3 = 1;
                mover.par.pinza = 1;
               
                move_pub_.publish(mover);
        }
        else {
                std::cout<<"Error, invalid coordinates or unattainable point"<<std::endl;                              
        }
 
  }
 
 
  int main(int argc, char **argv)
  {
 
        ros::init(argc, argv, "control_brazo");  
 
        ros::NodeHandle n;
 
 
        ros::Subscriber pose_sub_= n.subscribe("pose_arm", 1, posicion);
 
        ros::Subscriber point_sub_= n.subscribe("point", 1, punto);
 
        ros::Publisher move_pub_=n.advertise<brazo_fer::WriteServos>("move_arm", 1);  
 
 
        ros::spin();  
 
        return 0;
  }
