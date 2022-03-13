; Exercice 1

	const ax,debut
	jmp ax
:debut
; Préparation de la pile
	const bp,pile
	const sp,pile
	const ax,2
	sub sp,ax
; Résultat de bison
	const ax,4
	push ax
	const ax,0
	push ax
:s_err:div0:0
@string "Erreur de division par 0"
	pop bx
	pop ax
	const cx,err:div0:0
	pop bx
	div ax,bx
	jmpe cx
	push ax
	const ax,fin:div:0
:err:div0:0
	const ax,s_err:div0:0
	callprintfs ax
:fin:div:0
; Pour afficher la valeur calculée, qui se trouve normalement en sommet de pile
	cp ax,sp
	callprintfd ax
	end
; La zone de pile
:pile
@int 0
