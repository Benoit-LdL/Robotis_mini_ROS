#!/usr/bin/env python
import rospy
import time
from std_msgs.msg import Int16
from dynamixel_workbench_msgs.msg import XL320
from robotis_mini_ros.msg import imu
#----VARS----#
gyro_x = 0
gyro_y = 0

pub_global_torque = rospy.Publisher('global_Torque_State', Int16, queue_size=10)
pub_global_velocity = rospy.Publisher('global_Velocity', Int16, queue_size=10)

pub_angle_1 = rospy.Publisher('xl320_1_SetAngle', Int16, queue_size=10)
pub_angle_2 = rospy.Publisher('xl320_2_SetAngle', Int16, queue_size=10)
pub_angle_3 = rospy.Publisher('xl320_3_SetAngle', Int16, queue_size=10)
pub_angle_4 = rospy.Publisher('xl320_4_SetAngle', Int16, queue_size=10)
pub_angle_5 = rospy.Publisher('xl320_5_SetAngle', Int16, queue_size=10)
pub_angle_6 = rospy.Publisher('xl320_6_SetAngle', Int16, queue_size=10)
pub_angle_7 = rospy.Publisher('xl320_7_SetAngle', Int16, queue_size=10)
pub_angle_8 = rospy.Publisher('xl320_8_SetAngle', Int16, queue_size=10)
pub_angle_9 = rospy.Publisher('xl320_9_SetAngle', Int16, queue_size=10)
pub_angle_10 = rospy.Publisher('xl320_10_SetAngle', Int16, queue_size=10)
pub_angle_11 = rospy.Publisher('xl320_11_SetAngle', Int16, queue_size=10)
pub_angle_12 = rospy.Publisher('xl320_12_SetAngle', Int16, queue_size=10)
pub_angle_13 = rospy.Publisher('xl320_13_SetAngle', Int16, queue_size=10)
pub_angle_14 = rospy.Publisher('xl320_14_SetAngle', Int16, queue_size=10)
pub_angle_15 = rospy.Publisher('xl320_15_SetAngle', Int16, queue_size=10)
pub_angle_16 = rospy.Publisher('xl320_16_SetAngle', Int16, queue_size=10)

def imu_State_CB(dataIn):
    global gyro_x
    global gyro_y
    gyro_x = dataIn.gyro_x
    gyro_y =  dataIn.gyro_y


rospy.init_node('base', anonymous=True)
rospy.Subscriber("imu_State", imu, imu_State_CB)
rate = rospy.Rate(10)  # 10hz

def Tpose():
    pub_angle_1.publish(0)
    pub_angle_2.publish(0)
    pub_angle_3.publish(0)
    pub_angle_4.publish(0)
    pub_angle_5.publish(0)
    pub_angle_6.publish(0)
    pub_angle_7.publish(0)
    pub_angle_8.publish(0)
    pub_angle_9.publish(0)
    pub_angle_10.publish(0)
    pub_angle_11.publish(0)
    pub_angle_12.publish(0)
    pub_angle_13.publish(0)
    pub_angle_14.publish(0)
    pub_angle_15.publish(0)
    pub_angle_16.publish(0)

########START CODE########

rospy.loginfo("Enabling Torque")
pub_global_torque.publish(1)
time.sleep(2)

pub_global_velocity.publish(400)
time.sleep(2)

rospy.loginfo("initial T-Pose")
Tpose()
time.sleep(2)
rospy.loginfo("loop starting now")
while not rospy.is_shutdown():
    rospy.loginfo(gyro_y)
    pub_angle_3.publish(gyro_y) # set right arm
    pub_angle_4.publish(gyro_y) # set left arm

    pub_angle_9.publish(gyro_x)
    pub_angle_10.publish(-gyro_x)

    rate.sleep()
