    .arch armv7ve 
    .text 
    .globl counting_sort
    .p2align 2
    .type counting_sort, %function
counting_sort:
    push {r4, r5, r6, r7, r8, r9, r10, lr}
    sub sp, sp, #60
    Mov r4, r0
    Mov r6, r1
    Mov r5, r2
    Ldr r7, =0
    b bb0_0
bb0_0:
    ldr r1, =10
    cmp r7, r1
    ldr r0, =0
    ldrlt r0, =1
    mov r8, r0
    ldr r0, =0
    cmp r8, r0
    ldr r9, =0
    ldrne r9, =1
    ldr r0, =0
    cmp r8, r0
    bne bb0_1
    b bb0_2
bb0_1:
    add r8, sp, #8
    ldr r0, =4
    mul r10, r7, r0
    add r9, r8, r10
    ldr r0, =0
    str r0, [r9]
    add r0, r7, #1
    Mov r7, r0
    b bb0_0
bb0_2:
    Ldr r7, =0
    b bb0_3
bb0_3:
    cmp r7, r5
    ldr r0, =0
    ldrlt r0, =1
    mov r8, r0
    ldr r0, =0
    cmp r8, r0
    ldr r9, =0
    ldrne r9, =1
    ldr r10, =0
    cmp r8, r10
    bne bb0_4
    b bb0_5
bb0_4:
    add r8, r4, #0
    ldr r0, =4
    mul r1, r7, r0
    add r0, r8, r1
    ldr r9, [r0]
    add r8, sp, #8
    ldr r1, =4
    mul r0, r9, r1
    add r1, r8, r0
    ldr r9, [r1]
    add r8, r9, #1
    add r9, r4, #0
    ldr r0, =4
    mul r10, r7, r0
    add r0, r9, r10
    ldr r10, [r0]
    add r9, sp, #8
    ldr r1, =4
    mul r0, r10, r1
    add r1, r9, r0
    str r8, [r1]
    add r0, r7, #1
    Mov r7, r0
    b bb0_3
bb0_5:
    Ldr r7, =1
    b bb0_6
bb0_6:
    b litpool0_0
    .pool
litpool0_0:
    ldr r0, =10
    cmp r7, r0
    ldr r1, =0
    ldrlt r1, =1
    mov r8, r1
    ldr r0, =0
    cmp r8, r0
    ldr r9, =0
    ldrne r9, =1
    ldr r0, =0
    cmp r8, r0
    bne bb0_7
    b bb0_8
bb0_7:
    add r8, sp, #8
    ldr r0, =4
    mul r1, r7, r0
    add r0, r8, r1
    ldr r8, [r0]
    sub r9, r7, #1
    add r10, sp, #8
    ldr r1, =4
    mul r0, r9, r1
    add r9, r10, r0
    ldr r0, [r9]
    add r1, r8, r0
    add r8, sp, #8
    ldr r0, =4
    mul r10, r7, r0
    add r0, r8, r10
    str r1, [r0]
    add r0, r7, #1
    Mov r7, r0
    b bb0_6
bb0_8:
    b bb0_9
bb0_9:
    ldr r1, =0
    cmp r5, r1
    ldr r0, =0
    ldrgt r0, =1
    mov r7, r0
    ldr r0, =0
    cmp r7, r0
    ldr r8, =0
    ldrne r8, =1
    ldr r0, =0
    cmp r7, r0
    bne bb0_10
    b bb0_11
bb0_10:
    sub r7, r5, #1
    add r8, r4, #0
    ldr r0, =4
    mul r10, r7, r0
    add r9, r8, r10
    ldr r7, [r9]
    add r8, sp, #8
    ldr r0, =4
    mul r1, r7, r0
    add r7, r8, r1
    ldr r0, [r7]
    sub r7, r0, #1
    sub r9, r5, #1
    add r8, r4, #0
    ldr r1, =4
    mul r0, r9, r1
    add r1, r8, r0
    ldr r8, [r1]
    add r9, sp, #8
    ldr r1, =4
    mul r0, r8, r1
    add r1, r9, r0
    str r7, [r1]
    sub r8, r5, #1
    add r7, r4, #0
    ldr r0, =4
    mul r1, r8, r0
    add r0, r7, r1
    ldr r7, [r0]
    sub r9, r5, #1
    add r8, r4, #0
    ldr r0, =4
    mul r10, r9, r0
    add r9, r8, r10
    ldr r8, [r9]
    add r9, sp, #8
    ldr r10, =4
    mul r0, r8, r10
    add r10, r9, r0
    ldr r8, [r10]
    add r9, r6, #0
    ldr r1, =4
    mul r0, r8, r1
    add r1, r9, r0
    str r7, [r1]
    sub r7, r5, #1
    Mov r5, r7
    b bb0_9
bb0_11:
    b bb0_12
bb0_12:
    b litpool0_1
    .pool
litpool0_1:
    ldr r0, =0
    add sp, sp, #60
    pop {r4, r5, r6, r7, r8, r9, r10, lr}
    bx lr
    .pool

    .globl main
    .p2align 2
    .type main, %function
main:
    push {r4, r5, r6, r7, r8, r9, r11, lr}
    mov r11, sp
    sub sp, sp, #84
    bl current_time
    mov r4, r0
    ldr r5, =10
    push {r0}
    ldr r0, Addr1_0
    str r5, [r0]
    pop {r0}
    add r5, sp, #4
    ldr r6, =0
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =4
    str r5, [r6]
    add r5, sp, #4
    ldr r6, =1
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =3
    str r5, [r6]
    add r5, sp, #4
    ldr r6, =2
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =9
    str r5, [r6]
    add r5, sp, #4
    ldr r6, =3
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =2
    str r5, [r6]
    add r5, sp, #4
    ldr r6, =4
    ldr r8, =4
    mul r7, r6, r8
    add r6, r5, r7
    ldr r5, =0
    str r5, [r6]
    add r5, sp, #4
    ldr r6, =5
    ldr r8, =4
    mul r7, r6, r8
    add r6, r5, r7
    ldr r5, =1
    str r5, [r6]
    add r5, sp, #4
    ldr r6, =6
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =6
    str r5, [r6]
    add r5, sp, #4
    ldr r6, =7
    ldr r8, =4
    mul r7, r6, r8
    add r6, r5, r7
    ldr r5, =5
    str r5, [r6]
    add r5, sp, #4
    ldr r6, =8
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =7
    str r5, [r6]
    add r5, sp, #4
    ldr r6, =9
    ldr r8, =4
    mul r7, r6, r8
    add r6, r5, r7
    ldr r5, =8
    str r5, [r6]
    add r9, sp, #4
    ldr r5, =0
    ldr r8, =4
    mul r7, r5, r8
    add r5, r9, r7
    add r6, sp, #44
    ldr r7, =0
    ldr r8, =4
    mul r9, r7, r8
    add r7, r6, r9
    ldr r6, Addr1_0
    ldr r6, [r6]
    mov r0, r5
    mov r1, r7
    mov r2, r6
    bl counting_sort
    mov r8, r0
    Mov r5, r8
    b bb1_0
bb1_0:
    ldr r6, Addr1_0
    ldr r6, [r6]
    cmp r5, r6
    ldr r7, =0
    ldrlt r7, =1
    mov r6, r7
    ldr r8, =0
    cmp r6, r8
    ldr r9, =0
    ldrne r9, =1
    ldr r8, =0
    cmp r6, r8
    bne bb1_1
    b bb1_2
bb1_1:
    add r6, sp, #44
    ldr r7, =4
    mul r8, r5, r7
    add r7, r6, r8
    ldr r6, [r7]
    mov r0, r6
    bl put_int
    ldr r0, =10
    bl put_char
    add r6, r5, #1
    Mov r5, r6
    b bb1_0
bb1_2:
    bl current_time
    mov r5, r0
    ldr r0, =10
    bl put_char
    sub r6, r5, r4
    mov r0, r6
    bl put_int
    b bb1_3
bb1_3:
    b litpool1_0
    .pool
litpool1_0:
    ldr r0, =0
    mov sp, r11
    pop {r4, r5, r6, r7, r8, r9, r11, lr}
    bx lr
    .pool
Addr1_0:
    .long ..n

    .type ..n, %object
    .comm ..n, 4, 4

