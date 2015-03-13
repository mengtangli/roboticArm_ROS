#ifndef _ROS_baxter_core_msgs_NavigatorState_h
#define _ROS_baxter_core_msgs_NavigatorState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace baxter_core_msgs
{

  class NavigatorState : public ros::Msg
  {
    public:
      uint8_t names_length;
      char* st_names;
      char* * names;
      uint8_t buttons_length;
      bool st_buttons;
      bool * buttons;
      uint8_t wheel;
      uint8_t lights_length;
      bool st_lights;
      bool * lights;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = names_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < names_length; i++){
      uint32_t length_namesi = strlen(this->names[i]);
      memcpy(outbuffer + offset, &length_namesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->names[i], length_namesi);
      offset += length_namesi;
      }
      *(outbuffer + offset++) = buttons_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < buttons_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_buttonsi;
      u_buttonsi.real = this->buttons[i];
      *(outbuffer + offset + 0) = (u_buttonsi.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->buttons[i]);
      }
      *(outbuffer + offset + 0) = (this->wheel >> (8 * 0)) & 0xFF;
      offset += sizeof(this->wheel);
      *(outbuffer + offset++) = lights_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < lights_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_lightsi;
      u_lightsi.real = this->lights[i];
      *(outbuffer + offset + 0) = (u_lightsi.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->lights[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t names_lengthT = *(inbuffer + offset++);
      if(names_lengthT > names_length)
        this->names = (char**)realloc(this->names, names_lengthT * sizeof(char*));
      offset += 3;
      names_length = names_lengthT;
      for( uint8_t i = 0; i < names_length; i++){
      uint32_t length_st_names;
      memcpy(&length_st_names, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_names-1]=0;
      this->st_names = (char *)(inbuffer + offset-1);
      offset += length_st_names;
        memcpy( &(this->names[i]), &(this->st_names), sizeof(char*));
      }
      uint8_t buttons_lengthT = *(inbuffer + offset++);
      if(buttons_lengthT > buttons_length)
        this->buttons = (bool*)realloc(this->buttons, buttons_lengthT * sizeof(bool));
      offset += 3;
      buttons_length = buttons_lengthT;
      for( uint8_t i = 0; i < buttons_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_buttons;
      u_st_buttons.base = 0;
      u_st_buttons.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_buttons = u_st_buttons.real;
      offset += sizeof(this->st_buttons);
        memcpy( &(this->buttons[i]), &(this->st_buttons), sizeof(bool));
      }
      this->wheel =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->wheel);
      uint8_t lights_lengthT = *(inbuffer + offset++);
      if(lights_lengthT > lights_length)
        this->lights = (bool*)realloc(this->lights, lights_lengthT * sizeof(bool));
      offset += 3;
      lights_length = lights_lengthT;
      for( uint8_t i = 0; i < lights_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_lights;
      u_st_lights.base = 0;
      u_st_lights.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_lights = u_st_lights.real;
      offset += sizeof(this->st_lights);
        memcpy( &(this->lights[i]), &(this->st_lights), sizeof(bool));
      }
     return offset;
    }

    const char * getType(){ return "baxter_core_msgs/NavigatorState"; };
    const char * getMD5(){ return "626a2401ea06bafc2f1ecf16d05f1675"; };

  };

}
#endif