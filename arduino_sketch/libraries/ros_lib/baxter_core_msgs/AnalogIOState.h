#ifndef _ROS_baxter_core_msgs_AnalogIOState_h
#define _ROS_baxter_core_msgs_AnalogIOState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"

namespace baxter_core_msgs
{

  class AnalogIOState : public ros::Msg
  {
    public:
      ros::Time timestamp;
      float value;
      bool isInputOnly;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->timestamp.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timestamp.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->timestamp.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->timestamp.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timestamp.sec);
      *(outbuffer + offset + 0) = (this->timestamp.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timestamp.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->timestamp.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->timestamp.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timestamp.nsec);
      offset += serializeAvrFloat64(outbuffer + offset, this->value);
      union {
        bool real;
        uint8_t base;
      } u_isInputOnly;
      u_isInputOnly.real = this->isInputOnly;
      *(outbuffer + offset + 0) = (u_isInputOnly.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->isInputOnly);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->timestamp.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->timestamp.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->timestamp.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->timestamp.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->timestamp.sec);
      this->timestamp.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->timestamp.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->timestamp.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->timestamp.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->timestamp.nsec);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->value));
      union {
        bool real;
        uint8_t base;
      } u_isInputOnly;
      u_isInputOnly.base = 0;
      u_isInputOnly.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->isInputOnly = u_isInputOnly.real;
      offset += sizeof(this->isInputOnly);
     return offset;
    }

    const char * getType(){ return "baxter_core_msgs/AnalogIOState"; };
    const char * getMD5(){ return "39af371963dc9e4447e91f430c720b33"; };

  };

}
#endif