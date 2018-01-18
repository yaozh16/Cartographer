---
title: Have Fun with SLAM-02-Cartographer
date: 2017-11-07 15:11:44
tags:
    - SLAM
    - Cartographer
categories:
    - 探知
---
Cartographer，中文直译为建图者，是Google开源的一个ROS系统支持的2D和3D SLAM库。开发人员可以用这个库实现二维和三维定位及制图功能。其SLAM 算法结合了来自多个传感器（比如，LIDAR、IMU 和 摄像头）的数据，同步计算传感器的位置并绘制传感器周围的环境。开源 Cartographer 还搭配有开源机器人操作系统(ROS)，使得该技术库更易于部署到机器人、无人驾驶、无人机等系统。

## Getting Started
Cartographer 是一个独立的C++函数库。如果想要快速感受SLAM的乐趣，Google也提供了ROS封装好的算法包。

-  **Getting start with ROS**
刚开始接触SLAM时，即使对算法原理非常熟悉，但编写复杂代码仍然是非常费劲的。相比从一砖一瓦建筑大厦，不如通过充分利用现成的算法包，建立SLAM系统，快速实现SLAM功能。这样的学习方式，是站在一个较高的视角上认识SLAM的工作过程。同时，还能收获小小的成就感，从而激励自己更加深入地学习。

关于Cartographer_ROS的信息，请移步[这里](https://google-cartographer-ros.readthedocs.io/en/latest/)。

- **Getting start without ROS**
知其然，并要知其所以然。对于追求甚解的好奇宝宝们，Cartographer团队也提供了代码解读文档，详见[这里](https://google-cartographer.readthedocs.io/en/latest/index.html)。

同时，附上他们发表的论文：W. Hess, D. Kohler, H. Rapp, and D. Andor, Real-Time Loop Closure in 2D LIDAR SLAM, in Robotics and Automation (ICRA), 2016 IEEE International Conference on. IEEE, 2016. pp. 1271–1278.

## System Requirements
官网上说，虽然Cartographer能够支持其他类型的系统配置，但保证能在以下系统配置下正常工作：
64-bit, modern CPU (e.g. 3rd generation i7)
16 GB RAM
Ubuntu 14.04 (Trusty) and 16.04 (Xenial)
gcc version 4.8.4 and 5.4.0

## Cartographer ROS for TurtleBots
如果你打算用TurtleBots来玩SLAM， Cartographer团队也提供了 Cartographer SLAM for TurtleBots via Cartographer ROS，详见[这里](https://google-cartographer-ros-for-turtlebots.readthedocs.io/en/latest/)。
Cartographer_Turtlebot提供了很多资源，包含kobuki,kinect,hokuyo等，十分方便调用，绝对满足你的玩耍体验。另外，通过熟悉这一套系统框架，也可以为搭建自己的SLAM系统垫脚哦。

万事俱备啦，还不赶紧去Run the Demo，感受SLAM的乐趣吧～