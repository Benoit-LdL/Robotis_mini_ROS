#!/usr/bin/env python3
import rospy
import time
from std_msgs.msg import Int16
from robotis_mini_ros.msg import xl320_state
from robotis_mini_ros.msg import xl320_position

pub_global_xl320_state = rospy.Publisher('global_xl320_State',Int16,queue_size=10)
pub_global_torque = rospy.Publisher('global_Torque_State', Int16, queue_size=10)
pub_global_velocity = rospy.Publisher('global_Velocity', Int16, queue_size=10)

pub_position_1 = rospy.Publisher('xl320_1_SetPosition', xl320_position, queue_size=10)
pub_position_2 = rospy.Publisher('xl320_2_SetPosition', xl320_position, queue_size=10)
pub_position_3 = rospy.Publisher('xl320_3_SetPosition', xl320_position, queue_size=10)
pub_position_4 = rospy.Publisher('xl320_4_SetPosition', xl320_position, queue_size=10)
pub_position_5 = rospy.Publisher('xl320_5_SetPosition', xl320_position, queue_size=10)
pub_position_6 = rospy.Publisher('xl320_6_SetPosition', xl320_position, queue_size=10)
pub_position_7 = rospy.Publisher('xl320_7_SetPosition', xl320_position, queue_size=10)
pub_position_8 = rospy.Publisher('xl320_8_SetPosition', xl320_position, queue_size=10)
pub_position_9 = rospy.Publisher('xl320_9_SetPosition', xl320_position, queue_size=10)
pub_position_10 = rospy.Publisher('xl320_10_SetPosition', xl320_position, queue_size=10)
pub_position_11 = rospy.Publisher('xl320_11_SetPosition', xl320_position, queue_size=10)
pub_position_12 = rospy.Publisher('xl320_12_SetPosition', xl320_position, queue_size=10)
pub_position_13 = rospy.Publisher('xl320_13_SetPosition', xl320_position, queue_size=10)
pub_position_14 = rospy.Publisher('xl320_14_SetPosition', xl320_position, queue_size=10)
pub_position_15 = rospy.Publisher('xl320_15_SetPosition', xl320_position, queue_size=10)
pub_position_16 = rospy.Publisher('xl320_16_SetPosition', xl320_position, queue_size=10)

rospy.init_node('base', anonymous=True)
rate = rospy.Rate(0.3)  # 10hz

########START CODE########
time.sleep(5)

rospy.loginfo("Enabling Torque")
pub_global_torque.publish(1)

rospy.loginfo("Setting global velocity to 100")
pub_global_velocity.publish(100)

#rospy.loginfo("Sending request for xl320 states")
#pub_global_xl320_state.publish(1)

rospy.loginfo("Setting Base position")
# #Arm Right
pub_position_1.publish(angle=0,velocity=200)
pub_position_3.publish(angle=-70,velocity=200)
pub_position_5.publish(angle=0,velocity=200)

#Arm Left
pub_position_2.publish(angle=0,velocity=0)
pub_position_4.publish(angle=70,velocity=0)
pub_position_6.publish(angle=0,velocity=0)

# #Leg Right
pub_position_7.publish(angle=0,velocity=0)
pub_position_9.publish(angle=-40,velocity=0)
pub_position_11.publish(angle=60,velocity=0)
pub_position_13.publish(angle=30,velocity=0)
pub_position_15.publish(angle=0,velocity=0)

# #Lef Left
pub_position_8.publish(angle=0,velocity=0)
pub_position_10.publish(angle=40,velocity=0)
pub_position_12.publish(angle=-60,velocity=0)
pub_position_14.publish(angle=-30,velocity=0)
pub_position_16.publish(angle=0,velocity=0)

time.sleep(10)
rospy.loginfo("Disabling Torque")
pub_global_torque.publish(0)


while not rospy.is_shutdown():
    rospy.loginfo("looping...")
    time.sleep(2)
