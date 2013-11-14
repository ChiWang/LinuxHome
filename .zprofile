
#=======================================#
#       User Special Setting            #
#=======================================#

#+  author information
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

#+ set user tools
source $HOME/Tools/SoftwareSetup.sh

