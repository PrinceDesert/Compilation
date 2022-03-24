; Exercice : Division : (Prend en compte la division par zéro)

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
	const ax,0
	push ax
	pop bx
	pop ax
	const cx,err:div0:0
	div ax,bx
	jmpe cx
	push ax
	const ax,fin:div:0
	jmp ax
:err:div0:0
	const ax,s_err:div0:0
	callprintfs ax
	end
:fin:div:0
; Pour afficher la valeur calculée, qui se trouve normalement en sommet de pile
	cp ax,sp
	callprintfd ax
	end
; La zone de pile
:pile
@int 0

