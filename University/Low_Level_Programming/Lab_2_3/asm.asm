.CODE
_DATA SEGMENT
_DATA ENDS

_TEXT SEGMENT
	public suma
	suma PROC
		movsxd rax, ecx
		movsxd rdx, edx
		add rax, rdx
		ret
	suma ENDP
_TEXT ENDS
END
