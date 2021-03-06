#ifndef _ROS_pr2_mechanism_controllers_DebugInfo_h
#define _ROS_pr2_mechanism_controllers_DebugInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pr2_mechanism_controllers
{

  class DebugInfo : public ros::Msg
  {
    public:
      uint8_t timing_length;
      float st_timing;
      float * timing;
      int32_t sequence;
      bool input_valid;
      float residual;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = timing_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < timing_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->timing[i]);
      }
      union {
        int32_t real;
        uint32_t base;
      } u_sequence;
      u_sequence.real = this->sequence;
      *(outbuffer + offset + 0) = (u_sequence.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sequence.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sequence.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sequence.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sequence);
      union {
        bool real;
        uint8_t base;
      } u_input_valid;
      u_input_valid.real = this->input_valid;
      *(outbuffer + offset + 0) = (u_input_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->input_valid);
      offset += serializeAvrFloat64(outbuffer + offset, this->residual);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t timing_lengthT = *(inbuffer + offset++);
      if(timing_lengthT > timing_length)
        this->timing = (float*)realloc(this->timing, timing_lengthT * sizeof(float));
      offset += 3;
      timing_length = timing_lengthT;
      for( uint8_t i = 0; i < timing_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_timing));
        memcpy( &(this->timing[i]), &(this->st_timing), sizeof(float));
      }
      union {
        int32_t real;
        uint32_t base;
      } u_sequence;
      u_sequence.base = 0;
      u_sequence.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sequence.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sequence.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sequence.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->sequence = u_sequence.real;
      offset += sizeof(this->sequence);
      union {
        bool real;
        uint8_t base;
      } u_input_valid;
      u_input_valid.base = 0;
      u_input_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->input_valid = u_input_valid.real;
      offset += sizeof(this->input_valid);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->residual));
     return offset;
    }

    const char * getType(){ return "pr2_mechanism_controllers/DebugInfo"; };
    const char * getMD5(){ return "6281356ce897e33da024b8eb319460f2"; };

  };

}
#endif