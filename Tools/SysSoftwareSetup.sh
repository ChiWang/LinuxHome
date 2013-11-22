# Common tools for all users
# Created by Chi WANG (chiwang@mail.ustc.edu.cn)
                         
#+ SVN
export SVN_EDITOR=vim

#+ Scons -Q
export SCONSFLAGS="-Q"
export NUM_CPU=`more /proc/cpuinfo| grep "processor" | wc -l`

#+ root         
cd /usr/local/Tools/root_v5.34 > /dev/null 2>&1
source ./bin/thisroot.sh                            
cd - >/dev/null         
   
#+ geant4
#cd /usr/local/Tools/geant4_v9.6/share/Geant4*/geant4make >/dev/null 2>&1
#source geant4make.sh
#cd - >/dev/null                   
                         
cd $HOME

