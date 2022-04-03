.CODE
_TEXT SEGMENT
	PUBLIC Zad_9_x64
	Zad_9_x64 PROC
		mov r10, rdx;
	_FOR:
		xor rdx, rdx;
		mov rax, [r8 + 8 * rcx - 8];
		mov rbx, [r9 + 8 * rcx - 8];
		div rbx;
		mov [r10 + 8 * rcx - 8], rax;
		loop _FOR;
		ret
	Zad_9_x64 ENDP
_TEXT ENDS
END