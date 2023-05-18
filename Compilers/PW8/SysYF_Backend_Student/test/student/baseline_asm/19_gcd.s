    .arch armv7ve 
    .text 
    .globl gcd
    .p2align 2
    .type gcd, %function
gcd:
    push {r4, r5, r6, r7, r8, r9, r10, lr}
    sub sp, sp, #12
    Mov r4, r0
    Mov r5, r1
    cmp r4, r5
    ldr r7, =0
    ldrlt r7, =1
    mov r8, r7
    ldr r7, =0
    cmp r8, r7
    ldr r9, =0
    ldrne r9, =1
    ldr r7, =0
    cmp r8, r7
    bne bb0_0
    Mov r8, r5
    Mov r9, r4
    b bb0_1
bb0_0:
    Mov r8, r4
    Mov r9, r5
    b bb0_1
bb0_1:
    sdiv r10, r9, r8
    mul r0, r10, r8
    sub r10, r9, r0
    Mov r6, r10
    Mov r7, r8
    Mov r8, r9
    b bb0_2
bb0_2:
    ldr r9, =0
    cmp r6, r9
    ldr r10, =0
    ldrne r10, =1
    mov r9, r10
    ldr r10, =0
    cmp r9, r10
    ldr r0, =0
    ldrne r0, =1
    ldr r10, =0
    cmp r9, r10
    bne bb0_3
    b bb0_4
bb0_3:
    sdiv r9, r7, r6
    mul r10, r9, r6
    sub r9, r7, r10
    str r6, [sp, #-8]
    str r7, [sp, #-12]
    Mov r6, r9
    ldr r7, [sp, #-8]
    ldr r8, [sp, #-12]
    b bb0_2
bb0_4:
    b bb0_5
bb0_5:
    mov r0, r7
    add sp, sp, #12
    pop {r4, r5, r6, r7, r8, r9, r10, lr}
    bx lr
    .pool

    .globl main
    .p2align 2
    .type main, %function
main:
    push {r4, r5, r6, r7, r11, lr}
    mov r11, sp
    sub sp, sp, #4
    bl current_time
    mov r4, r0
    bl get_int
    mov r5, r0
    bl get_int
    mov r6, r0
    mov r0, r5
    mov r1, r6
    bl gcd
    mov r7, r0
    bl current_time
    mov r5, r0
    ldr r0, =10
    bl put_char
    sub r6, r5, r4
    mov r0, r6
    bl put_int
    b bb1_0
bb1_0:
    b litpool1_0
    .pool
litpool1_0:
    mov r0, r7
    mov sp, r11
    pop {r4, r5, r6, r7, r11, lr}
    bx lr
    .pool

    .type ..n, %object
    .comm ..n, 4, 4

