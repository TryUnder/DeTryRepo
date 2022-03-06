.CODE
_TEXT SEGMENT
	public if_2
	if_2 PROC
		cmp rcx, rdx;
		jnge _true;
		sub rcx, rdx;
		mov rax, rcx;
		jmp exit;
	_true:
		sub rdx, rcx;
		mov rax, rdx;
	if_2 ENDP
	exit:
		ret
_TEXT ENDS
END
