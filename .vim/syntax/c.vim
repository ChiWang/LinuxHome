"=====================================================================
"   File:   c.vim
"   Author: Chi WANG  (chiwang@mail.ustc.edu.cn)    21/01/2014
"---------------------------------------------------------------------
"   Description:
"       highlight
"---------------------------------------------------------------------
"   History:
"                           Last update:  21/01/2014   12:09:28
"=====================================================================

"+  highlight functions
"syn match cFunction "\<[a-zA-Z_][a-zA-Z_0-9]*\>[^()]*)("me=e-2
"syn match cFunction "\<[a-zA-Z_][a-zA-Z_0-9]*\>\s*("me=e-1
"hi cFunction gui=NONE guifg=#B5A1FF
"
"echo "in c.vim "$PWD
" this line where print the $PWD of the local

""+  highlight math operator
"syn match cMathOperator display "[+-\*/%=]"
"hi cMathOperator guifg=#3EFFE2

set foldmethod=syntax
"set foldmethod=indent
"set foldmethod=marker
