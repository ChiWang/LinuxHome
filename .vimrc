
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
set backupext=.bak
set backupdir=$HOME/tmp/vimback

"set number             " show line number
filetype plugin on

"let NERDChristmasTree=1

let g:vimrc_author='Chi Wang'
let g:vimrc_email='chiwang@mail.ustc.edu.cn'
"let g:vimrc_email='hgs@ustc.edu.cn ylzhang1@mail.ustc.edu.cn chiwang@mail.ustc.edu.cn zhzhy@mail.ustc.edu.cn weiyf@mail.ustc.edu.cn'

nmap <F4> :AuthorInfoDetect<cr>
map <c-t> iprintf("Threads = %d\n",omp_get_thread_num());<Esc>A

