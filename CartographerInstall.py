#!/usr/bin/python
# -*- coding: utf-8 -*-
import os
import sys
if not os.geteuid() == 0:
    sys.exit("""\033[1;91m\n[!] ROS installer must be run as root.\n\033[0m""")

print("""\033[1;36m
┌══════════════════════════════════════════════════════════════┐
|                                                              |
|                  Cartographer Installer                      |
|                                                              |
└══════════════════════════════════════════════════════════════┘     \033[0m""")
def install():
    def ModifyCerePath(path):
        f=file(path,"r").readlines()
        lines=list()
        for eachline in f:
            lines.append(eachline.replace("https://ceres-solver.googlesource.com/ceres-solver.git","https://github.com/ceres-solver/ceres-solver.git"))
        f=file(path,"w")
        for eachline in lines:
            f.write(eachline)
        f.close()
    path = raw_input("\033[1;32m请输入您的Cartographer安装绝对路径(空文件夹)\033[0m>>")
    try:
        os.chdir(path)
    except:
        print("\033[1;34m路径出错\033[0m")
        install()
        return
    os.system("apt-get update")
    print("\033[1;34m其他包安装中...\033[0m")
    os.system("apt-get install -y python-wstool python-rosdep ninja-build git liblua5.2-dev oogle-mock libboost-all-dev  libeigen3-dev libgflags-dev libgoogle-glog-dev libprotobuf-dev  libsuitesparse-dev libwebp-dev protobuf-compiler python-sphinx  ros-kinetic-tf2-eigen libatlas-base-dev libsuitesparse-dev liblapack-dev libgflags-dev google-mock libgoogle-glog-dev libatlas-base-dev libsuitesparse-dev ")
    print("\033[1;34m库安装完毕\033[0m")
    # 安装ceres
    print("\033[1;34m安装ceres...\033[0m")
    os.chdir(path)
    os.system("git clone https://github.com/hitcm/ceres-solver-1.11.0.git")
    os.system("mkdir ceres-solver-1.11.0/build")
    os.chdir("ceres-solver-1.11.0/build")
    os.system("cmake .. && make -j && make install")
    # 安装cartographer
    print("\033[1;34m安装cartographer...\033[0m")
    os.chdir(path)
    os.system("git clone https://github.com/hitcm/cartographer.git")
    os.system("mkdir cartographer/build")
    os.chdir("cartographer/build")
    try:
        os.system("cmake .. -G Ninja")
        os.system("ninja")
        os.system("ninja test")
        os.system("ninja install")
    except:
        os.system("cmake .. && make && make install")
    # 安装cartographer_ros
    print("\033[1;34m安装cartographer_ros...\033[0m")
    os.chdir(path)
    os.system("mkdir src")
    os.chdir("src")
    os.system("git clone https://github.com/hitcm/cartographer_ros.git")
    os.chdir("..")
    os.system("catkin_make")
    os.system("source devel/setup.bash")
    os.system("rospack profile")


    print("\033[1;34m安装完毕\033[0m")
    comm=raw_input("\033[1;32m是否安装测试包？\033[0m>>yes/no:")
    if comm=="yes":
        path2 = raw_input("\033[1;32m请输入您的数据存放绝对路径(空文件夹)\033[0m>>")
        try:
            os.chdir(path2)
        except:
            print("\033[1;34m路径出错\033[0m")
            return
        os.system("wget https://storage.googleapis.com/cartographer-public-data/bags/backpack_2d/cartographer_paper_deutsches_museum.bag")
        print("请输入\n\033[1;33mroslaunch cartographer_ros demo_backpack_2d.launch bag_filename:="+path1+"/cartographer_paper_deutsches_museum.bag\033[0m\n开始测试")
        return
    print("\033[1;34m结束\033[0m")
install()
