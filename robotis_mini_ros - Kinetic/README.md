# ROS Package for Robotis Mini
Here I'll give more explanantion regarding the ROS package for the Mini that will run on the Raspberry Pi 4B

Packages necessary to make this robotis_mini_ros package work:
* [dynamixel-workbench-msgs](https://github.com/ROBOTIS-GIT/dynamixel-workbench-msgs) package
* [robotis_mini](https://github.com/roberto-martinmartin/robotis_mini) package from Roberto Martìn (specifically for the urdf files)

## Dynamixel Workbench
Robotis has 3 major arduino libraries to communicate with their Dynamixel Servos:
* ❌Dynamixel2Arduino: Really easy and straight-forward but maybe not complex enough
* ❌DynamixelSDK: This is some complex stuff, I don't even want to start understanding this...
* ✔️Dynamixel Workbench: More complicated than the first one but has built-in ROS messages (.msg) for each dynamixel servo
  * You need to download the Dynamixel_Workbench_msgs ROS package and put it in your catkin_ws/src directory as described [here](https://emanual.robotis.com/docs/en/software/dynamixel/dynamixel_workbench/)
  * Don't forget to do **catkin_make** afterwards

## Roberto Martìn's robotis_mini package
He created urdf files and much more for the Mini. If you want more info, go see his repoistory!
<br><br>
My plan is to use his urdf files when trying out the ikpy python library. This library is used to calculate inverse kinematics using the FABRIK method. One of the features of this library is to import a urdf-file and use it to create the kinematic model.

## mini.launch file
This launch file will be the main launch file for this project

