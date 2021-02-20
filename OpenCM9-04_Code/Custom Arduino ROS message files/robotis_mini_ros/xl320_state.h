#ifndef _ROS_robotis_mini_ros_xl320_state_h
#define _ROS_robotis_mini_ros_xl320_state_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robotis_mini_ros
{

  class xl320_state : public ros::Msg
  {
    public:
      typedef uint8_t _ID_type;
      _ID_type ID;
      typedef uint8_t _Torque_Enable_type;
      _Torque_Enable_type Torque_Enable;
      typedef float _Present_Position_type;
      _Present_Position_type Present_Position;
      typedef uint16_t _Present_Speed_type;
      _Present_Speed_type Present_Speed;
      typedef uint16_t _Present_Load_type;
      _Present_Load_type Present_Load;
      typedef uint8_t _Present_Voltage_type;
      _Present_Voltage_type Present_Voltage;
      typedef uint8_t _Present_Temperature_type;
      _Present_Temperature_type Present_Temperature;
      typedef uint8_t _LED_type;
      _LED_type LED;
      typedef uint8_t _Hardware_Error_Status_type;
      _Hardware_Error_Status_type Hardware_Error_Status;

    xl320_state():
      ID(0),
      Torque_Enable(0),
      Present_Position(0),
      Present_Speed(0),
      Present_Load(0),
      Present_Voltage(0),
      Present_Temperature(0),
      LED(0),
      Hardware_Error_Status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->ID >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ID);
      *(outbuffer + offset + 0) = (this->Torque_Enable >> (8 * 0)) & 0xFF;
      offset += sizeof(this->Torque_Enable);
      union {
        float real;
        uint32_t base;
      } u_Present_Position;
      u_Present_Position.real = this->Present_Position;
      *(outbuffer + offset + 0) = (u_Present_Position.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_Present_Position.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_Present_Position.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_Present_Position.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->Present_Position);
      *(outbuffer + offset + 0) = (this->Present_Speed >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->Present_Speed >> (8 * 1)) & 0xFF;
      offset += sizeof(this->Present_Speed);
      *(outbuffer + offset + 0) = (this->Present_Load >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->Present_Load >> (8 * 1)) & 0xFF;
      offset += sizeof(this->Present_Load);
      *(outbuffer + offset + 0) = (this->Present_Voltage >> (8 * 0)) & 0xFF;
      offset += sizeof(this->Present_Voltage);
      *(outbuffer + offset + 0) = (this->Present_Temperature >> (8 * 0)) & 0xFF;
      offset += sizeof(this->Present_Temperature);
      *(outbuffer + offset + 0) = (this->LED >> (8 * 0)) & 0xFF;
      offset += sizeof(this->LED);
      *(outbuffer + offset + 0) = (this->Hardware_Error_Status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->Hardware_Error_Status);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->ID =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->ID);
      this->Torque_Enable =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->Torque_Enable);
      union {
        float real;
        uint32_t base;
      } u_Present_Position;
      u_Present_Position.base = 0;
      u_Present_Position.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_Present_Position.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_Present_Position.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_Present_Position.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->Present_Position = u_Present_Position.real;
      offset += sizeof(this->Present_Position);
      this->Present_Speed =  ((uint16_t) (*(inbuffer + offset)));
      this->Present_Speed |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->Present_Speed);
      this->Present_Load =  ((uint16_t) (*(inbuffer + offset)));
      this->Present_Load |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->Present_Load);
      this->Present_Voltage =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->Present_Voltage);
      this->Present_Temperature =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->Present_Temperature);
      this->LED =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->LED);
      this->Hardware_Error_Status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->Hardware_Error_Status);
     return offset;
    }

    const char * getType(){ return "robotis_mini_ros/xl320_state"; };
    const char * getMD5(){ return "fe290b79ad1bcdaf1fedc2e29f00f434"; };

  };

}
#endif