# ! Not maintained anymore (for now...) ! 

# New repository :point_right: [here](https://github.com/Benoit-LdL/Robotis_Mini_Python)



## What's this project about?
This is version 2. For more information regarding this project, please check the readme file from the [V1 branch](https://github.com/Benoit-LdL/Robotis_Mini_ROS/tree/V1).
OpenCM-code
## What is the problem with V1?
In version 1 I used the OpenCM9.04 board from the Robotis Mini Kit and ran custom arduino code on it that communicated with ros running on a Raspberry Pi.

These were the main issues with version 1:
* The raspberry Pi 3/4 was too havy to be installed on the back of the robot.
* Programming the OpenCM9.04 was an absolute pain:
	1) Writing code in C++
	2) Building code in Arduino IDE
	3) Putting MCU in flash mode by pressing a button which is hidden somewhere inside the robot
	4) Getting the timing right between pushing that button, connecting the USB cable and starting the code deployment in the Arduino IDE

Only when these 4 steps were followed correclty I knew if my code worked or not (which didn't most of the time to be honest...)

These issues, together with covid, did not really make me want to continue working on this project.

Until I found out you can run ROS on a raspberry PI zero!

## What's the plan for V2?
1) Run ROSCORE together with all "heavy" computing on my laptop.
2) Use ROS on the Pi Zero to bridge communication between my laptop and the servos wirelessly.
3) use the GPIO pins of the Pi Zero to connect directly to the Serial interface of the servos. This means the OpenCM9.04 board will only be used to power the servos, while the Pi Zero will be used to communicate with them.
4) All code will be written in python and will be much easier to test (no compiling, uploading etc to the MCU).

## Hardware & Software Used

### Raspberry Pi Setup
* [Raspberry Pi Zero W](https://www.raspberrypi.org/products/raspberry-pi-zero-w/) 
	* [Latest version of Raspberry Pi OS Lite](https://www.raspberrypi.org/software/)
		* Based on Raspbian Buster
	* [ROS Melodic](http://wiki.ros.org/melodic) thanks to [this](https://gist.github.com/Tiryoh/76be0ac467c09667ca51b5f8d9f4b3bc) amazing script by [Tiryoh](https://github.com/Tiryoh)

### PC Setup
* Laptop running Ubuntu Focal (Dualbooting with windows 10)
	* [ROS Noetic](http://wiki.ros.org/noetic) installed by following the [official instructions](http://wiki.ros.org/noetic/Installation/Ubuntu)


## 3D Printing
I will need to print new parts for the robot:

* Raspberry Pi Zero case
* Raspberry Pi attachment for Robotis Mini

**Please check the 3D_Files folder in this repo for more info and photos**

## Changelog

###### 23 June 2021
* Updated Ubuntu and ROS on Laptop
* Installed ROS on Raspberry Pi Zero W
* Created ROS packages for both the laptop and the robot (Pi Zero)
* Created launch files to check if both ROS setups can communicate with eachother
	* using the simple Talker / Listener scripts from the rospy_tutorials package

###### Mid June 2021
Starting research on Raspberry Pi Zero W

###### Before June 2021
Version 1 of the project
