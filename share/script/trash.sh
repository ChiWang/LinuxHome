#! /bin/bash
#=============================================================================
#       FileName :          trash.sh
#       Version  :          0.0.1
#       Author   :          Chi Wang    (chiwang@mail.ustc.edu.cn)
#       Time     :          2013-10-02   17:35:39
#------------------------------------------------------------------------------
#       Description  :
#           Goal:
#               rm file into a trash(default is $HOME/.Trash)
#           Installation:
#               1. add alias into .zshrc(or .bashrc)
#                   alias rm='bash /PathToThisFile/trash.sh'
#               2. source .*rc file
#
#------------------------------------------------------------------------------
#       History  :
#                                          Update:  2013-10-02   17:50:14
#=============================================================================

# set trash path
trashPath="$HOME/.Trash"

# move into trash
name=`date "+%y-%m-%d-%H_%M"`
mkdir -p $trashPath/$name

while [ $# != 0 ];do
	mv $1 $trashPath/$name
	shift
done


