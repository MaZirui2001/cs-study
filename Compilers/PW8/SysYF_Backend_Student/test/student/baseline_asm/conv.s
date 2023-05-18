    .arch armv7ve 
    .text 
    .globl checkrange
    .p2align 2
    .type checkrange, %function
checkrange:
    push {r4, r5, r6, r7, r8, lr}
    sub sp, sp, #4
    Mov r4, r0
    b bb0_0
bb0_0:
    ldr r5, =1073741824
    cmp r4, r5
    ldr r6, =0
    ldrgt r6, =1
    mov r5, r6
    ldr r6, =0
    cmp r5, r6
    ldr r7, =0
    ldrne r7, =1
    ldr r6, =0
    cmp r5, r6
    bne bb0_1
    b bb0_2
bb0_1:
    ldr r5, =1073741824
    sub r6, r4, r5
    Mov r4, r6
    b bb0_0
bb0_2:
    Mov r5, r4
    b bb0_3
bb0_3:
    ldr r6, =0
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
    bne bb0_4
    b bb0_5
bb0_4:
    ldr r6, =1073741824
    add r7, r5, r6
    Mov r5, r7
    b bb0_3
bb0_5:
    b bb0_6
bb0_6:
    b litpool0_0
    .pool
litpool0_0:
    mov r0, r5
    add sp, sp, #4
    pop {r4, r5, r6, r7, r8, lr}
    bx lr
    .pool

    .globl reduce
    .p2align 2
    .type reduce, %function
reduce:
    push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    mov r11, sp
    sub sp, sp, #32
    Mov r4, r0
    Mov r5, r1
    Mov r6, r2
    ldr r7, =0
    cmp r4, r7
    ldr r8, =0
    ldreq r8, =1
    mov r7, r8
    ldr r8, =0
    cmp r7, r8
    ldr r9, =0
    ldrne r9, =1
    ldr r8, =0
    cmp r7, r8
    bne bb1_0
    b bb1_1
bb1_0:
    add r4, r5, r6
    mov r0, r4
    bl checkrange
    mov r5, r0
    Mov r1, r5
    b bb1_32
bb1_1:
    ldr r7, =1
    cmp r4, r7
    ldr r8, =0
    ldreq r8, =1
    mov r7, r8
    ldr r8, =0
    cmp r7, r8
    ldr r9, =0
    ldrne r9, =1
    ldr r8, =0
    cmp r7, r8
    bne bb1_2
    b bb1_3
bb1_2:
    Ldr r4, =1
    Ldr r7, =0
    b bb1_4
bb1_3:
    ldr r7, =2
    cmp r4, r7
    ldr r8, =0
    ldreq r8, =1
    mov r7, r8
    ldr r8, =0
    cmp r7, r8
    ldr r9, =0
    ldrne r9, =1
    ldr r8, =0
    cmp r7, r8
    bne bb1_10
    b bb1_11
bb1_4:
    ldr r8, =1073741824
    cmp r4, r8
    ldr r9, =0
    ldrlt r9, =1
    mov r8, r9
    ldr r9, =0
    cmp r8, r9
    ldr r10, =0
    ldrne r10, =1
    ldr r9, =0
    cmp r8, r9
    bne bb1_5
    b bb1_6
bb1_5:
    b litpool1_0
    .pool
litpool1_0:
    sdiv r8, r5, r4
    ldr r9, =2
    sdiv r10, r8, r9
    ldr r9, =2
    mul r0, r10, r9
    sub r9, r8, r0
    sdiv r8, r6, r4
    ldr r10, =2
    sdiv r0, r8, r10
    ldr r10, =2
    mul r1, r0, r10
    sub r10, r8, r1
    cmp r9, r10
    ldr r8, =0
    ldreq r8, =1
    mov r9, r8
    ldr r8, =0
    cmp r9, r8
    ldr r10, =0
    ldrne r10, =1
    ldr r8, =0
    cmp r9, r8
    bne bb1_7
    b bb1_8
bb1_6:
    Mov r10, r4
    Mov r0, r7
    Mov r1, r7
    b bb1_32
bb1_7:
    ldr r8, =2
    mul r9, r7, r8
    Mov r8, r9
    b bb1_9
bb1_8:
    ldr r8, =2
    mul r9, r7, r8
    add r8, r9, #1
    b bb1_9
bb1_9:
    ldr r9, =2
    mul r10, r4, r9
    Mov r4, r10
    Mov r7, r8
    b bb1_4
bb1_10:
    cmp r5, r6
    ldr r4, =0
    ldrgt r4, =1
    mov r7, r4
    ldr r4, =0
    cmp r7, r4
    ldr r8, =0
    ldrne r8, =1
    ldr r4, =0
    cmp r7, r4
    bne bb1_12
    b bb1_13
bb1_11:
    b litpool1_1
    .pool
litpool1_1:
    ldr r7, =3
    cmp r4, r7
    ldr r8, =0
    ldreq r8, =1
    mov r7, r8
    ldr r8, =0
    cmp r7, r8
    ldr r9, =0
    ldrne r9, =1
    ldr r8, =0
    cmp r7, r8
    bne bb1_14
    b bb1_15
bb1_12:
    Mov r1, r5
    b bb1_32
bb1_13:
    Mov r1, r6
    b bb1_32
bb1_14:
    Ldr r4, =1
    Ldr r7, =0
    b bb1_16
bb1_15:
    ldr r7, =4
    cmp r4, r7
    ldr r8, =0
    ldreq r8, =1
    mov r4, r8
    ldr r7, =0
    cmp r4, r7
    ldr r8, =0
    ldrne r8, =1
    ldr r7, =0
    cmp r4, r7
    bne bb1_23
    b bb1_24
bb1_16:
    ldr r8, =1073741824
    cmp r4, r8
    ldr r9, =0
    ldrlt r9, =1
    mov r8, r9
    ldr r9, =0
    cmp r8, r9
    ldr r10, =0
    ldrne r10, =1
    ldr r9, =0
    cmp r8, r9
    bne bb1_17
    b bb1_18
bb1_17:
    sdiv r8, r5, r4
    ldr r9, =2
    sdiv r10, r8, r9
    ldr r9, =2
    mul r0, r10, r9
    sub r9, r8, r0
    ldr r8, =1
    cmp r9, r8
    ldr r10, =0
    ldreq r10, =1
    mov r8, r10
    ldr r9, =0
    cmp r8, r9
    ldr r10, =0
    ldrne r10, =1
    ldr r9, =0
    cmp r8, r9
    bne bb1_19
    b bb1_22
bb1_18:
    b litpool1_2
    .pool
litpool1_2:
    Mov r8, r4
    Mov r9, r7
    Mov r1, r7
    b bb1_32
bb1_19:
    ldr r8, =2
    mul r9, r7, r8
    add r7, r9, #1
    Mov r8, r7
    b bb1_21
bb1_20:
    ldr r8, =2
    mul r9, r7, r8
    Mov r8, r9
    b bb1_21
bb1_21:
    ldr r9, =2
    mul r10, r4, r9
    Mov r4, r10
    Mov r7, r8
    b bb1_16
bb1_22:
    sdiv r8, r6, r4
    ldr r9, =2
    sdiv r10, r8, r9
    ldr r9, =2
    mul r0, r10, r9
    sub r9, r8, r0
    ldr r8, =1
    cmp r9, r8
    ldr r10, =0
    ldreq r10, =1
    mov r8, r10
    ldr r9, =0
    cmp r8, r9
    ldr r10, =0
    ldrne r10, =1
    ldr r9, =0
    cmp r8, r9
    bne bb1_19
    b bb1_20
bb1_23:
    Ldr r4, =1
    Ldr r7, =0
    b bb1_25
bb1_24:
    Ldr r1, =0
    b bb1_32
bb1_25:
    ldr r8, =1073741824
    cmp r4, r8
    ldr r9, =0
    ldrlt r9, =1
    mov r8, r9
    ldr r9, =0
    cmp r8, r9
    ldr r10, =0
    ldrne r10, =1
    ldr r9, =0
    cmp r8, r9
    bne bb1_26
    b bb1_27
bb1_26:
    b litpool1_3
    .pool
litpool1_3:
    sdiv r8, r5, r4
    ldr r9, =2
    sdiv r10, r8, r9
    ldr r9, =2
    mul r0, r10, r9
    sub r9, r8, r0
    ldr r8, =1
    cmp r9, r8
    ldr r10, =0
    ldreq r10, =1
    mov r8, r10
    ldr r9, =0
    cmp r8, r9
    ldr r10, =0
    ldrne r10, =1
    ldr r9, =0
    cmp r8, r9
    bne bb1_31
    b bb1_29
bb1_27:
    Mov r1, r7
    b bb1_32
bb1_28:
    ldr r8, =2
    mul r9, r7, r8
    add r7, r9, #1
    Mov r8, r7
    b bb1_30
bb1_29:
    ldr r8, =2
    mul r9, r7, r8
    Mov r8, r9
    b bb1_30
bb1_30:
    ldr r9, =2
    mul r10, r4, r9
    Mov r4, r10
    Mov r7, r8
    b bb1_25
bb1_31:
    sdiv r8, r6, r4
    ldr r9, =2
    sdiv r10, r8, r9
    ldr r9, =2
    mul r0, r10, r9
    sub r9, r8, r0
    ldr r8, =1
    cmp r9, r8
    ldr r10, =0
    ldreq r10, =1
    mov r8, r10
    ldr r9, =0
    cmp r8, r9
    ldr r10, =0
    ldrne r10, =1
    ldr r9, =0
    cmp r8, r9
    bne bb1_28
    b bb1_29
bb1_32:
    b litpool1_4
    .pool
litpool1_4:
    mov r0, r1
    mov sp, r11
    pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    bx lr
    .pool

    .globl getvalue
    .p2align 2
    .type getvalue, %function
getvalue:
    push {r4, r5, r6, r7, r8, r9, r10, lr}
    sub sp, sp, #20
    Mov r4, r0
    Mov r5, r1
    Mov r6, r2
    Mov r7, r3
    ldr r8, [sp, #52]
    ldr r9, =0
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
    bne bb2_0
    b bb2_4
bb2_0:
    Ldr r4, =0
    b bb2_5
bb2_1:
    mul r5, r7, r6
    add r6, r5, r8
    add r5, r4, #0
    ldr r4, =4
    mul r7, r6, r4
    add r4, r5, r7
    ldr r5, [r4]
    Mov r4, r5
    b bb2_5
bb2_2:
    cmp r8, r6
    ldr r5, =0
    ldrge r5, =1
    mov r9, r5
    ldr r5, =0
    cmp r9, r5
    ldr r10, =0
    ldrne r10, =1
    ldr r5, =0
    cmp r9, r5
    bne bb2_0
    b bb2_1
bb2_3:
    cmp r7, r5
    ldr r9, =0
    ldrge r9, =1
    mov r5, r9
    ldr r9, =0
    cmp r5, r9
    ldr r10, =0
    ldrne r10, =1
    ldr r9, =0
    cmp r5, r9
    bne bb2_0
    b bb2_2
bb2_4:
    ldr r9, =0
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
    bne bb2_0
    b bb2_3
bb2_5:
    b litpool2_0
    .pool
litpool2_0:
    mov r0, r4
    add sp, sp, #20
    pop {r4, r5, r6, r7, r8, r9, r10, lr}
    bx lr
    .pool

    .globl convn
    .p2align 2
    .type convn, %function
convn:
    push {r4, r5, r6, r7, r8, r9, r10, r11, r12, lr}
    mov r11, sp
    sub sp, sp, #72
    str r0, [sp, #56]
    str r1, [sp, #60]
    str r2, [sp, #64]
    str r3, [sp, #68]
    ldr r9, [sp, #116]
    Ldr r2, =0
    Ldr r3, =0
    b bb3_0
bb3_0:
    ldr r12, =1
    ldr r4, =1
    cmp r12, r4
    ldr r5, =0
    ldreq r5, =1
    mov r4, r5
    ldr r5, =0
    cmp r4, r5
    ldr r12, =0
    ldrne r12, =1
    ldr r5, =0
    cmp r4, r5
    bne bb3_1
    str r2, [sp, #-8]
    Mov r4, r10
    Mov r5, r0
    Mov r2, r1
    ldr r12, [sp, #-8]
    Mov r6, r3
    b bb3_2
bb3_1:
    Mov r4, r10
    Mov r5, r0
    Mov r6, r1
    Ldr r10, =0
    b bb3_3
bb3_2:
    b bb3_20
bb3_3:
    ldr r0, =1
    ldr r1, =1
    cmp r0, r1
    ldr r2, =0
    ldreq r2, =1
    mov r0, r2
    ldr r1, =0
    cmp r0, r1
    ldr r2, =0
    ldrne r2, =1
    ldr r1, =0
    cmp r0, r1
    bne bb3_4
    str r6, [sp, #-8]
    Mov r6, r5
    ldr r0, [sp, #-8]
    Mov r1, r10
    b bb3_5
bb3_4:
    ldr r4, =2
    sdiv r6, r9, r4
    sub r4, r3, r6
    str r4, [sp, #-8]
    Ldr r4, =0
    ldr r6, [sp, #-8]
    b bb3_6
bb3_5:
    add r2, r3, #1
    str r0, [sp, #20]
    ldr r0, [sp, #68]
    cmp r2, r0
    ldr r12, =0
    ldrge r12, =1
    mov r7, r12
    ldr r12, =0
    cmp r7, r12
    ldr r8, =0
    ldrne r8, =1
    ldr r12, =0
    cmp r7, r12
    ldr r0, [sp, #20]
    bne bb3_18
    b bb3_19
bb3_6:
    b litpool3_0
    .pool
litpool3_0:
    ldr r7, =1
    ldr r8, =1
    cmp r7, r8
    ldr r0, =0
    ldreq r0, =1
    mov r7, r0
    ldr r8, =0
    cmp r7, r8
    ldr r0, =0
    ldrne r0, =1
    ldr r8, =0
    cmp r7, r8
    bne bb3_7
    str r5, [sp, #-8]
    Mov r5, r4
    ldr r7, [sp, #-8]
    Mov r8, r6
    b bb3_8
bb3_7:
    ldr r5, =2
    sdiv r7, r9, r5
    sub r5, r10, r7
    b bb3_9
bb3_8:
    str r1, [sp, #20]
    ldr r1, [sp, #112]
    mul r0, r3, r1
    add r1, r0, r10
    str r1, [sp, #20]
    ldr r1, [sp, #64]
    add r0, r1, #0
    ldr r2, =4
    ldr r1, [sp, #20]
    mul r12, r1, r2
    add r1, r0, r12
    str r5, [r1]
    add r0, r10, #1
    str r2, [sp, #20]
    ldr r2, [sp, #112]
    cmp r0, r2
    ldr r1, =0
    ldrge r1, =1
    mov r2, r1
    ldr r1, =0
    cmp r2, r1
    ldr r12, =0
    ldrne r12, =1
    ldr r1, =0
    cmp r2, r1
    bne bb3_16
    b bb3_17
bb3_9:
    ldr r7, =1
    ldr r8, =1
    cmp r7, r8
    ldr r0, =0
    ldreq r0, =1
    mov r7, r0
    ldr r8, =0
    cmp r7, r8
    ldr r0, =0
    ldrne r0, =1
    ldr r8, =0
    cmp r7, r8
    bne bb3_10
    Mov r7, r4
    Mov r8, r5
    b bb3_11
bb3_10:
    STM SP, {r3}
    push {r5}
    ldr r0, [sp, #64]
    ldr r1, [sp, #72]
    ldr r2, [sp, #116]
    mov r3, r6
    bl getvalue
    ADD sp, sp, #4
    LDM SP, {r3}
    mov r7, r0
    STM SP, {r3}
    ldr r0, [sp, #56]
    mov r1, r4
    mov r2, r7
    bl reduce
    LDM SP, {r3}
    mov r8, r0
    add r4, r5, #1
    ldr r5, =2
    sdiv r7, r9, r5
    add r5, r10, r7
    cmp r4, r5
    ldr r7, =0
    ldrge r7, =1
    mov r5, r7
    ldr r7, =0
    cmp r5, r7
    ldr r0, =0
    ldrne r0, =1
    ldr r7, =0
    cmp r5, r7
    bne bb3_12
    b bb3_13
bb3_11:
    add r0, r6, #1
    ldr r1, =2
    sdiv r2, r9, r1
    add r1, r3, r2
    cmp r0, r1
    ldr r2, =0
    ldrge r2, =1
    mov r1, r2
    ldr r2, =0
    cmp r1, r2
    ldr r12, =0
    ldrne r12, =1
    ldr r2, =0
    cmp r1, r2
    bne bb3_14
    b bb3_15
bb3_12:
    b litpool3_1
    .pool
litpool3_1:
    Mov r7, r8
    Mov r8, r4
    b bb3_11
bb3_13:
    str r4, [sp, #-8]
    Mov r4, r8
    ldr r5, [sp, #-8]
    b bb3_9
bb3_14:
    Mov r5, r7
    Mov r7, r8
    Mov r8, r0
    b bb3_8
bb3_15:
    Mov r4, r7
    Mov r5, r8
    Mov r6, r0
    b bb3_6
bb3_16:
    str r0, [sp, #-8]
    Mov r4, r5
    Mov r6, r7
    Mov r0, r8
    ldr r1, [sp, #-8]
    b bb3_5
bb3_17:
    Mov r4, r5
    Mov r5, r7
    Mov r6, r8
    Mov r10, r0
    b bb3_3
bb3_18:
    str r2, [sp, #-8]
    Mov r5, r6
    Mov r2, r0
    Mov r12, r1
    ldr r6, [sp, #-8]
    b bb3_2
bb3_19:
    str r0, [sp, #-8]
    str r1, [sp, #-12]
    str r2, [sp, #-16]
    Mov r10, r4
    Mov r0, r6
    ldr r1, [sp, #-8]
    ldr r2, [sp, #-12]
    ldr r3, [sp, #-16]
    b bb3_0
bb3_20:
    ldr r0, =0
    mov sp, r11
    pop {r4, r5, r6, r7, r8, r9, r10, r11, r12, lr}
    bx lr
    .pool

    .globl memmove
    .p2align 2
    .type memmove, %function
memmove:
    push {r4, r5, r6, r7, r8, r9, r10, lr}
    sub sp, sp, #16
    Mov r4, r0
    Mov r5, r1
    Mov r6, r2
    Ldr r7, =0
    b bb4_0
bb4_0:
    cmp r7, r6
    ldr r8, =0
    ldrlt r8, =1
    mov r9, r8
    ldr r8, =0
    cmp r9, r8
    ldr r10, =0
    ldrne r10, =1
    ldr r8, =0
    cmp r9, r8
    bne bb4_1
    b bb4_2
bb4_1:
    b litpool4_0
    .pool
litpool4_0:
    add r8, r5, #0
    ldr r9, =4
    mul r10, r7, r9
    add r9, r8, r10
    ldr r8, [r9]
    add r9, r4, #0
    ldr r10, =4
    mul r0, r7, r10
    add r10, r9, r0
    str r8, [r10]
    add r8, r7, #1
    Mov r7, r8
    b bb4_0
bb4_2:
    b bb4_3
bb4_3:
    add sp, sp, #16
    pop {r4, r5, r6, r7, r8, r9, r10, lr}
    bx lr
    .pool

    .globl main
    .p2align 2
    .type main, %function
main:
    push {r4, r5, r6, r7, r8, r9, r10, r11, r12, lr}
    mov r11, sp
    sub sp, sp, #36
    bl current_time
    mov r4, r0
    bl get_int
    mov r5, r0
    bl get_int
    mov r6, r0
    bl get_int
    mov r7, r0
    ldr r8, Addr5_0
    ldr r9, =0
    ldr r10, =4
    mul r0, r9, r10
    add r9, r8, r0
    mov r0, r9
    bl get_int_array
    mov r8, r0
    ldr r9, Addr5_2
    ldr r10, =0
    ldr r0, =4
    mul r1, r10, r0
    add r10, r9, r1
    mov r0, r10
    bl get_int_array
    mov r9, r0
    Ldr r8, =0
    b bb5_0
bb5_0:
    cmp r8, r9
    ldr r10, =0
    ldrlt r10, =1
    mov r0, r10
    ldr r10, =0
    cmp r0, r10
    ldr r1, =0
    ldrne r1, =1
    ldr r10, =0
    cmp r0, r10
    bne bb5_1
    b bb5_2
bb5_1:
    ldr r10, Addr5_2
    ldr r0, =4
    mul r1, r8, r0
    add r0, r10, r1
    ldr r10, [r0]
    ldr r0, Addr5_0
    ldr r1, =0
    ldr r2, =4
    mul r3, r1, r2
    add r1, r0, r3
    ldr r0, Addr5_1
    ldr r2, =0
    ldr r3, =4
    mul r12, r2, r3
    add r2, r0, r12
    STM SP, {r0, r1, r2}
    push {r5}
    push {r7}
    mov r0, r10
    ldr r1, [sp, #12]
    ldr r2, [sp, #16]
    mov r3, r6
    bl convn
    ADD sp, sp, #8
    LDMIB SP, {r1, r2}
    ldr r10, Addr5_0
    ldr r1, =0
    ldr r2, =4
    mul r3, r1, r2
    add r1, r10, r3
    ldr r10, Addr5_1
    ldr r2, =0
    ldr r3, =4
    mul r12, r2, r3
    add r2, r10, r12
    mul r10, r6, r7
    STM SP, {r0, r1, r2}
    ldr r0, [sp, #4]
    ldr r1, [sp, #8]
    mov r2, r10
    bl memmove
    LDM sp, {r0, r1, r2}
    add r10, r8, #1
    Mov r8, r10
    b bb5_0
bb5_2:
    mul r10, r6, r7
    ldr r0, Addr5_0
    ldr r1, =0
    ldr r2, =4
    mul r3, r1, r2
    add r1, r0, r3
    STM SP, {r1}
    mov r0, r10
    ldr r1, [sp]
    bl put_int_array
    LDM sp, {r1}
    ldr r0, =10
    bl put_char
    bl current_time
    mov r10, r0
    sub r0, r10, r4
    STM SP, {r0}
    ldr r0, [sp]
    bl put_int
    LDM sp, {r0}
    b bb5_3
bb5_3:
    b litpool5_0
    .pool
litpool5_0:
    ldr r0, =0
    mov sp, r11
    pop {r4, r5, r6, r7, r8, r9, r10, r11, r12, lr}
    bx lr
    .pool
Addr5_0:
    .long ..a
Addr5_1:
    .long ..b
Addr5_2:
    .long ..kernelid

    .type ..a, %object
    .comm ..a, 40000000, 4

    .type ..b, %object
    .comm ..b, 40000000, 4

    .type ..kernelid, %object
    .comm ..kernelid, 40000, 4

