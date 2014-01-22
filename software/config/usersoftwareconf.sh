#=====================================================================
#   File:   usersoftwareconf.sh
#   Author: Chi WANG  (chiwang@mail.ustc.edu.cn)    24/10/2013
#---------------------------------------------------------------------
#   Description:
#
#       User Special Tools
#       
#   just source me.
#---------------------------------------------------------------------
#   History:
#                           Last update:  06/01/2014   23:27:55
#=====================================================================

# path
userTool=$HOME/software

#+  DMPSW (DAMPE software)
#source $HOME/main/DmpSW/svn/trunk/thisdmpsw.sh
pushd $HOME/tmp/DmpInstall >/dev/null 2>&1
source ./bin/thisdmpos.sh
popd


#+  Set OpenMP
if [ !1 ];then


fi

unset userTool

