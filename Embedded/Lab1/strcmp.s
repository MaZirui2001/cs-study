# int strcmp(char* str1, char* str2)
    # EXPORT strcmp
    # AREA STRCMP, CODE, READONLY
strcmp:
    STMFD sp!, {r2-r7}      ; save regs
    mov v1, #0              ; i = 0
loop: 
    ldrb v2, [a1, v1]       ; v2 = str1[i]
    ldrb v3, [a2, v1]       ; v3 = str2[i]
    cmp v2, #0              ; 
    beq compare             ; if(str1[i] == 0) go to compare 
    cmp v3, #0              ; compare str2[i] with 0
    beq compare             ; if(str2[i] == 0) go to compare

    cmp v2, v3              ; compare str1[i] with str2[i]
    blt return_minus1       ; if(str1[i] < str2[i]) go to return -1
    bgt return_1            ; if(str1[i] > str2[i]) go to return 1
    add v1, v1, #1          ; i++
    b loop                  ; go to loop

compare:
    cmp v2, #0              ; compare str1[i] with 0
    bne return_1            ; if(str1[i] != 0) str1 is bigger than str2, return 1
    cmp v3, #0              ; compare str2[i] with 0
    bne return_minus1       ; if(str2[i] != 0) str2 is bigger than str1, return -1

return_0:
    mov a1, #0              
    LDMFD sp!, {r2-r7}      ; restore regs 
    mov PC, LR              ; return 0

return_minus1:
    mov a1, #-1
    LDMFD sp!, {r2-r7}      ; restore regs
    mov PC, LR              ; return -1

return_1:
    mov a1, #1
    LDMFD sp!, {r2-r7}      ; restore regs
    mov PC, LR              ; return 1

    END