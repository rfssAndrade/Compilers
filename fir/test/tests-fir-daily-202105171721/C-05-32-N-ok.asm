segment	.bss
align	4
x:
	resb	4
segment	.bss
align	4
y:
	resb	4
segment	.text
align	4
global	_main:function
_main:
	push	ebp
	mov	ebp, esp
	sub	esp, 4
	push	dword 0
	lea	eax, [ebp+-4]
	push	eax
	pop	ecx
	pop	eax
	mov	[ecx], eax
        ;; before body 
	push	dword 2
	push	dword 4
	push	dword [esp]
	push	dword $x
	pop	ecx
	pop	eax
	mov	[ecx], eax
	pop	eax
	add	dword [esp], eax
	push	dword [esp]
	push	dword $y
	pop	ecx
	pop	eax
	mov	[ecx], eax
	add	esp, 4
	push	dword $y
	pop	eax
	push	dword [eax]
	call	printi
	add	esp, 4
	call	println
_L1:
        ;; after body 
_L2:
	lea	eax, [ebp+-4]
	push	eax
	pop	eax
	push	dword [eax]
	pop	eax
	leave
	ret
extern	printi
extern	println
