.CODE
_TEXT SEGMENT
	PUBLIC Zad_4_x64
	Zad_4_x64 PROC
		xor rax, rax;
		mov rsi, rdx;
		mov rbx, rcx;
	_FOR:
		add rax, [rsi + 8 * rcx - 8];
		dec rcx;
		jnz _FOR;
		xor rdx, rdx;
		idiv rbx;
		ret
	Zad_4_x64 ENDP
_TEXT ENDS
END
