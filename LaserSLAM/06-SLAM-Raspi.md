---
title: Have Fun with SLAM-06-Raspberry Pi 3
date: 2017-11-09 21:00:52
tags:
    - SLAM
    - Cartographer
categories:
    - 探知
---
经过前面的积累，我们现在已经利用一台笔记本电脑和TurtleBot，就能够实现实时室内建图了。但是，考虑到实际应用场景，例如无人机来做SLAM，或是其他的移动平台，往往其计算能力是有限，而实时SLAM算法对计算机的性能较高。因此，我们可以在微机系统下录包，然后在笔记本上离线建图。这里，我们选择树莓派作为移动平台的处理器。

## 树莓派安装Ubuntu操作系统
在树莓派上安装与笔记本上版本相同的Ubuntu系统。现在，[Ubuntu MATE 16.04 LTS(xenial)](https://ubuntu-mate.org/raspberry-pi/)已经发布，支持树莓派３和树莓派２．

刚接触树莓派的朋友，操作系统安装方法可参考[这里](http://bbs.elecfans.com/jishu_599362_1_1.html)。树莓派有HDMI借口，可以连电脑显示器，也可以买一块显示屏，显示屏配置方法可参考[微雪电子４inch HDMI LCD](http://www.waveshare.net/wiki)。

## 安装ROS，Cartographer，TurtleBot
这里的安装过程与前面几节一模一样，那就当做再熟悉一遍安装流程吧：）

不过，需要注意的是，如果在树莓派安装UBuntu时，选择的是默认安装，没有手动分区，可能会造成在编译Cartographer_turtlebot时非常卡顿。那可不是一般的慢，让人误以为是系统死机了。后来找到了解决办法，原来是是需要扩展swap空间，具体方法请见[树莓派swap空间扩展](http://blog.csdn.net/wxz3wxz/article/details/70237302)。

## 配置launch文件
又要配置launch文件？没错，但操作非常简单，只需要更改[hokuyo_xsens.launch](hokuyo_xsens.launch)里的一些配置就好。
- **在树莓派上**
因为不需要在树莓派上运行cartographer算法包，所以删除launch文件里的cartographer_node，cartographer_occupancy_grid_node，rviz就好了。附上我的[raspi_turtlebot_hokuyo_xsens.launch](raspi_turtlebot_hokuyo_xsens.launch)。
- **在笔记本上**
笔记本不需要启动各种传感器和移动平台，所有的传感器信息已经存在录制的bag文件里，所以，笔记本只需调用读取bag文件和cartographer算法包即可。录包方法将在后面介绍。

这里我们使用到了一个cartographer离线建图包cartographer_offline_node，配置如下：
```js
  <node name="cartographer_offline_node" pkg="cartographer_ros"
      type="cartographer_offline_node" args="
          -configuration_directory
              $(find cartographer_turtlebot)/configuration_files
          -configuration_basename turtlebot_hokuyo_2d.lua
          -bag_filenames /home/dodo/bagfiles/2017-10-25-16-14-11.bag"
      output="screen">
  </node>
```
这里有两点需要注意：
1. 指定lua文件路径和名称，例如这里的configuration_directory和configuration_basename;
2. 指定bag文件路径和名称 ,例如这里的bag_filenames /home/dodo/bagfiles/2017-10-25-16-14-11.bag 。
附上我的[offline.launch](demo_offline_2d.launch)

## 录包操作
```js
rosbag record -a
```
详细的使用方法请见[ROS/Recording and play](http://wiki.ros.org/cn/ROS/Tutorials/Recording%20and%20playing%20back%20data)。

好了，赶紧去试试树莓派吧～




