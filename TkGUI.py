#!/usr/bin/python
# -*- coding: utf-8 -*-

from Tkinter import *
from time import  *
import os
import re

import threading

class CartoGUI(object):
    def __init__(self):
        self.root= Tk()
        def init_ToolBar():
            self.frm_toolBar= Frame()
            self.bttn_roscore =  Button(self.frm_toolBar,  width=30,  text="roscore",command=self.roscore)
            self.bttn_roslaunch =  Button(self.frm_toolBar,width=30, text="roslaunch",command=self.roslaunch)
            self.bttn_rosmapSaver =  Button(self.frm_toolBar,width=30, text="rosmapSaver",command=self.rosmapSaver)
            self.bttn_roscore.pack(side= LEFT)
            self.bttn_roslaunch.pack(side= LEFT)
            self.bttn_rosmapSaver.pack(side= LEFT)
            self.frm_toolBar.pack()
        init_ToolBar()

        def init_Entry():
            def add_Entry(rank,labelText,initEntry,buttonCommand):
                self.frm_entry.append( Frame(self.root))
                self.labels.append((( Label(self.frm_entry[rank],width=20, text=labelText)),rank))
                self.entry_texts.append(StringVar(self.root))
                self.entry_texts[rank].set(initEntry)
                self.entries.append( Entry(self.frm_entry[rank],width=65,textvariable=self.entry_texts[rank]))
                self.buttons.append( Button(self.frm_entry[rank],width=10 , text="select",command=buttonCommand))
                self.labels[rank][0].pack(side= LEFT)
                self.entries[rank].pack(side= LEFT)
                self.buttons[rank].pack(side= LEFT)
                self.frm_entry[rank].pack()
            self.frm_entry=list()
            self.labels=list()
            self.entry_texts=list()
            self.entries=list()
            self.buttons=list()
            add_Entry(0,"catkin work space","/home/yaozh16/Project/ROS/catkin_ws",lambda:self.setPath(0))
            add_Entry(1,"bag","/home/yaozh16/Project/ROS/data/cartographer_paper_deutsches_museum.bag",lambda:self.setPath(1))
            add_Entry(2,"package","cartographer_ros",lambda:self.setPackage(2))
            add_Entry(3,"launch file","demo_backpack_2d.launch",lambda:self.setPath(3))
            add_Entry(4,"map save directory",os.getcwd(),lambda:self.setPath(4))
        init_Entry()

        self.infotext=StringVar(self.root)
        self.info=Label(self.root,textvariable=self.infotext,fg="white",wraplength=800,width=80,justify="left")
        self.info.pack()
    def __del__(self):
        os.system("ps aux|grep ros|awk '{print $2}'|xargs kill -9")
    def setPackage(self,n):
        PkgDlg(self.entry_texts[n])
        pass
    def setPath(self,n):
        FDlg(self.entry_texts[n])
    def setMessage(self,msg,color="black"):
        self.infotext.set(msg)
        self.info.config(fg=color)
        self.root.update()
    def runCommandBackground(self, command):
        if not os.path.exists(self.entry_texts[0].get()+"/install_isolated/setup.sh"):
            self.setMessage("catkin workspace error or cartographer not installed","red")
            return
        def threadCommand():
            try:
                os.system("echo '#!/bin/bash'> _virtShell_.sh")
                os.system("echo 'source /opt/ros/kinetic/setup.bash'>> _virtShell_.sh")
                os.system("echo 'source "+self.entry_texts[0].get()+"/install_isolated/setup.sh'>> _virtShell_.sh")
                os.system("echo "+command+">>_virtShell_.sh")
                os.system("chmod a+x ./_virtShell_.sh")
                os.system("./_virtShell_.sh &")
            except:
                print "Error:catkin work space error or cartographer not installed successfully"
                self.setMessage("error:"+command,"red")
        NewT=threading.Thread(target=threadCommand())
        self.setMessage("run command:"+command,"green")
        NewT.start()
    # start up roscore
    def roscore(self):
        self.runCommandBackground("roscore")
    # roslaunch the script
    def roslaunch(self,command=None):
        global roslaunch_command
        if(command!=None):
            roslaunch_command=command
        else:
            roslaunch_command='roslaunch '+self.entry_texts[2].get()+" "+self.entry_texts[3].get()+' bag_filename:='+self.entry_texts[1].get()
        self.runCommandBackground(roslaunch_command)
    # save the map
    def rosmapSaver(self):
        dir=self.entry_texts[4].get()
        if not os.path.isdir(dir):
            # not a directory
            return
        c=0
        while True:
            if(os.path.exists(os.path.join(dir,str(c)+".pgm")) or os.path.exists(os.path.join(dir,str(c)+".yaml"))):
                c+=1
                continue
            else:
                break

        threading.Thread(target=self.runCommandBackground("rosrun map_server map_saver -f " + os.path.join(self.entry_texts[4].get(), str(c)))).start()
    # start the GUI
    def start(self):
        self.root.mainloop()
class FDlg(object):
    def __init__(self,text):
        self.text=text
        self.finished=False
        self.subroot= Tk()
        self.label= Label(self.subroot, text="File")
        self.label.pack()
        self.cwd= StringVar(self.subroot)

        self.dirl=Label(self.subroot, fg="blue", font=("Helvetica", 12, 'bold'))
        self.dirl.pack()

        # 列表
        self.dirfm=Frame(self.subroot)
        self.dirsb=Scrollbar(self.dirfm)
        self.dirsb.pack(side=RIGHT,fill=Y)
        self.dirs=Listbox(self.dirfm,height=15,width=50,yscrollcommand=self.dirsb.set)
        self.dirs.bind('<Double-1>',self.setDirAndGo)
        self.dirs.bind('<<ListboxSelect>>',self.setClickRet)
        self.dirsb.config(command=self.dirs.yview)
        self.dirs.pack(side=LEFT,fill=BOTH)
        self.dirfm.pack()

        # 输入框
        self.dirn= Entry(self.subroot, width=50, textvariable=self.cwd)
        self.dirn.bind('<Return>',self.doLS)
        self.dirn.pack()

        self.bfm=Frame(self.subroot)
        self.clr=Button(self.bfm,text="Clear",command=self.clrDir,activeforeground="white",activebackground="blue")
        self.ls=Button(self.bfm,text="List Directory",command=self.doLS,activeforeground="white",activebackground="green")
        self.quit=Button(self.bfm, text="Confirm", command=self.finish, activeforeground="white", activebackground="red")
        self.clr.pack(side=LEFT)
        self.ls.pack(side=LEFT)
        self.quit.pack(side=LEFT)
        self.bfm.pack()
        initDir=self.text.get()
        if initDir and not os.path.isdir(initDir):
            initDir=os.getcwd()
        self.cwd.set(initDir)
        self.doLS()
        self.finalRet=os.getcwd()
        self.cwd.set(self.finalRet)
        self.text.set(self.finalRet)
        self.subroot.update()
    def setClickRet(self,ev=None):
        if self.dirs.curselection()==():
            return
        tdir=self.dirs.get(self.dirs.curselection())
        if(os.path.isdir(tdir)):
            self.finalRet=os.path.join(os.getcwd(),tdir)
            self.cwd.set(self.finalRet)
            self.text.set(self.finalRet)
            self.subroot.update()
    def finish(self,ev=None):
        self.subroot.destroy()
        self.finished=True
    def clrDir(self,ev=None):
        self.cwd.set('')
        self.finalRet=None
        self.text.set('')
    def setDirAndGo(self,ev=None):
        self.last=self.cwd.get()
        self.dirs.config(selectbackground="red")
        check=None
        try:
            check=self.dirs.get(self.dirs.curselection())
        except:
            pass
        if not check:
            check= os.curdir
        self.cwd.set(check)
        self.text.set(check)
        self.doLS()
    def doLS(self,ev=None):
        error=''
        tdir=self.cwd.get()
        if not tdir:
            tdir=os.curdir

        if not os.path.exists(tdir):
            error=tdir+': no such file'
        elif not os.path.isdir(tdir):
            error = tdir + ': not a directory'

        if error:
            self.cwd.set(error)
            self.subroot.update()
            sleep(1)
            if not (hasattr(self,'last') and self.last):
                self.last=os.curdir
            self.cwd.set(self.last)
            self.dirs.config(selectbackground='LightSkyBlue')
            self.subroot.update()
            self.finalRet = None
            self.cwd.set(self.finalRet)
            self.subroot.update()
            return
        self.cwd.set('FETCHING DIRECTORY CONTENTS...')
        self.subroot.update()
        dirlist=os.listdir(tdir)
        dirlist.sort()
        os.chdir(tdir)

        self.finalRet=os.getcwd()
        self.cwd.set(self.finalRet)
        self.text.set(self.finalRet)
        self.subroot.update()


        self.dirl.config(text=os.getcwd())
        self.dirs.delete(0,END)
        self.dirs.insert(END,os.curdir)
        self.dirs.insert(END,os.pardir)
        for each in dirlist:
            self.dirs.insert(END,each)
        self.dirs.config(selectbackground="LightSkyBlue")
class PkgDlg(object):
    def __init__(self,text):
        os.system("echo '#!/bin/bash'> _virtShell_.sh")
        os.system("echo 'source /opt/ros/kinetic/setup.bash'>> _virtShell_.sh")
        os.system("echo 'source /home/yaozh16/Project/ROS/catkin_ws/install_isolated/setup.sh'>> _virtShell_.sh")
        os.system("echo rospack list>>_virtShell_.sh")
        os.system("chmod a+x ./_virtShell_.sh")
        tempkglist=os.popen("./_virtShell_.sh").readlines()
        self.pkglist = list()
        pa=re.compile("([\S])+ [\S]+")
        for each in tempkglist:
            self.pkglist.append(each.split(' ')[0])

        self.text=text

        self.subroot= Tk()
        self.label= Label(self.subroot, text="Package")
        self.label.pack()
        self.filter_pattern= StringVar(self.subroot)

        self.dirl=Label(self.subroot, fg="blue", font=("Helvetica", 12, 'bold'))
        self.dirl.pack()

        # 列表
        self.dirfm=Frame(self.subroot)
        self.dirsb=Scrollbar(self.dirfm)
        self.dirsb.pack(side=RIGHT,fill=Y)
        self.dirs=Listbox(self.dirfm,height=15,width=50,yscrollcommand=self.dirsb.set)
        self.dirs.bind('<Double-1>',self.finish)
        self.dirs.bind('<<ListboxSelect>>',self.setClickRet)
        self.dirsb.config(command=self.dirs.yview)
        self.dirs.pack(side=LEFT,fill=BOTH)
        self.dirfm.pack()

        # 输入框
        self.dirn= Entry(self.subroot, width=50, textvariable=self.filter_pattern)
        self.dirn.bind('<Key>',self.filter)
        self.dirn.pack()

        self.bfm=Frame(self.subroot)
        self.clr=Button(self.bfm,text="Clear",command=(lambda :{self.filter_pattern.set(''),self.filter()}),activeforeground="white",activebackground="blue")
        self.ls=Button(self.bfm,text="Filter",command=self.filter,activeforeground="white",activebackground="green")
        self.quit=Button(self.bfm, text="Confirm", command=self.finish, activeforeground="white", activebackground="red")
        self.clr.pack(side=LEFT)
        self.ls.pack(side=LEFT)
        self.quit.pack(side=LEFT)
        self.bfm.pack()
        initDir=self.text.get()
        self.filter_pattern.set(initDir)
        self.finalRet=initDir
        self.filter_pattern.set(self.finalRet)
        self.filter()
        self.text.set(self.finalRet)
        self.subroot.update()
    def setClickRet(self,ev=None):
        if self.dirs.curselection()==():
            return
        tpkg=self.dirs.get(self.dirs.curselection())
        if(self.pkglist.__contains__(tpkg)):
            self.finalRet=tpkg
            self.filter_pattern.set(self.finalRet)
            self.text.set(self.finalRet)
            self.subroot.update()
    def finish(self,ev=None):
        self.subroot.destroy()
        self.finished=True
    def filter(self,ev=None):
        print 1
        pattern=self.filter_pattern.get()
        self.dirs.delete(0, END)
        pa=re.compile(pattern)
        for each in  self.pkglist:
            if pa.search(each):
                self.dirs.insert(END, each)
        self.dirs.config(selectbackground="LightSkyBlue")
gui=CartoGUI()
gui.start()

