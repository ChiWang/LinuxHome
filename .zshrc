#+
#+  $Id: .zshrc, 2014-02-15 23:12:51 chi $
#+  Author(s):
#+    Chi WANG (chiwang@mail.ustc.edu.cn) 26/07/2013
#+

# set title of terminal
case $TERM in
  xterm*)
    precmd () {print -Pn "\e]0;%n@%m: %~\a"}
    ;;
esac

# set prompt style
#PROMPT='%{[34m%}%n%{[35m%}@%{[33m%}%m %{[36m%}%D %T %{[32m%}%/
PROMPT='%{[34m%}%n%{[35m%}@%{[33m%}%m %{[36m%}%T %{[32m%}%/
%{[31m%}>>%{[m%}'

# set auto cd. Do not need cd before path
#setopt autocd

# never ever beep
setopt NO_BEEP

# disable mail checking
MAILCHECK=0

# cd -[TAB], cd to history directory
setopt AUTOPUSHD
setopt PUSHDIGNORE_DUPS

# history
#+ number of lines kept in history
export HISTSIZE=10000
#+ number of lines saved in the history after logout
export SAVEHIST=10000
#+ location of history
export HISTFILE=~/.zhistory
#+ append command to history file once executed
setopt INC_APPEND_HISTORY
#+ set history ignore space
setopt hist_ignore_space

# Disable core dumps
limit coredumpsize 0

#Emacs style key
#bindkey -e
# vim style key
bindkey -v
# DEL key: delete back
bindkey "\e[3~" delete-char

# charactor below as part of word
WORDCHARS='*?_-[]~=&;!#$%^(){}<>'

# auto list
setopt AUTO_LIST
setopt AUTO_MENU
setopt MENU_COMPLETE

autoload -U compinit
compinit

# Completion caching
zstyle ':completion::complete:*' use-cache on
zstyle ':completion::complete:*' cache-path .zcache
#zstyle ':completion:*:cd:*' ignore-parents parent pwd

# Completion Options
zstyle ':completion:*:match:*' original only
zstyle ':completion::prefix-1:*' completer _complete
zstyle ':completion:predict:*' completer _complete
zstyle ':completion:incremental:*' completer _complete _correct
zstyle ':completion:*' completer _complete _prefix _correct _prefix _match _approximate

# Path Expansion
zstyle ':completion:*' expand 'yes'
zstyle ':completion:*' squeeze-shlashes 'yes'
zstyle ':completion::complete:*' '\\'

zstyle ':completion:*:*:*:default' menu yes select
zstyle ':completion:*:*:default' force-list always

# GNU Colors. need /etc/DIR_COLORS. Or, not color in table of auto-list
[ -f /etc/DIR_COLORS ] && eval $(dircolors -b /etc/DIR_COLORS)
export ZLSCOLORS="${LS_COLORS}"
zmodload zsh/complist
zstyle ':completion:*' list-colors ${(s.:.)LS_COLORS}
zstyle ':completion:*:*:kill:*:processes' list-colors '=(#b) #([0-9]#)*=0=01;31'

zstyle ':completion:*' completer _complete _match _approximate
zstyle ':completion:*:match:*' original only
zstyle ':completion:*:approximate:*' max-errors 1 numeric

compdef pkill=kill
compdef pkill=killall
zstyle ':completion:*:*:kill:*' menu yes select
zstyle ':completion:*:processes' command 'ps -au$USER'

# Group matches and Describe
zstyle ':completion:*:matches' group 'yes'
zstyle ':completion:*:options' description 'yes'
zstyle ':completion:*:options' auto-description '%d'
zstyle ':completion:*:descriptions' format $'\e[01;33m -- %d --\e[0m'
zstyle ':completion:*:messages' format $'\e[01;35m -- %d --\e[0m'
zstyle ':completion:*:warnings' format $'\e[01;31m -- No Matches Found --\e[0m'

# alias directory. cd ~D = cd /DataDir
#hash -d D="/DataDir"
hash -d D="/DataDir"
hash -d G4Damp="~/g/DA/Cor"
hash -d I="/etc/rc.d"

# alias and login
if [ -d ~/share/login ];then
  source ~/share/login/aliasrc          # must source aliasrc in .zshrc instead of in .zprofile
else
	mkdir -p ~/share/login
fi
#+

# set user tools
source $HOME/software/config/usersoftwareconf.sh

