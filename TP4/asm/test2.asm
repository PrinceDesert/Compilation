; Généré sur bison

; Permet de passer la zone de stockage des constantes
	const ax,debut
	jmp ax
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Début de la zone de stockage des constantes
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

:s_err:div0:0
@string "Erreur de division par 0\n"

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Fin de la zone de stockage des constantes
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;
; Fonction principale
;;;;;;;;;;;;;;;;;;;;;
:debut
; Préparation de la pile
	const bp,pile
	const sp,pile
	const ax,2
	sub sp,ax
; Résultat de bison
	const ax,4
	push ax
	pop bx
	const bx,var:x
	storew ax,bx
	push ax
	const ax,7
	push ax
	pop bx
	const bx,var:c
	storew ax,bx
	push ax
; Pour afficher la valeur calculée, qui se trouve normalement en sommet de pile
	cp ax,sp
	callprintfd ax
	end

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Début de stockage de la zone de pile
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
:pile
@int 0
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Fin de stockage de la zone de pile
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
:var:
@int 0

:var:
@int 0

