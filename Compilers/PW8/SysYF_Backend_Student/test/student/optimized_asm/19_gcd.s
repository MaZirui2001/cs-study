    .arch armv7ve 
    .text 
    .globl gcd
    .p2align 2
    .type gcd, %function
gcd:
    push {r4, r5, r6, r7, r8, r9, lr}
    sub sp, sp, #8
    Mov r4, r0
    Mov r6, r1
    cmp r4, r6
    ldr r8, =0
    ldrlt r8, =1
    mov r7, r8
    ldr r9, =0
    cmp r7, r9
    ldr r8, =0
    ldrne r8, =1
    ldr r9, =0
    cmp r7, r9
    bne bb0_0
    Mov r7, r4
    Mov r4, r6
    b bb0_1
bb0_0:
    Mov r7, r6
    b bb0_1
bb0_1:
    sdiv r8, r7, r4
    mul r9, r8, r4
    sub r8, r7, r9
    Mov r5, r8
    Mov r6, r7
    b bb0_2
bb0_2:
    ldr r7, =0
    cmp r5, r7
    ldr r8, =0
    ldrne r8, =1
    mov r7, r8
    ldr r9, =0
    cmp r7, r9
    ldr r8, =0
    ldrne r8, =1
    ldr r9, =0
    cmp r7, r9
    bne bb0_3
    b bb0_4
bb0_3:
    sdiv r7, r4, r5
    mul r8, r7, r5
    sub r7, r4, r8
    Mov r6, r4
    Mov r4, r5
    Mov r5, r7
    b bb0_2
bb0_4:
    b bb0_5
bb0_5:
    mov r0, r4
    add sp, sp, #8
    pop {r4, r5, r6, r7, r8, r9, lr}
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
    mov r6, r0
    bl get_int
    mov r7, r0
    mov r0, r6
    mov r1, r7
    bl gcd
    mov r5, r0
    bl current_time
    mov r6, r0
    ldr r0, =10
    bl put_char
    sub r7, r6, r4
    mov r0, r7
    bl put_int
    b bb1_0
bb1_0:
    b litpool1_0
    .pool
litpool1_0:
    mov r0, r5
    mov sp, r11
    pop {r4, r5, r6, r7, r11, lr}
    bx lr
    .pool

    .type ..n, %object
    .comm ..n, 4, 4

