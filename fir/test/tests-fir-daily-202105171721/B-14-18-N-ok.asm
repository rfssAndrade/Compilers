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
	push	dword 10
	push	dword 3
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	sete	cl
	mov	[esp], ecx
	push	dword [esp]
	pop	eax
	cmp	eax, byte 0
	je	near _L3
	push	dword 10
	push	dword 3
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setne	cl
	mov	[esp], ecx
	pop	eax
	and	dword [esp], eax
align	4
_L3:
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
