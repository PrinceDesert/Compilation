; STORE : enregistrement

	const ax,debut
	jmp ax

:s_err:div0:0
@string "Erreur de division par 0\n"

:var:b
@int 2

:debut
; Préparation de la pile
	const bp,pile
	const sp,pile
	const ax,2
	sub sp,ax
; Résultat de bison
	const ax,var:b
	push ax
; Pour afficher la valeur calculée, qui se trouve normalement en sommet de pile
	cp ax,sp
	callprintfd ax
	end
; La zone de pile
:pile
@int 0
