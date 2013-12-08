
#! /bin/bash

yum install -y zsh yum-fastestmirror
yum install -y expat-devel
yum install  -y xorg-x11-fonts-ISO8859-1-75dpi
yum -y update
bash requirments_root.sh
yum clean all
