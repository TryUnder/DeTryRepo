.CODE
_TEXT SEGMENT
	PUBLIC for_1
	for_1 PROC
		mov r8, rcx;
		xor rbx, rbx;
		mov rcx, 0;
		xor rax, rax;
		_FOR:
			cmp rcx, r8;
			jge _ENDFOR;
				imul rax, rcx, 2;
				add rbx, rax;
				inc rcx;
				jmp _FOR;
		_ENDFOR:
		mov rax, rbx;
		ret
	for_1 ENDP

_TEXT ENDS
END
