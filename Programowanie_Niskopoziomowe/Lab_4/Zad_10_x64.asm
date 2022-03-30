.CODE
_TEXT SEGMENT
	PUBLIC Zad_10_x64
	Zad_10_x64 PROC
		mov rsi, rdx;
	_FOR:
		mov rdi, 1;
		mov rax, [rsi + 8 * rcx - 8];
		mov rbx, rax;
	_NE:
		cmp rdi, rbx;
		jne _INC;
		mov [rsi + 8 * rcx - 8], rax;
		loop _FOR;
		jmp _EXIT;
	_INC:
		add rax, rbx;
		inc rdi;
		jmp _NE;
	_EXIT:
		ret
	Zad_10_x64 ENDP
_TEXT ENDS
END