    .arch armv7ve 
    .text 
    .globl long_array
    .p2align 2
    .type long_array, %function
long_array:
    push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    mov r11, sp
    ldr lr, =120032
    sub sp, sp, lr
    Mov r4, r0
    Ldr r2, =0
    b bb0_0
bb0_0:
    ldr r0, =10000
    cmp r2, r0
    ldr r1, =0
    ldrlt r1, =1
    mov r6, r1
    ldr r0, =0
    cmp r6, r0
    ldr r7, =0
    ldrne r7, =1
    ldr r0, =0
    cmp r6, r0
    bne bb0_1
    b bb0_2
bb0_1:
    mul r6, r2, r2
    ldr r8, =10
    sdiv r7, r6, r8
    ldr r1, =10
    mul r0, r7, r1
    sub r7, r6, r0
    add r6, sp, #28
    ldr r1, =4
    mul r0, r2, r1
    add r1, r6, r0
    str r7, [r1]
    add r0, r2, #1
    Mov r2, r0
    b bb0_0
bb0_2:
    Ldr r5, =0
    b bb0_3
bb0_3:
    ldr r1, =10000
    cmp r5, r1
    ldr r0, =0
    ldrlt r0, =1
    mov r6, r0
    ldr r0, =0
    cmp r6, r0
    ldr r7, =0
    ldrne r7, =1
    ldr r0, =0
    cmp r6, r0
    bne bb0_4
    b bb0_5
bb0_4:
    add r6, sp, #28
    ldr r0, =4
    mul r1, r5, r0
    add r0, r6, r1
    ldr r6, [r0]
    add r7, sp, #28
    ldr r1, =4
    mul r0, r5, r1
    add r1, r7, r0
    ldr r0, [r1]
    mul r7, r6, r0
    ldr r0, =10
    sdiv r6, r7, r0
    ldr r1, =10
    mul r0, r6, r1
    sub r6, r7, r0
    ldr r7, =40028
    add r7, sp, r7
    ldr r8, =4
    mul r0, r5, r8
    add r1, r7, r0
    str r6, [r1]
    add r0, r5, #1
    Mov r5, r0
    b bb0_3
bb0_5:
    Ldr r5, =0
    b bb0_6
bb0_6:
    b litpool0_0
    .pool
litpool0_0:
    ldr r1, =10000
    cmp r5, r1
    ldr r0, =0
    ldrlt r0, =1
    mov r6, r0
    ldr r0, =0
    cmp r6, r0
    ldr r7, =0
    ldrne r7, =1
    ldr r0, =0
    cmp r6, r0
    bne bb0_7
    b bb0_8
bb0_7:
    ldr r6, =40028
    add r6, sp, r6
    ldr r1, =4
    mul r0, r5, r1
    add r1, r6, r0
    ldr r6, [r1]
    ldr r7, =40028
    add r7, sp, r7
    ldr r0, =4
    mul r1, r5, r0
    add r0, r7, r1
    ldr r1, [r0]
    mul r7, r6, r1
    ldr r0, =100
    sdiv r6, r7, r0
    ldr r1, =100
    mul r0, r6, r1
    sub r6, r7, r0
    add r7, sp, #28
    ldr r1, =4
    mul r0, r5, r1
    add r1, r7, r0
    ldr r0, [r1]
    add r7, r6, r0
    ldr r6, =80028
    add r6, sp, r6
    ldr r0, =4
    mul r1, r5, r0
    add r0, r6, r1
    str r7, [r0]
    add r0, r5, #1
    Mov r5, r0
    b bb0_6
bb0_8:
    Ldr r7, =0
    Ldr r8, =0
    b bb0_9
bb0_9:
    ldr r1, =10000
    cmp r7, r1
    ldr r0, =0
    ldrlt r0, =1
    mov r9, r0
    ldr r0, =0
    cmp r9, r0
    ldr r10, =0
    ldrne r10, =1
    ldr r0, =0
    cmp r9, r0
    bne bb0_10
    b bb0_11
bb0_10:
    ldr r0, =10
    cmp r7, r0
    ldr r1, =0
    ldrlt r1, =1
    mov r9, r1
    ldr r0, =0
    cmp r9, r0
    ldr r10, =0
    ldrne r10, =1
    ldr r1, =0
    cmp r9, r1
    bne bb0_12
    b bb0_13
bb0_11:
    b bb0_30
bb0_12:
    b litpool0_1
    .pool
litpool0_1:
    ldr r10, =80028
    add r10, sp, r10
    ldr r0, =4
    mul r1, r7, r0
    add r0, r10, r1
    ldr r1, [r0]
    add r10, r8, r1
    ldr r0, =1333
    sdiv r8, r10, r0
    ldr r1, =1333
    mul r0, r8, r1
    sub r1, r10, r0
    STM SP, {r1}
    ldr r0, [sp]
    bl put_int
    LDM sp, {r1}
    Mov r8, r1
    b bb0_14
bb0_13:
    ldr r1, =20
    cmp r7, r1
    ldr r0, =0
    ldrlt r0, =1
    mov r9, r0
    ldr r0, =0
    cmp r9, r0
    ldr r10, =0
    ldrne r10, =1
    ldr r0, =0
    cmp r9, r0
    bne bb0_15
    b bb0_16
bb0_14:
    add r0, r7, #1
    Mov r7, r0
    b bb0_9
bb0_15:
    Ldr r6, =5000
    b bb0_18
bb0_16:
    ldr r0, =30
    cmp r7, r0
    ldr r1, =0
    ldrlt r1, =1
    mov r9, r1
    ldr r0, =0
    cmp r9, r0
    ldr r10, =0
    ldrne r10, =1
    ldr r0, =0
    cmp r9, r0
    bne bb0_21
    b bb0_22
bb0_17:
    Mov r8, r0
    b bb0_14
bb0_18:
    b litpool0_2
    .pool
litpool0_2:
    ldr r1, =10000
    cmp r6, r1
    ldr r0, =0
    ldrlt r0, =1
    mov r9, r0
    ldr r0, =0
    cmp r9, r0
    ldr r10, =0
    ldrne r10, =1
    ldr r0, =0
    cmp r9, r0
    bne bb0_19
    b bb0_20
bb0_19:
    ldr r9, =80028
    add r9, sp, r9
    ldr r0, =4
    mul r1, r7, r0
    add r0, r9, r1
    ldr r1, [r0]
    add r9, r8, r1
    add r8, sp, #28
    ldr r0, =4
    mul r10, r6, r0
    add r1, r8, r10
    ldr r0, [r1]
    sub r8, r9, r0
    add r0, r6, #1
    Mov r6, r0
    b bb0_18
bb0_20:
    mov r0, r8
    bl put_int
    Mov r0, r8
    b bb0_17
bb0_21:
    Ldr r5, =5000
    b bb0_24
bb0_22:
    ldr r10, =80028
    add r10, sp, r10
    ldr r1, =4
    mul r0, r7, r1
    add r2, r10, r0
    ldr r1, [r2]
    mul r0, r1, r4
    add r10, r8, r0
    ldr r0, =99988
    sdiv r8, r10, r0
    ldr r2, =99988
    mul r0, r8, r2
    sub r8, r10, r0
    Mov r0, r8
    b bb0_23
bb0_23:
    b bb0_17
bb0_24:
    b litpool0_3
    .pool
litpool0_3:
    ldr r1, =10000
    cmp r5, r1
    ldr r0, =0
    ldrlt r0, =1
    mov r9, r0
    ldr r0, =0
    cmp r9, r0
    ldr r10, =0
    ldrne r10, =1
    ldr r0, =0
    cmp r9, r0
    bne bb0_25
    b bb0_26
bb0_25:
    ldr r0, =2233
    cmp r5, r0
    ldr r1, =0
    ldrgt r1, =1
    mov r9, r1
    ldr r0, =0
    cmp r9, r0
    ldr r10, =0
    ldrne r10, =1
    ldr r0, =0
    cmp r9, r0
    bne bb0_27
    b bb0_28
bb0_26:
    mov r0, r8
    bl put_int
    Mov r0, r8
    b bb0_23
bb0_27:
    ldr r9, =40028
    add r9, sp, r9
    ldr r1, =4
    mul r0, r7, r1
    add r1, r9, r0
    ldr r0, [r1]
    add r9, r8, r0
    add r8, sp, #28
    ldr r1, =4
    mul r0, r5, r1
    add r1, r8, r0
    ldr r0, [r1]
    sub r8, r9, r0
    add r0, r5, #1
    Mov r5, r0
    Mov r0, r8
    b bb0_29
bb0_28:
    add r10, sp, #28
    ldr r1, =4
    mul r0, r7, r1
    add r1, r10, r0
    ldr r0, [r1]
    add r10, r8, r0
    ldr r8, =80028
    add r8, sp, r8
    ldr r1, =4
    mul r0, r5, r1
    add r1, r8, r0
    ldr r0, [r1]
    add r8, r10, r0
    ldr r0, =13333
    sdiv r10, r8, r0
    ldr r1, =13333
    mul r0, r10, r1
    sub r10, r8, r0
    add r0, r5, #2
    Mov r5, r0
    Mov r0, r10
    b bb0_29
bb0_29:
    Mov r8, r0
    b bb0_24
bb0_30:
    b litpool0_4
    .pool
litpool0_4:
    mov r0, r8
    mov sp, r11
    pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
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
    mov r5, r0
    ldr r0, =9
    bl long_array
    mov r4, r0
    ldr r0, =10
    bl put_char
    bl current_time
    mov r7, r0
    sub r6, r7, r5
    mov r0, r6
    bl put_int
    b bb1_0
bb1_0:
    mov r0, r4
    mov sp, r11
    pop {r4, r5, r6, r7, r11, lr}
    bx lr
    .pool

