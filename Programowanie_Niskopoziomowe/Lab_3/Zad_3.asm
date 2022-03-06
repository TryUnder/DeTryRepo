.CODE
_TEXT SEGMENT
	PUBLIC if_3
	if_3 PROC
	cmp rcx, rdx;
	jnge _true;
		mov rcx, 0;
		mov rax, rcx;
		jmp _exit;
	_true:
		mov rax, rdx;
		imul rax;
		sub rax, rcx;
	_exit:
		ret
	if_3 ENDP
_TEXT ENDS
END
