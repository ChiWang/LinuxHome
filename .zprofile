#=====================================================================
#   File:   .zprofile
#   Author: Chi WANG  (chiwang@mail.ustc.edu.cn)    13/12/2013
#---------------------------------------------------------------------
#   Description:
#       
#       User Special Setting
#
#---------------------------------------------------------------------
#   History:
#                           Last update:  13/12/2013   14:11:18
#=====================================================================

#+  author information  // will be used in ~/.vim/plugin/authorinfor.vim
export AUTHOR="Chi WANG"
export AUTHOREMAIL="chiwang@mail.ustc.edu.cn"

#+  set vim back path. Add 3 lines in ~/.vimrc
#   set backup
#   set backupext=.back
#   set backupdir=$VIMBACKDIR
if [ ! $VIMBACKDIR ];then
    export VIMBACKDIR="$HOME/.vimback"
    if [ ! -d $VIMBACKDIR ];then
        mkdir $VIMBACKDIR
    fi
fi

#+ Trash    // will be used in ~/bin/del
if [ !$TRASH ];then
    export TRASH="$HOME/.Trash"
fi

#+ set user tools
source $HOME/software/SoftwareSetup.sh

