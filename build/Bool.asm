	push 0
	push 0
	call main
	add esp, 8
	#stop
main:
	push ebp
	mov ebp, esp
	sub esp, 40
	mov eax, 10
	mov dword [ebp + 8], eax
label_0:
	mov eax, dword [ebp + 8]
	cmp eax, 10
	jge label_4
	mov eax, 1
	jmp label_5
label_4: 
	 mov eax, 0
label_5:
	mov [ebp - 4], eax
	mov eax, dword [ebp - 4]
	cmp eax, 0
	je label_2
	mov eax, 1
	mov ebx, 0
	int 0x80
	mov eax, 11
	mov ebx, 10
	int 0x80
	jmp label_3
label_2:
label_6:
	mov eax, dword [ebp + 8]
	cmp eax, 10
	jne label_10
	mov eax, 1
	jmp label_11
label_10: 
	 mov eax, 0
label_11:
	mov [ebp - 8], eax
	mov eax, dword [ebp - 8]
	cmp eax, 0
	je label_8
	mov eax, 1
	mov ebx, 10
	int 0x80
	mov eax, 11
	mov ebx, 10
	int 0x80
	jmp label_9
label_8:
label_9:
label_3:
	mov eax, 10
	mov dword [ebp + 8], eax
label_12:
	mov eax, dword [ebp + 8]
	cmp eax, 10
	jge label_16
	mov eax, 1
	jmp label_17
label_16: 
	 mov eax, 0
label_17:
	mov [ebp - 20], eax
	mov eax, dword [ebp - 20]
	and eax, dword [ebp + 8]
	mov [ebp - 16], eax
	mov eax, dword [ebp - 16]
	cmp eax, 10
	jne label_18
	mov eax, 1
	jmp label_19
label_18: 
	 mov eax, 0
label_19:
	mov [ebp - 12], eax
	mov eax, dword [ebp - 12]
	cmp eax, 0
	je label_14
	mov eax, 11
	mov ebx, 98
	int 0x80
	mov eax, 11
	mov ebx, 10
	int 0x80
	jmp label_15
label_14:
label_20:
	mov eax, dword [ebp + 8]
	cmp eax, 10
	jle label_24
	mov eax, 1
	jmp label_25
label_24: 
	 mov eax, 0
label_25:
	mov [ebp - 24], eax
	mov eax, dword [ebp - 24]
	cmp eax, 0
	je label_22
	mov eax, 1
	mov ebx, 100
	int 0x80
	mov eax, 11
	mov ebx, 10
	int 0x80
	jmp label_23
label_22:
label_26:
	mov eax, dword [ebp + 8]
	cmp eax, 10
	jne label_30
	mov eax, 1
	jmp label_31
label_30: 
	 mov eax, 0
label_31:
	mov [ebp - 28], eax
	mov eax, dword [ebp - 28]
	cmp eax, 0
	je label_28
	mov eax, 1
	mov ebx, 10
	int 0x80
	mov eax, 11
	mov ebx, 10
	int 0x80
	jmp label_29
label_28:
label_29:
label_23:
label_15:
	mov eax, 10
	mov dword [ebp + 8], eax
label_32:
	mov eax, dword [ebp + 8]
	cmp eax, 10
	je label_36
	mov eax, 1
	jmp label_37
label_36: 
	 mov eax, 0
label_37:
	mov [ebp - 32], eax
	mov eax, dword [ebp - 32]
	cmp eax, 0
	je label_34
	mov eax, 1
	mov ebx, 0
	int 0x80
	mov eax, 11
	mov ebx, 10
	int 0x80
	jmp label_35
label_34:
label_38:
	mov eax, dword [ebp + 8]
	cmp eax, 10
	jle label_42
	mov eax, 1
	jmp label_43
label_42: 
	 mov eax, 0
label_43:
	mov [ebp - 36], eax
	mov eax, dword [ebp - 36]
	cmp eax, 0
	je label_40
	mov eax, 1
	mov ebx, 100
	int 0x80
	mov eax, 11
	mov ebx, 10
	int 0x80
	jmp label_41
label_40:
label_44:
	mov eax, dword [ebp + 8]
	cmp eax, 10
	jne label_48
	mov eax, 1
	jmp label_49
label_48: 
	 mov eax, 0
label_49:
	mov [ebp - 40], eax
	mov eax, dword [ebp - 40]
	cmp eax, 0
	je label_46
	mov eax, 1
	mov ebx, 10
	int 0x80
	mov eax, 11
	mov ebx, 10
	int 0x80
	jmp label_47
label_46:
label_47:
label_41:
label_35:
	leave
	ret
