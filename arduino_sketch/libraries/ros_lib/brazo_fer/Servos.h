#ifndef _ROS_brazo_fer_Servos_h
#define _ROS_brazo_fer_Servos_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace brazo_fer
{

  class Servos : public ros::Msg
  {
    public:
      int16_t base;
      int16_t arti1;
      int16_t arti2;
      int16_t arti3;
      int16_t pinza;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_base;
      u_base.real = this->base;
      *(outbuffer + offset + 0) = (u_base.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_base.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->base);
      union {
        int16_t real;
        uint16_t base;
      } u_arti1;
      u_arti1.real = this->arti1;
      *(outbuffer + offset + 0) = (u_arti1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_arti1.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->arti1);
      union {
        int16_t real;
        uint16_t base;
      } u_arti2;
      u_arti2.real = this->arti2;
      *(outbuffer + offset + 0) = (u_arti2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_arti2.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->arti2);
      union {
        int16_t real;
        uint16_t base;
      } u_arti3;
      u_arti3.real = this->arti3;
      *(outbuffer + offset + 0) = (u_arti3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_arti3.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->arti3);
      union {
        int16_t real;
        uint16_t base;
      } u_pinza;
      u_pinza.real = this->pinza;
      *(outbuffer + offset + 0) = (u_pinza.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pinza.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pinza);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_base;
      u_base.base = 0;
      u_base.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_base.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->base = u_base.real;
      offset += sizeof(this->base);
      union {
        int16_t real;
        uint16_t base;
      } u_arti1;
      u_arti1.base = 0;
      u_arti1.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_arti1.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->arti1 = u_arti1.real;
      offset += sizeof(this->arti1);
      union {
        int16_t real;
        uint16_t base;
      } u_arti2;
      u_arti2.base = 0;
      u_arti2.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_arti2.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->arti2 = u_arti2.real;
      offset += sizeof(this->arti2);
      union {
        int16_t real;
        uint16_t base;
      } u_arti3;
      u_arti3.base = 0;
      u_arti3.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_arti3.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->arti3 = u_arti3.real;
      offset += sizeof(this->arti3);
      union {
        int16_t real;
        uint16_t base;
      } u_pinza;
      u_pinza.base = 0;
      u_pinza.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pinza.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->pinza = u_pinza.real;
      offset += sizeof(this->pinza);
     return offset;
    }

    const char * getType(){ return "brazo_fer/Servos"; };
    const char * getMD5(){ return "6be90daad19b44888c6ef8582506a939"; };

  };

}
#endif