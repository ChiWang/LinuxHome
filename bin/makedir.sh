#! /bin/bash

while [ $# != 0 ];do
    mkdir $1
    touch $1/Readme.md
    shift
done
