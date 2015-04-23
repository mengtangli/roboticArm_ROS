#ifndef _ROS_baxter_core_msgs_HeadState_h
#define _ROS_baxter_core_msgs_HeadState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace baxter_core_msgs
{

  class HeadState : public ros::Msg
  {
    public:
      float pan;
      bool isPanning;
      bool isNodding;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_pan;
      u_pan.real = this->pan;
      *(outbuffer + offset + 0) = (u_pan.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pan.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pan.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pan.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pan);
      union {
        bool real;
        uint8_t base;
      } u_isPanning;
      u_isPanning.real = this->isPanning;
      *(outbuffer + offset + 0) = (u_isPanning.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->isPanning);
      union {
        bool real;
        uint8_t base;
      } u_isNodding;
      u_isNodding.real = this->isNodding;
      *(outbuffer + offset + 0) = (u_isNodding.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->isNodding);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_pan;
      u_pan.base = 0;
      u_pan.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pan.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pan.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pan.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pan = u_pan.real;
      offset += sizeof(this->pan);
      union {
        bool real;
        uint8_t base;
      } u_isPanning;
      u_isPanning.base = 0;
      u_isPanning.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->isPanning = u_isPanning.real;
      offset += sizeof(this->isPanning);
      union {
        bool real;
        uint8_t base;
      } u_isNodding;
      u_isNodding.base = 0;
      u_isNodding.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->isNodding = u_isNodding.real;
      offset += sizeof(this->isNodding);
     return offset;
    }

    const char * getType(){ return "baxter_core_msgs/HeadState"; };
    const char * getMD5(){ return "a7a905cb9138493d35f02b3c35b9d65b"; };

  };

}
#endif