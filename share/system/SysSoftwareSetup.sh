# Common tools for all users
# Created by Chi WANG (chiwang@mail.ustc.edu.cn)
                         
#+ SVN
export SVN_EDITOR=vim

#+ SCons -Q
export SCONSFLAGS="-Q"
export NUM_CPU=`more /proc/cpuinfo| grep "processor" | wc -l`

#+ root         
cd /usr/local/software/root_v5.34 > /dev/null 2>&1
source ./bin/thisroot.sh
cd - >/dev/null
   
#+ geant4
cd /usr/local/software/geant4_v4.9.6/share/Geant4*/geant4make >/dev/null 2>&1
source geant4make.sh
cd - >/dev/null                   
                         
cd $HOME

