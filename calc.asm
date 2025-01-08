section .text
    
global _calc

_calc:
    push ebp
    mov ebp, esp

    %idefine value [ebp + 8]
    
    finit                 ; Zainicjalizuj FPU

    fld dword value
    fld1
    
    fdiv st1

    leave
    ret


