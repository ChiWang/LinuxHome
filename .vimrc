"+
"+  $Id: .vimrc, 2014-02-17 21:38:20 chi $
"+  Author(s):
"+    Chi WANG (chiwang@mail.ustc.edu.cn) 29/09/2013
"+
 

"-------------------------------------------------------------------
"+++    Common set
"-------------------------------------------------------------------
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
"set cursorline          " mark current line
"hi CursorLine cterm=NONE ctermbg=darkblue ctermfg=white guibg=purple guifg=NONE

"+ set backup
if ! isdirectory($HOME."/.vimback")
 call mkdir($HOME."/.vimback")
endif
set backup
set backupext=.back
set backupdir=$HOME/.vimback

"set number                 " show line number
"au FocusLost * :wa         " set auto wirte
set autowrite

let g:sh_fold_enabled=1     " enable folding of bash script, as for C++ (python) in $HOME/.vim/syntax/c.vim(python.vim)
" use space open/close folding
nnoremap <space> za
" color of folding line
"highlight Folded ctermfg=7 ctermfg=0

"-------------------------------------------------------------------
"   My plugins
"-------------------------------------------------------------------
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
nnoremap <silent> <F5> :AS<CR>

"+  pydiction
let g:pydiction_location=$HOME.'/.vim/pydiction/complete-dict'
let g:pydiction_menu_height=20

"-------------------------------------------------------------------
"   My shortcuts
"-------------------------------------------------------------------
"+  author infor
let g:vimrc_author='Chi WANG'
let g:vimrc_email="chiwang@mail.ustc.edu.cn"
"let g:vimrc_email='hgs@ustc.edu.cn ylzhang1@mail.ustc.edu.cn chiwang@mail.ustc.edu.cn zhzhy@mail.ustc.edu.cn weiyf@mail.ustc.edu.cn'
nmap aa :AuthorInfo<cr>

"+ add a new line as mark
nmap mm :Mark<cr>

"+ todo
nmap td0 i#pragma message("TODO ----> xxxx")<Esc>A
nmap td :Todo<cr>

"+ debug
nmap db istd::cout<<"DEBUG: "<<__FILE__<<"("<<__LINE__<<"), in "<<__PRETTY_FUNCTION__<<std::endl;<Esc>
nmap db0 i  assert();<Esc>
"+ for OpenMP
nmap co iprintf("Threads = %d\n",omp_get_thread_num());<Esc>A

"-------------------------------------------------------------------
"   add file types
"-------------------------------------------------------------------
autocmd BufNewFile,BufRead {*.scons,SCons*} set filetype=python
autocmd BufNewFile,BufRead *.gdml set filetype=htmldjango
autocmd BufRead,BufNewFile *.{md,mdown,mkd,mkdn,markdown,mdwn} set filetype=mkd

"-------------------------------------------------------------------
"   set vundle
"-------------------------------------------------------------------
if filereadable($HOME."/.vim/bundle/vundle.vim")
  source ~/.vim/bundle/vundle.vim
endif

