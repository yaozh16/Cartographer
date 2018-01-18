---
title: Have Fun with SLAM-04-Configuration
date: 2017-11-08 10:54:59
tags:
    - SLAM
    - Cartographer
categories:
    - 探知
---
完成[系统安装](https://zldodo.github.io/2017/11/07/03-SLAM-Installation/)后，接下来是编辑配置文件。这一部分内容非常关键，直接影响着SLAM系统能否顺利工作。可能这一部分需要花一些时间，需要清楚配置文件中每一部分的具体含义和功能。当熟悉完配置文件的格式后，你就可以针对自己搭建的系统进行相关配置了。
<!--more-->
## 创建配置文件
主要的配置文件包含三个，分别是.launch，.lua，.rviz。
- demo.launch，用于启动所需node，类似于程序启动。放在`$package/launch/`目录下，e.g.，`catkin_ws/src/cartographer_turtlebot/cartographer_turtlebot/launch/`，或者是`catkin_ws/src/cartographer_ros/cartographer_ros/launch/`。
- demo.lua，用于定义cartographer算法的一些参数，例如建图基准，是否使用imu，odom ，以及laser等传感器个数等。放在`$package/configuration_files/`目录下，e.g.， `catkin_ws/src/cartographer_turtlebot/cartographer_turtlebot/configuration_files/`，或者是`catkin_ws/src/cartographer_ros/cartographer_ros/configuration_files/`。
- demo.rivz，用于可视化建图结果和系统模型。所在目录与demo.lua一样。这个文件可以事先定义，也可以后续生成。例如，启动`riviz`后，手动添加`tf，RobotModel，laserscan`等设置，然后导出文件即可。

## launch文件配置
这部分包含启动turtlbot，hokuyo，cartographer_node，flat_world_imu_node，cartographer_occupancy_grid_node，rviz。整个文件可点击此处下载[demo.launch](demo.launch)。
下面将逐一解释该launch文件中每个node的启动方式。

### 1. 定义`use_sim_time`参数
```js
<param name="/use_sim_time" value="false" />
```
注意，当实时建图时，value=false;当通过bag文件建图时，value=true。

### 2. 启动Turtlebot
```js
<!-- Turtlebot -->
  <arg name="base"              default="$(env TURTLEBOT_BASE)"         doc="mobile base type [create, roomba]"/>
  <arg name="battery"           default="$(env TURTLEBOT_BATTERY)"      doc="kernel provided locatio for battery info, use /proc/acpi/battery/BAT0 in 2.6 or earlier kernels." />
  <arg name="stacks"            default="$(env TURTLEBOT_STACKS)"       doc="stack type displayed in visualisation/simulation [circles, hexagons]"/>
  <arg name="3d_sensor"         default="$(env TURTLEBOT_3D_SENSOR)"    doc="3d sensor types [kinect, asux_xtion_pro, hokuyo]"/>
  <arg name="simulation"        default="$(env TURTLEBOT_SIMULATION)"   doc="set flags to indicate this turtle is run in simulation mode."/>
  <arg name="serialport"        default="$(env TURTLEBOT_SERIAL_PORT)"  doc="used by create to configure the port it is connected on [/dev/ttyUSB0, /dev/ttyS0]"/>

 ```
将环境变量赋值给自定义变量。
```js
 <include file="$(find turtlebot_bringup)/launch/includes/robot.launch.xml">
    <arg name="base" value="$(arg base)" />
    <arg name="stacks" value="$(arg stacks)" />
    <arg name="3d_sensor" value="$(arg 3d_sensor)" />
  </include>
  <include file="$(find turtlebot_bringup)/launch/includes/mobile_base.launch.xml">
    <arg name="base" value="$(arg base)" />
    <arg name="serialport" value="$(arg serialport)" />
  </include>
  <include unless="$(eval arg('battery') == 'None')" file="$(find turtlebot_bringup)/launch/includes/netbook.launch.xml">
    <arg name="battery" value="$(arg battery)" />
  </include>
```
`robot.launch.xml`文件里定义了kobuki，stacks 和sensors的仿真模型，与tf的links和joints。在之前的系统安装里，没有包含hokuyo的模型文件，这个需要我们自己编写，附上我的[hokuyo.urdf.xacro](hokuyo.urdf.xacro)。有关urdf文件的编写方式，详见[ROS/urdf](http://wiki.ros.org/urdf)。
`mobile_base.launch.xml`定义了移动底盘kobuki的启动，包含imu，odom等传感器。

### 3. 启动激光雷达
```js
<node name="hokuyo" pkg="urg_node" type="urg_node">
      <param name="port" type="string" value="/dev/ttyACM0"/>
      <param name="frame_id" value="base_laser_link" />
</node>
```

### 4.  Cartographer相关节点
```js
<node name="cartographer_node" pkg="cartographer_ros"
      type="cartographer_node" args="
          -configuration_directory
              $(find cartographer_turtlebot)/configuration_files
          -configuration_basename turtlebot_hokuyo_2d.lua"
      output="screen">
    <remap from="scan" to="/scan" />
</node>

  <node name="flat_world_imu_node" pkg="cartographer_turtlebot"
      type="cartographer_flat_world_imu_node" output="screen">
    <remap from="imu_in" to="/mobile_base/sensors/imu_data_raw" />
    <remap from="imu_out" to="/imu" />
  </node>

  <node name="cartographer_occupancy_grid_node" pkg="cartographer_ros"
      type="cartographer_occupancy_grid_node" args="-resolution 0.05" />
```
### 5. 启动rivz
```js
  <node name="rviz" pkg="rviz" type="rviz" required="true"
      args="-d $(find cartographer_turtlebot
          )/configuration_files/demo.rviz" />
```
## lua文件配置
lua文件包含了Cartographer在ROS中的一些高层参数选项，附上[demo.lua](demo.lua)作为参考。
每个参数的定义请转至[Cartographer_ROS/Configuration](https://google-cartographer-ros.readthedocs.io/en/latest/configuration.html)。

## rviz文件配置
正如前面提到的，rviz文件可以后续手动添加，可以事先定义，附上[demo.rviz](demo.rivz)。

## 编译
```js
catkin_make_isolated --install –use-ninja
source install_isolated/setup.bash
```
可将`source install_isolated/setup.bash`写入`.bashrc`,之后再打开新终端时，就自动加载环境变量路径。
```js
echo “source install_isolated/setup.bash” --> ~/.bashrc
```
## 声明环境变量
将以下内容写入.bashrc文件。
```js
export TURTLEBOT_BASE=kobuki
export TURTLEBOT_STACKS=hexagons
export TURTLEBOT_3D_SENSOR=hokuyo
```

## Run It Up
完成这些配置后，就可以正式开始SLAM了。
在一个终端下，输入
```js
roscore
```
然后，打开一个新终端
```js
roslaunch cartographer_turtlebot demo.launch
```
这里，我的demo.launch文件是放在: `catkin_ws/src/cartographer_turtlebot/cartographer_turtlebot/launch/`目录下。

OK，如果配置没有问题的话，rviz界面应该是正常启动，你可以清楚地看到建图的情况了。

第一次尝试启动时，难免会碰到很多问题，大都是因为配置不正确。有些配置细节我没有放在这篇文档里，有待大家自行摸索哈，尤其是配置launch文件里的hokuyo.urdf，这部分可以模仿着Kinect.urdf的配置过程，然后仔细阅读robot.launch.xml，description.launch.xml等文件，这里需要做一些细微修改。


现在，相信你已经对Cartographer_ROS的工作流程非常清楚了吧。如有任何疑问，欢迎在评论区中交流哈～PS：我的评论区采用的是DISQUS，很多时间会被墙，造成无法显示。建议喜欢折腾的朋友，还是买个VPS服务吧:)









