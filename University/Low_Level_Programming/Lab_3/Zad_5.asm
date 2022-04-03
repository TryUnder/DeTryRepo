.CODE
_TEXT SEGMENT
	PUBLIC case_1
	case_1 PROC
		cmp rdx,3;
		je _case_3;
		cmp rdx,5;
		je _case_5;
		cmp rdx,7;
		je _case_7;
		jne _default;

		_case_3:
			add rcx, 7;
			mov rax, rcx;
			jmp _exit;

		_case_5:
			mov r8, rcx;
			sub rcx, 7;
			mov rax, rcx;
			imul r8;
			jmp _exit;

		_case_7:
			mov rax, rcx;
			imul rax;
			jmp _exit;

		_default:
			mov rax, 0;
		_exit:
			ret
	case_1 ENDP
_TEXT ENDS
END
