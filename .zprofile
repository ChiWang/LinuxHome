
#=======================================#
#       User Special Setting            #
#=======================================#

#+ user functions
if [ -d ~/share/function ];then
	for funfile in `ls ~/share/function`;do
		#source "~/share/function/"$funfile
	done
	unset funfile
else
	mkdir -p ~/share/function 
fi
#+

#+ Trash
if [ ! -d ~/.Trash ];then
  mkdir ~/.Trash
fi
#

#+ vim back
if [ ! -d ~/tmp/vimback ];then
    mkdir -p ~/tmp/vimback
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


#-----------------------------------    User special software

#+  Root
ROOT_VERSION="5.34"         # which version you want to use
if [[ `root-config --version 2>/dev/null | grep "${ROOT_VERSION}"` == "" ]];then
    source $HOME/Tools/SetupEnv/rootEnv.sh
fi
#+

#+  Geant4
GEANT4_VERSION="9.6"         # which version you want to use
if [[ `geant4-config --version 2>/dev/null | grep "${GEANT4_VERSION}"` == "" ]];then
    source $HOME/Tools/SetupEnv/geant4Env.sh
fi
#+

#+  Git
#GIT_VERSION="1.8.4"         # which version you want to use
if [[ `git --version 2>/dev/null | grep "git"` == "" ]];then
    source $HOME/Tools/SetupEnv/gitEnv.sh
fi
#+

#+  Set DAMPE software environment
if [ ! $DMPSWSYS ];then
    export DMPSWSYS="$HOME/Tools/dmpsw_v0.1/trunk"
    export PATH=$DMPSWSYS/Install/bin:$PATH
    export LD_LIBRARY_PATH=$DMPSWSYS/Install/lib:$LD_LIBRARY_PATH
fi
#+

#+  Set OpenMP
if [ !1 ];then


fi
#+


