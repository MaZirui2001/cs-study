    .arch armv7ve 
    .text 
    .globl myFunc
    .p2align 2
    .type myFunc, %function
myFunc:
    push {r4, r5, r6, r7, r8, lr}
    sub sp, sp, #12
    Mov r4, r1
    ldr r5, =0
    ldr r6, =0
    cmp r5, r6
    ldr r7, =0
    ldrne r7, =1
    mov r5, r7
    ldr r6, =0
    cmp r5, r6
    ldr r7, =0
    ldrne r7, =1
    ldr r6, =0
    cmp r5, r6
    bne bb0_0
    b bb0_1
bb0_0:
    Ldr r6, =0
    Mov r7, r4
    b bb0_5
bb0_1:
    Mov r5, r4
    b bb0_2
bb0_2:
    ldr r6, =0
    cmp r5, r6
    ldr r7, =0
    ldrgt r7, =1
    mov r6, r7
    ldr r7, =0
    cmp r6, r7
    ldr r8, =0
    ldrne r8, =1
    ldr r7, =0
    cmp r6, r7
    bne bb0_3
    b bb0_4
bb0_3:
    sub r6, r5, #1
    Mov r5, r6
    b bb0_2
bb0_4:
    add r6, r5, #2
    Mov r7, r5
    b bb0_5
bb0_5:
    mov r0, r6
    add sp, sp, #12
    pop {r4, r5, r6, r7, r8, lr}
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
    ldr r5, =3
    push {r0}
    ldr r0, Addr1_0
    str r5, [r0]
    pop {r0}
    ldr r0, =1
    ldr r1, =2
    ldr r2, =1
    bl myFunc
    mov r5, r0
    bl current_time
    mov r6, r0
    ldr r0, =10
    bl put_char
    sub r7, r6, r4
    mov r0, r7
    bl put_int
    ldr r4, Addr1_0
    ldr r4, [r4]
    add r6, r4, r5
    b bb1_0
bb1_0:
    b litpool1_0
    .pool
litpool1_0:
    mov r0, r6
    mov sp, r11
    pop {r4, r5, r6, r7, r11, lr}
    bx lr
    .pool
Addr1_0:
    .long ..a

    .type ..a, %object
    .comm ..a, 4, 4

