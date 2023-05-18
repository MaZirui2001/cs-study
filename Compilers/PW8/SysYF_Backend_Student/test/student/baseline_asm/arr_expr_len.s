    .arch armv7ve 
    .text 
    .globl main
    .p2align 2
    .type main, %function
main:
    push {r4, r5, r6, r7, r8, r9, r11, lr}
    mov r11, sp
    sub sp, sp, #4
    bl current_time
    mov r4, r0
    Ldr r5, =0
    Ldr r6, =0
    b bb0_0
bb0_0:
    ldr r7, =6
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
    bne bb0_1
    b bb0_2
bb0_1:
    ldr r7, Addr0_0
    ldr r8, =4
    mul r9, r6, r8
    add r8, r7, r9
    ldr r7, [r8]
    add r8, r5, r7
    add r5, r6, #1
    str r5, [sp, #-8]
    Mov r5, r8
    ldr r6, [sp, #-8]
    b bb0_0
bb0_2:
    ldr r0, =10
    bl put_char
    bl current_time
    mov r7, r0
    sub r8, r7, r4
    mov r0, r8
    bl put_int
    b bb0_3
bb0_3:
    mov r0, r5
    mov sp, r11
    pop {r4, r5, r6, r7, r8, r9, r11, lr}
    bx lr
    .pool
Addr0_0:
    .long ..arr

    .type ..arr, %object
    .data
    .globl ..arr
    .p2align 2
..arr:
    .long 1
    .long 2
    .long 33
    .long 4
    .long 5
    .long 6
    .size ..arr, 24

