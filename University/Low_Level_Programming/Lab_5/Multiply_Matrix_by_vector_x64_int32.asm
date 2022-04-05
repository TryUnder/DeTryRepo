.CODE
_DATA SEGMENT
partial_add DQ 0
_DATA ENDS
_TEXT SEGMENT
	Multiply_matrix_by_vector_x64_int32 PROC
	mov rsi, rdx
	mov rdi, r8
	mov r8, rcx
	push rsi
	xor r11,r11
	xor eax, eax
_OUTER:
	mov rdx, r8
	mov rbx, [rsi + 8 * rcx - 8]
_INNER:
	movsxd r11, DWORD PTR [rbx + 4 * rdx - 4]
	movsxd rax, DWORD PTR [rdi + 4 * rdx - 4]
	imul rax, r11
	add partial_add, rax
	dec rdx
	JNZ _INNER
	mov rax, partial_add
	mov partial_add, 0
	mov DWORD PTR [r9 + 4 * rcx - 4], eax
	dec rcx
	JNZ _OUTER
	pop rsi
	ret
	Multiply_matrix_by_vector_x64_int32 ENDP
_TEXT ENDS
END