    .arch armv7ve 
    .text 
    .globl move
    .p2align 2
    .type move, %function
move:
    push {r4, r5, r11, lr}
    mov r11, sp
    sub sp, sp, #12
    Mov r4, r0
    Mov r5, r1
    mov r0, r4
    bl put_int
    ldr r0, =32
    bl put_char
    mov r0, r5
    bl put_int
    ldr r0, =44
    bl put_char
    ldr r0, =32
    bl put_char
    b bb0_0
bb0_0:
    mov sp, r11
    pop {r4, r5, r11, lr}
    bx lr
    .pool

    .globl hanoi
    .p2align 2
    .type hanoi, %function
hanoi:
    push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    mov r11, sp
    sub sp, sp, #20
    Mov r4, r0
    Mov r5, r1
    Mov r6, r2
    Mov r7, r3
    ldr r8, =1
    cmp r4, r8
    ldr r9, =0
    ldreq r9, =1
    mov r8, r9
    ldr r9, =0
    cmp r8, r9
    ldr r10, =0
    ldrne r10, =1
    ldr r9, =0
    cmp r8, r9
    bne bb1_0
    b bb1_1
bb1_0:
    mov r0, r5
    mov r1, r7
    bl move
    b bb1_2
bb1_1:
    sub r8, r4, #1
    mov r0, r8
    mov r1, r5
    mov r2, r7
    mov r3, r6
    bl hanoi
    mov r0, r5
    mov r1, r7
    bl move
    sub r8, r4, #1
    mov r0, r8
    mov r1, r6
    mov r2, r5
    mov r3, r7
    bl hanoi
    b bb1_2
bb1_2:
    b bb1_3
bb1_3:
    mov sp, r11
    pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    bx lr
    .pool

    .globl main
    .p2align 2
    .type main, %function
main:
    push {r4, r5, r6, r7, r8, r11, lr}
    mov r11, sp
    sub sp, sp, #4
    bl current_time
    mov r4, r0
    bl get_int
    mov r5, r0
    b bb2_0
bb2_0:
    b litpool2_0
    .pool
litpool2_0:
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
    bne bb2_1
    b bb2_2
bb2_1:
    bl get_int
    mov r6, r0
    mov r0, r6
    ldr r1, =1
    ldr r2, =2
    ldr r3, =3
    bl hanoi
    ldr r0, =10
    bl put_char
    sub r6, r5, #1
    Mov r5, r6
    b bb2_0
bb2_2:
    ldr r0, =10
    bl put_char
    bl current_time
    mov r6, r0
    sub r7, r6, r4
    mov r0, r7
    bl put_int
    b bb2_3
bb2_3:
    ldr r0, =0
    mov sp, r11
    pop {r4, r5, r6, r7, r8, r11, lr}
    bx lr
    .pool

