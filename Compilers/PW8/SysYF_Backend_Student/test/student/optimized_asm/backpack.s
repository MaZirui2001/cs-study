    .arch armv7ve 
    .text 
    .globl KnapSack
    .p2align 2
    .type KnapSack, %function
KnapSack:
    push {r4, r5, r6, r7, r8, r9, r10, lr}
    sub sp, sp, #24
    Mov r4, r0
    Mov r5, r1
    Ldr r6, =1
    b bb0_0
bb0_0:
    cmp r6, r4
    ldr r0, =0
    ldrle r0, =1
    mov r10, r0
    ldr r1, =0
    cmp r10, r1
    ldr r0, =0
    ldrne r0, =1
    ldr r1, =0
    cmp r10, r1
    bne bb0_1
    b bb0_2
bb0_1:
    Ldr r9, =0
    b bb0_3
bb0_2:
    Mov r7, r5
    Mov r6, r4
    b bb0_12
bb0_3:
    add r1, r5, #1
    cmp r9, r1
    ldr r0, =0
    ldrlt r0, =1
    mov r10, r0
    ldr r1, =0
    cmp r10, r1
    ldr r0, =0
    ldrne r0, =1
    ldr r1, =0
    cmp r10, r1
    bne bb0_4
    b bb0_5
bb0_4:
    ldr r0, Addr0_1
    ldr r1, =4
    mul r2, r6, r1
    add r1, r0, r2
    ldr r0, [r1]
    cmp r9, r0
    ldr r1, =0
    ldrlt r1, =1
    mov r10, r1
    ldr r1, =0
    cmp r10, r1
    ldr r0, =0
    ldrne r0, =1
    ldr r1, =0
    cmp r10, r1
    bne bb0_6
    b bb0_7
bb0_5:
    add r0, r6, #1
    Mov r6, r0
    b bb0_0
bb0_6:
    b litpool0_0
    .pool
litpool0_0:
    sub r0, r6, #1
    ldr r1, =200
    mul r2, r0, r1
    add r1, r2, r9
    ldr r0, Addr0_0
    ldr r2, =4
    mul r10, r1, r2
    add r1, r0, r10
    ldr r10, [r1]
    ldr r1, =200
    mul r0, r6, r1
    add r1, r0, r9
    ldr r0, Addr0_0
    ldr r2, =4
    mul r3, r1, r2
    add r1, r0, r3
    str r10, [r1]
    Mov r0, r7
    Mov r1, r8
    b bb0_8
bb0_7:
    sub r0, r6, #1
    ldr r2, =200
    mul r1, r0, r2
    add r7, r1, r9
    ldr r0, Addr0_0
    ldr r2, =4
    mul r1, r7, r2
    add r2, r0, r1
    ldr r7, [r2]
    sub r0, r6, #1
    ldr r2, =200
    mul r1, r0, r2
    add r8, r1, r9
    ldr r0, Addr0_1
    ldr r1, =4
    mul r10, r6, r1
    add r2, r0, r10
    ldr r1, [r2]
    sub r0, r8, r1
    ldr r8, Addr0_0
    ldr r1, =4
    mul r2, r0, r1
    add r0, r8, r2
    ldr r10, [r0]
    ldr r0, Addr0_2
    ldr r1, =4
    mul r2, r6, r1
    add r1, r0, r2
    ldr r0, [r1]
    add r8, r10, r0
    cmp r7, r8
    ldr r0, =0
    ldrgt r0, =1
    mov r10, r0
    ldr r1, =0
    cmp r10, r1
    ldr r0, =0
    ldrne r0, =1
    ldr r1, =0
    cmp r10, r1
    bne bb0_9
    b bb0_10
bb0_8:
    add r2, r9, #1
    Mov r7, r0
    Mov r8, r1
    Mov r9, r2
    b bb0_3
bb0_9:
    ldr r0, =200
    mul r2, r6, r0
    add r1, r2, r9
    ldr r0, Addr0_0
    ldr r10, =4
    mul r2, r1, r10
    add r1, r0, r2
    str r7, [r1]
    b bb0_11
bb0_10:
    ldr r0, =200
    mul r1, r6, r0
    add r3, r1, r9
    ldr r10, Addr0_0
    ldr r1, =4
    mul r2, r3, r1
    add r0, r10, r2
    str r8, [r0]
    b bb0_11
bb0_11:
    b litpool0_1
    .pool
litpool0_1:
    Mov r0, r8
    Mov r1, r7
    b bb0_8
bb0_12:
    ldr r1, =1
    cmp r6, r1
    ldr r0, =0
    ldrge r0, =1
    mov r8, r0
    ldr r1, =0
    cmp r8, r1
    ldr r0, =0
    ldrne r0, =1
    ldr r1, =0
    cmp r8, r1
    bne bb0_13
    b bb0_14
bb0_13:
    ldr r0, =200
    mul r1, r6, r0
    add r0, r1, r7
    ldr r8, Addr0_0
    ldr r1, =4
    mul r2, r0, r1
    add r0, r8, r2
    ldr r8, [r0]
    sub r0, r6, #1
    ldr r2, =200
    mul r1, r0, r2
    add r9, r1, r7
    ldr r0, Addr0_0
    ldr r1, =4
    mul r2, r9, r1
    add r1, r0, r2
    ldr r0, [r1]
    cmp r8, r0
    ldr r1, =0
    ldrgt r1, =1
    mov r8, r1
    ldr r1, =0
    cmp r8, r1
    ldr r0, =0
    ldrne r0, =1
    ldr r1, =0
    cmp r8, r1
    bne bb0_15
    b bb0_16
bb0_14:
    ldr r0, =200
    mul r1, r4, r0
    add r0, r1, r5
    ldr r4, Addr0_0
    ldr r2, =4
    mul r1, r0, r2
    add r2, r4, r1
    ldr r0, [r2]
    b bb0_18
bb0_15:
    ldr r0, Addr0_3
    ldr r1, =4
    mul r2, r6, r1
    add r1, r0, r2
    ldr r0, =1
    str r0, [r1]
    ldr r8, Addr0_1
    ldr r1, =4
    mul r0, r6, r1
    add r1, r8, r0
    ldr r0, [r1]
    sub r1, r7, r0
    Mov r0, r1
    b bb0_17
bb0_16:
    ldr r0, Addr0_3
    ldr r1, =4
    mul r2, r6, r1
    add r1, r0, r2
    ldr r0, =0
    str r0, [r1]
    Mov r0, r7
    b bb0_17
bb0_17:
    sub r1, r6, #1
    Mov r7, r0
    Mov r6, r1
    b bb0_12
bb0_18:
    b litpool0_2
    .pool
litpool0_2:
    add sp, sp, #24
    pop {r4, r5, r6, r7, r8, r9, r10, lr}
    bx lr
    .pool
Addr0_0:
    .long ..V
Addr0_1:
    .long ..w
Addr0_2:
    .long ..v
Addr0_3:
    .long ..x

    .globl main
    .p2align 2
    .type main, %function
main:
    push {r4, r5, r6, r11, lr}
    mov r11, sp
    sub sp, sp, #4
    bl current_time
    mov r4, r0
    ldr r0, =5
    ldr r1, =10
    bl KnapSack
    mov r5, r0
    mov r0, r5
    bl put_int
    ldr r0, =10
    bl put_char
    bl current_time
    mov r5, r0
    sub r6, r5, r4
    mov r0, r6
    bl put_int
    b bb1_0
bb1_0:
    ldr r0, =0
    mov sp, r11
    pop {r4, r5, r6, r11, lr}
    bx lr
    .pool

    .type ..V, %object
    .bss
    .globl ..V
    .p2align 2
..V:
    .zero 160000
    .size ..V, 160000

    .type ..w, %object
    .data
    .globl ..w
    .p2align 2
..w:
    .long 0
    .long 2
    .long 2
    .long 6
    .long 5
    .long 4
    .size ..w, 24

    .type ..v, %object
    .data
    .globl ..v
    .p2align 2
..v:
    .long 0
    .long 6
    .long 3
    .long 5
    .long 4
    .long 6
    .size ..v, 24

    .type ..x, %object
    .comm ..x, 24, 4

