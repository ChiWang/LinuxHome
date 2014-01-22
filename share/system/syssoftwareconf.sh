#=====================================================================
#   File:   syssoftwareconf.sh
#   Author: Chi WANG  (chiwang@mail.ustc.edu.cn)    13/10/2013
#---------------------------------------------------------------------
#   Description:
#
#       Set common tools for all users
#   Set $ToolPath in /etc/profile
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

#+ Python
export PYTHONSTARTUP=$ToolPath/config/pythonconf.py

#+ root         
pushd $ToolPath/root_v5.34 >/dev/null 2>&1
source ./bin/thisroot.sh
popd >/dev/null
   
#+ geant4
pushd $ToolPath/geant4_v4.9.6/share/Geant4*/geant4make >/dev/null 2>&1
source geant4make.sh
popd >/dev/null

#+ CLHEP
export PATH="$ToolPath/clhep_v2.1.4.1/bin":$PATH
export LD_LIBRARY_PATH="$ToolPath/clhep_v2.1.4.1/lib":$LD_LIBRARY_PATH

unset ToolPath
