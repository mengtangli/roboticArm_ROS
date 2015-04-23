#ifndef _ROS_baxter_core_msgs_ITBState_h
#define _ROS_baxter_core_msgs_ITBState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace baxter_core_msgs
{

  class ITBState : public ros::Msg
  {
    public:
      bool buttons[4];
      bool up;
      bool down;
      bool left;
      bool right;
      uint8_t wheel;
      bool innerLight;
      bool outerLight;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint8_t i = 0; i < 4; i++){
      union {
        bool real;
        uint8_t base;
      } u_buttonsi;
      u_buttonsi.real = this->buttons[i];
      *(outbuffer + offset + 0) = (u_buttonsi.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->buttons[i]);
      }
      union {
        bool real;
        uint8_t base;
      } u_up;
      u_up.real = this->up;
      *(outbuffer + offset + 0) = (u_up.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->up);
      union {
        bool real;
        uint8_t base;
      } u_down;
      u_down.real = this->down;
      *(outbuffer + offset + 0) = (u_down.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->down);
      union {
        bool real;
        uint8_t base;
      } u_left;
      u_left.real = this->left;
      *(outbuffer + offset + 0) = (u_left.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->left);
      union {
        bool real;
        uint8_t base;
      } u_right;
      u_right.real = this->right;
      *(outbuffer + offset + 0) = (u_right.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->right);
      *(outbuffer + offset + 0) = (this->wheel >> (8 * 0)) & 0xFF;
      offset += sizeof(this->wheel);
      union {
        bool real;
        uint8_t base;
      } u_innerLight;
      u_innerLight.real = this->innerLight;
      *(outbuffer + offset + 0) = (u_innerLight.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->innerLight);
      union {
        bool real;
        uint8_t base;
      } u_outerLight;
      u_outerLight.real = this->outerLight;
      *(outbuffer + offset + 0) = (u_outerLight.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->outerLight);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint8_t i = 0; i < 4; i++){
      union {
        bool real;
        uint8_t base;
      } u_buttonsi;
      u_buttonsi.base = 0;
      u_buttonsi.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->buttons[i] = u_buttonsi.real;
      offset += sizeof(this->buttons[i]);
      }
      union {
        bool real;
        uint8_t base;
      } u_up;
      u_up.base = 0;
      u_up.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->up = u_up.real;
      offset += sizeof(this->up);
      union {
        bool real;
        uint8_t base;
      } u_down;
      u_down.base = 0;
      u_down.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->down = u_down.real;
      offset += sizeof(this->down);
      union {
        bool real;
        uint8_t base;
      } u_left;
      u_left.base = 0;
      u_left.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->left = u_left.real;
      offset += sizeof(this->left);
      union {
        bool real;
        uint8_t base;
      } u_right;
      u_right.base = 0;
      u_right.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->right = u_right.real;
      offset += sizeof(this->right);
      this->wheel =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->wheel);
      union {
        bool real;
        uint8_t base;
      } u_innerLight;
      u_innerLight.base = 0;
      u_innerLight.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->innerLight = u_innerLight.real;
      offset += sizeof(this->innerLight);
      union {
        bool real;
        uint8_t base;
      } u_outerLight;
      u_outerLight.base = 0;
      u_outerLight.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->outerLight = u_outerLight.real;
      offset += sizeof(this->outerLight);
     return offset;
    }

    const char * getType(){ return "baxter_core_msgs/ITBState"; };
    const char * getMD5(){ return "fd86ad89da05230247c94b4d8e7ed306"; };

  };

}
#endif