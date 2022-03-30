.CODE
_TEXT SEGMENT
	PUBLIC Zad_7_x64
	Zad_7_x64 PROC
		xor r9,r9;
		mov r10, rdx;
		xor rbx, rbx;
		mov r8, rcx;
		xor rdi, rdi;
		mov rdi, rcx;
		mov rcx, 1;
		mov rsi, 1;

	_BEFORE:
		xor rbx, rbx;
		mov rcx, rsi;

	_FOR:
		xor rdx, rdx;
		mov rax, rsi;
		idiv rcx;
		cmp rdx, 0;
		jnz _OUT;
		inc rbx;

	_OUT:
		dec rcx;
		jnz _FOR;

		cmp rbx, 2;
		jne _NOT_A_PRIME;
		mov [r10 + 8 * r9], rsi;
		inc r9;

	_NOT_A_PRIME:
		add rsi, 1;
		cmp r9,r8;
		jne _BEFORE;
		ret
		
	Zad_7_x64 ENDP
_TEXT ENDS
END