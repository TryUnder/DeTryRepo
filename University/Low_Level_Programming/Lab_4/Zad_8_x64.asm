.CODE
_TEXT SEGMENT
	PUBLIC Zad_8_x64
	Zad_8_x64 PROC
	_FOR:
		mov rax, [rdx + 8 * rcx - 8];
		add rax, [r8 + 8 * rcx - 8];
		mov [rdx + 8 * rcx - 8], rax;
		loop _FOR;
		ret
	Zad_8_x64 ENDP
_TEXT ENDS
END