.CODE
_TEXT SEGMENT
	public zad_1
	zad_1 PROC
		mov rax, 0;
		mov rsi, rdx;
		mov rdx, rcx;
		_FOR:
			mov rax, [rsi + 8 * rdx - 8];
			imul rax, rax;
			mov [rsi + 8 * rdx - 8], rax;
			dec rdx;
			jnz _FOR;
		ret
	zad_1 ENDP
_TEXT ENDS
END
