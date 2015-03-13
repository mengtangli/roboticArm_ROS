#ifndef brazo_fer_H
#define brazo_fer_H

  #include "ros/ros.h"
  #include "brazo_fer/Servos.h"
  #include "brazo_fer/WriteServos.h"  
  #include "brazo_fer/ReadServos.h"  
  #include "std_msgs/Int16.h"
  #include "geometry_msgs/Point.h"
  #include "math.h"
 
  #define PI 3.14159265
  #define L1 104
  #define L2 104
  #define Lp 60  

geometry_msgs::Point directa(brazo_fer::Servos posicion_servos_0, int inclinacion_pinza)
  {
       
        double alfa, beta, beta_a, beta_p, beta_pp, gamma, delta, delta_a, delta_p1, delta_p2, epsilon;
        double z_p;
        double L_a, L;
        double a, b;
        double x, y, z;
       
        alfa = (((posicion_servos_0.base*300)/1023)-150)*PI/180;
        beta = (((posicion_servos_0.arti1*300)/1023)-60)*PI/180;
        gamma = (((posicion_servos_0.arti2*300)/1023)+30)*PI/180;
        delta = (((posicion_servos_0.arti3*300)/1023)+30)*PI/180;
       
        epsilon = (inclinacion_pinza*PI)/180;  
       
        L_a = sqrt(pow(L1,2)+pow(L2,2)-2*L1*L2*cos(gamma));
       
        beta_a = acos((pow(L1,2)+pow(L_a,2)-pow(L2,2))/(2*L1*L_a));
       
        beta_p = beta - beta_a;
       
        delta_a = PI - (beta_a + gamma);
       
        delta_p1 = delta - delta_a;
       
        delta_p2 = 2*PI - (delta - delta_a);
       
        if (delta_p1 < delta_p2)
        {
                L = sqrt(pow(L_a,2)+pow(Lp,2)-2*L_a*Lp*cos(delta_p1));
        }
        else
        {
                L = sqrt(pow(L_a,2)+pow(Lp,2)-2*L_a*Lp*cos(delta_p2));
        }
       
        z_p = L_a*cos(beta_p) + Lp*cos(epsilon);
       
        beta_pp = acos(z_p/L);
       
        a = L1*sin(beta);
       
        b = L2*sin(beta+gamma)+Lp*sin(epsilon);
       
        if (a >= b)
        {
                y = L*sin(beta_pp);
        }
        else
        {
                y = -L*sin(beta_pp);
        }      
       
        z = z_p*cos(alfa);
       
        x = z_p*sin(alfa);
       
        geometry_msgs::Point punto;
       
        punto.x = x;
        punto.y = y;
        punto.z = z;
       
        return punto;
  }
 
brazo_fer::WriteServos inversa(geometry_msgs::Point destino, int inclinacion_pinza, brazo_fer::Servos posicion_servos_0, int velocidad)
  {
         
        double x = destino.x;
        double y = destino.y;
        double z = destino.z;

        int coordenadas_correctas = 1;

        double alfa, beta, beta_a, beta_p, beta_pp, gamma, delta, delta_a, delta_p, epsilon;
        double z_p;
        double L_a, L;
 
        epsilon = (inclinacion_pinza*PI)/180;
 
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
 
 
        if (isnan(gamma))
        {
                coordenadas_correctas = 0;
        }

        brazo_fer::Servos posicion_servos_1;
        brazo_fer::Servos velocidad_servos;
        brazo_fer::Servos par_servos;  
       
        posicion_servos_1.base = ((alfa+150)*1023)/300;
        posicion_servos_1.arti1 = ((beta+60)*1023)/300;
        posicion_servos_1.arti2 = ((gamma-30)*1023)/300;
        posicion_servos_1.arti3 = ((delta-30)*1023)/300;       
       
        if (velocidad == 0)
        {
                velocidad_servos.base = abs(posicion_servos_1.base - posicion_servos_0.base)/5;
                if (velocidad_servos.base > 1023){velocidad_servos.base = 1023;}
                else if (velocidad_servos.base < 10){velocidad_servos.base = 10;}
                velocidad_servos.arti1 = abs(posicion_servos_1.arti1 - posicion_servos_0.arti1)/5;
                if (velocidad_servos.arti1 > 1023){velocidad_servos.arti1 = 1023;}
                else if (velocidad_servos.arti1 < 10){velocidad_servos.arti1 = 10;}
                velocidad_servos.arti2 = abs(posicion_servos_1.arti2 - posicion_servos_0.arti2)/5;
                if (velocidad_servos.arti2 > 1023){velocidad_servos.arti2 = 1023;}
                else if (velocidad_servos.arti2 < 10){velocidad_servos.arti2 = 10;}
                velocidad_servos.arti3 = abs(posicion_servos_1.arti3 - posicion_servos_0.arti3)/5;
                if (velocidad_servos.arti3 > 1023){velocidad_servos.arti3 = 1023;}
                else if (velocidad_servos.arti3 < 10){velocidad_servos.arti3 = 10;}
               
        }
        else
        {
                velocidad_servos.base = abs(posicion_servos_1.base - posicion_servos_0.base)*(velocidad/10);
                if (velocidad_servos.base > 1023){velocidad_servos.base = 1023;}
                else if (velocidad_servos.base < 10){velocidad_servos.base = 10;}
                velocidad_servos.arti1 = abs(posicion_servos_1.arti1 - posicion_servos_0.arti1)*(velocidad/10);
                if (velocidad_servos.arti1 > 1023){velocidad_servos.arti1 = 1023;}
                else if (velocidad_servos.arti1 < 10){velocidad_servos.arti1 = 10;}
                velocidad_servos.arti2 = abs(posicion_servos_1.arti2 - posicion_servos_0.arti2)*(velocidad/10);
                if (velocidad_servos.arti2 > 1023){velocidad_servos.arti2 = 1023;}
                else if (velocidad_servos.arti2 < 10){velocidad_servos.arti2 = 10;}
                velocidad_servos.arti3 = abs(posicion_servos_1.arti3 - posicion_servos_0.arti3)*(velocidad/10);
                if (velocidad_servos.arti3 > 1023){velocidad_servos.arti3 = 1023;}
                else if (velocidad_servos.arti3 < 10){velocidad_servos.arti3 = 10;}
               
        }
       
        brazo_fer::Servos velocidad_servos_0;
       
        velocidad_servos_0.base = 0;
        velocidad_servos_0.arti1 = 0;
        velocidad_servos_0.arti2 = 0;
        velocidad_servos_0.arti3 = 0;
               
        par_servos.base = 1;
        par_servos.arti1 = 1;
        par_servos.arti2 = 1;
        par_servos.arti3 = 1;
       
        brazo_fer::WriteServos move_arm;                       
       
        if (coordenadas_correctas == 1 && (205 <= posicion_servos_1.base && posicion_servos_1.base <= 818) && (120 <= posicion_servos_1.arti1 && posicion_servos_1.arti1 <= 920) && posicion_servos_1.arti2 >= 50  && (posicion_servos_1.arti3 <= 828 && posicion_servos_1.arti3 >= 195)) {
                move_arm.posicion = posicion_servos_1;
                move_arm.velocidad = velocidad_servos;
                move_arm.par = par_servos;
                return move_arm;
        }
        else {
                std::cout<<"error coordenadas no validas o punto fuera del alcance"<<std::endl;
                move_arm.posicion = posicion_servos_0;
                move_arm.velocidad = velocidad_servos_0;
                move_arm.par = par_servos;
                return move_arm;                               
        }        
  }
 
brazo_fer::WriteServos  control_pinza(brazo_fer::Servos posicion_servos_1, brazo_fer::Servos posicion_servos_0, brazo_fer::Servos corriente_servos)
  {
       
        brazo_fer::Servos velocidad_servos;      
        brazo_fer::Servos par_servos;
       
        velocidad_servos.pinza = 50;
           
        par_servos.pinza = 1;
       
        brazo_fer::WriteServos hand_arm;               
       
        if ((posicion_servos_1.pinza >= 480 && posicion_servos_1.pinza <= 680 && corriente_servos.pinza <= 300) || (posicion_servos_0.pinza > posicion_servos_1.pinza && posicion_servos_1.pinza >= 480))
        {
                hand_arm.posicion = posicion_servos_1;
                hand_arm.velocidad = velocidad_servos;
                hand_arm.par = par_servos;
                return hand_arm;
        }
        else
        {
                std::cout<<"Alcanzado límite de la pinza"<<std::endl;         
                hand_arm.posicion = posicion_servos_0;
                hand_arm.velocidad = velocidad_servos;
                hand_arm.par = par_servos;
                return hand_arm;
        }
  }  
 
geometry_msgs::Point home(brazo_fer::Servos posicion_servos_0, brazo_fer::Servos corriente_servos)
  {
         
        ros::NodeHandle n;
 
        ros::Publisher move_pub_=n.advertise<brazo_fer::WriteServos>("move_arm", 1);  
       
        ros::Publisher hand_pub_=n.advertise<brazo_fer::WriteServos>("hand_arm", 1);  
               
                geometry_msgs::Point punto_0;
               
                punto_0.x = 0;
                punto_0.y = 80;
                punto_0.z = 50;
               
                int inclinacion_pinza = 0;             
                               
                brazo_fer::WriteServos inicio_brazo = inversa(punto_0, inclinacion_pinza, posicion_servos_0, 0);
       
                brazo_fer::Servos posicion_servos_1;
               
                posicion_servos_1.pinza = 511;
       
                brazo_fer::WriteServos inicio_pinza = control_pinza(posicion_servos_1, posicion_servos_0, corriente_servos);
                       
                move_pub_.publish(inicio_brazo);
               
                hand_pub_.publish(inicio_pinza);
               
                               
                return punto_0;

  }
   
#endif
