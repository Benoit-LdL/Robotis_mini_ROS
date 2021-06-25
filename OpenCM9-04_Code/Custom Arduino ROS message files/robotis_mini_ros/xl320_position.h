#ifndef _ROS_robotis_mini_ros_xl320_position_h
#define _ROS_robotis_mini_ros_xl320_position_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robotis_mini_ros
{

  class xl320_position : public ros::Msg
  {
    public:
      typedef uint16_t _angle_type;
      _angle_type angle;
      typedef uint16_t _velocity_type;
      _velocity_type velocity;

    xl320_position():
      angle(0),
      velocity(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->angle >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->angle >> (8 * 1)) & 0xFF;
      offset += sizeof(this->angle);
      *(outbuffer + offset + 0) = (this->velocity >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->velocity >> (8 * 1)) & 0xFF;
      offset += sizeof(this->velocity);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->angle =  ((uint16_t) (*(inbuffer + offset)));
      this->angle |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->angle);
      this->velocity =  ((uint16_t) (*(inbuffer + offset)));
      this->velocity |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->velocity);
     return offset;
    }

    virtual const char * getType() override { return "robotis_mini_ros/xl320_position"; };
    virtual const char * getMD5() override { return "3302327f499c72734e3b2ae13906484e"; };

  };

}
#endif
