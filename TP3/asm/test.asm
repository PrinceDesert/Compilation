; Exercice 1

	const ax,debut
	jmp ax

:s_err:div0:0
@string "Erreur de division par 0\n"

:debut
; Préparation de la pile
	const bp,pile
	const sp,pile
	const ax,2
	sub sp,ax
; Résultat de bison
	const ax,4
	push ax
	const ax,2
	push ax
	const bx,0
	pop ax
	const ax,saut:1
	cmp ax,bx
	jmpc cx
	const ax,0
	push ax
	const ax,finsaut:1
	jmp ax
:saut:1
	const ax,1
	push ax
:finsaut:1
; Pour afficher la valeur calculée, qui se trouve normalement en sommet de pile
	cp ax,sp
	callprintfd ax
	end
; La zone de pile
:pile
@int 0