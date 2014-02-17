"+
"+  $Id: c.vim, 2014-02-17 22:53:38 chi $
"+  Author(s):
"+    Chi WANG (chiwang@mail.ustc.edu.cn) 21/01/2014
"+


"+  highlight functions
"syn match cFunction "\<[a-zA-Z_][a-zA-Z_0-9]*\>[^()]*)("me=e-2
"syn match cFunction "\<[a-zA-Z_][a-zA-Z_0-9]*\>\s*("me=e-1
"hi cFunction gui=NONE guifg=#B5A1FF

"+  highlight math operator
"syn match cMathOperator display "[+-\*/%=]"
"hi cMathOperator guifg=#3EFFE2

setlocal foldmethod=syntax
