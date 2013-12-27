#! /bin/bash

yum install -y Xaw3d Xaw3d-devel imake ghostscript

# wget ftp://ftpthep.physik.uni-mainz.de/pub/gv/unix/gv-3.5.8.tar.gz
#   tar -xzvf xxx.tar.gz
#   into source dirctory
#   vim path.h

#--------------------------------- if get error of "INC_X11" etc while make
#   #ifdef VMS

#   define INC_X11(aaa) <X11/aaa>
#   define INC_XMU(aaa) <X11/Xmu/aaa>
#   define INC_XAW(aaa) <X11/Xaw3d/aaa>
#//#   define INC_X11(aaa) <X11/##aaa##>
#//#   define INC_XMU(aaa) <X11/Xmu/##aaa##>
#//#   define INC_XAW(aaa) <X11/Xaw3d/##aaa##>

#   #endif
