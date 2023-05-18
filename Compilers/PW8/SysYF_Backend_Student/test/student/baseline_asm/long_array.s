    .arch armv7ve 
    .text 
    .globl long_array
    .p2align 2
    .type long_array, %function
long_array:
    push {r4, r5, r6, r7, r8, r9, r10, r11, r12, lr}
    mov r11, sp
    ldr lr, =120052
    sub sp, sp, lr
    ldr lr, =120048
    add lr, lr, sp
    str r0, [lr]
    str lr, [sp, #-8]
    push {r12}
    Ldr r12, =0
    ldr lr, =120044
    add lr, lr, sp
    str r12, [lr]
    pop {r12}
    ldr lr, [sp, #-8]
    b bb0_0
bb0_0:
    ldr r6, =10000
    str r0, [sp, #20]
    ldr lr, =120040
    add lr, lr, sp
    ldr r0, [lr]
    cmp r0, r6
    ldr r7, =0
    ldrlt r7, =1
    mov r6, r7
    ldr r7, =0
    cmp r6, r7
    ldr r8, =0
    ldrne r8, =1
    ldr r7, =0
    cmp r6, r7
    ldr r0, [sp, #20]
    bne bb0_1
    b bb0_2
bb0_1:
    str r0, [sp, #20]
    ldr lr, =120040
    add lr, lr, sp
    ldr r0, [lr]
    mul r4, r0, r0
    ldr r5, =10
    sdiv r6, r4, r5
    ldr r5, =10
    mul r7, r6, r5
    sub r5, r4, r7
    add r4, sp, #36
    ldr r6, =4
    ldr lr, =120040
    add lr, lr, sp
    ldr r0, [lr]
    mul r7, r0, r6
    add r6, r4, r7
    str r5, [r6]
    ldr lr, =120040
    add lr, lr, sp
    ldr r0, [lr]
    add r4, r0, #1
    ldr r0, [sp, #20]
    str lr, [sp, #-8]
    ldr lr, =120040
    add lr, lr, sp
    str r4, [lr]
    ldr lr, [sp, #-8]
    b bb0_0
bb0_2:
    str lr, [sp, #-8]
    push {r12}
    Ldr r12, =0
    ldr lr, =120048
    add lr, lr, sp
    str r12, [lr]
    pop {r12}
    ldr lr, [sp, #-8]
    b bb0_3
bb0_3:
    ldr r7, =10000
    str r0, [sp, #20]
    ldr lr, =120044
    add lr, lr, sp
    ldr r0, [lr]
    cmp r0, r7
    ldr r8, =0
    ldrlt r8, =1
    mov r7, r8
    ldr r8, =0
    cmp r7, r8
    ldr r9, =0
    ldrne r9, =1
    ldr r8, =0
    cmp r7, r8
    ldr r0, [sp, #20]
    bne bb0_4
    b bb0_5
bb0_4:
    add r4, sp, #36
    ldr r5, =4
    str r0, [sp, #20]
    ldr lr, =120044
    add lr, lr, sp
    ldr r0, [lr]
    mul r6, r0, r5
    add r5, r4, r6
    ldr r4, [r5]
    add r5, sp, #36
    ldr r6, =4
    ldr lr, =120044
    add lr, lr, sp
    ldr r0, [lr]
    mul r7, r0, r6
    add r6, r5, r7
    ldr r5, [r6]
    mul r6, r4, r5
    ldr r4, =10
    sdiv r5, r6, r4
    ldr r4, =10
    mul r7, r5, r4
    sub r4, r6, r7
    ldr r5, =40036
    add r5, sp, r5
    ldr r6, =4
    ldr lr, =120044
    add lr, lr, sp
    ldr r0, [lr]
    mul r7, r0, r6
    add r6, r5, r7
    str r4, [r6]
    ldr lr, =120044
    add lr, lr, sp
    ldr r0, [lr]
    add r4, r0, #1
    ldr r0, [sp, #20]
    str lr, [sp, #-8]
    ldr lr, =120044
    add lr, lr, sp
    str r4, [lr]
    ldr lr, [sp, #-8]
    b bb0_3
bb0_5:
    b litpool0_0
    .pool
litpool0_0:
    Ldr r7, =0
    b bb0_6
bb0_6:
    ldr r8, =10000
    cmp r7, r8
    ldr r9, =0
    ldrlt r9, =1
    mov r8, r9
    ldr r9, =0
    cmp r8, r9
    ldr r10, =0
    ldrne r10, =1
    ldr r9, =0
    cmp r8, r9
    bne bb0_7
    b bb0_8
bb0_7:
    ldr r4, =40036
    add r4, sp, r4
    ldr r5, =4
    mul r6, r7, r5
    add r5, r4, r6
    ldr r4, [r5]
    ldr r5, =40036
    add r5, sp, r5
    ldr r6, =4
    mul r8, r7, r6
    add r6, r5, r8
    ldr r5, [r6]
    mul r6, r4, r5
    ldr r4, =100
    sdiv r5, r6, r4
    ldr r4, =100
    mul r8, r5, r4
    sub r4, r6, r8
    add r5, sp, #36
    ldr r6, =4
    mul r8, r7, r6
    add r6, r5, r8
    ldr r5, [r6]
    add r6, r4, r5
    ldr r4, =80036
    add r4, sp, r4
    ldr r5, =4
    mul r8, r7, r5
    add r5, r4, r8
    str r6, [r5]
    add r4, r7, #1
    Mov r7, r4
    b bb0_6
bb0_8:
    Ldr r10, =0
    Ldr r0, =0
    b bb0_9
bb0_9:
    ldr r1, =10000
    cmp r0, r1
    ldr r2, =0
    ldrlt r2, =1
    mov r1, r2
    ldr r2, =0
    cmp r1, r2
    ldr r3, =0
    ldrne r3, =1
    ldr r2, =0
    cmp r1, r2
    bne bb0_10
    b bb0_11
bb0_10:
    ldr r1, =10
    cmp r0, r1
    ldr r2, =0
    ldrlt r2, =1
    mov r1, r2
    ldr r2, =0
    cmp r1, r2
    ldr r3, =0
    ldrne r3, =1
    ldr r2, =0
    cmp r1, r2
    bne bb0_12
    b bb0_13
bb0_11:
    b bb0_30
bb0_12:
    b litpool0_1
    .pool
litpool0_1:
    ldr r4, =80036
    add r4, sp, r4
    ldr r6, =4
    mul r1, r0, r6
    add r6, r4, r1
    ldr r4, [r6]
    add r6, r10, r4
    ldr r4, =1333
    sdiv r10, r6, r4
    ldr r4, =1333
    mul r1, r10, r4
    sub r4, r6, r1
    STM SP, {r0}
    mov r0, r4
    bl put_int
    LDM sp, {r0}
    str r4, [sp, #-8]
    Mov r4, r8
    Mov r1, r9
    ldr r2, [sp, #-8]
    b bb0_14
bb0_13:
    ldr r1, =20
    cmp r0, r1
    ldr r2, =0
    ldrlt r2, =1
    mov r1, r2
    ldr r2, =0
    cmp r1, r2
    ldr r3, =0
    ldrne r3, =1
    ldr r2, =0
    cmp r1, r2
    bne bb0_15
    b bb0_16
bb0_14:
    add r3, r0, #1
    Mov r8, r4
    Mov r9, r1
    Mov r10, r2
    Mov r0, r3
    b bb0_9
bb0_15:
    Ldr r4, =5000
    Mov r5, r10
    b bb0_18
bb0_16:
    ldr r1, =30
    cmp r0, r1
    ldr r2, =0
    ldrlt r2, =1
    mov r1, r2
    ldr r2, =0
    cmp r1, r2
    ldr r3, =0
    ldrne r3, =1
    ldr r2, =0
    cmp r1, r2
    bne bb0_21
    b bb0_22
bb0_17:
    b bb0_14
bb0_18:
    b litpool0_2
    .pool
litpool0_2:
    ldr r6, =10000
    cmp r4, r6
    ldr r1, =0
    ldrlt r1, =1
    mov r6, r1
    ldr r1, =0
    cmp r6, r1
    ldr r2, =0
    ldrne r2, =1
    ldr r1, =0
    cmp r6, r1
    bne bb0_19
    b bb0_20
bb0_19:
    ldr r6, =80036
    add r6, sp, r6
    ldr r1, =4
    mul r2, r0, r1
    add r1, r6, r2
    ldr r6, [r1]
    add r1, r5, r6
    add r5, sp, #36
    ldr r6, =4
    mul r2, r4, r6
    add r6, r5, r2
    ldr r5, [r6]
    sub r6, r1, r5
    add r5, r4, #1
    Mov r4, r5
    Mov r5, r6
    b bb0_18
bb0_20:
    STM SP, {r0}
    mov r0, r5
    bl put_int
    LDM sp, {r0}
    str r4, [sp, #-8]
    Mov r4, r8
    ldr r1, [sp, #-8]
    Mov r2, r5
    b bb0_17
bb0_21:
    Ldr r4, =5000
    Mov r1, r10
    b bb0_24
bb0_22:
    ldr r1, =80036
    add r1, sp, r1
    ldr r3, =4
    mul r12, r0, r3
    add r3, r1, r12
    ldr r1, [r3]
    str r0, [sp, #20]
    ldr lr, =120048
    add lr, lr, sp
    ldr r0, [lr]
    mul r3, r1, r0
    add r1, r10, r3
    ldr r3, =99988
    sdiv r12, r1, r3
    ldr r3, =99988
    mul r4, r12, r3
    sub r3, r1, r4
    ldr r0, [sp, #20]
    Mov r4, r8
    Mov r1, r3
    b bb0_23
bb0_23:
    str r1, [sp, #-8]
    Mov r1, r9
    ldr r2, [sp, #-8]
    b bb0_17
bb0_24:
    b litpool0_3
    .pool
litpool0_3:
    ldr r2, =10000
    cmp r4, r2
    ldr r3, =0
    ldrlt r3, =1
    mov r2, r3
    ldr r3, =0
    cmp r2, r3
    ldr r12, =0
    ldrne r12, =1
    ldr r3, =0
    cmp r2, r3
    bne bb0_25
    b bb0_26
bb0_25:
    ldr r2, =2233
    cmp r4, r2
    ldr r3, =0
    ldrgt r3, =1
    mov r2, r3
    ldr r3, =0
    cmp r2, r3
    ldr r12, =0
    ldrne r12, =1
    ldr r3, =0
    cmp r2, r3
    bne bb0_27
    b bb0_28
bb0_26:
    STM SP, {r0, r1}
    ldr r0, [sp, #4]
    bl put_int
    LDM sp, {r0, r1}
    b bb0_23
bb0_27:
    ldr r5, =40036
    add r5, sp, r5
    ldr r6, =4
    mul r2, r0, r6
    add r6, r5, r2
    ldr r5, [r6]
    add r6, r1, r5
    add r5, sp, #36
    ldr r1, =4
    mul r2, r4, r1
    add r1, r5, r2
    ldr r5, [r1]
    sub r1, r6, r5
    add r5, r4, #1
    Mov r6, r1
    b bb0_29
bb0_28:
    add r2, sp, #36
    ldr r12, =4
    mul r5, r0, r12
    add r12, r2, r5
    ldr r5, [r12]
    add r2, r1, r5
    ldr r5, =80036
    add r5, sp, r5
    ldr r12, =4
    mul r6, r4, r12
    add r12, r5, r6
    ldr r5, [r12]
    add r6, r2, r5
    ldr r5, =13333
    sdiv r2, r6, r5
    ldr r5, =13333
    mul r12, r2, r5
    sub r5, r6, r12
    add r6, r4, #2
    str r5, [sp, #-8]
    Mov r5, r6
    ldr r6, [sp, #-8]
    b bb0_29
bb0_29:
    Mov r4, r5
    Mov r1, r6
    b bb0_24
bb0_30:
    b litpool0_4
    .pool
litpool0_4:
    mov r0, r10
    mov sp, r11
    pop {r4, r5, r6, r7, r8, r9, r10, r11, r12, lr}
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
    ldr r0, =9
    bl long_array
    mov r5, r0
    ldr r0, =10
    bl put_char
    bl current_time
    mov r6, r0
    sub r7, r6, r4
    mov r0, r7
    bl put_int
    b bb1_0
bb1_0:
    mov r0, r5
    mov sp, r11
    pop {r4, r5, r6, r7, r11, lr}
    bx lr
    .pool

