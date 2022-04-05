.CODE
_TEXT SEGMENT
	PUBLIC Add_Elem_Matrix_x64
	Add_Elem_Matrix_x64 PROC
		push rsi
		mov rsi, r8
		mov rax, 0
		mov r8, rdx;
	_OUTER:
		mov rdx, r8;
		mov rbx, [rsi + 8 * rcx - 8]
	_INTER:
		movsxd r9, DWORD PTR [rbx + 4 * rdx - 4]
		add rax, r9
		dec rdx;
		JNZ _INTER;
		dec rcx;
		JNZ _OUTER;
		pop rsi
		ret
	Add_Elem_Matrix_x64 ENDP
_TEXT ENDS
END