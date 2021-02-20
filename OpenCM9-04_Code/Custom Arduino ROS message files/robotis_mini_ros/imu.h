#ifndef _ROS_robotis_mini_ros_imu_h
#define _ROS_robotis_mini_ros_imu_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robotis_mini_ros
{

  class imu : public ros::Msg
  {
    public:
      typedef int16_t _gyro_x_type;
      _gyro_x_type gyro_x;
      typedef int16_t _gyro_y_type;
      _gyro_y_type gyro_y;
      typedef int16_t _gyro_z_type;
      _gyro_z_type gyro_z;
      typedef int16_t _accel_x_type;
      _accel_x_type accel_x;
      typedef int16_t _accel_y_type;
      _accel_y_type accel_y;
      typedef int16_t _accel_z_type;
      _accel_z_type accel_z;
      typedef int16_t _accel_w_type;
      _accel_w_type accel_w;
      typedef int8_t _temp_type;
      _temp_type temp;

    imu():
      gyro_x(0),
      gyro_y(0),
      gyro_z(0),
      accel_x(0),
      accel_y(0),
      accel_z(0),
      accel_w(0),
      temp(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_gyro_x;
      u_gyro_x.real = this->gyro_x;
      *(outbuffer + offset + 0) = (u_gyro_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gyro_x.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->gyro_x);
      union {
        int16_t real;
        uint16_t base;
      } u_gyro_y;
      u_gyro_y.real = this->gyro_y;
      *(outbuffer + offset + 0) = (u_gyro_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gyro_y.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->gyro_y);
      union {
        int16_t real;
        uint16_t base;
      } u_gyro_z;
      u_gyro_z.real = this->gyro_z;
      *(outbuffer + offset + 0) = (u_gyro_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gyro_z.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->gyro_z);
      union {
        int16_t real;
        uint16_t base;
      } u_accel_x;
      u_accel_x.real = this->accel_x;
      *(outbuffer + offset + 0) = (u_accel_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_accel_x.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->accel_x);
      union {
        int16_t real;
        uint16_t base;
      } u_accel_y;
      u_accel_y.real = this->accel_y;
      *(outbuffer + offset + 0) = (u_accel_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_accel_y.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->accel_y);
      union {
        int16_t real;
        uint16_t base;
      } u_accel_z;
      u_accel_z.real = this->accel_z;
      *(outbuffer + offset + 0) = (u_accel_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_accel_z.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->accel_z);
      union {
        int16_t real;
        uint16_t base;
      } u_accel_w;
      u_accel_w.real = this->accel_w;
      *(outbuffer + offset + 0) = (u_accel_w.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_accel_w.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->accel_w);
      union {
        int8_t real;
        uint8_t base;
      } u_temp;
      u_temp.real = this->temp;
      *(outbuffer + offset + 0) = (u_temp.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->temp);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_gyro_x;
      u_gyro_x.base = 0;
      u_gyro_x.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gyro_x.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->gyro_x = u_gyro_x.real;
      offset += sizeof(this->gyro_x);
      union {
        int16_t real;
        uint16_t base;
      } u_gyro_y;
      u_gyro_y.base = 0;
      u_gyro_y.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gyro_y.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->gyro_y = u_gyro_y.real;
      offset += sizeof(this->gyro_y);
      union {
        int16_t real;
        uint16_t base;
      } u_gyro_z;
      u_gyro_z.base = 0;
      u_gyro_z.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gyro_z.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->gyro_z = u_gyro_z.real;
      offset += sizeof(this->gyro_z);
      union {
        int16_t real;
        uint16_t base;
      } u_accel_x;
      u_accel_x.base = 0;
      u_accel_x.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_accel_x.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->accel_x = u_accel_x.real;
      offset += sizeof(this->accel_x);
      union {
        int16_t real;
        uint16_t base;
      } u_accel_y;
      u_accel_y.base = 0;
      u_accel_y.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_accel_y.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->accel_y = u_accel_y.real;
      offset += sizeof(this->accel_y);
      union {
        int16_t real;
        uint16_t base;
      } u_accel_z;
      u_accel_z.base = 0;
      u_accel_z.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_accel_z.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->accel_z = u_accel_z.real;
      offset += sizeof(this->accel_z);
      union {
        int16_t real;
        uint16_t base;
      } u_accel_w;
      u_accel_w.base = 0;
      u_accel_w.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_accel_w.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->accel_w = u_accel_w.real;
      offset += sizeof(this->accel_w);
      union {
        int8_t real;
        uint8_t base;
      } u_temp;
      u_temp.base = 0;
      u_temp.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->temp = u_temp.real;
      offset += sizeof(this->temp);
     return offset;
    }

    const char * getType(){ return "robotis_mini_ros/imu"; };
    const char * getMD5(){ return "b22ae62c7b96cd7e628bf256d0516fd1"; };

  };

}
#endif