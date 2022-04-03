.CODE
_TEXT SEGMENT
	PUBLIC case_2
	case_2 PROC
		cmp rdx, 0;
		je _case_0;
		cmp rdx, 1;
		je _case_1;
		cmp rdx, 2;
		je _case_2;
		cmp rdx, 3;
		je _case_3;
		jne _default;

		_case_0:
			mov rax, rcx;
			add rax, 7;
			jmp _exit;
		_case_1:
			mov r8, rcx;
			add rcx, 3;
			mov rax, rcx;
			imul rax, r8;
			jmp _exit;
		_case_2:
			mov r8, rcx;
			mov rax, rcx;
			imul rcx;
			imul r8, 2;
			add rax, r8;
			jmp _exit;
		_case_3:
			mov rax, rcx;
			imul rax;
			sub rax, 12;
			jmp _exit;
		_default:
			mov rax, 0;
		_exit:
			ret
	case_2 ENDP
_TEXT ENDS
END
