:<<EOF
 *  $Id: syssoftwareconf.sh, 2014-02-15 23:08:54 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 13/10/2013
 *  Note:
 *    Set common tools for all users
 *    Set $ToolPath in /etc/profile
 *    link this file in $ToolPath(set in /etc/profile), and source it in /etc/profile
EOF

 
#+ SVN
export SVN_EDITOR=vim

#+ SCons -Q
export SCONSFLAGS="-Q"
export NUM_CPU=`more /proc/cpuinfo| grep "processor" | wc -l`

#+ Python
export PYTHONSTARTUP=$ToolPath/config/pythonconf.py

#+ root         
pushd $ToolPath/root_v5.34 >&/dev/null
source ./bin/thisroot.sh
popd >&/dev/null
   
#+ geant4
pushd $ToolPath/geant4_v4.9.6/share/Geant4*/geant4make >&/dev/null
source geant4make.sh
popd >&/dev/null

#+ CLHEP
export PATH="$ToolPath/clhep_v2.1.4.1/bin":$PATH
export LD_LIBRARY_PATH="$ToolPath/clhep_v2.1.4.1/lib":$LD_LIBRARY_PATH

#+  DMPSW (DAMPE software)
pushd $ToolPath/DmpSW/bin >&/dev/null
source thisdmpsw.sh >&/dev/null
popd >&/dev/null

unset ToolPath
