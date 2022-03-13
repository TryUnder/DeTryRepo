.CODE
_TEXT SEGMENT
	PUBLIC _1
	_1 PROC
	cmp rcx, rdx;
	jnge _FALSE;
	mov rax, 10;
	_FALSE:
		ret
	_1 ENDP
_TEXT ENDS
END
