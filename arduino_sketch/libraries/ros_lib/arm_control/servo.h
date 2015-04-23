#ifndef _ROS_arm_control_servo_h
#define _ROS_arm_control_servo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace arm_control
{

  class servo : public ros::Msg
  {
    public:
      int16_t first;
      int16_t second;
      int16_t third;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_first;
      u_first.real = this->first;
      *(outbuffer + offset + 0) = (u_first.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_first.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->first);
      union {
        int16_t real;
        uint16_t base;
      } u_second;
      u_second.real = this->second;
      *(outbuffer + offset + 0) = (u_second.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_second.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->second);
      union {
        int16_t real;
        uint16_t base;
      } u_third;
      u_third.real = this->third;
      *(outbuffer + offset + 0) = (u_third.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_third.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->third);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_first;
      u_first.base = 0;
      u_first.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_first.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->first = u_first.real;
      offset += sizeof(this->first);
      union {
        int16_t real;
        uint16_t base;
      } u_second;
      u_second.base = 0;
      u_second.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_second.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->second = u_second.real;
      offset += sizeof(this->second);
      union {
        int16_t real;
        uint16_t base;
      } u_third;
      u_third.base = 0;
      u_third.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_third.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->third = u_third.real;
      offset += sizeof(this->third);
     return offset;
    }

    const char * getType(){ return "arm_control/servo"; };
    const char * getMD5(){ return "a857454193b3801feabc5fd6d0dba368"; };

  };

}
#endif
