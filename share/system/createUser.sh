#! /bin/bash
:<<EOF
 *  $Id: createUser.sh, 2014-02-15 23:07:34 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 27/11/2013
EOF

for name in $@;do
  if [ "XX`ls /home | grep "$name"`" = "XX" ];then
    echo "  **  add user:       $name"
    useradd -m $name
    chmod a+rx /home/$name
    echo $name"123" | passwd --stdin $name
    tmpDir=/tmp/$name
    mkdir $tmpDir
    chmod a+rx $tmpDir
    chown -hR   $tmpDir $tmpDir
    chgrp -hR   $tmpDir $tmpDir
    ln -s $tmpDir /home/$name/tmp
  else
    echo "  $name   is existed"
  fi
done

