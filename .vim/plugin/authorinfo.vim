"+
"+  $Id: authorinfo.vim, 2014-02-15 23:32:36 chi $
"+  Author(s):
"+    Chi WANG (chiwang@mail.ustc.edu.cn) 14/02/2014
"+


if exists('g:loaded_authorinfo')
    finish
endif
let g:loaded_authorinfo= 1
let s:t_mapleader = '\'

function s:DetectFirstLine()
    " find the first line, for some script, must after #! /bin/xxx
    let line = getline(1)
    if line =~ '#!'
        exe 'normal '.2.'G'
    else
        exe 'normal '.1.'G'
    endif
    normal O
endfunction

function s:AddTitle()
    call s:DetectFirstLine()
    let firstLine = line('.')
    let preChar = '+'
    let hasMul = 0

    call setline('.','test mul')
    let oldline = getline('.')
    exec 'normal '.s:t_mapleader.'cm'
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
    call setline('.',preChar.'  $Id: '.expand("%:t").', '.strftime("%Y-%m-%d %H:%M:%S").' '.$USER.' $')
    normal o
    call setline('.',preChar.'  Author(s):')
    normal o
    call setline('.',preChar.'    '.g:vimrc_author.' ('.g:vimrc_email.') '.strftime("%d/%m/%Y"))
    normal o
    call setline('.','') | let lastLine = line('.')

    if hasMul == 1
        exe 'normal '.firstLine.'Gv'.lastLine.'G'.s:t_mapleader.'cm'
    else
        call setline('.',preChar)
        exe 'normal '.firstLine.'Gv'.lastLine.'G'.s:t_mapleader.'cl'
    endif
    " Set copyright here

    normal o
    call setline('.','') | let gotoLn = line('.')
    exe 'normal '.gotoLn.'G'

    startinsert!
    echohl WarningMsg | echo "Succ to add the copyright." | echohl None
endfunction

function s:TitleDet()
    "silent! normal ms
    let n = 1
    while n < 5
        let line = getline(n)
        if line =~ '$Id'
            "silent! normal 's
            let newline=substitute(line,':\(\s*\)\(\S.*$\)$',':\1'.expand("%:t").', '.strftime("%Y-%m-%d %H:%M:%S").' '.$USER.' $','g')
            call setline(n,newline)
            echohl WarningMsg | echo "Succ to update the copyright." | echohl None
            return
        endif
        let n = n + 1
    endwhile
    call s:AddTitle()
endfunction

command! -nargs=0 AuthorInfoDetect :call s:TitleDet()
