"=============================================================================
"       FileName :          .vimrc
"       Version  :          0.0.1
"       Author   :          Chi Wang    (chiwang@mail.ustc.edu.cn)
"       Time     :          2013-09-29   01:12:11

"------------------------------------------------------------------------------
"       Description  :
"           vim set
"------------------------------------------------------------------------------
"       History  :
"                                          Update:  2013-09-29   01:12:11
"=============================================================================

"+++    Common set
set showmatch           " Show matching brackets.
set matchtime=2         " Show time of matching brackets.
set hlsearch            " high light searching words
set tabstop=4           " tap longth = 2
set expandtab           " replace tab by space
set laststatus=2        " show status line
set vb t_vb=            " 
set autoindent          " duiqi
set ai!                 " suojing
"colorscheme murphy
set guifont=Monospace:h13:cANSI

set backup
set backupext=.back
set backupdir=$HOME/tmp/vimback     " you need to create this directory firstly

"set number             " show line number


"+++    Plugins
filetype plugin on

"+  NERDTree
"let NERDChristmasTree=1

"+  author infor
let g:vimrc_author='Chi Wang'
let g:vimrc_email='chiwang@mail.ustc.edu.cn'
"let g:vimrc_email='hgs@ustc.edu.cn ylzhang1@mail.ustc.edu.cn chiwang@mail.ustc.edu.cn zhzhy@mail.ustc.edu.cn weiyf@mail.ustc.edu.cn'
nmap <F4> :AuthorInfoDetect<cr>

"+++    shortcuts
map <c-t> iprintf("Threads = %d\n",omp_get_thread_num());<Esc>A

