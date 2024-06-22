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
	sub esp, 0
	mov eax, 5
	int x80		mov dword [ebp + 8], eax
	leave
	ret
