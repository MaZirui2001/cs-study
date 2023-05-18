    .arch armv7ve 
    .text 
    .globl maxSubArray
    .p2align 2
    .type maxSubArray, %function
maxSubArray:
    push {r4, r5, r6, r7, r8, r9, r10, lr}
    sub sp, sp, #16
    Mov r4, r0
    Mov r5, r1
    ldr r0, =0
    cmp r5, r0
    ldr r1, =0
    ldreq r1, =1
    mov r6, r1
    ldr r0, =0
    cmp r6, r0
    ldr r7, =0
    ldrne r7, =1
    ldr r0, =0
    cmp r6, r0
    bne bb0_0
    b bb0_1
bb0_0:
    Ldr r4, =0
    b bb0_11
bb0_1:
    ldr r0, =1
    cmp r5, r0
    ldr r1, =0
    ldreq r1, =1
    mov r6, r1
    ldr r0, =0
    cmp r6, r0
    ldr r7, =0
    ldrne r7, =1
    ldr r0, =0
    cmp r6, r0
    bne bb0_2
    b bb0_3
bb0_2:
    add r5, r4, #0
    ldr r4, =0
    ldr r0, =4
    mul r1, r4, r0
    add r0, r5, r1
    ldr r1, [r0]
    Mov r4, r1
    b bb0_11
bb0_3:
    add r6, r4, #0
    ldr r7, =0
    ldr r1, =4
    mul r0, r7, r1
    add r1, r6, r0
    ldr r0, [r1]
    Ldr r6, =1
    Mov r8, r0
    Mov r7, r0
    b bb0_4
bb0_4:
    cmp r6, r5
    ldr r10, =0
    ldrlt r10, =1
    mov r9, r10
    ldr r0, =0
    cmp r9, r0
    ldr r1, =0
    ldrne r1, =1
    ldr r0, =0
    cmp r9, r0
    bne bb0_5
    b bb0_6
bb0_5:
    b litpool0_0
    .pool
litpool0_0:
    ldr r0, =0
    cmp r8, r0
    ldr r10, =0
    ldrlt r10, =1
    mov r9, r10
    ldr r1, =0
    cmp r9, r1
    ldr r10, =0
    ldrne r10, =1
    ldr r0, =0
    cmp r9, r0
    bne bb0_7
    Mov r9, r8
    b bb0_8
bb0_6:
    Mov r5, r6
    Mov r6, r7
    Mov r4, r7
    Mov r0, r8
    b bb0_11
bb0_7:
    Ldr r9, =0
    b bb0_8
bb0_8:
    add r8, r4, #0
    ldr r0, =4
    mul r10, r6, r0
    add r1, r8, r10
    ldr r0, [r1]
    add r8, r9, r0
    cmp r7, r8
    ldr r0, =0
    ldrlt r0, =1
    mov r9, r0
    ldr r0, =0
    cmp r9, r0
    ldr r10, =0
    ldrne r10, =1
    ldr r0, =0
    cmp r9, r0
    bne bb0_9
    b bb0_10
bb0_9:
    Mov r7, r8
    b bb0_10
bb0_10:
    add r9, r6, #1
    Mov r6, r9
    b bb0_4
bb0_11:
    mov r0, r4
    add sp, sp, #16
    pop {r4, r5, r6, r7, r8, r9, r10, lr}
    bx lr
    .pool

    .globl main
    .p2align 2
    .type main, %function
main:
    push {r4, r5, r6, r7, r8, r11, lr}
    mov r11, sp
    sub sp, sp, #44
    bl current_time
    mov r4, r0
    add r5, sp, #4
    ldr r6, =0
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =-4
    str r5, [r6]
    add r5, sp, #4
    ldr r6, =1
    ldr r8, =4
    mul r7, r6, r8
    add r6, r5, r7
    ldr r5, =3
    str r5, [r6]
    add r5, sp, #4
    ldr r6, =2
    ldr r8, =4
    mul r7, r6, r8
    add r6, r5, r7
    ldr r5, =9
    str r5, [r6]
    add r5, sp, #4
    ldr r6, =3
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =-2
    str r5, [r6]
    add r5, sp, #4
    ldr r6, =4
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    add r5, sp, #4
    ldr r6, =5
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =1
    str r5, [r6]
    add r5, sp, #4
    ldr r6, =6
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =-6
    str r5, [r6]
    add r5, sp, #4
    ldr r6, =7
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =5
    str r5, [r6]
    add r5, sp, #4
    ldr r6, =8
    ldr r8, =4
    mul r7, r6, r8
    add r6, r5, r7
    ldr r5, =7
    str r5, [r6]
    add r5, sp, #4
    ldr r6, =9
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =8
    str r5, [r6]
    add r5, sp, #4
    ldr r6, =0
    ldr r8, =4
    mul r7, r6, r8
    add r6, r5, r7
    mov r0, r6
    ldr r1, =10
    bl maxSubArray
    mov r8, r0
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
    mov r0, r8
    mov sp, r11
    pop {r4, r5, r6, r7, r8, r11, lr}
    bx lr
    .pool

