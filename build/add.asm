	push 0
	call main
	add esp, 4
	#stop
main:
	push ebp
	mov ebp, esp
	sub esp, 0
	mov eax, 5
	int 0x80
	mov dword [ebp + 8], eax
	mov eax, 1
	mov ebx, dword [ebp + 8]
	int 0x80
	mov eax, 11
	mov ebx, 10
	int 0x80
	leave
	ret
