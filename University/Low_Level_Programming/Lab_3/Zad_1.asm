.CODE

_TEXT SEGMENT
	PUBLIC if_1
	if_1 PROC
		cmp rcx, rdx;
			jnge _true;
			mov rdx, 0;
			mov rax, rdx;
			jmp _exit;
		_true:
			sub rdx, rcx;
			mov rax, rdx;
		_exit:
			ret
	if_1 ENDP
_TEXT ENDS
END
