---
title: Have Fun with SLAM-03-Installation
date: 2017-11-07 21:53:18
tags:
    - SLAM
    - Cartographer
categories:
    - 探知
---
现在，让我们正式开始SLAM吧！需要准备1台或2台电脑，一个移动平台和SLAM传感器（激光雷达或视觉传感器，如Kinect）。我们采用的传感器是激光雷达，移动平台是Turtlebot2，SLAM算法是 Google公司发布的Cartographer。此外，我们将树莓派作为下位机，搭载在Turtlebot2上，负责记录激光雷达和IMU（Inertial Measurement Unit），odometry等传感器信息，然后发送至上位机（一台笔记本电脑）。r然后在上位机上，运行SLAM算法，实时显示地图结果。
<!-- more -->

## 系统组成
目前，搭建的地图构建系统由激光雷达、TurtleBot2、树莓派、笔记本电脑四部分组成。下面分别介绍各部分的功能：
- 激光雷达：信息采集前端。激光雷达发出激光束，测得距离信息，从而能获得环境的轮廓形状。
- TurtleBot2：移动平台。Turtlebot是一个开源的硬件平台和移动基站，集成了IMU，里程计等传感器，采用ROS操作系统，给开发者的应用程序开发带来极大的便利。
- 树莓派：下位机。树莓派一款基于ARM的微型电脑主板，又称卡片式电脑。在本项目中，其负责融合激光雷达和TurtleBot2的信息，然后发送给上位机，以进行后续操作。同时，它可以接收上位机指令，控制TurtleBot的移动。 
- 笔记本电脑：上位机。中央控制处理端，获取下位机的传感器信息，然后运行SlAM算法，实时产生地图。同时，控制TurtleBot在环境中的运动。

系统各部分的连接方式如图所示。我们利用3D打印制作了一个固定制作，将激光雷达安装到TurtleBot上。将激光雷达数据线和TurtleBot通讯线连接到树莓派上，然后树莓派与上位机电脑通过局域网进行通信。

![系统组成实物图](03-SLAM-Installation/系统组成.png)

## 操作系统环境安装
（树莓派和笔记本的安装配置相同）

1. 安装Ubuntu操作系统和ROS操作系统。可选有两种方式：
    - Ubuntu 14.04 (Trusty) ，ROS Indigo
    - Ubuntu 16.04 (Xenial) ， ROS Kinetic

2. 在ROS下安装Turlebot。
    安装过程参见[ROS/TurtleBot](http://wiki.ros.org/Robots/TurtleBot)。

3. 安装cartographer算法包。有两个选择：
    - [cartographer_ros](https://google-cartographer-ros.readthedocs.io/en/latest/) 。这个包仅包含cartographer必需的函数。
    - [cartographer_turtlebot](https://google-cartographer-ros-for-turtlebots.readthedocs.io/en/latest/)。这个包涵盖了cartographer，cartographer_ros和turtlebot相关的文件，内容更多。

4. 安装传感器驱动。
    如果使用激光雷达，indigo版本需要安装[hokuyo_node](https://github.com/yaozh16/Cartographer/wiki/use_Hokuyo_Laser_Scanners_with_the_hokuyo_node)，kinetic版本需要安装[urg_node](https://github.com/yaozh16/Cartographer/wiki/hokuyo_laser_scanner_configuration_for_ros_kinetic)。

Ps:我在Kinetic版本下安装完cartographer_turtlebot后，urg_node就已经默认安装好了，无需再安装。

一切大功告成！！！

刚开始安装，可能会遇到很多小问题。没关系，不要因此沮丧哦，可以将出现的问题粘贴到[ROS answer](https://answers.ros.org/questions/)，或是仔细阅读上述安装文档，一步步排查问题所在，最终都会解决的。欢迎交流哈～






