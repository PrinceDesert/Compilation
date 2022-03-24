; Equals : 19 != 19 = 0, 19 != 18 = 1

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
	const ax,19
	push ax
	const ax,18
	push ax
	pop bx
	pop ax
	const cx,neq:false
	cmp ax,bx
	jmpc cx
	const ax,1
	push ax
	const cx,endneq:false
	jmp cx
:neq:false
	const ax,0
	push ax
:endneq:false
; Pour afficher la valeur calculée, qui se trouve normalement en sommet de pile
	cp ax,sp
	callprintfd ax
	end
; La zone de pile
:pile
@int 0
