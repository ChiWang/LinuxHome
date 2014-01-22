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
"                           Last update:  21/01/2014   23:27:51
"=====================================================================


"+++    Common set
set showmatch           " Show matching brackets.
set matchtime=2         " Show time of matching brackets.
set hlsearch            " high light searching words
set tabstop=4           " tap longth = 2
set expandtab           " replace tab by space
set laststatus=2        " show status line
set vb t_vb=            " 
set autoindent          " autoindenting
set ai!                 " suojing
"colorscheme desert
"colorscheme murphy
set guifont=Monospace:h13:cANSI

set backup
set backupext=.back
set backupdir=$HOME/.vimback     " you need to create this directory firstly

"set number                 " show line number
"au FocusLost * :wa         " set auto wirte
set autowrite

set foldmethod=syntax
"set foldmethod=indent
"set foldmethod=marker
nnoremap <space> za

"==================================="
"       User Special Setting        "
"==================================="
"echo "in .vimrc "$PWD      " this line where print the $PWD of the local
"directory at where and whenever you use vim to open a file
"==================================="

"+++    My personal plugins
filetype plugin on

"+  NERDTree
" add 7 lines here in order to let winManager to call NERDTree
let NERDTree_title='NERD_Tree'
function! NERDTree_Start()
    exec 'NERDTree'
endfunction
function! NERDTree_IsValid()
    return 1
endfunction
"let NERDChristmasTree=1
"nmap <F3> <Esc>:NERDTree<cr>

"+  taglist
let Tlist_Show_One_File=1
let Tlist_Exit_OnlyWindow=1
let Tlist_Use_Right_Window=1
"let Tlist_Show_Menu=1

"+  winManager
let g:winManagerWindowLayout='NERDTree|TagList'
let g:winManagerWidth=30
nmap <F2> :WMToggle<cr>

"+  a, switch between *.h and *.cc
nnoremap <silent> <F3> :AS<CR>

"+  pydiction
let g:pydiction_location='$HOME/.vim/pydiction/complete-dict'
let g:pydiction_menu_height=20

"+  author infor
let g:vimrc_author='Chi WANG'
let g:vimrc_email=$MYEMAIL
"let g:vimrc_email='hgs@ustc.edu.cn ylzhang1@mail.ustc.edu.cn chiwang@mail.ustc.edu.cn zhzhy@mail.ustc.edu.cn weiyf@mail.ustc.edu.cn'
nmap <F4> :AuthorInfoDetect<cr>

"+  some shortcuts
" for C++
    " mark of function
map cm i//-------------------------------------------------------------------<Esc>A
    " assert to debug
map cd i  assert();<Esc>
    " for OpenMP
map co iprintf("Threads = %d\n",omp_get_thread_num());<Esc>A
" for bash and python
map bm i#--------------------------------------------------------------------<Esc>A
