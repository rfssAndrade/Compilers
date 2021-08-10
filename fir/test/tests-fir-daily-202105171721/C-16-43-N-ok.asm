segment	.data
align	4
x:
	dd	0
segment	.data
align	4
y:
	dd	1
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
	push	dword $x
	pop	eax
	push	dword [eax]
	push	dword $y
	pop	eax
	push	dword [eax]
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setne	cl
	mov	[esp], ecx
	push	dword $x
	pop	eax
	push	dword [eax]
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	sete	cl
	mov	[esp], ecx
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
