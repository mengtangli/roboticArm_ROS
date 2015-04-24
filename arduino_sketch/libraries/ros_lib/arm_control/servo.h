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
      int16_t forth;
      int16_t fifth;

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
      union {
        int16_t real;
        uint16_t base;
      } u_forth;
      u_forth.real = this->forth;
      *(outbuffer + offset + 0) = (u_forth.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_forth.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->forth);
      union {
        int16_t real;
        uint16_t base;
      } u_fifth;
      u_fifth.real = this->fifth;
      *(outbuffer + offset + 0) = (u_fifth.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fifth.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->fifth);
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
      union {
        int16_t real;
        uint16_t base;
      } u_forth;
      u_forth.base = 0;
      u_forth.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_forth.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->forth = u_forth.real;
      offset += sizeof(this->forth);
      union {
        int16_t real;
        uint16_t base;
      } u_fifth;
      u_fifth.base = 0;
      u_fifth.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fifth.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->fifth = u_fifth.real;
      offset += sizeof(this->fifth);

     return offset;
    }

    const char * getType(){ return "arm_control/servo"; };
    const char * getMD5(){ return "418e6ef17161af8b9a9f73f67b2c84e6"; };

  };

}
#endif
