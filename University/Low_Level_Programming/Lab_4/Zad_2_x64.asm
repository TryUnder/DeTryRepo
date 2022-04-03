.CODE
_TEXT SEGMENT
	public Zad_2_x64
	Zad_2_x64 PROC
	mov ebx, 2;
	mov rsi, rdx;

_FOR:
	xor rdx, rdx;
	mov rax, [rsi + 8 * rcx - 8];
	idiv ebx;
	mov rax, [rsi + 8 * rcx - 8];
	cmp rdx, 0;
	jnz _REST;
	imul rax, rax;
	mov [rsi + 8 * rcx - 8], rax;

_REST:
	dec rcx;
	jnz _FOR;
	ret
	Zad_2_x64 ENDP
_TEXT ENDS
END
