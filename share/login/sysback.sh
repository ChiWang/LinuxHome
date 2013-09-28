#! /bin/bash

# Dir BackUp  DBU
Day=`date '+%d'`
if [[ $Day == 10 || $Day == 21 || $Day == 30 ]];then
	# Files BackUp  FBU
	FBUDir="$HOME/bin/Backup/newversion"
	if [ ! -d $FBUDir ];then
		mkdir -p $FBUDir
	fi

	for IMF	in {"bashrc","bash_logout"};do
		if [[ "$HOME/.$IMF" -nt "$FBUDir/${USER}_$IMF" ]];then
			cp "$HOME/.$IMF" "$FBUDir/${USER}_$IMF"
		fi
	done
	unset FBUDir

	#for DBU in {"~/work","~/bin"};do		#only chi need backup ~/bin
		bash $HOME/bin/backup "$HOME/bin"
	#done
	#unset DBU
	
fi
unset Day

exit 0

