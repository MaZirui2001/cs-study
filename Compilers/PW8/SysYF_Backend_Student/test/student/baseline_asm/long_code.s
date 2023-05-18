    .arch armv7ve 
    .text 
    .globl bubblesort
    .p2align 2
    .type bubblesort, %function
bubblesort:
    push {r4, r5, r6, r7, r8, r9, r10, lr}
    sub sp, sp, #12
    Mov r4, r0
    Ldr r6, =0
    b bb0_0
bb0_0:
    ldr r7, Addr0_0
    ldr r7, [r7]
    sub r8, r7, #1
    cmp r6, r8
    ldr r7, =0
    ldrlt r7, =1
    mov r8, r7
    ldr r7, =0
    cmp r8, r7
    ldr r9, =0
    ldrne r9, =1
    ldr r7, =0
    cmp r8, r7
    bne bb0_1
    b bb0_2
bb0_1:
    Ldr r5, =0
    b bb0_3
bb0_2:
    b bb0_8
bb0_3:
    ldr r7, Addr0_0
    ldr r7, [r7]
    sub r8, r7, r6
    sub r7, r8, #1
    cmp r5, r7
    ldr r8, =0
    ldrlt r8, =1
    mov r7, r8
    ldr r8, =0
    cmp r7, r8
    ldr r9, =0
    ldrne r9, =1
    ldr r8, =0
    cmp r7, r8
    bne bb0_4
    b bb0_5
bb0_4:
    add r7, r4, #0
    ldr r8, =4
    mul r9, r5, r8
    add r8, r7, r9
    ldr r7, [r8]
    add r8, r5, #1
    add r9, r4, #0
    ldr r10, =4
    mul r0, r8, r10
    add r8, r9, r0
    ldr r9, [r8]
    cmp r7, r9
    ldr r8, =0
    ldrgt r8, =1
    mov r7, r8
    ldr r8, =0
    cmp r7, r8
    ldr r9, =0
    ldrne r9, =1
    ldr r8, =0
    cmp r7, r8
    bne bb0_6
    b bb0_7
bb0_5:
    add r7, r6, #1
    Mov r6, r7
    b bb0_0
bb0_6:
    b litpool0_0
    .pool
litpool0_0:
    add r7, r5, #1
    add r8, r4, #0
    ldr r9, =4
    mul r10, r7, r9
    add r7, r8, r10
    ldr r8, [r7]
    add r7, r4, #0
    ldr r9, =4
    mul r10, r5, r9
    add r9, r7, r10
    ldr r7, [r9]
    add r9, r5, #1
    add r10, r4, #0
    ldr r0, =4
    mul r1, r9, r0
    add r9, r10, r1
    str r7, [r9]
    add r7, r4, #0
    ldr r9, =4
    mul r10, r5, r9
    add r9, r7, r10
    str r8, [r9]
    b bb0_7
bb0_7:
    add r7, r5, #1
    Mov r5, r7
    b bb0_3
bb0_8:
    ldr r0, =0
    add sp, sp, #12
    pop {r4, r5, r6, r7, r8, r9, r10, lr}
    bx lr
    .pool
Addr0_0:
    .long ..n

    .globl insertsort
    .p2align 2
    .type insertsort, %function
insertsort:
    push {r4, r5, r6, r7, r8, r9, r10, lr}
    sub sp, sp, #12
    Mov r4, r0
    Ldr r7, =1
    b bb1_0
bb1_0:
    ldr r8, Addr1_0
    ldr r8, [r8]
    cmp r7, r8
    ldr r9, =0
    ldrlt r9, =1
    mov r8, r9
    ldr r9, =0
    cmp r8, r9
    ldr r10, =0
    ldrne r10, =1
    ldr r9, =0
    cmp r8, r9
    bne bb1_1
    b bb1_2
bb1_1:
    add r5, r4, #0
    ldr r6, =4
    mul r8, r7, r6
    add r6, r5, r8
    ldr r5, [r6]
    sub r6, r7, #1
    b bb1_3
bb1_2:
    b bb1_7
bb1_3:
    b litpool1_0
    .pool
litpool1_0:
    ldr r8, =-1
    cmp r6, r8
    ldr r9, =0
    ldrgt r9, =1
    mov r8, r9
    ldr r9, =0
    cmp r8, r9
    ldr r10, =0
    ldrne r10, =1
    ldr r9, =0
    cmp r8, r9
    bne bb1_6
    b bb1_5
bb1_4:
    add r8, r4, #0
    ldr r9, =4
    mul r10, r6, r9
    add r9, r8, r10
    ldr r8, [r9]
    add r9, r6, #1
    add r10, r4, #0
    ldr r0, =4
    mul r1, r9, r0
    add r9, r10, r1
    str r8, [r9]
    sub r8, r6, #1
    Mov r6, r8
    b bb1_3
bb1_5:
    add r8, r6, #1
    add r9, r4, #0
    ldr r10, =4
    mul r0, r8, r10
    add r8, r9, r0
    str r5, [r8]
    add r8, r7, #1
    str r5, [sp, #-8]
    Mov r5, r6
    ldr r6, [sp, #-8]
    Mov r7, r8
    b bb1_0
bb1_6:
    add r8, r4, #0
    ldr r9, =4
    mul r10, r6, r9
    add r9, r8, r10
    ldr r8, [r9]
    cmp r5, r8
    ldr r9, =0
    ldrlt r9, =1
    mov r8, r9
    ldr r9, =0
    cmp r8, r9
    ldr r10, =0
    ldrne r10, =1
    ldr r9, =0
    cmp r8, r9
    bne bb1_4
    b bb1_5
bb1_7:
    ldr r0, =0
    add sp, sp, #12
    pop {r4, r5, r6, r7, r8, r9, r10, lr}
    bx lr
    .pool
Addr1_0:
    .long ..n

    .globl QuickSort
    .p2align 2
    .type QuickSort, %function
QuickSort:
    push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    mov r11, sp
    sub sp, sp, #48
    Mov r4, r0
    Mov r5, r1
    Mov r6, r2
    cmp r5, r6
    ldr r7, =0
    ldrlt r7, =1
    mov r8, r7
    ldr r7, =0
    cmp r8, r7
    ldr r9, =0
    ldrne r9, =1
    ldr r7, =0
    cmp r8, r7
    bne bb2_0
    b bb2_1
bb2_0:
    add r7, r4, #0
    ldr r8, =4
    mul r9, r5, r8
    add r8, r7, r9
    ldr r7, [r8]
    Mov r8, r6
    Mov r9, r5
    b bb2_2
bb2_1:
    b litpool2_0
    .pool
litpool2_0:
    b bb2_17
bb2_2:
    cmp r9, r8
    ldr r10, =0
    ldrlt r10, =1
    mov r0, r10
    ldr r10, =0
    cmp r0, r10
    ldr r1, =0
    ldrne r1, =1
    ldr r10, =0
    cmp r0, r10
    bne bb2_3
    b bb2_4
bb2_3:
    b bb2_5
bb2_4:
    add r10, r4, #0
    ldr r0, =4
    mul r1, r9, r0
    add r0, r10, r1
    str r7, [r0]
    sub r10, r9, #1
    STM SP, {r0}
    mov r0, r4
    mov r1, r5
    mov r2, r10
    bl QuickSort
    add r10, r9, #1
    STM SP, {r0, r1}
    mov r0, r4
    mov r1, r10
    mov r2, r6
    bl QuickSort
    LDMIB SP, {r1}
    mov r1, r0
    ldr r0, [SP]
    b bb2_1
bb2_5:
    cmp r9, r8
    ldr r10, =0
    ldrlt r10, =1
    mov r0, r10
    ldr r10, =0
    cmp r0, r10
    ldr r1, =0
    ldrne r1, =1
    ldr r10, =0
    cmp r0, r10
    bne bb2_8
    b bb2_7
bb2_6:
    sub r10, r8, #1
    Mov r8, r10
    b bb2_5
bb2_7:
    cmp r9, r8
    ldr r10, =0
    ldrlt r10, =1
    mov r0, r10
    ldr r10, =0
    cmp r0, r10
    ldr r1, =0
    ldrne r1, =1
    ldr r10, =0
    cmp r0, r10
    bne bb2_9
    Mov r10, r9
    b bb2_10
bb2_8:
    b litpool2_1
    .pool
litpool2_1:
    add r10, r4, #0
    ldr r0, =4
    mul r1, r8, r0
    add r0, r10, r1
    ldr r10, [r0]
    sub r0, r7, #1
    cmp r10, r0
    ldr r1, =0
    ldrgt r1, =1
    mov r10, r1
    ldr r0, =0
    cmp r10, r0
    ldr r1, =0
    ldrne r1, =1
    ldr r0, =0
    cmp r10, r0
    bne bb2_6
    b bb2_7
bb2_9:
    add r10, r4, #0
    ldr r0, =4
    mul r1, r8, r0
    add r0, r10, r1
    ldr r10, [r0]
    add r0, r4, #0
    ldr r1, =4
    mul r2, r9, r1
    add r1, r0, r2
    str r10, [r1]
    add r10, r9, #1
    b bb2_10
bb2_10:
    b bb2_11
bb2_11:
    cmp r10, r8
    ldr r0, =0
    ldrlt r0, =1
    mov r1, r0
    ldr r0, =0
    cmp r1, r0
    ldr r2, =0
    ldrne r2, =1
    ldr r0, =0
    cmp r1, r0
    bne bb2_14
    b bb2_13
bb2_12:
    add r0, r10, #1
    Mov r10, r0
    b bb2_11
bb2_13:
    cmp r10, r8
    ldr r0, =0
    ldrlt r0, =1
    mov r1, r0
    ldr r0, =0
    cmp r1, r0
    ldr r2, =0
    ldrne r2, =1
    ldr r0, =0
    cmp r1, r0
    bne bb2_15
    Mov r0, r8
    b bb2_16
bb2_14:
    b litpool2_2
    .pool
litpool2_2:
    add r0, r4, #0
    ldr r1, =4
    mul r2, r10, r1
    add r1, r0, r2
    ldr r0, [r1]
    cmp r0, r7
    ldr r1, =0
    ldrlt r1, =1
    mov r0, r1
    ldr r1, =0
    cmp r0, r1
    ldr r2, =0
    ldrne r2, =1
    ldr r1, =0
    cmp r0, r1
    bne bb2_12
    b bb2_13
bb2_15:
    add r0, r4, #0
    ldr r1, =4
    mul r2, r10, r1
    add r1, r0, r2
    ldr r0, [r1]
    add r1, r4, #0
    ldr r2, =4
    mul r3, r8, r2
    add r2, r1, r3
    str r0, [r2]
    sub r0, r8, #1
    b bb2_16
bb2_16:
    Mov r8, r0
    Mov r9, r10
    b bb2_2
bb2_17:
    ldr r0, =0
    mov sp, r11
    pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    bx lr
    .pool

    .globl getMid
    .p2align 2
    .type getMid, %function
getMid:
    push {r4, r5, r6, r7, r8, lr}
    sub sp, sp, #4
    Mov r4, r0
    ldr r5, Addr3_0
    ldr r5, [r5]
    ldr r6, =2
    sdiv r7, r5, r6
    ldr r6, =2
    mul r8, r7, r6
    sub r6, r5, r8
    ldr r5, =0
    cmp r6, r5
    ldr r7, =0
    ldreq r7, =1
    mov r5, r7
    ldr r6, =0
    cmp r5, r6
    ldr r7, =0
    ldrne r7, =1
    ldr r6, =0
    cmp r5, r6
    bne bb3_0
    b bb3_1
bb3_0:
    ldr r5, Addr3_0
    ldr r5, [r5]
    ldr r6, =2
    sdiv r7, r5, r6
    add r5, r4, #0
    ldr r6, =4
    mul r8, r7, r6
    add r6, r5, r8
    ldr r5, [r6]
    sub r6, r7, #1
    add r7, r4, #0
    ldr r4, =4
    mul r8, r6, r4
    add r4, r7, r8
    ldr r6, [r4]
    add r4, r5, r6
    ldr r5, =2
    sdiv r6, r4, r5
    Mov r5, r6
    b bb3_2
bb3_1:
    ldr r5, Addr3_0
    ldr r5, [r5]
    ldr r6, =2
    sdiv r7, r5, r6
    add r5, r4, #0
    ldr r6, =4
    mul r8, r7, r6
    add r6, r5, r8
    ldr r5, [r6]
    b bb3_2
bb3_2:
    b litpool3_0
    .pool
litpool3_0:
    mov r0, r5
    add sp, sp, #4
    pop {r4, r5, r6, r7, r8, lr}
    bx lr
    .pool
Addr3_0:
    .long ..n

    .globl getMost
    .p2align 2
    .type getMost, %function
getMost:
    push {r4, r5, r6, r7, r8, r9, r10, lr}
    ldr lr, =4016
    sub sp, sp, lr
    Mov r4, r0
    Ldr r5, =0
    b bb4_0
bb4_0:
    ldr r6, =1000
    cmp r5, r6
    ldr r7, =0
    ldrlt r7, =1
    mov r6, r7
    ldr r7, =0
    cmp r6, r7
    ldr r8, =0
    ldrne r8, =1
    ldr r7, =0
    cmp r6, r7
    bne bb4_1
    b bb4_2
bb4_1:
    add r6, sp, #12
    ldr r7, =4
    mul r8, r5, r7
    add r7, r6, r8
    ldr r6, =0
    str r6, [r7]
    add r6, r5, #1
    Mov r5, r6
    b bb4_0
bb4_2:
    Ldr r8, =0
    Ldr r9, =0
    b bb4_3
bb4_3:
    ldr r10, Addr4_0
    ldr r10, [r10]
    cmp r9, r10
    ldr r0, =0
    ldrlt r0, =1
    mov r10, r0
    ldr r0, =0
    cmp r10, r0
    ldr r1, =0
    ldrne r1, =1
    ldr r0, =0
    cmp r10, r0
    bne bb4_4
    b bb4_5
bb4_4:
    add r6, r4, #0
    ldr r10, =4
    mul r0, r9, r10
    add r10, r6, r0
    ldr r6, [r10]
    add r10, sp, #12
    ldr r0, =4
    mul r1, r6, r0
    add r0, r10, r1
    ldr r10, [r0]
    add r0, r10, #1
    add r10, sp, #12
    ldr r1, =4
    mul r2, r6, r1
    add r1, r10, r2
    str r0, [r1]
    add r10, sp, #12
    ldr r0, =4
    mul r1, r6, r0
    add r0, r10, r1
    ldr r10, [r0]
    cmp r10, r8
    ldr r0, =0
    ldrgt r0, =1
    mov r10, r0
    ldr r0, =0
    cmp r10, r0
    ldr r1, =0
    ldrne r1, =1
    ldr r0, =0
    cmp r10, r0
    bne bb4_6
    b bb4_7
bb4_5:
    b bb4_8
bb4_6:
    b litpool4_0
    .pool
litpool4_0:
    add r7, sp, #12
    ldr r8, =4
    mul r10, r6, r8
    add r8, r7, r10
    ldr r7, [r8]
    str r7, [sp, #-8]
    Mov r7, r6
    ldr r8, [sp, #-8]
    b bb4_7
bb4_7:
    add r10, r9, #1
    Mov r9, r10
    b bb4_3
bb4_8:
    mov r0, r7
    ldr lr, =4016
    add sp, sp, lr
    pop {r4, r5, r6, r7, r8, r9, r10, lr}
    bx lr
    .pool
Addr4_0:
    .long ..n

    .globl revert
    .p2align 2
    .type revert, %function
revert:
    push {r4, r5, r6, r7, r8, r9, r10, lr}
    sub sp, sp, #8
    Mov r4, r0
    Ldr r5, =0
    Ldr r6, =0
    b bb5_0
bb5_0:
    cmp r6, r5
    ldr r7, =0
    ldrlt r7, =1
    mov r8, r7
    ldr r7, =0
    cmp r8, r7
    ldr r9, =0
    ldrne r9, =1
    ldr r7, =0
    cmp r8, r7
    bne bb5_1
    b bb5_2
bb5_1:
    add r7, r4, #0
    ldr r8, =4
    mul r9, r6, r8
    add r8, r7, r9
    ldr r7, [r8]
    add r8, r4, #0
    ldr r9, =4
    mul r10, r5, r9
    add r9, r8, r10
    ldr r8, [r9]
    add r9, r4, #0
    ldr r10, =4
    mul r0, r6, r10
    add r10, r9, r0
    str r8, [r10]
    add r8, r4, #0
    ldr r9, =4
    mul r10, r5, r9
    add r9, r8, r10
    str r7, [r9]
    add r7, r6, #1
    sub r6, r5, #1
    Mov r5, r6
    Mov r6, r7
    b bb5_0
bb5_2:
    b bb5_3
bb5_3:
    ldr r0, =0
    add sp, sp, #8
    pop {r4, r5, r6, r7, r8, r9, r10, lr}
    bx lr
    .pool

    .globl arrCopy
    .p2align 2
    .type arrCopy, %function
arrCopy:
    push {r4, r5, r6, r7, r8, r9, r10, lr}
    sub sp, sp, #8
    Mov r4, r0
    Mov r5, r1
    Ldr r6, =0
    b bb6_0
bb6_0:
    b litpool6_0
    .pool
litpool6_0:
    ldr r7, Addr6_0
    ldr r7, [r7]
    cmp r6, r7
    ldr r8, =0
    ldrlt r8, =1
    mov r7, r8
    ldr r8, =0
    cmp r7, r8
    ldr r9, =0
    ldrne r9, =1
    ldr r8, =0
    cmp r7, r8
    bne bb6_1
    b bb6_2
bb6_1:
    add r7, r4, #0
    ldr r8, =4
    mul r9, r6, r8
    add r8, r7, r9
    ldr r7, [r8]
    add r8, r5, #0
    ldr r9, =4
    mul r10, r6, r9
    add r9, r8, r10
    str r7, [r9]
    add r7, r6, #1
    Mov r6, r7
    b bb6_0
bb6_2:
    b bb6_3
bb6_3:
    ldr r0, =0
    add sp, sp, #8
    pop {r4, r5, r6, r7, r8, r9, r10, lr}
    bx lr
    .pool
Addr6_0:
    .long ..n

    .globl calSum
    .p2align 2
    .type calSum, %function
calSum:
    push {r4, r5, r6, r7, r8, r9, r10, lr}
    sub sp, sp, #8
    Mov r4, r0
    Mov r5, r1
    Ldr r6, =0
    Ldr r7, =0
    b bb7_0
bb7_0:
    ldr r8, Addr7_0
    ldr r8, [r8]
    cmp r6, r8
    ldr r9, =0
    ldrlt r9, =1
    mov r8, r9
    ldr r9, =0
    cmp r8, r9
    ldr r10, =0
    ldrne r10, =1
    ldr r9, =0
    cmp r8, r9
    bne bb7_1
    b bb7_2
bb7_1:
    add r8, r4, #0
    ldr r9, =4
    mul r10, r6, r9
    add r9, r8, r10
    ldr r8, [r9]
    add r9, r7, r8
    sdiv r7, r6, r5
    mul r8, r7, r5
    sub r7, r6, r8
    sub r8, r5, #1
    cmp r7, r8
    ldr r10, =0
    ldrne r10, =1
    mov r7, r10
    ldr r8, =0
    cmp r7, r8
    ldr r10, =0
    ldrne r10, =1
    ldr r8, =0
    cmp r7, r8
    bne bb7_3
    b bb7_4
bb7_2:
    b litpool7_0
    .pool
litpool7_0:
    b bb7_6
bb7_3:
    add r7, r4, #0
    ldr r8, =4
    mul r10, r6, r8
    add r8, r7, r10
    ldr r7, =0
    str r7, [r8]
    Mov r7, r9
    b bb7_5
bb7_4:
    add r7, r4, #0
    ldr r8, =4
    mul r10, r6, r8
    add r8, r7, r10
    str r9, [r8]
    Ldr r7, =0
    b bb7_5
bb7_5:
    add r8, r6, #1
    Mov r6, r8
    b bb7_0
bb7_6:
    ldr r0, =0
    add sp, sp, #8
    pop {r4, r5, r6, r7, r8, r9, r10, lr}
    bx lr
    .pool
Addr7_0:
    .long ..n

    .globl avgPooling
    .p2align 2
    .type avgPooling, %function
avgPooling:
    push {r4, r5, r6, r7, r8, r9, r10, r12, lr}
    sub sp, sp, #24
    Mov r4, r0
    Mov r5, r1
    Ldr r7, =0
    Ldr r8, =0
    b bb8_0
bb8_0:
    ldr r9, Addr8_0
    ldr r9, [r9]
    cmp r7, r9
    ldr r10, =0
    ldrlt r10, =1
    mov r9, r10
    ldr r10, =0
    cmp r9, r10
    ldr r0, =0
    ldrne r0, =1
    ldr r10, =0
    cmp r9, r10
    bne bb8_1
    b bb8_2
bb8_1:
    sub r9, r5, #1
    cmp r7, r9
    ldr r10, =0
    ldrlt r10, =1
    mov r9, r10
    ldr r10, =0
    cmp r9, r10
    ldr r0, =0
    ldrne r0, =1
    ldr r10, =0
    cmp r9, r10
    bne bb8_3
    b bb8_4
bb8_2:
    ldr r9, Addr8_0
    ldr r9, [r9]
    sub r10, r9, r5
    add r9, r10, #1
    b bb8_9
bb8_3:
    b litpool8_0
    .pool
litpool8_0:
    add r9, r4, #0
    ldr r10, =4
    mul r0, r7, r10
    add r10, r9, r0
    ldr r9, [r10]
    add r10, r8, r9
    Mov r9, r6
    b bb8_5
bb8_4:
    sub r9, r5, #1
    cmp r7, r9
    ldr r10, =0
    ldreq r10, =1
    mov r9, r10
    ldr r10, =0
    cmp r9, r10
    ldr r0, =0
    ldrne r0, =1
    ldr r10, =0
    cmp r9, r10
    bne bb8_6
    b bb8_7
bb8_5:
    add r0, r7, #1
    Mov r6, r9
    Mov r7, r0
    Mov r8, r10
    b bb8_0
bb8_6:
    add r9, r4, #0
    ldr r10, =0
    ldr r0, =4
    mul r1, r10, r0
    add r10, r9, r1
    ldr r9, [r10]
    sdiv r10, r8, r5
    add r0, r4, #0
    ldr r1, =0
    ldr r2, =4
    mul r3, r1, r2
    add r1, r0, r3
    str r10, [r1]
    Mov r10, r8
    b bb8_8
bb8_7:
    add r9, r4, #0
    ldr r10, =4
    mul r0, r7, r10
    add r10, r9, r0
    ldr r9, [r10]
    add r10, r8, r9
    sub r9, r10, r6
    sub r10, r7, r5
    add r0, r10, #1
    add r10, r4, #0
    ldr r1, =4
    mul r2, r0, r1
    add r0, r10, r2
    ldr r10, [r0]
    sdiv r0, r9, r5
    sub r1, r7, r5
    add r2, r1, #1
    add r1, r4, #0
    ldr r3, =4
    mul r12, r2, r3
    add r2, r1, r12
    str r0, [r2]
    str r9, [sp, #-8]
    Mov r9, r10
    ldr r10, [sp, #-8]
    b bb8_8
bb8_8:
    b bb8_5
bb8_9:
    b litpool8_1
    .pool
litpool8_1:
    ldr r10, Addr8_0
    ldr r10, [r10]
    cmp r9, r10
    ldr r0, =0
    ldrlt r0, =1
    mov r10, r0
    ldr r0, =0
    cmp r10, r0
    ldr r1, =0
    ldrne r1, =1
    ldr r0, =0
    cmp r10, r0
    bne bb8_10
    b bb8_11
bb8_10:
    add r10, r4, #0
    ldr r0, =4
    mul r1, r9, r0
    add r0, r10, r1
    ldr r10, =0
    str r10, [r0]
    add r10, r9, #1
    Mov r9, r10
    b bb8_9
bb8_11:
    b bb8_12
bb8_12:
    ldr r0, =0
    add sp, sp, #24
    pop {r4, r5, r6, r7, r8, r9, r10, r12, lr}
    bx lr
    .pool
Addr8_0:
    .long ..n

    .globl main
    .p2align 2
    .type main, %function
main:
    push {r4, r5, r6, r7, r8, r9, r10, r11, r12, lr}
    mov r11, sp
    ldr lr, =292
    sub sp, sp, lr
    bl current_time
    mov r4, r0
    ldr r5, =32
    push {r0}
    ldr lr, =Addr9_0
    ldr r0, [lr]
    str r5, [r0]
    pop {r0}
    add r5, sp, #36
    ldr r6, =0
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =7
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =1
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =23
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =2
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =89
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =3
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =26
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =4
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =282
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =5
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =254
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =6
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =27
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =7
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =5
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =8
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =83
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =9
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =273
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =10
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =574
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =11
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =905
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =12
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =354
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =13
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =657
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =14
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =935
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =15
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =264
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =16
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =639
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =17
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =459
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =18
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =29
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =19
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =68
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =20
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =929
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =21
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =756
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =22
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =452
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =23
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =279
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =24
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =58
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =25
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =87
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =26
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =96
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =27
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =36
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =28
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =39
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =29
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =28
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =30
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =1
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =31
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =290
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =0
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    add r5, sp, #164
    ldr r7, =0
    ldr r8, =4
    mul r9, r7, r8
    add r7, r5, r9
    mov r0, r6
    mov r1, r7
    bl arrCopy
    mov r5, r0
    add r6, sp, #164
    ldr r7, =0
    ldr r8, =4
    mul r9, r7, r8
    add r7, r6, r9
    mov r0, r7
    bl revert
    mov r6, r0
    Ldr r5, =0
    b bb9_0
bb9_0:
    ldr r6, =32
    cmp r5, r6
    ldr r7, =0
    ldrlt r7, =1
    mov r6, r7
    ldr r7, =0
    cmp r6, r7
    ldr r8, =0
    ldrne r8, =1
    ldr r7, =0
    cmp r6, r7
    bne bb9_1
    b bb9_2
bb9_1:
    b litpool9_0
    .pool
litpool9_0:
    add r6, sp, #164
    ldr r7, =4
    mul r8, r5, r7
    add r7, r6, r8
    ldr r6, [r7]
    mov r0, r6
    bl put_int
    add r6, r5, #1
    Mov r5, r6
    b bb9_0
bb9_2:
    add r6, sp, #164
    ldr r7, =0
    ldr r8, =4
    mul r9, r7, r8
    add r7, r6, r9
    mov r0, r7
    bl bubblesort
    mov r6, r0
    Ldr r6, =0
    b bb9_3
bb9_3:
    ldr r7, =32
    cmp r6, r7
    ldr r8, =0
    ldrlt r8, =1
    mov r7, r8
    ldr r8, =0
    cmp r7, r8
    ldr r9, =0
    ldrne r9, =1
    ldr r8, =0
    cmp r7, r8
    bne bb9_4
    b bb9_5
bb9_4:
    add r7, sp, #164
    ldr r8, =4
    mul r9, r6, r8
    add r8, r7, r9
    ldr r7, [r8]
    mov r0, r7
    bl put_int
    add r7, r6, #1
    Mov r6, r7
    b bb9_3
bb9_5:
    add r7, sp, #164
    ldr r8, =0
    ldr r9, =4
    mul r10, r8, r9
    add r8, r7, r10
    mov r0, r8
    bl getMid
    mov r7, r0
    mov r0, r7
    bl put_int
    add r7, sp, #164
    ldr r8, =0
    ldr r9, =4
    mul r10, r8, r9
    add r8, r7, r10
    mov r0, r8
    bl getMost
    mov r7, r0
    mov r0, r7
    bl put_int
    add r7, sp, #36
    ldr r8, =0
    ldr r9, =4
    mul r10, r8, r9
    add r8, r7, r10
    add r7, sp, #164
    ldr r9, =0
    ldr r10, =4
    mul r0, r9, r10
    add r9, r7, r0
    mov r0, r8
    mov r1, r9
    bl arrCopy
    mov r7, r0
    add r8, sp, #164
    ldr r9, =0
    ldr r10, =4
    mul r0, r9, r10
    add r9, r8, r0
    mov r0, r9
    bl bubblesort
    mov r8, r0
    Ldr r7, =0
    b bb9_6
bb9_6:
    ldr r8, =32
    cmp r7, r8
    ldr r9, =0
    ldrlt r9, =1
    mov r8, r9
    ldr r9, =0
    cmp r8, r9
    ldr r10, =0
    ldrne r10, =1
    ldr r9, =0
    cmp r8, r9
    bne bb9_7
    b bb9_8
bb9_7:
    b litpool9_1
    .pool
litpool9_1:
    add r8, sp, #164
    ldr r9, =4
    mul r10, r7, r9
    add r9, r8, r10
    ldr r8, [r9]
    mov r0, r8
    bl put_int
    add r8, r7, #1
    Mov r7, r8
    b bb9_6
bb9_8:
    add r8, sp, #36
    ldr r9, =0
    ldr r10, =4
    mul r0, r9, r10
    add r9, r8, r0
    add r8, sp, #164
    ldr r10, =0
    ldr r0, =4
    mul r1, r10, r0
    add r10, r8, r1
    mov r0, r9
    mov r1, r10
    bl arrCopy
    mov r8, r0
    add r9, sp, #164
    ldr r10, =0
    ldr r0, =4
    mul r1, r10, r0
    add r10, r9, r1
    mov r0, r10
    bl insertsort
    mov r9, r0
    Ldr r8, =0
    b bb9_9
bb9_9:
    ldr r9, =32
    cmp r8, r9
    ldr r10, =0
    ldrlt r10, =1
    mov r9, r10
    ldr r10, =0
    cmp r9, r10
    ldr r0, =0
    ldrne r0, =1
    ldr r10, =0
    cmp r9, r10
    bne bb9_10
    b bb9_11
bb9_10:
    add r9, sp, #164
    ldr r10, =4
    mul r0, r8, r10
    add r10, r9, r0
    ldr r9, [r10]
    mov r0, r9
    bl put_int
    add r9, r8, #1
    Mov r8, r9
    b bb9_9
bb9_11:
    add r9, sp, #36
    ldr r10, =0
    ldr r0, =4
    mul r1, r10, r0
    add r10, r9, r1
    add r9, sp, #164
    ldr r0, =0
    ldr r1, =4
    mul r2, r0, r1
    add r0, r9, r2
    STM SP, {r0}
    mov r0, r10
    ldr r1, [sp]
    bl arrCopy
    mov r9, r0
    ldr r0, [SP]
    add r10, sp, #164
    ldr r0, =0
    ldr r1, =4
    mul r2, r0, r1
    add r0, r10, r2
    STM SP, {r0}
    ldr r0, [sp]
    ldr r1, =0
    ldr r2, =31
    bl QuickSort
    mov r10, r0
    ldr r0, [SP]
    Ldr r9, =0
    b bb9_12
bb9_12:
    ldr r10, =32
    cmp r9, r10
    ldr r0, =0
    ldrlt r0, =1
    mov r10, r0
    ldr r0, =0
    cmp r10, r0
    ldr r1, =0
    ldrne r1, =1
    ldr r0, =0
    cmp r10, r0
    bne bb9_13
    b bb9_14
bb9_13:
    b litpool9_2
    .pool
litpool9_2:
    add r10, sp, #164
    ldr r0, =4
    mul r1, r9, r0
    add r0, r10, r1
    ldr r10, [r0]
    mov r0, r10
    bl put_int
    add r10, r9, #1
    Mov r9, r10
    b bb9_12
bb9_14:
    add r10, sp, #36
    ldr r0, =0
    ldr r1, =4
    mul r2, r0, r1
    add r0, r10, r2
    add r10, sp, #164
    ldr r1, =0
    ldr r2, =4
    mul r3, r1, r2
    add r1, r10, r3
    STM SP, {r0, r1}
    ldr r0, [sp]
    ldr r1, [sp, #4]
    bl arrCopy
    LDMIB SP, {r1}
    mov r10, r0
    ldr r0, [SP]
    add r0, sp, #164
    ldr r1, =0
    ldr r2, =4
    mul r3, r1, r2
    add r1, r0, r3
    STM SP, {r0, r1}
    ldr r0, [sp, #4]
    ldr r1, =4
    bl calSum
    LDMIB SP, {r1}
    Ldr r10, =0
    b bb9_15
bb9_15:
    ldr r0, =32
    cmp r10, r0
    ldr r1, =0
    ldrlt r1, =1
    mov r0, r1
    ldr r1, =0
    cmp r0, r1
    ldr r2, =0
    ldrne r2, =1
    ldr r1, =0
    cmp r0, r1
    bne bb9_16
    b bb9_17
bb9_16:
    add r0, sp, #164
    ldr r1, =4
    mul r2, r10, r1
    add r1, r0, r2
    ldr r0, [r1]
    STM SP, {r0}
    ldr r0, [sp]
    bl put_int
    LDM sp, {r0}
    add r0, r10, #1
    Mov r10, r0
    b bb9_15
bb9_17:
    add r0, sp, #36
    ldr r1, =0
    ldr r2, =4
    mul r3, r1, r2
    add r1, r0, r3
    add r0, sp, #164
    ldr r2, =0
    ldr r3, =4
    mul r12, r2, r3
    add r2, r0, r12
    STM SP, {r0, r1, r2}
    ldr r0, [sp, #4]
    ldr r1, [sp, #8]
    bl arrCopy
    LDMIB SP, {r1, r2}
    add r1, sp, #164
    ldr r2, =0
    ldr r3, =4
    mul r12, r2, r3
    add r2, r1, r12
    STM SP, {r0, r1, r2}
    ldr r0, [sp, #8]
    ldr r1, =3
    bl avgPooling
    LDMIB SP, {r1, r2}
    mov r1, r0
    ldr r0, [SP]
    Ldr r0, =0
    b bb9_18
bb9_18:
    ldr r1, =32
    cmp r0, r1
    ldr r2, =0
    ldrlt r2, =1
    mov r1, r2
    ldr r2, =0
    cmp r1, r2
    ldr r3, =0
    ldrne r3, =1
    ldr r2, =0
    cmp r1, r2
    bne bb9_19
    b bb9_20
bb9_19:
    b litpool9_3
    .pool
litpool9_3:
    add r1, sp, #164
    ldr r2, =4
    mul r3, r0, r2
    add r2, r1, r3
    ldr r1, [r2]
    STM SP, {r0, r1}
    ldr r0, [sp, #4]
    bl put_int
    LDM sp, {r0, r1}
    add r1, r0, #1
    Mov r0, r1
    b bb9_18
bb9_20:
    ldr r0, =10
    bl put_char
    STM SP, {r1}
    bl current_time
    LDM SP, {r1}
    mov r1, r0
    sub r2, r1, r4
    STM SP, {r2}
    ldr r0, [sp]
    bl put_int
    LDM sp, {r2}
    b bb9_21
bb9_21:
    ldr r0, =0
    mov sp, r11
    pop {r4, r5, r6, r7, r8, r9, r10, r11, r12, lr}
    bx lr
    .pool
Addr9_0:
    .long ..n

    .type ..n, %object
    .comm ..n, 4, 4

