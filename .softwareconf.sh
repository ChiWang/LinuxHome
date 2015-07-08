#! /bin/bash
:<<EOF
 *  $Id: usersoftwareconf.sh, 2015-07-08 16:12:36 DAMPE $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 24/10/2013
 *  Note:
 *    User Special Tools
EOF

# path
#userTool=$HOME/software

#+ SVN
export SVN_EDITOR=vim

#+ SCons -Q
export SCONSFLAGS="-Q"
export NUM_CPU=`more /proc/cpuinfo| grep "processor" | wc -l`

#+ Python
export PYTHONSTARTUP='.pythonconf.py'

# history
#+ number of lines kept in history
export HISTSIZE=10000
#+ number of lines saved in the history after logout
export SAVEHIST=10000

set bell-style none

export ZLSCOLORS="${LS_COLORS}"

#+  Set OpenMP

#unset userTool

