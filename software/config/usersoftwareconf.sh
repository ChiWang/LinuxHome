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

#+  DMPSW (DAMPE software)
#source $HOME/main/DmpSW/svn/trunk/thisdmpsw.sh
#source $HOME/tmp/DmpInstall/bin/thisdmpsw.sh >&/dev/null
source /exports/DMPSW/bin/thisdmpsw.sh

#+  Set OpenMP
if [ !1 ];then
fi

#unset userTool

