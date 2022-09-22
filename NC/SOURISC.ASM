IGROUP group _text
DGROUP group _bss, _data ;const
	   assume CS:IGROUP, DS:DGROUP, ES:DGROUP, SS:DGROUP

;CONST  segment word public 'CONST'
;CONST  ends

_BSS   segment word public 'BSS'
_BSS   ends

_DATA  segment word public 'DATA'
_DATA  ends

_TEXT  segment byte public 'CODE'

public 		_AssHand

extrn  _MouEventHandler : near

actif  db  0

_AssHand   	proc far

			cmp actif,0
			jne fin

			mov actif,1

			push ax
			push bx
			push cx
			push dx
			push di
			push si
			push bp
			push es
			push ds

			push dx
			push cx
			push bx
			push ax

			mov ax,DGROUP
			mov ds,ax

			call _MouEventHandler

			add sp,8

			pop ds
			pop es
			pop bp
			pop si
			pop di
			pop dx
			pop cx
			pop bx
			pop ax

			mov actif,0

fin:		ret

_AssHand    endp

_text       ends
			end





