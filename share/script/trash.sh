#! /bin/bash
#=============================================================================
#       FileName :          trash.sh
#       Version  :          0.0.1
#       Author   :          Chi WANG    (chiwang@mail.ustc.edu.cn)
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

# move into trash
name=`date "+%y-%m-%d-%H_%M"`
mkdir -p $TRASH/$name

while [ $# != 0 ];do
	mv $1 $TRASH/$name
	shift
done


