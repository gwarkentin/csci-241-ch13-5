
.model flat, C

isPrimeASM PROTO C, intVal:DWORD
intSqrt PROTO C, n:DWORD

.code

isPrimeASM PROC C USES EDI, intVal:DWORD
	mov ebx, intVal			; save n to register
	INVOKE intSqrt, ebx
	mov edi, eax			; sqrt of intVal
	mov ecx, 2
	cmp ebx, ecx
	jl Lfalse
L1:
	cmp ecx, edi
	jg Ltrue
	mov eax, ebx
	mov edx, 0
	div ecx
	cmp edx, 0
	je Lfalse
Lskip:
	inc ecx
	test ecx, 1
	jnz L1
	inc ecx
	jmp L1
Ltrue:
	mov eax, 1
	jmp Lreturn
Lfalse:
	mov eax, 0
Lreturn:
	ret
isPrimeASM ENDP

END