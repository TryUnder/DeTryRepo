.CODE
_TEXT SEGMENT
	PUBLIC _WHILE_1
	_WHILE_1 PROC
	mov r12, rcx; r12 -- a
	mov r11, rdx; r11 -- r
				; r8 -- max
	mov r10, r12;
	add r10, r11; r10 -- w = a + r
	_WHILE:
		r10, r8;
	jnl _OUT_OF_WHILE;
	add r12, r10;
	add r10, r11;
	jmp _WHILE;
	_OUT_OF_WHILE:
		mov rax, r10;
		ret

_WHILE_1 ENDP
_TEXT ENDS
END
