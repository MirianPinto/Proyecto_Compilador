	push 0
	push 0
	push 0
	push 0
	call main
	add esp, 16
	#stop
main:
	push ebp
	mov ebp, esp
	sub esp, 8
	mov eax, 65
	mov dword [ebp + 8], eax
	mov eax, 27
	mov dword [ebp + 12], eax
	mov eax, dword [ebp + 8]
	add eax, dword [ebp + 12]
	mov [ebp - 4], eax
	mov eax, dword [ebp - 4]
	mov dword [ebp + 16], eax
	mov eax, 1
	mov ebx, dword [ebp + 16]
	int 0x80
	mov eax, 11
	mov ebx, 10
	int 0x80
	mov eax, dword [ebp + 8]
	sub eax, dword [ebp + 12]
	mov [ebp - 8], eax
	mov eax, 1
	mov ebx, dword [ebp - 8]
	int 0x80
	mov eax, 11
	mov ebx, 10
	int 0x80
	leave
	ret
