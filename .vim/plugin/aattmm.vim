"+
"+  $Id: aattmm.vim, 2014-04-25 15:58:51 $
"+  Author(s):
"+    Chi WANG (chiwang@mail.ustc.edu.cn) 14/02/2014
"+

if exists('g:loaded_authorinfo')
    finish
endif
let g:loaded_authorinfo= 1

function s:AddTitle() "{{{
    " find the first line, for some script, must after #! /bin/xxx
    let line = getline(1)
    if line =~ '#!'
        exe 'normal '.2.'G'
    else
        exe 'normal '.1.'G'
    endif
    normal O
    let firstLine = line('.')

    " prepare
    let preChar = '+'
    let hasMul = 0
    call setline('.','test mul')
    let oldline = getline('.')
    exec 'normal \cm'
    let newline = getline('.')
    if oldline != newline
        let hasMul = 1
        let preChar = ' *'
        call setline('.','')
    else
        call setline('.',preChar)
    endif

    " Set copyright here
    normal o
    call setline('.',preChar.'  $Id: '.expand("%:t").', '.strftime("%Y-%m-%d %H:%M:%S").' DAMPE $')
    normal o
    call setline('.',preChar.'  Author(s):')
    normal o
    call setline('.',preChar.'    '.g:vimrc_author.' ('.g:vimrc_email.') '.strftime("%d/%m/%Y"))
    normal o
    call setline('.','') | let lastLine = line('.')

    if hasMul == 1
        exe 'normal '.firstLine.'Gv'.lastLine.'G\cm'
    else
        call setline('.',preChar)
        exe 'normal '.firstLine.'Gv'.lastLine.'G\cl'
    endif

    normal o
    call setline('.','') | let gotoLn = line('.')
    exe 'normal '.gotoLn.'G'
    " Set copyright here

    startinsert!
    echohl WarningMsg | echo "Succ to add the copyright." | echohl None
endfunction "}}}

function s:TitleDet() "{{{
    "silent! normal ms
    let n = 1
    while n < 5
        let line = getline(n)
        if line =~ '$Id'
            "silent! normal 's
            let newline=substitute(line,':\(\s*\)\(\S.*$\)$',':\1'.expand("%:t").', '.strftime("%Y-%m-%d %H:%M:%S").' DAMPE $','g')
            call setline(n,newline)
            echohl WarningMsg | echo "Succ to update the copyright." | echohl None
            return
        endif
        let n = n + 1
    endwhile
    call s:AddTitle()
endfunction "}}}

function s:AddTodo() "{{{
    let preChar = " *"

    " Set Todo
    normal O
    call setline('.','tmpline') | let firstLine = line('.') 
    normal o
    call setline('.',preChar.'  TODO: ') | let goLn = line('.')
    normal o
    call setline('.',preChar) | let lastLine = line('.') 
    exe 'normal '.firstLine.'Gv'.lastLine.'G\cl'
    exe '%s/tmpline/'.preChar.'/g'
    " Set Todo

    exe 'normal '.goLn.'G'

    startinsert!
    echohl WarningMsg | echo "Succ to add Todo" | echohl None
endfunction "}}}

function s:AddMark() "{{{
    " add mark
    normal O
    call setline('.','-------------------------------------------------------------------') | let goLn = line('.') 
    exe 'normal \cl'
    " add mark
    exe 'normal '.goLn.'G'
    startinsert!
endfunction "}}}

command! -nargs=0 AuthorInfo :call s:TitleDet()
command! -nargs=0 Todo :call s:AddTodo()
command! -nargs=0 Mark :call s:AddMark()

" vim:ft=vim:fdm=marker

