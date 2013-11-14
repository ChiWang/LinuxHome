
#=======================================#
#       User Special Tools              #
#=======================================#

##  set path
ToolPath=/home/chi/Tools

#+  git
GIT_VERSION="1.8.4"         # which version you want to use
if [[ `git --version 2>/dev/null | grep "GIT_VERSION"` == "" ]];then
    source $HOME/share/login/git-completion.zsh
    GITSYS=$ToolPath/git_v$GIT_VERSION
    export PATH=$GITSYS/bin:$PATH
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$GITSYS/lib:$GITSYS/lib64
fi

#+  DMPSW (DAMPE software)
source $HOME/tmp/trunk/thisdmpsw.sh
source $HOME/main/workDir/DmpSoftware/thisdmpsw.sh

#+  Set OpenMP
if [ !1 ];then


fi

#+  unset path
unset ToolPath
