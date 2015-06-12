#ifndef _ROS_brazo_fer_ReadServos_h
#define _ROS_brazo_fer_ReadServos_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "brazo_fer/Servos.h"

namespace brazo_fer
{

  class ReadServos : public ros::Msg
  {
    public:
      brazo_fer::Servos posicion;
      brazo_fer::Servos estado;
      brazo_fer::Servos corriente;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->posicion.serialize(outbuffer + offset);
      offset += this->estado.serialize(outbuffer + offset);
      offset += this->corriente.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->posicion.deserialize(inbuffer + offset);
      offset += this->estado.deserialize(inbuffer + offset);
      offset += this->corriente.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "brazo_fer/ReadServos"; };
    const char * getMD5(){ return "eb601df5ba86278a5ceaf5eea9e7da64"; };

  };

}
#endif