#=====================================================================
#   File:   SoftwareSetup.sh
#   Author: Chi WANG  (chiwang@mail.ustc.edu.cn)    13/12/2013
#---------------------------------------------------------------------
#   Description:
#
#       Set common tools for all users
#
#   link this file in $ToolPath(set in /etc/profile), and source it in /etc/profile
#
#---------------------------------------------------------------------
#   History:
#                           Last update:  13/12/2013   14:26:54
#=====================================================================

#+ SVN
export SVN_EDITOR=vim

#+ SCons -Q
export SCONSFLAGS="-Q"
export NUM_CPU=`more /proc/cpuinfo| grep "processor" | wc -l`

#+ root         
pushd $ToolPath/root_v5.34 > /dev/null 2>&1
source ./bin/thisroot.sh
popd >/dev/null
   
#+ geant4
pushd $ToolPath/geant4_v4.9.6/share/Geant4*/geant4make >/dev/null 2>&1
source geant4make.sh
popd >/dev/null                   

unset ToolPath


