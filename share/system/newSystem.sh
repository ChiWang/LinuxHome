#! /bin/bash
:<<EOF
 *  $Id: newSystem.sh, 2014-02-15 23:08:18 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 14/10/2013
EOF


yum install -y zsh yum-fastestmirror
yum install -y expat-devel
yum install  -y xorg-x11-fonts-ISO8859-1-75dpi
yum install -y colordiff
yum -y update
bash requirments_root.sh
yum clean all
