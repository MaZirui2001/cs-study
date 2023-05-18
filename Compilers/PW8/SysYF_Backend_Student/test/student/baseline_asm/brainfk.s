    .arch armv7ve 
    .text 
    .globl read_program
    .p2align 2
    .type read_program, %function
read_program:
    push {r4, r5, r6, r7, r8, r9, r11, lr}
    mov r11, sp
    sub sp, sp, #4
    bl get_int
    mov r4, r0
    Ldr r5, =0
    b bb0_0
bb0_0:
    cmp r5, r4
    ldr r6, =0
    ldrlt r6, =1
    mov r7, r6
    ldr r6, =0
    cmp r7, r6
    ldr r8, =0
    ldrne r8, =1
    ldr r6, =0
    cmp r7, r6
    bne bb0_1
    b bb0_2
bb0_1:
    bl get_char
    mov r6, r0
    ldr r7, Addr0_0
    ldr r8, =4
    mul r9, r5, r8
    add r8, r7, r9
    str r6, [r8]
    add r6, r5, #1
    Mov r5, r6
    b bb0_0
bb0_2:
    ldr r6, Addr0_0
    ldr r7, =4
    mul r8, r5, r7
    add r7, r6, r8
    ldr r6, =0
    str r6, [r7]
    b bb0_3
bb0_3:
    mov sp, r11
    pop {r4, r5, r6, r7, r8, r9, r11, lr}
    bx lr
    .pool
Addr0_0:
    .long ..program

    .globl interpret
    .p2align 2
    .type interpret, %function
interpret:
    push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    mov r11, sp
    sub sp, sp, #20
    Ldr r4, =0
    b bb1_0
bb1_0:
    ldr r7, Addr1_1
    ldr r8, =4
    mul r9, r4, r8
    add r8, r7, r9
    ldr r7, [r8]
    ldr r8, =0
    cmp r7, r8
    ldr r9, =0
    ldrne r9, =1
    ldr r8, =0
    cmp r7, r8
    bne bb1_1
    b bb1_2
bb1_1:
    ldr r6, Addr1_1
    ldr r7, =4
    mul r8, r4, r7
    add r7, r6, r8
    ldr r6, [r7]
    ldr r7, =62
    cmp r6, r7
    ldr r8, =0
    ldreq r8, =1
    mov r7, r8
    ldr r8, =0
    cmp r7, r8
    ldr r9, =0
    ldrne r9, =1
    ldr r8, =0
    cmp r7, r8
    bne bb1_3
    b bb1_4
bb1_2:
    b litpool1_0
    .pool
litpool1_0:
    b bb1_33
bb1_3:
    ldr r7, Addr1_2
    ldr r7, [r7]
    add r8, r7, #1
    push {r0}
    ldr r0, Addr1_2
    str r8, [r0]
    pop {r0}
    Mov r7, r4
    Mov r8, r5
    Mov r9, r6
    b bb1_5
bb1_4:
    ldr r7, =60
    cmp r6, r7
    ldr r8, =0
    ldreq r8, =1
    mov r7, r8
    ldr r8, =0
    cmp r7, r8
    ldr r9, =0
    ldrne r9, =1
    ldr r8, =0
    cmp r7, r8
    bne bb1_6
    b bb1_7
bb1_5:
    add r10, r7, #1
    Mov r4, r10
    Mov r5, r8
    Mov r6, r9
    b bb1_0
bb1_6:
    ldr r7, Addr1_2
    ldr r7, [r7]
    sub r8, r7, #1
    push {r0}
    ldr r0, Addr1_2
    str r8, [r0]
    pop {r0}
    Mov r7, r4
    Mov r8, r5
    Mov r9, r6
    b bb1_8
bb1_7:
    ldr r7, =43
    cmp r6, r7
    ldr r8, =0
    ldreq r8, =1
    mov r7, r8
    ldr r8, =0
    cmp r7, r8
    ldr r9, =0
    ldrne r9, =1
    ldr r8, =0
    cmp r7, r8
    bne bb1_9
    b bb1_10
bb1_8:
    b bb1_5
bb1_9:
    b litpool1_1
    .pool
litpool1_1:
    ldr r7, Addr1_2
    ldr r7, [r7]
    ldr r8, Addr1_0
    ldr r9, =4
    mul r10, r7, r9
    add r7, r8, r10
    ldr r8, [r7]
    add r7, r8, #1
    ldr r8, Addr1_2
    ldr r8, [r8]
    ldr r9, Addr1_0
    ldr r10, =4
    mul r0, r8, r10
    add r8, r9, r0
    str r7, [r8]
    Mov r7, r4
    Mov r8, r5
    Mov r9, r6
    b bb1_11
bb1_10:
    ldr r7, =45
    cmp r6, r7
    ldr r8, =0
    ldreq r8, =1
    mov r7, r8
    ldr r8, =0
    cmp r7, r8
    ldr r9, =0
    ldrne r9, =1
    ldr r8, =0
    cmp r7, r8
    bne bb1_12
    b bb1_13
bb1_11:
    b bb1_8
bb1_12:
    ldr r7, Addr1_2
    ldr r7, [r7]
    ldr r8, Addr1_0
    ldr r9, =4
    mul r10, r7, r9
    add r7, r8, r10
    ldr r8, [r7]
    sub r7, r8, #1
    ldr r8, Addr1_2
    ldr r8, [r8]
    ldr r9, Addr1_0
    ldr r10, =4
    mul r0, r8, r10
    add r8, r9, r0
    str r7, [r8]
    Mov r7, r4
    Mov r8, r5
    Mov r9, r6
    b bb1_14
bb1_13:
    ldr r7, =46
    cmp r6, r7
    ldr r8, =0
    ldreq r8, =1
    mov r7, r8
    ldr r8, =0
    cmp r7, r8
    ldr r9, =0
    ldrne r9, =1
    ldr r8, =0
    cmp r7, r8
    bne bb1_15
    b bb1_16
bb1_14:
    b bb1_11
bb1_15:
    b litpool1_2
    .pool
litpool1_2:
    ldr r7, Addr1_2
    ldr r7, [r7]
    ldr r8, Addr1_0
    ldr r9, =4
    mul r10, r7, r9
    add r7, r8, r10
    ldr r8, [r7]
    mov r0, r8
    bl put_char
    Mov r7, r4
    Mov r8, r5
    Mov r9, r6
    b bb1_17
bb1_16:
    ldr r7, =44
    cmp r6, r7
    ldr r8, =0
    ldreq r8, =1
    mov r7, r8
    ldr r8, =0
    cmp r7, r8
    ldr r9, =0
    ldrne r9, =1
    ldr r8, =0
    cmp r7, r8
    bne bb1_18
    b bb1_19
bb1_17:
    b bb1_14
bb1_18:
    bl get_char
    mov r7, r0
    ldr r8, Addr1_2
    ldr r8, [r8]
    ldr r9, Addr1_0
    ldr r10, =4
    mul r0, r8, r10
    add r8, r9, r0
    str r7, [r8]
    Mov r7, r4
    Mov r8, r5
    Mov r9, r6
    b bb1_20
bb1_19:
    ldr r7, =93
    cmp r6, r7
    ldr r8, =0
    ldreq r8, =1
    mov r7, r8
    ldr r8, =0
    cmp r7, r8
    ldr r9, =0
    ldrne r9, =1
    ldr r8, =0
    cmp r7, r8
    bne bb1_21
    Mov r7, r4
    Mov r8, r5
    Mov r9, r6
    b bb1_22
bb1_20:
    b bb1_17
bb1_21:
    b litpool1_3
    .pool
litpool1_3:
    ldr r7, Addr1_2
    ldr r7, [r7]
    ldr r8, Addr1_0
    ldr r9, =4
    mul r10, r7, r9
    add r7, r8, r10
    ldr r8, [r7]
    ldr r7, =0
    cmp r8, r7
    ldr r9, =0
    ldrne r9, =1
    ldr r7, =0
    cmp r8, r7
    bne bb1_23
    Mov r7, r4
    Mov r8, r5
    Mov r9, r6
    b bb1_24
bb1_22:
    b bb1_20
bb1_23:
    Mov r7, r4
    Ldr r8, =1
    Mov r9, r6
    b bb1_25
bb1_24:
    b bb1_22
bb1_25:
    ldr r10, =0
    cmp r8, r10
    ldr r0, =0
    ldrgt r0, =1
    mov r10, r0
    ldr r0, =0
    cmp r10, r0
    ldr r1, =0
    ldrne r1, =1
    ldr r0, =0
    cmp r10, r0
    bne bb1_26
    b bb1_27
bb1_26:
    sub r9, r7, #1
    ldr r7, Addr1_1
    ldr r10, =4
    mul r0, r9, r10
    add r10, r7, r0
    ldr r7, [r10]
    ldr r10, =91
    cmp r7, r10
    ldr r0, =0
    ldreq r0, =1
    mov r10, r0
    ldr r0, =0
    cmp r10, r0
    ldr r1, =0
    ldrne r1, =1
    ldr r0, =0
    cmp r10, r0
    bne bb1_28
    b bb1_29
bb1_27:
    b bb1_24
bb1_28:
    b litpool1_4
    .pool
litpool1_4:
    sub r10, r8, #1
    b bb1_30
bb1_29:
    ldr r10, =93
    cmp r7, r10
    ldr r0, =0
    ldreq r0, =1
    mov r10, r0
    ldr r0, =0
    cmp r10, r0
    ldr r1, =0
    ldrne r1, =1
    ldr r0, =0
    cmp r10, r0
    bne bb1_31
    Mov r10, r8
    b bb1_32
bb1_30:
    str r7, [sp, #-8]
    Mov r7, r9
    Mov r8, r10
    ldr r9, [sp, #-8]
    b bb1_25
bb1_31:
    add r10, r8, #1
    b bb1_32
bb1_32:
    b bb1_30
bb1_33:
    mov sp, r11
    pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    bx lr
    .pool
Addr1_0:
    .long ..tape
Addr1_1:
    .long ..program
Addr1_2:
    .long ..ptr

    .globl main
    .p2align 2
    .type main, %function
main:
    push {r4, r5, r6, r11, lr}
    mov r11, sp
    sub sp, sp, #4
    bl current_time
    mov r4, r0
    bl read_program
    bl interpret
    ldr r0, =10
    bl put_char
    bl current_time
    mov r5, r0
    sub r6, r5, r4
    mov r0, r6
    bl put_int
    b bb2_0
bb2_0:
    ldr r0, =0
    mov sp, r11
    pop {r4, r5, r6, r11, lr}
    bx lr
    .pool

    .type ..tape, %object
    .comm ..tape, 262144, 4

    .type ..program, %object
    .comm ..program, 131072, 4

    .type ..ptr, %object
    .bss
    .globl ..ptr
    .p2align 2
..ptr:
    .long 0
    .size ..ptr, 4

