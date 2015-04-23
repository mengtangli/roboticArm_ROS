#ifndef _ROS_brazo_fer_WriteServos_h
#define _ROS_brazo_fer_WriteServos_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "brazo_fer/Servos.h"

namespace brazo_fer
{

  class WriteServos : public ros::Msg
  {
    public:
      brazo_fer::Servos posicion;
      brazo_fer::Servos velocidad;
      brazo_fer::Servos par;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->posicion.serialize(outbuffer + offset);
      offset += this->velocidad.serialize(outbuffer + offset);
      offset += this->par.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->posicion.deserialize(inbuffer + offset);
      offset += this->velocidad.deserialize(inbuffer + offset);
      offset += this->par.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "brazo_fer/WriteServos"; };
    const char * getMD5(){ return "9551946156ffa6c4d13c8c60abd574c1"; };

  };

}
#endif