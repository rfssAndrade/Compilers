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
	jmp	dword _L5
_L3:
	push	dword 0
	pop	eax
	cmp	eax, byte 0
	je	near _L6
segment	.rodata
align	4
_L7:
	db	"elif1", 0
segment	.text
	push	dword $_L7
	call	prints
	add	esp, 4
	call	println
	jmp	dword _L8
_L6:
	push	dword 0
	pop	eax
	cmp	eax, byte 0
	je	near _L9
segment	.rodata
align	4
_L10:
	db	"elif2", 0
segment	.text
	push	dword $_L10
	call	prints
	add	esp, 4
	call	println
	jmp	dword _L11
_L9:
	push	dword 0
	pop	eax
	cmp	eax, byte 0
	je	near _L12
segment	.rodata
align	4
_L13:
	db	"elif3", 0
segment	.text
	push	dword $_L13
	call	prints
	add	esp, 4
	call	println
	jmp	dword _L14
_L12:
	push	dword 1
	pop	eax
	cmp	eax, byte 0
	je	near _L15
segment	.rodata
align	4
_L16:
	db	"elif4", 0
segment	.text
	push	dword $_L16
	call	prints
	add	esp, 4
	call	println
	jmp	dword _L17
_L15:
segment	.rodata
align	4
_L18:
	db	"OK", 0
segment	.text
	push	dword $_L18
	call	prints
	add	esp, 4
	call	println
_L17:
_L14:
_L11:
_L8:
_L5:
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
