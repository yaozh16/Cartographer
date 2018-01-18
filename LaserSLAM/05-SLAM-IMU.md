---
title: Have Fun with SLAM-05-IMU
date: 2017-11-09 20:45:50
tags:
    - SLAM
    - Cartographer
categories:
    - 探知
---

在 [W. Hess2016](http://ieeexplore.ieee.org/document/7487258/?arnumber=7487258&tag=1)论文里提到，Cartographer算法可以不使用IMU信息，可以仅依靠激光雷达/视觉相机，估算运动状态和轨迹，实现建图。但如果缺乏IMU，pose精度得不到保证，这将影响到建图精度。因此，为了获得高精度地图，IMU是非常关键的。

在上一节[Have Fun with SLAM-04-Configuration](https://zldodo.github.io/2017/11/08/04-SLAM-Configuration/)中，我们默认使用了TurtleBot的IMU，并没有自行配置。这一节将重点介绍IMU的配置方法，以XSENS公司的MTw系列IMU为例。

## 安装MTw USB Serial Driver
这一步貌似可以忽略，我在树莓派上省略了这一步，也能正常工作。
```js
git clone https://github.com/xsens/xsens_mt.git
cd ~/xsens_mt
make
sudo modprobe usbserial
sudo insmod ./xsens_mt.ko
```
## 下载源文件gps_common，xsens_driver，custom_msgs
- gps_common
    安装源：https://github.com/swri-robotics/gps_umd，下载gps_common文件夹，放到caktin_ws/src/目录下。
- custom_msgs
    安装源：https://github.com/xsens/xsens_mti_ros_node/tree/master/src，下载custom_msgs文件夹，放到caktin_ws/src/目录下。
- xsens_driver
    安装源：https://github.com/ethz-asl/ethzasl_xsens_driver，将文件夹命名为xsens_driver，放到caktin_ws/src/目录下。

## 编译gps_common，xsens_driver，custom_msgs
这里的编译命令需要注意下，如果使用`catkin_make_isolated –install –use-ninja`,是对/src目录下的所有文件进行编译，貌似会出错。如果报错的话，可以分别对每个Package分别编译：
```js
catkin_make_isolated --pkg gas_common --install –use-ninja
catkin_make_isolated --pkg xsens_driver --install –use-ninja
catkin_make_isolated --pkg custom_msgs --install –use-ninja
```


到这里，IMU的启动配置就完成了。但如果需要整合到SLAM系统中，还需要像Hokuyo那样配置URDF文件，然后修改launch文件。配置IMU的过程在此就不做赘述了啊，与hokuyo类似。

## 配置launch文件
这里的配置，是在[上一节](https://zldodo.github.io/2017/11/08/04-SLAM-Configuration/)基础上进行增添和修改。

1. 修改模型文件
```
  <include file="$(find turtlebot_bringup)/launch/includes/myrobot.launch.xml">
```
这里的`myrobot.launch.xml`不同于之前的`robot.launch.xml`，主要是加入了IMU的urdf模型，并且定义了imu_link。

2. 增加xsen_driver node
```js
<!-- parameters -->
    <arg name="device" default="auto" doc="device file of the IMU"/>
    <arg name="baudrate" default="152000" doc="baudrate of the IMU"/>
    <arg name="timeout" default="0.01" doc="timeout for the IMU communication"/>
    <arg name="frame_id" default="/imu" doc="frame id of the IMU"/>
    <arg name="frame_local" default="ENU" doc="desired frame orientation (ENU, NED or NWU)"/>
    <arg name="no_rotation_duration" default="0" doc="duration (int in seconds) of the no-rotation calibration procedure"/>

    <!-- node -->
  <node pkg="xsens_driver" type="mtnode.py" name="xsens_driver" output="screen" >
    <param name="device" value="$(arg device)"/>
    <param name="baudrate" value="$(arg baudrate)"/>
    <param name="timeout" value="$(arg timeout)"/>
    <param name="frame_id" value="imu_link"/>
    <param name="frame_local" value="$(arg frame_local)"/>
    <param name="no_rotation_duration" value="$(arg no_rotation_duration)"/>
  </node>
```
这部分内容是从`xsens_driver/launch`下复制过来的，但是需要修改了一下frame_id，改成我们在imu.urdf.xacro里定义的imu_link。

3. 修改cartographer_ros的imu_data源
```js
  <node name="flat_world_imu_node" pkg="cartographer_turtlebot"
      type="cartographer_flat_world_imu_node" output="screen">
    <remap from="imu_in" to="/imu/data" />
    <remap from="imu_out" to="/imu" />
  </node>
```
这里和之前的改动在于，把"/mobile_base/sensors/imu_data_raw"改为"/imu/data" 。

## 编译cartographer_turtlebot
在编译之前，需要配置一下catkin_ws/src/cartographer_turtlebot/下的CMakeLists.txt和package.xml。
在CMakeLists.txt中的PACKAGE_DEPENDENCIES处，加入xsens_driver，gps_common，custom_msgs，如下。
```js
cmake_minimum_required(VERSION 2.8.12)  # Ships with Ubuntu 14.04 (Trusty)

project(cartographer_turtlebot)

set(PACKAGE_DEPENDENCIES
  cartographer_ros
  roscpp
  roslib
  sensor_msgs
  xsens_driver
  gps_common
  custom_msgs
)
```
在package.xml中的最后加入xsens_driver，gps_common，custom_msgs，如下所示。
```js
  <depend>cartographer_ros</depend>
  <depend>depthimage_to_laserscan</depend>
  <depend>kobuki</depend>
  <depend>kobuki_core</depend>
  <depend>message_runtime</depend>
  <depend>openni2_launch</depend>
  <depend>roscpp</depend>
  <depend>roslib</depend>
  <depend>sensor_msgs</depend>
  <depend>turtlebot_bringup</depend>
  <depend>urg_node</depend>
  <depend>xsens_driver</depend>
  <depend>gps_common</depend>
  <depend>custom_msgs</depend>
  <test_depend>rosunit</test_depend>
```
完成上述配置后，然后编译cartographer_turtlebot。
```js
catkin_make_isolated --pkg cartographer_turtlebot --install –use-ninja
```

Notice: XSENS_IMU可以设置多种数据文件格式，这里我们需要使用到的加速度和角速度的原始数据。IMU传感器的输出数据类型设置，可参考XSENS官网上的[MT Software Suite](https://www.xsens.com/mt-software-suite/)使用说明。



