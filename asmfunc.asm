section .data
	kmph_to_mps dd 3.6 ; 1000m/3600s
section .text
	bits 64
	default rel

global compute_accelerations
extern printf

compute_accelerations:
	MOVSS XMM3, [kmph_to_mps] ;1000m/3600s
	
.loop:
	CMP RDX, 0
	JE .output

	MOVSS XMM0, [RCX]	;Initial Velocity (Vi)
	MOVSS XMM1, [RCX+4]	;Final Velocity (Vf)
	MOVSS XMM2, [RCX+8] ;Time (T)
	SUBSS XMM1, XMM0 ; Vf - Vi

	DIVSS XMM1, XMM3 ; (Vf - Vi)Km/h --> M/s 

	DIVSS XMM1, XMM2 ; (Vf- Vi) / T
	CVTSS2SI EAX, XMM1
	MOV [R8], EAX

	ADD RCX, 12
    ADD R8, 4
    DEC RDX
    JMP .loop

.output:
	ret