.CODE
_TEXT SEGMENT
	public _FACTORIAL
	_FACTORIAL PROC
		mov r8, rcx;
		xor rcx, rcx;
		mov rcx, 1;
		mov rax, 1;
		_FOR:
			cmp rcx, r8
			jnle _ENDFOR;
			imul rcx;
			inc rcx;
			jmp _FOR;
			_ENDFOR:
				ret
	_FACTORIAL ENDP
_TEXT ENDS
END
