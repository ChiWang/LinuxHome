#! /bin/bash
#=============================================================================
#       FileName :          makedir.sh
#       Version  :          0.0.1
#       Author   :          Chi Wang    (chiwang@mail.ustc.edu.cn)
#       Time     :          2013-10-02   17:31:29
#
#------------------------------------------------------------------------------
#       Description  :
#           Goal:
#               create a Readme.md file while creating a directory
#
#           Installation:
#               1. Add
#                       alias mkdir='bash /PathToThisFile/makedir.sh'
#                   into .zshrc(.bashrc)
#               2. then source .*rc file 
#------------------------------------------------------------------------------
#       History  :
#                                          Update:  2013-10-02   17:31:29
#=============================================================================

while [ $# != 0 ];do
    mkdir $1
    touch $1/Readme.md
    shift
done


