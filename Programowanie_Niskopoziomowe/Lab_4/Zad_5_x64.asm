.CODE
_TEXT SEGMENT
	PUBLIC Zad_5_x64
	Zad_5_x64 PROC
		mov rsi, rdx;
		mov rax, [rsi + 8 * rcx - 8];
	_FOR:
		cmp rax, [rsi + 8 * rcx - 8];
		jnge _OUT;
		mov rax, [rsi + 8 * rcx - 8];
	_OUT:
		dec rcx;
		jnz _FOR;
		ret;
	Zad_5_x64 ENDP
_TEXT ENDS
END
