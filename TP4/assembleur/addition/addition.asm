; Exercice 1 : addition
	const ax,debut
	jmp ax
:debut
; Préparation de la pile
	const bp,pile
	const sp,pile
	const ax,2
	sub sp,ax
	const ax,4
	push ax
	const bx,4
	push bx
; Met ax, bx sur la pile
	pop ax
	pop bx
	add ax,bx
; Le résultat de l'addition de ax va en sommet de pile
	push ax
; copie de l'adresse du sommet de pile dans ax
	cp ax,sp
; affiche adresse de ax
	callprintfd ax
	end
; La zone de pile
:pile
@int 0

