#! /bin/bash
:<<EOF
 *  $Id: usersoftwareconf.sh, 2014-02-15 23:11:54 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 24/10/2013
 *  Note:
 *    User Special Tools
EOF

# path
userTool=$HOME/software

#+  DMPSW (DAMPE software)
#source $HOME/main/DmpSW/svn/trunk/thisdmpsw.sh
pushd $HOME/tmp/DmpInstall >/dev/null 2>&1
source ./bin/thisdmpsw.sh
popd >/dev/null 2>&1

#+  Set OpenMP
if [ !1 ];then


fi

unset userTool

