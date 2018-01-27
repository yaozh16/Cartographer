#!/usr/bin/python
# -*- coding: utf-8 -*-

import Tkinter
import os
import sys

from PIL import Image,ImageTk
import virtShell
import threading
import multiprocessing
global PackageAbsolutePath

PackageAbsolutePath="/home/yaozh16/Project/ROS/catkin_ws/"



class CartoGUI(object):
    def __init__(self):
        def init_config():
            self.state_roscore=0
            self.state_display=0
            self.state_launch=None
        init_config()
        self.root=Tkinter.Tk()
        def init_ToolBar():
            self.frm_toolBar=Tkinter.Frame(self.root)
            self.bttn_roscore = Tkinter.Button(self.frm_toolBar,  width=20,  text="roscore",command=self.roscore)
            self.bttn_roslaunch = Tkinter.Button(self.frm_toolBar,width=20, text="roslaunch",command=self.roslaunch)
            self.bttn_rosmapSaver = Tkinter.Button(self.frm_toolBar,width=20, text="rosmapSaver",command=self.rosmapSaver)
            self.bttn_roscore.pack(side=Tkinter.LEFT)
            self.bttn_roslaunch.pack(side=Tkinter.LEFT)
            self.bttn_rosmapSaver.pack(side=Tkinter.LEFT)
            self.frm_toolBar.pack()
        init_ToolBar()
    def runCommand(self,command):
        def threadCommand():
            os.chdir("/home/yaozh16/Project/ROS/PyTk")
            os.system("echo '#!/bin/bash'> _virtShell_.sh")
            os.system("echo 'source /opt/ros/kinetic/setup.bash'>> _virtShell_.sh")
            os.system("echo 'source /home/yaozh16/Project/ROS/catkin_ws/install_isolated/setup.sh'>> _virtShell_.sh")
            os.system("echo "+command+">>_virtShell_.sh")
            os.system("chmod a+x ./_virtShell_.sh")
            os.system("./_virtShell_.sh")
        NewT=multiprocessing.Process(target=threadCommand())
        NewT.start()
    # start up roscore
    def roscore(self):
        self.state_roscore=1-self.state_roscore
        # self.runCommand("roscore")

    def roslaunch(self,command=None):
        global roslaunch_command
        if(command!=None):
            roslaunch_command=command
        else:
            # roslaunch_command='roslaunch cartographer_ros demo_backpack_2d.launch bag_filename:=/home/yaozh16/Project/ROS/data/cartographer_paper_deutsches_museum.bag'
            roslaunch_command='roslaunch cartographer_turtlebot turtlebot_urg_lidar_2d.launch'
        def display_Thread():
            global roslaunch_command
            os.chdir(PackageAbsolutePath)
            os.system("echo '#!/bin/bash'> __startup__.sh")
            os.system("echo 'cd /home/yaozh16/Project/ROS/catkin_ws'>>__startup__.sh")
            os.system("echo 'source install_isolated/setup.sh'>>__startup__.sh")
            os.system(
                "echo "+roslaunch_command+">>__startup__.sh")
            os.system("chmod a+x __startup__.sh")
            os.system("./__startup__.sh")

        self.display_thread = threading.Thread(target=display_Thread, name='DisplayThread')
        self.display_thread.setDaemon(True)
        if self.state_roscore==1:
            print "1"
            self.display_thread.start()
        else:
            print "2"

    def rosmapSaver(self):
        self.runCommand("rosrun map_server map_saver -f ~/Project/ROS/T")
        pass
    def start(self):
        self.root.mainloop()
    def config(self):
        pass

gui=CartoGUI()
gui.start()