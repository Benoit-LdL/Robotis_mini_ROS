# OpenCM9.04 Code
Here I'll give more explanantion regarding the programming of the OpenCM9.04 by Robotis.


The OpenCM9.04 board package for Arduino IDE allready pre-installs ros_lib folder inside itself (package),
so you don't need to install the rosserial library from the library manager and just use rosserial from OpenCM9.04 package instead.
<br><br>

## Dynamixel Workbench
Robotis has 3 major arduino libraries to communicate with their Dynamixel Servos:
* ❌Dynamixel2Arduino: Really easy and straight-forward but maybe not complex enough
* ❌DynamixelSDK: This is some complex stuff, I don't even want to start understanding this...
* ✔️Dynamixel Workbench: More complicated than the first one but has built-in ROS messages (.msg) for each dynamixel servo
  * Download [my ROS package from this repository](https://github.com/Benoit-LdL/Robotis_Mini_ROS/tree/master/robotis_mini_ros) and put it your **catkin_ws/src folder**
  * Next do **catkin_make** and **catkin_make install** from your catkin_ws dir
  * Next follow [this](http://wiki.ros.org/rosserial/Tutorials/Adding%20Other%20Messages) tutorial and this will create a ros_lib folder at your specified directory
  * This ros_lib folder contains a folder named **robotis_mini_ros**, in this folder you will see all my ROS message file converted to arduino **'.h'** files

## OpenCM9.04 Board package in Arduino
* Follow [this](https://emanual.robotis.com/docs/en/parts/controller/opencm904/#arduino-ide) guide to setup your Arduino to be able to program the OpenCM9.04
* Put the **robotis_mini_ros** folder containing the **'.h'** files inside the existing **ros_lib** folder inside the openCM9.04 board package directory
  * On windows it's located at **"C:\Users\\#*user*#\\AppData\Local\Arduino15\packages\OpenCM904\hardware\OpenCM904\\#*version_nr*#\\libraries"**

<br><br>
After Following these ridiculously complicated and totally not user friendly steps, you should be able to compile my arduino code without any errors (fingers crossed🤞)
<br>
[Demo video: publishing xl320 info to topic](https://youtu.be/2PTbYqYYdJ8)
