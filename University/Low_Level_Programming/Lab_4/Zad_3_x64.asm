.CODE
_TEXT SEGMENT
	PUBLIC Zad_3_x64
	Zad_3_x64 PROC
		mov r8, 0;
		mov rbx, 2;
		mov rsi, rdx;

	_FOR:
		xor rdx, rdx;
		mov rax, rcx;
		idiv rbx;
		cmp rdx, 1;
		jz _REST;
		mov [rsi + 8 * rcx - 8], r8;

	_REST:
		dec rcx;
		jnz _FOR;
		ret

	Zad_3_x64 ENDP
_TEXT ENDS
END
