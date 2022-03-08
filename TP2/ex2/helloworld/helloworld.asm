; Exercice 2 : TP2 : Hello World

	const ax,debut
	jmp ax

:sHelloWorkd
@string "Hello world !\n"

; Le main
:debut
	const bx,sHelloWorkd
	callprintfs bx
	end

; La zone de pile
:pile
@int 0
