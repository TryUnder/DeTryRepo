.CODE
_TEXT SEGMENT
	PUBLIC if_4
	if_4 PROC
		cmp rcx, rdx;
		jnge _true;
			mov rax, rcx;
			mov r8, rdx;
			imul rax;
			sub rax, r8;
			jmp _exit;
		_true:
			mov rax, rcx;
			mov r8, rdx;
			imul rax;
			add rax, r8;
		_exit:
			ret
	if_4 ENDP
_TEXT ENDS
END
