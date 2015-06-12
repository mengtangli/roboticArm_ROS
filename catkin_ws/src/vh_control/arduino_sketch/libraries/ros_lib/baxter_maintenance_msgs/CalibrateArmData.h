#ifndef _ROS_baxter_maintenance_msgs_CalibrateArmData_h
#define _ROS_baxter_maintenance_msgs_CalibrateArmData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace baxter_maintenance_msgs
{

  class CalibrateArmData : public ros::Msg
  {
    public:

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return "baxter_maintenance_msgs/CalibrateArmData"; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

}
#endif