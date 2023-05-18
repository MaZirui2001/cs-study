.global string_sort
string_sort:
    STMFD sp!, {r2-r7, LR}  
    sub sp, sp, #8          @ p + 4@ i, sp + 8
    mov v1, #0              @v1 = 0
    str v1, [sp, #4]        @ i = 0

loop1:
    ldr v1, [sp, #4]        @@ ld i to v1
    cmp v1, a2              @ compare i with n
    bge return              

    mov v2, #0              @ v2 = 0
    str v2, [sp, #8]        @ j = 0

loop2:
    ldr v1, [sp, #4]        @ v1 = i
    ldr v2, [sp, #8]        @ v2 = j
    sub v3, a2, v1          @ v3 = n - i
    sub v3, v3, #1          @ v3 = n - i - 1 

    cmp v2, v3              @ compare j with n - i - 1
    bge loop1_end           @ for(j = 0@ j < n - i - 1@ j++)

    STMFD sp!, {a1-a2}      @ save str, n
    add v4, a1, v2, LSL#2   @ v4 = str + j
    ldmia v4, {a1, a2}      @ a1 = str[j], a2 = str[j+1]
    bl strcmp               @ a1 = strcmp(str[j], str[j+1])
    mov v1, a1              @ v1 = result
    LDMFD sp!, {a1-a2}      @ restore str, n

    cmp v1, #1              @ if result < 1
    blt skip_swap           @ skip swap

    ldr v1, [v4, #4]        @ v1 = str[j+1]
    swp v1, v1, [v4]        @ str[j] = str[j+1]
    str v1, [v4, #4]        @ st str[j+1]

skip_swap:
    ldr v2, [sp, #8]        @ ld j to v2
    add v2, v2, #1          @ j++
    str v2, [sp, #8]        @ st j to mem
    b loop2

loop1_end:
    ldr v1, [sp, #4]        @ ld i to v1
    add v1, v1, #1          @ i++
    str v1, [sp, #4]        @ st i to mem
    b loop1             

return:
    add sp, sp, #8          @ pop stack
    LDMFD sp!, {r2-r7, LR}  @ restore regs
    mov PC, LR              @ return 
