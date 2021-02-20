#!/usr/bin/env python
import rospy
import time
from std_msgs.msg import Int16
from robotis_mini_ros.msg import xl320_state

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

rospy.init_node('base', anonymous=True)
rate = rospy.Rate(0.3)  # 10hz

########START CODE########

rospy.loginfo("Enabling Torque")
pub_global_torque.publish(1)
time.sleep(2)

rospy.loginfo("Setting global velocity to 100")
pub_global_velocity.publish(100)
time.sleep(2)

rospy.loginfo("Setting Base position")
#Arm Right
pub_angle_1.publish(0)
pub_angle_3.publish(-70)
pub_angle_5.publish(0)

#Arm Left
pub_angle_2.publish(0)
pub_angle_4.publish(70)
pub_angle_6.publish(0)

#Leg Right
pub_angle_7.publish(0)
pub_angle_9.publish(-40)
pub_angle_11.publish(60)
pub_angle_13.publish(30)
pub_angle_15.publish(0)
#Lef Left
pub_angle_8.publish(0)
pub_angle_10.publish(40)
pub_angle_12.publish(-60)
pub_angle_14.publish(-30)
pub_angle_16.publish(0)

time.sleep(5)
rospy.loginfo("Disabling Torque")
pub_global_torque.publish(0)
while not rospy.is_shutdown():
    rospy.loginfo("looping...")
    rate.sleep()
