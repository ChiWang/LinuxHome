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

let g:sh_fold_enabled=1     " enable folding of bash script, as for C++ (python) in $HOME/.vim/syntax/c.vim(python.vim)
"set foldlevel=99            " =0 enable nothing
" color of folding line
highlight Folded ctermfg=7 ctermfg=0
" use space open/close folding
nnoremap <space> za

"==================================="
"       User Special Setting        "
"==================================="
"echo "in .vimrc "$PWD      " this line where print the $PWD of the local
"directory at where and whenever you use vim to open a file
"==================================="
    "-------------------------
    "   My personal plugins  "
    "-------------------------
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
nmap <F2> <Esc>:NERDTree<cr>

"+  taglist
let Tlist_Show_One_File=1
let Tlist_Exit_OnlyWindow=1
let Tlist_Use_Right_Window=1
"let Tlist_Show_Menu=1
nmap <F4> <Esc>:Tlist<cr>

"+  winManager
let g:winManagerWindowLayout='NERDTree|TagList'
let g:winManagerWidth=30
nmap <F3> :WMToggle<cr>

"+  switch between *.h and *.cc
nnoremap <silent> <F6> :AS<CR>

"+  pydiction
let g:pydiction_location='$HOME/.vim/pydiction/complete-dict'
let g:pydiction_menu_height=20

"+  author infor
let g:vimrc_author='Chi WANG'
let g:vimrc_email=$MYEMAIL
"let g:vimrc_email='hgs@ustc.edu.cn ylzhang1@mail.ustc.edu.cn chiwang@mail.ustc.edu.cn zhzhy@mail.ustc.edu.cn weiyf@mail.ustc.edu.cn'
nmap <F5> :AuthorInfoDetect<cr>

" marks
    " comment
map cm0 i//-------------------------------------------------------------------<Esc>A
map cm1 i/*  needless*/<Esc>A
map cm2 i#--------------------------------------------------------------------<Esc>A
    " todo
map td0 i// *TODO: <Esc>A
map td1 i#  *TODO: <Esc>A
" assert to debug
map db0 istd::cout<<"DEBUG: in file "<<__FILE__<<", line: "<<__LINE__<<", function: "<<__PRETTY_FUNCTION__<<std::endl;<Esc>
map db1 istd::cout<<"DEBUG: in file "<<__FILE__<<", line: "<<__LINE__<<std::endl;<Esc>
map db2 i  assert();<Esc>
" for OpenMP
map co iprintf("Threads = %d\n",omp_get_thread_num());<Esc>A
