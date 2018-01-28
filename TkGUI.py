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
        self.root=Tkinter.Tk()
        def init_ToolBar():
            self.frm_toolBar=Tkinter.Frame()
            self.bttn_roscore = Tkinter.Button(self.frm_toolBar,  width=30,  text="roscore",command=self.roscore)
            self.bttn_roslaunch = Tkinter.Button(self.frm_toolBar,width=30, text="roslaunch",command=self.roslaunch)
            self.bttn_rosmapSaver = Tkinter.Button(self.frm_toolBar,width=30, text="rosmapSaver",command=self.rosmapSaver)
            self.bttn_roscore.pack(side=Tkinter.LEFT)
            self.bttn_roslaunch.pack(side=Tkinter.LEFT)
            self.bttn_rosmapSaver.pack(side=Tkinter.LEFT)
            self.frm_toolBar.pack()
        init_ToolBar()

        def init_Entry():
            def add_Entry(rank,labelText):
                self.frm_entry.append(Tkinter.Frame(self.root))
                self.labels.append(((Tkinter.Label(self.frm_entry[rank],width=20, text=labelText)),rank))
                self.entries.append(Tkinter.Entry(self.frm_entry[rank],width=65))
                self.buttons.append(Tkinter.Button(self.frm_entry[rank],width=10 , text="select"))
                self.labels[rank][0].pack(side=Tkinter.LEFT)
                self.entries[rank].pack(side=Tkinter.LEFT)
                self.buttons[rank].pack(side=Tkinter.LEFT)
                self.frm_entry[rank].pack()
            self.frm_entry=list()
            self.labels=list()
            self.entries=list()
            self.buttons=list()
            add_Entry(0,"catkin work space")
            add_Entry(1,"bag")
            add_Entry(2,"3")
        init_Entry()
    def runCommand(self,command):
        def threadCommand():
            os.chdir("/home/yaozh16/Project/ROS/PyTk")
            os.system("echo '#!/bin/bash'> _virtShell_.sh")
            os.system("echo 'source /opt/ros/kinetic/setup.bash'>> _virtShell_.sh")
            os.system("echo 'source /home/yaozh16/Project/ROS/catkin_ws/install_isolated/setup.sh'>> _virtShell_.sh")
            os.system("echo "+command+">>_virtShell_.sh")
            os.system("chmod a+x ./_virtShell_.sh")
            os.system("./_virtShell_.sh &")
        NewT=threading.Thread(target=threadCommand())
        NewT.start()
    # start up roscore
    def roscore(self):
        self.runCommand("roscore")
    def roslaunch(self,command=None):
        global roslaunch_command
        if(command!=None):
            roslaunch_command=command
        else:
            # roslaunch_command='roslaunch cartographer_ros demo_backpack_2d.launch bag_filename:=/home/yaozh16/Project/ROS/data/cartographer_paper_deutsches_museum.bag'
            roslaunch_command='roslaunch cartographer_turtlebot turtlebot_urg_lidar_2d.launch'
        self.runCommand(roslaunch_command)
    def rosmapSaver(self):
        self.runCommand("rosrun map_server map_saver -f ~/Project/ROS/T")
        pass
    def start(self):
        self.root.mainloop()
    def config(self):
        pass
class FDS(object):
    def __init__(self):
        self.top=Tkinter.Tk()
        self.label=Tkinter.Label(self.top,text="File")
        self.label.pack()
        
gui=CartoGUI()
gui.start()
