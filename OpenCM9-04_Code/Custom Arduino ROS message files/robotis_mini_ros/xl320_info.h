#ifndef _ROS_robotis_mini_ros_xl320_info_h
#define _ROS_robotis_mini_ros_xl320_info_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robotis_mini_ros
{

  class xl320_info : public ros::Msg
  {
    public:
      typedef uint16_t _Model_Number_type;
      _Model_Number_type Model_Number;
      typedef uint8_t _Firmware_Version_type;
      _Firmware_Version_type Firmware_Version;
      typedef uint8_t _ID_type;
      _ID_type ID;
      typedef uint8_t _Baud_Rate_type;
      _Baud_Rate_type Baud_Rate;
      typedef float _Goal_Position_type;
      _Goal_Position_type Goal_Position;
      typedef uint8_t _Moving_type;
      _Moving_type Moving;
      typedef uint16_t _Moving_Speed_type;
      _Moving_Speed_type Moving_Speed;
      typedef uint16_t _Torque_Limit_type;
      _Torque_Limit_type Torque_Limit;
      typedef uint8_t _P_gain_type;
      _P_gain_type P_gain;
      typedef uint8_t _I_gain_type;
      _I_gain_type I_gain;
      typedef uint8_t _D_gain_type;
      _D_gain_type D_gain;

    xl320_info():
      Model_Number(0),
      Firmware_Version(0),
      ID(0),
      Baud_Rate(0),
      Goal_Position(0),
      Moving(0),
      Moving_Speed(0),
      Torque_Limit(0),
      P_gain(0),
      I_gain(0),
      D_gain(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->Model_Number >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->Model_Number >> (8 * 1)) & 0xFF;
      offset += sizeof(this->Model_Number);
      *(outbuffer + offset + 0) = (this->Firmware_Version >> (8 * 0)) & 0xFF;
      offset += sizeof(this->Firmware_Version);
      *(outbuffer + offset + 0) = (this->ID >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ID);
      *(outbuffer + offset + 0) = (this->Baud_Rate >> (8 * 0)) & 0xFF;
      offset += sizeof(this->Baud_Rate);
      union {
        float real;
        uint32_t base;
      } u_Goal_Position;
      u_Goal_Position.real = this->Goal_Position;
      *(outbuffer + offset + 0) = (u_Goal_Position.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_Goal_Position.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_Goal_Position.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_Goal_Position.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->Goal_Position);
      *(outbuffer + offset + 0) = (this->Moving >> (8 * 0)) & 0xFF;
      offset += sizeof(this->Moving);
      *(outbuffer + offset + 0) = (this->Moving_Speed >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->Moving_Speed >> (8 * 1)) & 0xFF;
      offset += sizeof(this->Moving_Speed);
      *(outbuffer + offset + 0) = (this->Torque_Limit >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->Torque_Limit >> (8 * 1)) & 0xFF;
      offset += sizeof(this->Torque_Limit);
      *(outbuffer + offset + 0) = (this->P_gain >> (8 * 0)) & 0xFF;
      offset += sizeof(this->P_gain);
      *(outbuffer + offset + 0) = (this->I_gain >> (8 * 0)) & 0xFF;
      offset += sizeof(this->I_gain);
      *(outbuffer + offset + 0) = (this->D_gain >> (8 * 0)) & 0xFF;
      offset += sizeof(this->D_gain);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->Model_Number =  ((uint16_t) (*(inbuffer + offset)));
      this->Model_Number |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->Model_Number);
      this->Firmware_Version =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->Firmware_Version);
      this->ID =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->ID);
      this->Baud_Rate =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->Baud_Rate);
      union {
        float real;
        uint32_t base;
      } u_Goal_Position;
      u_Goal_Position.base = 0;
      u_Goal_Position.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_Goal_Position.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_Goal_Position.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_Goal_Position.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->Goal_Position = u_Goal_Position.real;
      offset += sizeof(this->Goal_Position);
      this->Moving =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->Moving);
      this->Moving_Speed =  ((uint16_t) (*(inbuffer + offset)));
      this->Moving_Speed |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->Moving_Speed);
      this->Torque_Limit =  ((uint16_t) (*(inbuffer + offset)));
      this->Torque_Limit |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->Torque_Limit);
      this->P_gain =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->P_gain);
      this->I_gain =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->I_gain);
      this->D_gain =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->D_gain);
     return offset;
    }

    const char * getType(){ return "robotis_mini_ros/xl320_info"; };
    const char * getMD5(){ return "2e06938da130592b488e7a7e5b00e1be"; };

  };

}
#endif