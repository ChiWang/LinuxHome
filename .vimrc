"=====================================================================
"   File:   .vimrc
"   Author: Chi WANG  (chiwang@mail.ustc.edu.cn)    29/09/2013
"---------------------------------------------------------------------
"   Description:
"      author infor:
"           set $AUTHOR, $AUTHOREMAIL in .zprofile
"
"---------------------------------------------------------------------
"   History:
"                           Last update:  13/12/2013   14:40:04
"=====================================================================


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
set backupdir=$VIMBACKDIR     " you need to create this directory firstly

"set number             " show line number
"au FocusLost * :wa      " set auto wirte
set autowrite

set foldmethod=syntax
"set foldmethod=indent
"set foldmethod=marker
nnoremap <space> za


"==================================="
"       User Special Setting        "
"==================================="

"+++    Plugins
filetype plugin on

"+  NERDTree
"let NERDChristmasTree=1

"+  author infor
let g:vimrc_author=$AUTHOR
let g:vimrc_email=$AUTHOREMAIL
"let g:vimrc_email='hgs@ustc.edu.cn ylzhang1@mail.ustc.edu.cn chiwang@mail.ustc.edu.cn zhzhy@mail.ustc.edu.cn weiyf@mail.ustc.edu.cn'
nmap <F4> :AuthorInfoDetect<cr>

"+++    shortcuts
"<ctrl+t>   openmp
map <c-t> iprintf("Threads = %d\n",omp_get_thread_num());<Esc>A
"<ctrl+f>   function note for C++
map <c-f> i//---------------------------------------------------<Esc>A
"<ctrl+p>   function note for pyton
map <c-p> i#----------------------------------------------------<Esc>A
"<ctrl+a>   assert()
map <c-a> i  assert();<Esc>A

