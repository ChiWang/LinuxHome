#=============================================================================
#       FileName :          createUser.sh
#       Version  :          0.0.1
#       Author   :          Chi WANG    (chiwang@mail.ustc.edu.cn)
#       Time     :          2013-11-27   14:08:51
#------------------------------------------------------------------------------
#       Description  :
#
#------------------------------------------------------------------------------
#       History  :
#                                          Update:  2013-11-27   14:08:51
#=============================================================================

#! /bin/bash
#   call users.list

for name in `more userName.list`;do
  if [ "XX`ls /home | grep "$name"`" = "XX" ];then
    echo "  **  add user:       $name"
    useradd -m $name
    chmod a+rx /home/$name
    echo $name"123" | passwd --stdin $name
  else
    echo "  $name   is existed"
  fi
done

