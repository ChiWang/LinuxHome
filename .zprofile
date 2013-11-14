
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
#+

#+ SVN
if [ ! $SVN_EDITOR ];then
    export SVN_EDITOR=vim
fi
#+

#+ Scons -Q
if [ ! $SCONSFLAGS ];then
    export SCONSFLAGS="-Q"
    export NUM_CPU=`more /proc/cpuinfo| grep "processor" | wc -l`
fi
#

##+  Git
GIT_VERSION="1.8.4"         # which version you want to use
if [[ `git --version 2>/dev/null | grep "GIT_VERSION"` == "" ]];then
    source $HOME/share/login/git-completion.zsh
    GITSYS=$HOME/Tools/git_v$GIT_VERSION
    export PATH=$GITSYS/bin:$PATH
    export LD_LIBRARY_PATH=$GITSYS/lib:$GITSYS/lib64:$LD_LIBRARY_PATH
fi
#+


#-----------------------------------    User special software

#+  Set DAMPE software environment
source $HOME/tmp/trunk/thisdmpsw.sh
source $HOME/main/workDir/DmpSoftware/thisdmpsw.sh

#+  Set OpenMP
if [ !1 ];then


fi
#+

