    .arch armv7ve 
    .text 
    .globl func1
    .p2align 2
    .type func1, %function
func1:
    push {r4, r5, r6, r7, r8, r9, r11, lr}
    mov r11, sp
    sub sp, sp, #16
    Mov r4, r0
    Mov r5, r1
    Mov r6, r2
    ldr r7, =0
    cmp r6, r7
    ldr r8, =0
    ldreq r8, =1
    mov r7, r8
    ldr r9, =0
    cmp r7, r9
    ldr r8, =0
    ldrne r8, =1
    ldr r9, =0
    cmp r7, r9
    bne bb0_0
    b bb0_1
bb0_0:
    mul r6, r4, r5
    Mov r4, r6
    b bb0_2
bb0_1:
    sub r7, r5, r6
    mov r0, r4
    mov r1, r7
    ldr r2, =0
    bl func1
    mov r5, r0
    Mov r4, r5
    b bb0_2
bb0_2:
    mov r0, r4
    mov sp, r11
    pop {r4, r5, r6, r7, r8, r9, r11, lr}
    bx lr
    .pool

    .globl func2
    .p2align 2
    .type func2, %function
func2:
    push {r4, r5, r6, r7, r11, lr}
    mov r11, sp
    sub sp, sp, #12
    Mov r4, r0
    Mov r5, r1
    ldr r7, =0
    cmp r5, r7
    ldr r6, =0
    ldrne r6, =1
    ldr r7, =0
    cmp r5, r7
    bne bb1_0
    b bb1_1
bb1_0:
    sdiv r6, r4, r5
    mul r7, r6, r5
    sub r5, r4, r7
    mov r0, r5
    ldr r1, =0
    bl func2
    mov r4, r0
    b bb1_2
bb1_1:
    b bb1_2
bb1_2:
    b litpool1_0
    .pool
litpool1_0:
    mov r0, r4
    mov sp, r11
    pop {r4, r5, r6, r7, r11, lr}
    bx lr
    .pool

    .globl func3
    .p2align 2
    .type func3, %function
func3:
    push {r4, r5, r6, r7, r8, r11, lr}
    mov r11, sp
    sub sp, sp, #12
    Mov r4, r0
    Mov r5, r1
    ldr r6, =0
    cmp r5, r6
    ldr r7, =0
    ldreq r7, =1
    mov r6, r7
    ldr r8, =0
    cmp r6, r8
    ldr r7, =0
    ldrne r7, =1
    ldr r8, =0
    cmp r6, r8
    bne bb2_0
    b bb2_1
bb2_0:
    add r5, r4, #1
    Mov r4, r5
    b bb2_2
bb2_1:
    add r6, r4, r5
    mov r0, r6
    ldr r1, =0
    bl func3
    mov r4, r0
    b bb2_2
bb2_2:
    mov r0, r4
    mov sp, r11
    pop {r4, r5, r6, r7, r8, r11, lr}
    bx lr
    .pool

    .globl func4
    .p2align 2
    .type func4, %function
func4:
    push {r4, r5, r6, r7, r8, lr}
    sub sp, sp, #12
    Mov r6, r0
    Mov r4, r1
    Mov r5, r2
    ldr r8, =0
    cmp r6, r8
    ldr r7, =0
    ldrne r7, =1
    ldr r8, =0
    cmp r6, r8
    bne bb3_0
    b bb3_1
bb3_0:
    b bb3_2
bb3_1:
    Mov r4, r5
    b bb3_2
bb3_2:
    b litpool3_0
    .pool
litpool3_0:
    mov r0, r4
    add sp, sp, #12
    pop {r4, r5, r6, r7, r8, lr}
    bx lr
    .pool

    .globl func5
    .p2align 2
    .type func5, %function
func5:
    push {r4, r5, lr}
    sub sp, sp, #4
    Mov r5, r0
    rsb r4, r5, #0
    b bb4_0
bb4_0:
    mov r0, r4
    add sp, sp, #4
    pop {r4, r5, lr}
    bx lr
    .pool

    .globl func6
    .p2align 2
    .type func6, %function
func6:
    push {r4, r5, r6, r7, lr}
    sub sp, sp, #8
    Mov r5, r0
    Mov r4, r1
    ldr r7, =0
    cmp r5, r7
    ldr r6, =0
    ldrne r6, =1
    ldr r7, =0
    cmp r5, r7
    bne bb5_2
    b bb5_1
bb5_0:
    Ldr r4, =1
    b bb5_3
bb5_1:
    Ldr r4, =0
    b bb5_3
bb5_2:
    ldr r6, =0
    cmp r4, r6
    ldr r5, =0
    ldrne r5, =1
    ldr r6, =0
    cmp r4, r6
    bne bb5_0
    b bb5_1
bb5_3:
    mov r0, r4
    add sp, sp, #8
    pop {r4, r5, r6, r7, lr}
    bx lr
    .pool

    .globl func7
    .p2align 2
    .type func7, %function
func7:
    push {r4, r5, r6, lr}
    sub sp, sp, #4
    Mov r4, r0
    ldr r6, =0
    cmp r4, r6
    ldr r5, =0
    ldreq r5, =1
    mov r4, r5
    ldr r6, =0
    cmp r4, r6
    ldr r5, =0
    ldrne r5, =1
    ldr r6, =0
    cmp r4, r6
    bne bb6_0
    b bb6_1
bb6_0:
    Ldr r4, =1
    b bb6_2
bb6_1:
    b litpool6_0
    .pool
litpool6_0:
    Ldr r4, =0
    b bb6_2
bb6_2:
    mov r0, r4
    add sp, sp, #4
    pop {r4, r5, r6, lr}
    bx lr
    .pool

    .globl main
    .p2align 2
    .type main, %function
main:
    push {r4, r5, r6, r7, r8, r9, r10, r11, r12, lr}
    mov r11, sp
    sub sp, sp, #84
    bl current_time
    str r0, [sp, #76]
    bl get_int
    str r0, [sp, #80]
    bl get_int
    mov r6, r0
    bl get_int
    mov r7, r0
    bl get_int
    mov r8, r0
    Ldr r4, =0
    b bb7_0
bb7_0:
    ldr r0, =10
    cmp r4, r0
    ldr r1, =0
    ldrlt r1, =1
    mov r0, r1
    ldr r2, =0
    cmp r0, r2
    ldr r1, =0
    ldrne r1, =1
    ldr r2, =0
    cmp r0, r2
    bne bb7_1
    b bb7_2
bb7_1:
    STM SP, {r0}
    bl get_int
    add r1, sp, #36
    ldr r2, =4
    mul r3, r4, r2
    add r2, r1, r3
    str r0, [r2]
    add r0, r4, #1
    Mov r4, r0
    b bb7_0
bb7_2:
    STM SP, {r0}
    ldr r0, [sp, #80]
    bl func7
    STM SP, {r0, r2}
    mov r0, r6
    bl func5
    LDMIB SP, {r2}
    mov r2, r0
    ldr r0, [SP]
    STM SP, {r0, r1, r2}
    ldr r0, [sp]
    ldr r1, [sp, #8]
    bl func6
    LDMIB SP, {r1, r2}
    mov r1, r0
    ldr r0, [SP]
    STM SP, {r0, r1}
    ldr r0, [sp, #4]
    mov r1, r7
    bl func2
    LDMIB SP, {r1}
    STM SP, {r0, r1}
    ldr r0, [sp]
    mov r1, r8
    bl func3
    LDMIB SP, {r1}
    mov r1, r0
    ldr r0, [SP]
    STM SP, {r1}
    ldr r0, [sp]
    bl func5
    LDM SP, {r1}
    mov r9, r0
    add r0, sp, #36
    ldr r1, =0
    ldr r3, =4
    mul r2, r1, r3
    add r1, r0, r2
    ldr r10, [r1]
    add r0, sp, #36
    ldr r1, =1
    ldr r3, =4
    mul r2, r1, r3
    add r1, r0, r2
    ldr r2, [r1]
    STM SP, {r0, r2}
    ldr r0, [sp, #4]
    bl func5
    LDMIB SP, {r2}
    add r1, sp, #36
    ldr r2, =2
    ldr r3, =4
    mul r4, r2, r3
    add r3, r1, r4
    ldr r2, [r3]
    add r1, sp, #36
    ldr r3, =3
    ldr r5, =4
    mul r12, r3, r5
    add r3, r1, r12
    ldr r1, [r3]
    STM SP, {r0, r1, r2, r3}
    ldr r0, [sp, #4]
    bl func7
    LDMIB SP, {r1, r2, r3}
    mov r3, r0
    ldr r0, [SP]
    STM SP, {r0, r1, r2, r3}
    ldr r0, [sp, #8]
    ldr r1, [sp, #12]
    bl func6
    LDMIB SP, {r1, r2, r3}
    mov r1, r0
    ldr r0, [SP]
    add r2, sp, #36
    ldr r3, =4
    ldr r12, =4
    mul r4, r3, r12
    add r3, r2, r4
    ldr r2, [r3]
    add r3, sp, #36
    ldr r12, =5
    ldr r4, =4
    mul r5, r12, r4
    add r4, r3, r5
    ldr r12, [r4]
    STM SP, {r0, r1, r2, r3, r12}
    ldr r0, [sp, #16]
    bl func7
    LDMIB SP, {r1, r2, r3, r12}
    mov r3, r0
    ldr r0, [SP]
    STM SP, {r0, r1, r2, r3}
    ldr r0, [sp, #8]
    ldr r1, [sp, #12]
    bl func2
    LDMIB SP, {r1, r2, r3}
    mov r4, r0
    ldr r0, [SP]
    STM SP, {r0, r1, r2}
    ldr r0, [sp]
    ldr r1, [sp, #4]
    mov r2, r4
    bl func4
    LDMIB SP, {r1, r2}
    mov r2, r0
    ldr r0, [SP]
    add r0, sp, #36
    ldr r1, =6
    ldr r3, =4
    mul r4, r1, r3
    add r1, r0, r4
    ldr r0, [r1]
    STM SP, {r0, r1, r2}
    ldr r0, [sp, #8]
    ldr r1, [sp]
    bl func3
    LDMIB SP, {r1, r2}
    mov r1, r0
    ldr r0, [SP]
    add r0, sp, #36
    ldr r2, =7
    ldr r3, =4
    mul r4, r2, r3
    add r3, r0, r4
    ldr r2, [r3]
    STM SP, {r0, r1, r2}
    ldr r0, [sp, #4]
    ldr r1, [sp, #8]
    bl func2
    LDMIB SP, {r1, r2}
    add r1, sp, #36
    ldr r2, =8
    ldr r4, =4
    mul r3, r2, r4
    add r2, r1, r3
    ldr r1, [r2]
    add r2, sp, #36
    ldr r3, =9
    ldr r4, =4
    mul r12, r3, r4
    add r3, r2, r12
    ldr r2, [r3]
    STM SP, {r0, r1, r2}
    ldr r0, [sp, #8]
    bl func7
    LDMIB SP, {r1, r2}
    mov r4, r0
    ldr r0, [SP]
    STM SP, {r0, r1, r3}
    ldr r0, [sp, #4]
    mov r1, r4
    bl func3
    LDMIB SP, {r1, r3}
    mov r3, r0
    ldr r0, [SP]
    STM SP, {r0, r2, r3}
    ldr r0, [sp]
    ldr r1, [sp, #8]
    ldr r2, [sp, #80]
    bl func1
    LDMIB SP, {r2, r3}
    mov r2, r0
    ldr r0, [SP]
    STM SP, {r1, r2}
    mov r0, r9
    mov r1, r10
    ldr r2, [sp, #4]
    bl func4
    LDM SP, {r1, r2}
    mov r1, r0
    STM SP, {r1, r2}
    mov r0, r7
    bl func7
    LDM SP, {r1, r2}
    mov r2, r0
    STM SP, {r0, r1, r2}
    ldr r0, [sp, #8]
    mov r1, r8
    bl func3
    LDMIB SP, {r1, r2}
    STM SP, {r0, r1, r2}
    mov r0, r6
    ldr r1, [sp]
    bl func2
    LDMIB SP, {r1, r2}
    mov r2, r0
    ldr r0, [SP]
    STM SP, {r0, r1, r2}
    ldr r0, [sp, #4]
    ldr r1, [sp, #8]
    bl func3
    LDMIB SP, {r1, r2}
    add r1, sp, #36
    ldr r2, =0
    ldr r6, =4
    mul r3, r2, r6
    add r4, r1, r3
    ldr r2, [r4]
    add r1, sp, #36
    ldr r3, =1
    ldr r6, =4
    mul r4, r3, r6
    add r6, r1, r4
    ldr r3, [r6]
    STM SP, {r0, r1, r2, r3}
    ldr r0, [sp]
    ldr r1, [sp, #8]
    ldr r2, [sp, #12]
    bl func1
    LDMIB SP, {r1, r2, r3}
    mov r1, r0
    ldr r0, [SP]
    add r0, sp, #36
    ldr r2, =2
    ldr r3, =4
    mul r4, r2, r3
    add r2, r0, r4
    ldr r0, [r2]
    STM SP, {r0, r1}
    ldr r0, [sp, #4]
    ldr r1, [sp]
    bl func2
    LDMIB SP, {r1}
    mov r6, r0
    ldr r0, [SP]
    add r0, sp, #36
    ldr r1, =3
    ldr r3, =4
    mul r2, r1, r3
    add r1, r0, r2
    ldr r7, [r1]
    add r0, sp, #36
    ldr r1, =4
    ldr r3, =4
    mul r2, r1, r3
    add r1, r0, r2
    ldr r0, [r1]
    add r1, sp, #36
    ldr r2, =5
    ldr r3, =4
    mul r4, r2, r3
    add r2, r1, r4
    ldr r1, [r2]
    STM SP, {r0, r1, r2}
    ldr r0, [sp, #4]
    bl func5
    LDMIB SP, {r1, r2}
    mov r2, r0
    ldr r0, [SP]
    STM SP, {r0, r1, r2}
    ldr r0, [sp]
    ldr r1, [sp, #8]
    bl func3
    LDMIB SP, {r1, r2}
    mov r1, r0
    ldr r0, [SP]
    add r0, sp, #36
    ldr r2, =6
    ldr r3, =4
    mul r4, r2, r3
    add r2, r0, r4
    ldr r0, [r2]
    STM SP, {r0, r1, r2}
    ldr r0, [sp]
    bl func5
    LDMIB SP, {r1, r2}
    mov r2, r0
    ldr r0, [SP]
    STM SP, {r0, r1, r2}
    ldr r0, [sp, #4]
    ldr r1, [sp, #8]
    bl func2
    LDMIB SP, {r1, r2}
    add r1, sp, #36
    ldr r2, =7
    ldr r3, =4
    mul r4, r2, r3
    add r3, r1, r4
    ldr r2, [r3]
    add r1, sp, #36
    ldr r3, =8
    ldr r4, =4
    mul r8, r3, r4
    add r3, r1, r8
    ldr r1, [r3]
    STM SP, {r0, r1, r2, r3}
    ldr r0, [sp, #4]
    bl func7
    LDMIB SP, {r1, r2, r3}
    mov r3, r0
    ldr r0, [SP]
    STM SP, {r0, r1, r2, r3}
    ldr r0, [sp]
    ldr r1, [sp, #8]
    ldr r2, [sp, #12]
    bl func1
    LDMIB SP, {r1, r2, r3}
    mov r1, r0
    ldr r0, [SP]
    add r0, sp, #36
    ldr r2, =9
    ldr r3, =4
    mul r4, r2, r3
    add r2, r0, r4
    ldr r3, [r2]
    STM SP, {r0, r1, r3}
    ldr r0, [sp, #8]
    bl func5
    LDMIB SP, {r1, r3}
    STM SP, {r0, r1, r2}
    ldr r0, [sp, #4]
    ldr r1, [sp]
    bl func2
    LDMIB SP, {r1, r2}
    mov r2, r0
    ldr r0, [SP]
    STM SP, {r1, r2}
    ldr r0, [sp, #4]
    ldr r1, [sp, #80]
    bl func3
    LDM SP, {r1, r2}
    mov r1, r0
    STM SP, {r0, r1}
    mov r0, r6
    mov r1, r7
    ldr r2, [sp, #4]
    bl func1
    LDMIB SP, {r1}
    STM SP, {r0}
    ldr r0, =10
    bl put_char
    LDM sp, {r0}
    STM SP, {r0, r2}
    bl current_time
    LDMIB SP, {r2}
    mov r2, r0
    ldr r0, [SP]
    str r0, [sp, #20]
    ldr r0, [sp, #76]
    sub r1, r2, r0
    STM SP, {r0, r1}
    ldr r0, [sp, #4]
    bl put_int
    LDM sp, {r0, r1}
    ldr r0, [sp, #20]
    b bb7_3
bb7_3:
    b litpool7_0
    .pool
litpool7_0:
    mov sp, r11
    pop {r4, r5, r6, r7, r8, r9, r10, r11, r12, lr}
    bx lr
    .pool

