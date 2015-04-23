#ifndef _ROS_baxter_core_msgs_SEAJointState_h
#define _ROS_baxter_core_msgs_SEAJointState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace baxter_core_msgs
{

  class SEAJointState : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t name_length;
      char* st_name;
      char* * name;
      uint8_t commanded_position_length;
      float st_commanded_position;
      float * commanded_position;
      uint8_t commanded_velocity_length;
      float st_commanded_velocity;
      float * commanded_velocity;
      uint8_t commanded_acceleration_length;
      float st_commanded_acceleration;
      float * commanded_acceleration;
      uint8_t commanded_effort_length;
      float st_commanded_effort;
      float * commanded_effort;
      uint8_t actual_position_length;
      float st_actual_position;
      float * actual_position;
      uint8_t actual_velocity_length;
      float st_actual_velocity;
      float * actual_velocity;
      uint8_t actual_effort_length;
      float st_actual_effort;
      float * actual_effort;
      uint8_t gravity_model_effort_length;
      float st_gravity_model_effort;
      float * gravity_model_effort;
      uint8_t gravity_only_length;
      float st_gravity_only;
      float * gravity_only;
      uint8_t hysteresis_model_effort_length;
      float st_hysteresis_model_effort;
      float * hysteresis_model_effort;
      uint8_t crosstalk_model_effort_length;
      float st_crosstalk_model_effort;
      float * crosstalk_model_effort;
      float hystState;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = name_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < name_length; i++){
      uint32_t length_namei = strlen(this->name[i]);
      memcpy(outbuffer + offset, &length_namei, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name[i], length_namei);
      offset += length_namei;
      }
      *(outbuffer + offset++) = commanded_position_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < commanded_position_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->commanded_position[i]);
      }
      *(outbuffer + offset++) = commanded_velocity_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < commanded_velocity_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->commanded_velocity[i]);
      }
      *(outbuffer + offset++) = commanded_acceleration_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < commanded_acceleration_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->commanded_acceleration[i]);
      }
      *(outbuffer + offset++) = commanded_effort_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < commanded_effort_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->commanded_effort[i]);
      }
      *(outbuffer + offset++) = actual_position_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < actual_position_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->actual_position[i]);
      }
      *(outbuffer + offset++) = actual_velocity_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < actual_velocity_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->actual_velocity[i]);
      }
      *(outbuffer + offset++) = actual_effort_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < actual_effort_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->actual_effort[i]);
      }
      *(outbuffer + offset++) = gravity_model_effort_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < gravity_model_effort_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->gravity_model_effort[i]);
      }
      *(outbuffer + offset++) = gravity_only_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < gravity_only_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->gravity_only[i]);
      }
      *(outbuffer + offset++) = hysteresis_model_effort_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < hysteresis_model_effort_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->hysteresis_model_effort[i]);
      }
      *(outbuffer + offset++) = crosstalk_model_effort_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < crosstalk_model_effort_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->crosstalk_model_effort[i]);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->hystState);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t name_lengthT = *(inbuffer + offset++);
      if(name_lengthT > name_length)
        this->name = (char**)realloc(this->name, name_lengthT * sizeof(char*));
      offset += 3;
      name_length = name_lengthT;
      for( uint8_t i = 0; i < name_length; i++){
      uint32_t length_st_name;
      memcpy(&length_st_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_name-1]=0;
      this->st_name = (char *)(inbuffer + offset-1);
      offset += length_st_name;
        memcpy( &(this->name[i]), &(this->st_name), sizeof(char*));
      }
      uint8_t commanded_position_lengthT = *(inbuffer + offset++);
      if(commanded_position_lengthT > commanded_position_length)
        this->commanded_position = (float*)realloc(this->commanded_position, commanded_position_lengthT * sizeof(float));
      offset += 3;
      commanded_position_length = commanded_position_lengthT;
      for( uint8_t i = 0; i < commanded_position_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_commanded_position));
        memcpy( &(this->commanded_position[i]), &(this->st_commanded_position), sizeof(float));
      }
      uint8_t commanded_velocity_lengthT = *(inbuffer + offset++);
      if(commanded_velocity_lengthT > commanded_velocity_length)
        this->commanded_velocity = (float*)realloc(this->commanded_velocity, commanded_velocity_lengthT * sizeof(float));
      offset += 3;
      commanded_velocity_length = commanded_velocity_lengthT;
      for( uint8_t i = 0; i < commanded_velocity_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_commanded_velocity));
        memcpy( &(this->commanded_velocity[i]), &(this->st_commanded_velocity), sizeof(float));
      }
      uint8_t commanded_acceleration_lengthT = *(inbuffer + offset++);
      if(commanded_acceleration_lengthT > commanded_acceleration_length)
        this->commanded_acceleration = (float*)realloc(this->commanded_acceleration, commanded_acceleration_lengthT * sizeof(float));
      offset += 3;
      commanded_acceleration_length = commanded_acceleration_lengthT;
      for( uint8_t i = 0; i < commanded_acceleration_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_commanded_acceleration));
        memcpy( &(this->commanded_acceleration[i]), &(this->st_commanded_acceleration), sizeof(float));
      }
      uint8_t commanded_effort_lengthT = *(inbuffer + offset++);
      if(commanded_effort_lengthT > commanded_effort_length)
        this->commanded_effort = (float*)realloc(this->commanded_effort, commanded_effort_lengthT * sizeof(float));
      offset += 3;
      commanded_effort_length = commanded_effort_lengthT;
      for( uint8_t i = 0; i < commanded_effort_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_commanded_effort));
        memcpy( &(this->commanded_effort[i]), &(this->st_commanded_effort), sizeof(float));
      }
      uint8_t actual_position_lengthT = *(inbuffer + offset++);
      if(actual_position_lengthT > actual_position_length)
        this->actual_position = (float*)realloc(this->actual_position, actual_position_lengthT * sizeof(float));
      offset += 3;
      actual_position_length = actual_position_lengthT;
      for( uint8_t i = 0; i < actual_position_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_actual_position));
        memcpy( &(this->actual_position[i]), &(this->st_actual_position), sizeof(float));
      }
      uint8_t actual_velocity_lengthT = *(inbuffer + offset++);
      if(actual_velocity_lengthT > actual_velocity_length)
        this->actual_velocity = (float*)realloc(this->actual_velocity, actual_velocity_lengthT * sizeof(float));
      offset += 3;
      actual_velocity_length = actual_velocity_lengthT;
      for( uint8_t i = 0; i < actual_velocity_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_actual_velocity));
        memcpy( &(this->actual_velocity[i]), &(this->st_actual_velocity), sizeof(float));
      }
      uint8_t actual_effort_lengthT = *(inbuffer + offset++);
      if(actual_effort_lengthT > actual_effort_length)
        this->actual_effort = (float*)realloc(this->actual_effort, actual_effort_lengthT * sizeof(float));
      offset += 3;
      actual_effort_length = actual_effort_lengthT;
      for( uint8_t i = 0; i < actual_effort_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_actual_effort));
        memcpy( &(this->actual_effort[i]), &(this->st_actual_effort), sizeof(float));
      }
      uint8_t gravity_model_effort_lengthT = *(inbuffer + offset++);
      if(gravity_model_effort_lengthT > gravity_model_effort_length)
        this->gravity_model_effort = (float*)realloc(this->gravity_model_effort, gravity_model_effort_lengthT * sizeof(float));
      offset += 3;
      gravity_model_effort_length = gravity_model_effort_lengthT;
      for( uint8_t i = 0; i < gravity_model_effort_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_gravity_model_effort));
        memcpy( &(this->gravity_model_effort[i]), &(this->st_gravity_model_effort), sizeof(float));
      }
      uint8_t gravity_only_lengthT = *(inbuffer + offset++);
      if(gravity_only_lengthT > gravity_only_length)
        this->gravity_only = (float*)realloc(this->gravity_only, gravity_only_lengthT * sizeof(float));
      offset += 3;
      gravity_only_length = gravity_only_lengthT;
      for( uint8_t i = 0; i < gravity_only_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_gravity_only));
        memcpy( &(this->gravity_only[i]), &(this->st_gravity_only), sizeof(float));
      }
      uint8_t hysteresis_model_effort_lengthT = *(inbuffer + offset++);
      if(hysteresis_model_effort_lengthT > hysteresis_model_effort_length)
        this->hysteresis_model_effort = (float*)realloc(this->hysteresis_model_effort, hysteresis_model_effort_lengthT * sizeof(float));
      offset += 3;
      hysteresis_model_effort_length = hysteresis_model_effort_lengthT;
      for( uint8_t i = 0; i < hysteresis_model_effort_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_hysteresis_model_effort));
        memcpy( &(this->hysteresis_model_effort[i]), &(this->st_hysteresis_model_effort), sizeof(float));
      }
      uint8_t crosstalk_model_effort_lengthT = *(inbuffer + offset++);
      if(crosstalk_model_effort_lengthT > crosstalk_model_effort_length)
        this->crosstalk_model_effort = (float*)realloc(this->crosstalk_model_effort, crosstalk_model_effort_lengthT * sizeof(float));
      offset += 3;
      crosstalk_model_effort_length = crosstalk_model_effort_lengthT;
      for( uint8_t i = 0; i < crosstalk_model_effort_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_crosstalk_model_effort));
        memcpy( &(this->crosstalk_model_effort[i]), &(this->st_crosstalk_model_effort), sizeof(float));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->hystState));
     return offset;
    }

    const char * getType(){ return "baxter_core_msgs/SEAJointState"; };
    const char * getMD5(){ return "d36406dcbb6d860b1b39c4e28f81352b"; };

  };

}
#endif