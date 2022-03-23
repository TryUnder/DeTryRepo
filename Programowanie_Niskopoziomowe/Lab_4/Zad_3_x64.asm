.CODE

;DO POPRAWY

_TEXT SEGMENT
	PUBLIC Zad_3_x64
	Zad_3_x64 PROC
		mov rbx, 2;
		mov rsi, rdx;

	_FOR:
		xor rdx, rdx;
		mov rax, rcx;
		cmp rdx, 1;
		jz _REST;
		mov [rsi + 8 * rcx - 8], 0;

	_REST:
		dec rcx;
		jnz _FOR;
		ret

	Zad_3_x64 ENDP
_TEXT ENDS
END
