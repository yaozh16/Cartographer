#!/usr/bin/python
# -*- coding: utf-8 -*-
import os
import sys
if not os.geteuid() == 0:
    sys.exit("""\033[1;91m\n[!] ROS installer must be run as root.\n\033[0m""")

print("""\033[1;36m
┌══════════════════════════════════════════════════════════════┐
█                                                              █
█                        ROS Installer                         █
█                                                              █
└══════════════════════════════════════════════════════════════┘     \033[0m""")

def install():
    def InstallToUbuntu():
        print("\033[1;34m\nROS Kinetic支持的Ubuntu版本：\nXenial\t: amd64 i386 armhf\nWily\t:amd64 i386\n\033[0m")
        system0 = raw_input("\033[1;34m是否需要继续安装 ROS?\033[0m yes/no>>")
        if system0 == "yes":
            print("\033[1;34m\nReady To Install ROS...\033[0m")
            os.system("sh -c 'echo \"deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main\" > /etc/apt/sources.list.d/ros-latest.list'")
            os.system("apt-key adv --keyserver hkp://ha.pool.sks-keyservers.net:80 --recv-key 421C365BD9FF1F717815A3895523BAEEB01FA116")
            os.system("apt-get update")
            os.system("apt-get install -y ros-kinetic-desktop-full")
            os.system("rosdep init")
            os.system("rosdep update")
            comm=raw_input("\033[1;34m\n是否需要为您配置系统全局环境变量?\033[0m yes/no>>")
            if comm== "yes":
                os.system("echo \"source /opt/ros/kinetic/setup.bash\" >> ~/.bashrc")
            comm=raw_input("\033[1;34m\n是否需要为您安装配软件包?\033[0m\n\033[1;32mpython-rosinstall python-rosinstall-generator python-wstool build-essential\n\033[0myes/no>>")
            if comm== "yes":
                os.system("apt-get install -y python-rosinstall python-rosinstall-generator python-wstool build-essential")
            print("\033[1;34m\nROS安装完毕\033[0m")
        elif system0=="no":
            print("\033[1;34m退出...\033[0m")
            install()
        else:
            print("\033[1;34m\n请回答 yes 或 no\n\033[0m")
            installToUbuntu()
    def InstallToDebian():
        print("\033[1;34m\nROS Kinetic支持Debian版本：\nJessie\t: amd64 arm64\n\033[0m")
        system0 = raw_input("\033[1;34m是否需要继续安装 ROS?\033[0m yes/no>>")
        if system0 == "yes":
            print("\033[1;37;41m请手动许可apt-get的contrib与non-free\033[0m\n")
            comm=raw_input("继续>>")
            os.system("apt-get update")
            os.system("apt-cache search -n dirmngr")
            os.system("apt-get install -y dirmngr")
            os.system("sudo sh -c 'echo \"deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main\" > /etc/apt/sources.list.d/ros-latest.list'")
            os.system("sudo apt-key adv --keyserver hkp://ha.pool.sks-keyservers.net:80 --recv-key 421C365BD9FF1F717815A3895523BAEEB01FA116")
            os.system("apt-get update")
            os.system("apt-cache search ros-kinetic")
            os.system("apt-get update")
            os.system("apt-get install -y ros-kinetic-desktop-full")
            os.system("rosdep init")
            os.system("rosdep update")
            comm=raw_input("\033[1;34m\n是否需要为您配置系统全局环境变量?\033[0m yes/no>>")
            if comm== "yes":
                os.system("echo \"source /opt/ros/kinetic/setup.bash\" >> ~/.bashrc")
            comm=raw_input("\033[1;34m\n是否需要为您安装配软件包?\033[0m\n\033[1;32mpython-rosinstall python-rosinstall-generator python-wstool build-essential\n\033[0myes/no>>")
            if comm== "yes":
                os.system("apt-get install -y python-rosinstall python-rosinstall-generator python-wstool build-essential")
            print("\033[1;34m\nROS安装完毕\033[0m")
        elif system0=="no":
            print("\033[1;34m退出...\033[0m")
            install()
        else:
            print("\033[1;34m\n请回答 yes 或 no\n\033[0m")
            InstallToDebian()
        pass
    def InstallToRaspbian():
        print("Not Finished Code Here. Sorry! XD")
        install()
        pass
        system0=raw_input("\033[1;34m请输入您的Raspbian版本\033[0mWheezy/Jessie>>")
        if system0=="Wheezy":
            pass
        elif system0=="Jessie":
            path = raw_input("\033[1;34m请输入您的ROS安装绝对路径\033[0mWheezy/Jessie>>")
            try:
                os.chdir(path)
            except:
                print("\033[1;34m路径出错\033[0m")
                pass
            os.system("sudo sh -c 'echo \"deb http://packages.ros.org/ros/ubuntu jessie main\" > /etc/apt/sources.list.d/ros-latest.list'")
            os.system("wget https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -O - | sudo apt-key add -")
            os.system("apt-get update")
            os.system("apt-get sudo apt-get upgrade")
            os.system("sudo apt-get install -y python-pip python-setuptools python-yaml python-distribute python-docutils python-dateutil python-six")
            os.system("pip install rosdep rosinstall_generator wstool rosinstall")
            os.system("rosdep init")
            os.system("rosdep update")
            os.system("rosinstall_generator ros_comm --rosdistro indigo --deps --wet-only --exclude roslisp --tar > indigo-ros_comm-wet.rosinstall")
            try:
                os.system("wstool init src indigo-ros_comm-wet.rosinstall")
            except:
                os.system("wstool update -t src")
            pass
        else:
            install()
    print("""\033[1;32m\n
┌————————————————┐
    1.Ubuntu
    2.Debian
    3.Raspbian
└————————————————┘
    \033[0m""")
    system0=raw_input("\033[1;34m请输入您的操作系统(其他任意输入可退出)\033[0m>>")
    if system0=="1" or system0=="Ubuntu":
        InstallToUbuntu()
    elif system0=="2" or system0=="Debian":
        InstallToDebian()
    elif system0=="3" or system0=="Raspbian":
        InstallToRaspbian()
install()
