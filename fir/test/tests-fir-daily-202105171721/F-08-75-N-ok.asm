segment	.text
align	4
f:
	push	ebp
	mov	ebp, esp
	sub	esp, 4
	push	dword 10
	lea	eax, [ebp+-4]
	push	eax
	pop	ecx
	pop	eax
	mov	[ecx], eax
        ;; before body 
	lea	eax, [ebp+8]
	push	eax
	pop	eax
	push	dword [eax]
	call	g
	add	esp, 4
	push	eax
	add	esp, 4
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
segment	.text
align	4
g:
	push	ebp
	mov	ebp, esp
	sub	esp, 4
	push	dword 14
	lea	eax, [ebp+-4]
	push	eax
	pop	ecx
	pop	eax
	mov	[ecx], eax
        ;; before body 
	lea	eax, [ebp+8]
	push	eax
	pop	eax
	push	dword [eax]
	call	prints
	add	esp, 4
_L3:
        ;; after body 
_L4:
	lea	eax, [ebp+-4]
	push	eax
	pop	eax
	push	dword [eax]
	pop	eax
	leave
	ret
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
segment	.rodata
align	4
_L7:
	db	"ola", 0
segment	.text
	push	dword $_L7
	call	f
	add	esp, 4
	push	eax
	call	printi
	add	esp, 4
_L5:
        ;; after body 
_L6:
	lea	eax, [ebp+-4]
	push	eax
	pop	eax
	push	dword [eax]
	pop	eax
	leave
	ret
extern	printi
extern	prints
