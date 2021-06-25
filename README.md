# Robotis_Mini_ROS Repository

## Short Description
I'm interested in humanoid robots, but most of the dev robots / robot kits are way to expensive.
<br><br>
Robotis creates a wide range of humanoid robots: from the really expensive Thormang and Darwin OP (>€8.000) series to the budget Darwin Mini (\~€500).
<br><br>
The Darwin Mini  uses dynamixel XL320 actuators, which are the smallest and cheapest smart servos from robotis.
They're relatively cheap (\~€25) but have a lot of cool features (temp,voltage,torque control,etc...).
<br>
After some research it's clear that the Mini is the most popular and open humanoid robot kit on the market (for now...).
<br><br>
The plan for this project is to control the Robotis (Darwin) Mini using ROS
<br><br>
**This project is a fork from the great work of [Roberto Martín Martín](https://github.com/roberto-martinmartin/robotis_mini)**

## Detailed Description

- I don't know yet if the code made by Martin will be useful as he used potpy and a direct connection to the servos to control his Mini.
- I'm planning on using the OpenCM9.04 to send and recieve data from the servos and to ROS topics using ROSSerial.
- The OpenCM9.04 will be connected to the Raspberry Pi using a usb cable and the Pi will be running ROS.
- the MPU6050 will be connected to the OpenCM9.04, as it's just a fancy arduino board, and send important data to a ROS topic using ROSSerial.
- A camera will be connected to the Pi for OpenCV.
- The goal of this project is to learn more about humanoid robots and how to program them.

## Raspberry Pi Setup
<details>
  <summary>Click to Expand</summary>

* [~Raspberry Pi 4~](https://www.raspberrypi.org/products/raspberry-pi-4-model-b/?resellerType=home) --> [Raspberry Pi 3B+](https://www.raspberrypi.org/products/raspberry-pi-3-model-b-plus/)
	* [~Lubuntu 16.04~](https://downloads.ubiquityrobotics.com/pi.html) --> [Ubuntu 20.04 server](https://ubuntu.com/download/raspberry-pi)  
		* ~Official Ubuntu Xenial 16.04 didn't boot on the Pi 4B (bootloop)...~
		* ~Raspbian image with pre-installed ROS from Robotis didn't work (non-installable ROS packages) ...
	Eventually I found an image made by Ubiquity Robotics which is based on Ubuntu 16.04 and has ROS Kinetic pre-installed + it runs on the Pi 4B!**~
    * Nothing better than a clean, freshly installed version of Ubuntu ;)
	* [~ROS Kinetic (desktop-full)~](http://wiki.ros.org/kinetic) --> [ROS Noetic](http://wiki.ros.org/noetic/Installation/Ubuntu)
	**~! ROS Kinetic has been chosen because it's the most used version of ROS !~**
	* ~Installed VNC server and added a cronjob to be able to access the pi's desktop remotely in the future (vnc has built-in virtual desktop so it works without a hdmi connection)~
	* ~Overclocked the Pi to 1.75Ghz because why not~
  * ROS Kinetic EOL is 1/5/2021 so I've chosen the lastest version of ROS1

</details>

## 3D Printing
I've printed several parts for this project:

* Raspberry Pi 3B+ case
* Raspberry Pi attachment for Robotis Mini
* Structure to hold the Mini in standing position when off

**Please check the 3D_Files folder in this repo for more info and photos**

## Planning
<details>
  <summary>Click to Expand</summary>

* Robotis Mini
	* buy ✔️
	* build ✔️
	* test max load (weight):✔️ Looks to be ok, but the center of cravity has obviously changed
		* I can always remove the included batteries to remove some weight if necessary (even though this would change the center of gravity even more).
		* If I see that the robot works less optimal with the added Raspberry pi, I can always remove it for now and thether the robot to it.
		* [Video of Mini Doing Squads with his Raspberry Pi backpack](https://youtu.be/nuyvmqLuNoM)
	* 3d print RPi mount ✔️


* 3D print
	* Custom Pi Case ✔️
	* Custom piece to attach Pi to the back of the Mini ✔️
	* Custom piece for camera in head

* IMU MPU-6050
	* buy ✔️
	* install on OpenCM9.04

* Raspberry Camera
	* buy ✔️
	* install on Pi

* Basic software Setup
	* Control dynamixel servos using OpenCM9.04
		* trying 3 different libraries from Robotis:
			* ✔️ DynamixelWorkbench: more complicated but has built-in XL320.msg for ROS which is a great thing for later
	* Implement ROS on OpenCM9.04
		* publish all info from servos✔️,IMU✔️,raspberry
		* subcribe to get positions for servos
	* implement OpenCV on Pi with camera

* Advanced Programming
	* implement FABRIK (Inverse Kinematic) in Mini movement
		* [ikpy](https://github.com/Phylliade/ikpy) could be a premade option
	* Make Mini dynamicly stable using IMU data
	* Make Mini walk using Fabrik
	* Make Mini walk on (small) stairs
	* Detect object and follow people

</details>

## Changelog
###### November 2020:
  First hands-on with the Mini and basic implemention of ROS where all servos publish their data on topics

###### 7 Dec 2020:
  I can control and monitor both servos and the imu via ROS. Haven't made the mini move yet.
###### 27 Dec 2020:
  decently sized update:

  1) the IMU data is getting published too slowly, this can be seen when executing the IMU test script that sends specific positions to the servos when reading x and y gyro changes. This is probably because the OpenCM9.04 is pushed at its limit due to all the messages published to the servo topics. I tried to shrink the message size by creating a custom message that only contains interesting data (firmware version, baudrate etc are data I don't need every 200ms...) And by publishing those messages less often but I still have some Lagg... --> a solution could be to only publish necessary servo data when needed (using a subscription based system on the Opencm)

  2) I made a first version of a 'walking' script (the code is purely hardcoded servo angles). The main problem I found was that the xl320 are definitely low-end servos: they aren't super powerful and have a lot of backlash. It is not possible to make the robot walk like most high-end robots slowly swinging from left to right with the raspberry pi on its back. The servos just aren't powerful enough for that. --> a solution could be to make him walk more like when he did out of the box: quick and dirty. This will probably work with the Pi on its back un thus I could continue with my project (adding the Pi Camera and doing some ml/ai stuff)
###### 20 Feb 2021
  Big update:

  1) Changed to ROS Noetic because Kinetic is EOL in a few weeks

  2) Removed the IMU from the OpenCM: The costant stream of data from the MCU to the Pi uses a substantial part of the bandwidth. The plan is now to connect the IMU directly to the Pi using it's I/O pins to reduce overal lagg in the project.

  3) Changed the openCM code to only send XL320 state data when needed. If the OpenCM sees a '1' on the global_xl320_state stopic, it will read the data from the servo's and send it once. This should also reduce overall bandwidth use and thus potential lagg in the project.

  4) Created a new custom message: xl320_position.msg. This is used to set the angle *AND the velocity* of an individual servo. This makes it possible to move multiple servos with different velocities at the same time.

  5) cleaned up the OpenCM code a bit

  6) Nothing changed to the ROS code for now. The next step is definitely the inverse kinematics. Using the Pi camera for vision recognition could also be a great thing to explore next.

  7) The normal Raspberry Pi boards are to heavy to be carried by Darwin, I've been thinking to switch to a Raspberry Pi Zero W wich is much smaller and lighter and should have enough processing power (ROScore could run on an other pc and the Zero W could connect to it). But it hasn't got a usb a port and it's not compatible with the camera I have so I would have to buy a new one :| Let's start with making what I have work

## Project Cost

| **Item** | **Price** | ✔️ / ❌ |
|----------|-----------|---------|
|Robotis Mini	|~€500	|✔️	|
|Raspberry Pi 4B|~€40	|✔️	|
|Pi Camera	|~€25	|✔️ |
|IMU (MPU6050)	|~€1-5	|✔️	|
|-		|	|	|
|**Total**	|~€570	|	|
