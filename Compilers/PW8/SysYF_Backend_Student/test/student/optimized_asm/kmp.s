    .arch armv7ve 
    .text 
    .globl get_next
    .p2align 2
    .type get_next, %function
get_next:
    push {r4, r5, r6, r7, r8, r9, r10, lr}
    sub sp, sp, #12
    Mov r4, r0
    Mov r5, r1
    add r6, r5, #0
    ldr r7, =0
    ldr r0, =4
    mul r8, r7, r0
    add r7, r6, r8
    ldr r0, =-1
    str r0, [r7]
    Ldr r7, =-1
    Ldr r6, =0
    b bb0_0
bb0_0:
    add r8, r4, #0
    ldr r0, =4
    mul r9, r6, r0
    add r0, r8, r9
    ldr r8, [r0]
    ldr r0, =0
    cmp r8, r0
    ldr r9, =0
    ldrne r9, =1
    ldr r0, =0
    cmp r8, r0
    bne bb0_1
    b bb0_2
bb0_1:
    ldr r0, =-1
    cmp r7, r0
    ldr r9, =0
    ldreq r9, =1
    mov r8, r9
    ldr r10, =0
    cmp r8, r10
    ldr r9, =0
    ldrne r9, =1
    ldr r10, =0
    cmp r8, r10
    bne bb0_3
    b bb0_6
bb0_2:
    b bb0_7
bb0_3:
    add r10, r7, #1
    add r7, r6, #1
    add r6, r5, #0
    ldr r9, =4
    mul r0, r7, r9
    add r9, r6, r0
    str r10, [r9]
    Mov r6, r10
    b bb0_5
bb0_4:
    add r8, r5, #0
    ldr r9, =4
    mul r0, r7, r9
    add r9, r8, r0
    ldr r7, [r9]
    str r7, [sp, #-8]
    Mov r7, r6
    ldr r6, [sp, #-8]
    b bb0_5
bb0_5:
    b litpool0_0
    .pool
litpool0_0:
    str r6, [sp, #-8]
    Mov r6, r7
    ldr r7, [sp, #-8]
    b bb0_0
bb0_6:
    add r8, r4, #0
    ldr r9, =4
    mul r0, r6, r9
    add r9, r8, r0
    ldr r8, [r9]
    add r9, r4, #0
    ldr r10, =4
    mul r0, r7, r10
    add r10, r9, r0
    ldr r0, [r10]
    cmp r8, r0
    ldr r9, =0
    ldreq r9, =1
    mov r8, r9
    ldr r0, =0
    cmp r8, r0
    ldr r9, =0
    ldrne r9, =1
    ldr r0, =0
    cmp r8, r0
    bne bb0_3
    b bb0_4
bb0_7:
    add sp, sp, #12
    pop {r4, r5, r6, r7, r8, r9, r10, lr}
    bx lr
    .pool

    .globl KMP
    .p2align 2
    .type KMP, %function
KMP:
    push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    mov r11, sp
    ldr lr, =16404
    sub sp, sp, lr
    Mov r4, r0
    Mov r5, r1
    add r6, sp, #12
    ldr r7, =0
    ldr r8, =4
    mul r0, r7, r8
    add r7, r6, r0
    mov r0, r4
    mov r1, r7
    bl get_next
    Ldr r7, =0
    Ldr r6, =0
    b bb1_0
bb1_0:
    add r8, r5, #0
    ldr r0, =4
    mul r9, r6, r0
    add r0, r8, r9
    ldr r8, [r0]
    ldr r0, =0
    cmp r8, r0
    ldr r9, =0
    ldrne r9, =1
    ldr r10, =0
    cmp r8, r10
    bne bb1_1
    b bb1_2
bb1_1:
    add r8, r4, #0
    ldr r9, =4
    mul r10, r7, r9
    add r0, r8, r10
    ldr r8, [r0]
    add r9, r5, #0
    ldr r10, =4
    mul r0, r6, r10
    add r10, r9, r0
    ldr r9, [r10]
    cmp r8, r9
    ldr r0, =0
    ldreq r0, =1
    mov r8, r0
    ldr r0, =0
    cmp r8, r0
    ldr r9, =0
    ldrne r9, =1
    ldr r0, =0
    cmp r8, r0
    bne bb1_3
    b bb1_4
bb1_2:
    Mov r4, r6
    Mov r5, r7
    Ldr r6, =-1
    b bb1_10
bb1_3:
    b litpool1_0
    .pool
litpool1_0:
    add r8, r7, #1
    add r7, r6, #1
    add r6, r4, #0
    ldr r9, =4
    mul r0, r8, r9
    add r9, r6, r0
    ldr r6, [r9]
    ldr r9, =0
    cmp r6, r9
    ldr r0, =0
    ldreq r0, =1
    mov r6, r0
    ldr r0, =0
    cmp r6, r0
    ldr r9, =0
    ldrne r9, =1
    ldr r10, =0
    cmp r6, r10
    bne bb1_6
    b bb1_7
bb1_4:
    add r8, sp, #12
    ldr r9, =4
    mul r0, r7, r9
    add r9, r8, r0
    ldr r7, [r9]
    ldr r0, =-1
    cmp r7, r0
    ldr r9, =0
    ldreq r9, =1
    mov r8, r9
    ldr r0, =0
    cmp r8, r0
    ldr r9, =0
    ldrne r9, =1
    ldr r0, =0
    cmp r8, r0
    bne bb1_8
    Mov r0, r7
    b bb1_9
bb1_5:
    Mov r7, r0
    b bb1_0
bb1_6:
    Mov r6, r7
    Mov r4, r7
    Mov r5, r8
    b bb1_10
bb1_7:
    Mov r6, r7
    Mov r0, r8
    b bb1_5
bb1_8:
    add r8, r7, #1
    add r7, r6, #1
    Mov r6, r7
    Mov r0, r8
    b bb1_9
bb1_9:
    b litpool1_1
    .pool
litpool1_1:
    b bb1_5
bb1_10:
    mov r0, r6
    mov sp, r11
    pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    bx lr
    .pool

    .globl read_str
    .p2align 2
    .type read_str, %function
read_str:
    push {r4, r5, r6, r7, r8, r9, r11, lr}
    mov r11, sp
    sub sp, sp, #8
    Mov r4, r0
    Ldr r5, =0
    b bb2_0
bb2_0:
    ldr r7, =1
    ldr r8, =0
    cmp r7, r8
    ldr r6, =0
    ldrne r6, =1
    ldr r7, =1
    ldr r8, =0
    cmp r7, r8
    bne bb2_1
    b bb2_2
bb2_1:
    bl get_char
    mov r6, r0
    add r7, r4, #0
    ldr r8, =4
    mul r9, r5, r8
    add r8, r7, r9
    str r6, [r8]
    add r6, r4, #0
    ldr r8, =4
    mul r7, r5, r8
    add r8, r6, r7
    ldr r6, [r8]
    ldr r7, =10
    cmp r6, r7
    ldr r8, =0
    ldreq r8, =1
    mov r6, r8
    ldr r8, =0
    cmp r6, r8
    ldr r7, =0
    ldrne r7, =1
    ldr r8, =0
    cmp r6, r8
    bne bb2_3
    b bb2_4
bb2_2:
    add r6, r4, #0
    ldr r4, =4
    mul r7, r5, r4
    add r4, r6, r7
    ldr r6, =0
    str r6, [r4]
    b bb2_5
bb2_3:
    b bb2_2
bb2_4:
    add r6, r5, #1
    Mov r5, r6
    b bb2_0
bb2_5:
    mov r0, r5
    mov sp, r11
    pop {r4, r5, r6, r7, r8, r9, r11, lr}
    bx lr
    .pool

    .globl main
    .p2align 2
    .type main, %function
main:
    push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    mov r11, sp
    ldr lr, =32780
    sub sp, sp, lr
    bl current_time
    mov r4, r0
    add r5, sp, #12
    ldr r6, =0
    ldr r7, =4
    b litpool3_0
    .pool
litpool3_0:
    mul r0, r6, r7
    add r6, r5, r0
    mov r0, r6
    bl read_str
    mov r5, r0
    ldr r6, =16396
    add r6, sp, r6
    ldr r7, =0
    ldr r0, =4
    mul r8, r7, r0
    add r0, r6, r8
    STM SP, {r0}
    ldr r0, [sp]
    bl read_str
    mov r6, r0
    ldr r0, [SP]
    add r10, sp, #12
    ldr r7, =0
    ldr r0, =4
    mul r9, r7, r0
    add r7, r10, r9
    ldr r8, =16396
    add r8, sp, r8
    ldr r9, =0
    ldr r10, =4
    mul r0, r9, r10
    add r9, r8, r0
    STM SP, {r0}
    mov r0, r7
    mov r1, r9
    bl KMP
    STM SP, {r0}
    ldr r0, [sp]
    bl put_int
    LDM sp, {r0}
    ldr r0, =10
    bl put_char
    bl current_time
    mov r7, r0
    sub r0, r7, r4
    STM SP, {r0}
    ldr r0, [sp]
    bl put_int
    LDM sp, {r0}
    b bb3_0
bb3_0:
    ldr r0, =0
    mov sp, r11
    pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    bx lr
    .pool

