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
	push	dword 0
	pop	eax
	cmp	eax, byte 0
	je	near _L3
segment	.rodata
align	4
_L4:
	db	"KO", 0
segment	.text
	push	dword $_L4
	call	prints
	add	esp, 4
	call	println
_L3:
segment	.rodata
align	4
_L5:
	db	"OK", 0
segment	.text
	push	dword $_L5
	call	prints
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
extern	println
extern	prints
