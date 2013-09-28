#! /bin/bash

dat=`date "+%Y-%m-%d-%H_%M"`
name="${dat}--${1}_${2}_${3}"
mkdir -p ~/.Trash/$name
while [ $# != 0 ];do
	mv $1 ~/.Trash/$name
	shift
done


