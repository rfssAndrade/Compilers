segment	.text
align	4
f:
	push	ebp
	mov	ebp, esp
	sub	esp, 0
        ;; before body 
segment	.rodata
align	4
_L3:
	db	"ola", 0
segment	.text
	push	dword $_L3
	call	prints
	add	esp, 4
_L1:
        ;; after body 
_L2:
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
	call	f
	add	esp, 0
_L4:
        ;; after body 
_L5:
	lea	eax, [ebp+-4]
	push	eax
	pop	eax
	push	dword [eax]
	pop	eax
	leave
	ret
extern	prints
