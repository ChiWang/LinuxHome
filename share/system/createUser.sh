#=====================================================================
#   File:   createUser.sh
#   Author: Chi WANG  (chiwang@mail.ustc.edu.cn)    27/11/2013
#---------------------------------------------------------------------
#   Description:
#
#---------------------------------------------------------------------
#   History:
#                           Last update:  13/12/2013   14:26:03
#=====================================================================

#! /bin/bash
#   call users.list

for name in `more userName.list`;do
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

