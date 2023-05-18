    .arch armv7ve 
    .text 
    .globl next_char
    .p2align 2
    .type next_char, %function
next_char:
    push {r4, r11, lr}
    mov r11, sp
    sub sp, sp, #4
    bl get_char
    mov r4, r0
    push {r0}
    ldr r0, Addr0_0
    str r4, [r0]
    pop {r0}
    ldr r4, Addr0_0
    ldr r4, [r4]
    b bb0_0
bb0_0:
    mov r0, r4
    mov sp, r11
    pop {r4, r11, lr}
    bx lr
    .pool
Addr0_0:
    .long ..last_char

    .globl is_space
    .p2align 2
    .type is_space, %function
is_space:
    push {r4, r5, r6, r7, lr}
    sub sp, sp, #4
    Mov r4, r0
    ldr r5, =32
    cmp r4, r5
    ldr r6, =0
    ldreq r6, =1
    mov r5, r6
    ldr r7, =0
    cmp r5, r7
    ldr r6, =0
    ldrne r6, =1
    ldr r7, =0
    cmp r5, r7
    bne bb1_0
    b bb1_2
bb1_0:
    Ldr r4, =1
    b bb1_3
bb1_1:
    Ldr r4, =0
    b bb1_3
bb1_2:
    ldr r6, =10
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
    bne bb1_0
    b bb1_1
bb1_3:
    mov r0, r4
    add sp, sp, #4
    pop {r4, r5, r6, r7, lr}
    bx lr
    .pool

    .globl is_num
    .p2align 2
    .type is_num, %function
is_num:
    push {r4, r5, r6, r7, lr}
    sub sp, sp, #4
    Mov r4, r0
    ldr r5, =48
    cmp r4, r5
    ldr r6, =0
    ldrge r6, =1
    mov r5, r6
    ldr r7, =0
    cmp r5, r7
    ldr r6, =0
    ldrne r6, =1
    ldr r7, =0
    cmp r5, r7
    bne bb2_2
    b bb2_1
bb2_0:
    b litpool2_0
    .pool
litpool2_0:
    Ldr r4, =1
    b bb2_3
bb2_1:
    Ldr r4, =0
    b bb2_3
bb2_2:
    ldr r6, =57
    cmp r4, r6
    ldr r5, =0
    ldrle r5, =1
    mov r4, r5
    ldr r6, =0
    cmp r4, r6
    ldr r5, =0
    ldrne r5, =1
    ldr r6, =0
    cmp r4, r6
    bne bb2_0
    b bb2_1
bb2_3:
    mov r0, r4
    add sp, sp, #4
    pop {r4, r5, r6, r7, lr}
    bx lr
    .pool

    .globl next_token
    .p2align 2
    .type next_token, %function
next_token:
    push {r4, r5, r6, r11, lr}
    mov r11, sp
    sub sp, sp, #4
    b bb3_0
bb3_0:
    ldr r5, Addr3_0
    ldr r5, [r5]
    mov r0, r5
    bl is_space
    mov r4, r0
    ldr r6, =0
    cmp r4, r6
    ldr r5, =0
    ldrne r5, =1
    ldr r6, =0
    cmp r4, r6
    bne bb3_1
    b bb3_2
bb3_1:
    bl next_char
    mov r4, r0
    b bb3_0
bb3_2:
    ldr r5, Addr3_0
    ldr r5, [r5]
    mov r0, r5
    bl is_num
    mov r4, r0
    ldr r6, =0
    cmp r4, r6
    ldr r5, =0
    ldrne r5, =1
    ldr r6, =0
    cmp r4, r6
    bne bb3_3
    b bb3_4
bb3_3:
    ldr r4, Addr3_0
    ldr r4, [r4]
    sub r5, r4, #48
    push {r0}
    ldr r0, Addr3_1
    str r5, [r0]
    pop {r0}
    b bb3_6
bb3_4:
    b litpool3_0
    .pool
litpool3_0:
    ldr r4, Addr3_0
    ldr r4, [r4]
    push {r0}
    ldr r0, Addr3_2
    str r4, [r0]
    pop {r0}
    bl next_char
    mov r4, r0
    ldr r5, =1
    push {r0}
    ldr r0, Addr3_3
    str r5, [r0]
    pop {r0}
    b bb3_5
bb3_5:
    ldr r4, Addr3_3
    ldr r4, [r4]
    b bb3_9
bb3_6:
    bl next_char
    mov r5, r0
    mov r0, r5
    bl is_num
    mov r4, r0
    ldr r6, =0
    cmp r4, r6
    ldr r5, =0
    ldrne r5, =1
    ldr r6, =0
    cmp r4, r6
    bne bb3_7
    b bb3_8
bb3_7:
    ldr r5, Addr3_1
    ldr r5, [r5]
    ldr r6, =10
    mul r4, r5, r6
    ldr r6, Addr3_0
    ldr r6, [r6]
    add r5, r4, r6
    sub r4, r5, #48
    push {r0}
    ldr r0, Addr3_1
    str r4, [r0]
    pop {r0}
    b bb3_6
bb3_8:
    ldr r4, =0
    push {r0}
    ldr r0, Addr3_3
    str r4, [r0]
    pop {r0}
    b bb3_5
bb3_9:
    mov r0, r4
    mov sp, r11
    pop {r4, r5, r6, r11, lr}
    bx lr
    .pool
Addr3_0:
    .long ..last_char
Addr3_1:
    .long ..num
Addr3_2:
    .long ..other
Addr3_3:
    .long ..cur_token

    .globl panic
    .p2align 2
    .type panic, %function
panic:
    push {r11, lr}
    mov r11, sp
    sub sp, sp, #4
    ldr r0, =112
    bl put_char
    ldr r0, =97
    bl put_char
    ldr r0, =110
    bl put_char
    ldr r0, =105
    bl put_char
    ldr r0, =99
    bl put_char
    ldr r0, =33
    bl put_char
    ldr r0, =10
    bl put_char
    b bb4_0
bb4_0:
    b litpool4_0
    .pool
litpool4_0:
    ldr r0, =-1
    mov sp, r11
    pop {r11, lr}
    bx lr
    .pool

    .globl get_op_prec
    .p2align 2
    .type get_op_prec, %function
get_op_prec:
    push {r4, r5, r6, r7, lr}
    sub sp, sp, #4
    Mov r4, r0
    ldr r5, =43
    cmp r4, r5
    ldr r6, =0
    ldreq r6, =1
    mov r5, r6
    ldr r7, =0
    cmp r5, r7
    ldr r6, =0
    ldrne r6, =1
    ldr r7, =0
    cmp r5, r7
    bne bb5_0
    b bb5_2
bb5_0:
    Ldr r4, =10
    b bb5_7
bb5_1:
    ldr r5, =42
    cmp r4, r5
    ldr r6, =0
    ldreq r6, =1
    mov r5, r6
    ldr r7, =0
    cmp r5, r7
    ldr r6, =0
    ldrne r6, =1
    ldr r7, =0
    cmp r5, r7
    bne bb5_3
    b bb5_6
bb5_2:
    ldr r5, =45
    cmp r4, r5
    ldr r6, =0
    ldreq r6, =1
    mov r5, r6
    ldr r7, =0
    cmp r5, r7
    ldr r6, =0
    ldrne r6, =1
    ldr r7, =0
    cmp r5, r7
    bne bb5_0
    b bb5_1
bb5_3:
    Ldr r4, =20
    b bb5_7
bb5_4:
    Ldr r4, =0
    b bb5_7
bb5_5:
    b litpool5_0
    .pool
litpool5_0:
    ldr r6, =37
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
    bne bb5_3
    b bb5_4
bb5_6:
    ldr r5, =47
    cmp r4, r5
    ldr r6, =0
    ldreq r6, =1
    mov r5, r6
    ldr r7, =0
    cmp r5, r7
    ldr r6, =0
    ldrne r6, =1
    ldr r7, =0
    cmp r5, r7
    bne bb5_3
    b bb5_5
bb5_7:
    mov r0, r4
    add sp, sp, #4
    pop {r4, r5, r6, r7, lr}
    bx lr
    .pool

    .globl stack_push
    .p2align 2
    .type stack_push, %function
stack_push:
    push {r4, r5, r6, r7, r8, r9, r10, lr}
    sub sp, sp, #8
    Mov r5, r0
    Mov r4, r1
    add r6, r5, #0
    ldr r7, =0
    ldr r8, =4
    mul r9, r7, r8
    add r7, r6, r9
    ldr r8, [r7]
    add r6, r8, #1
    add r7, r5, #0
    ldr r8, =0
    ldr r10, =4
    mul r9, r8, r10
    add r8, r7, r9
    str r6, [r8]
    add r6, r5, #0
    ldr r7, =0
    ldr r8, =4
    mul r9, r7, r8
    add r7, r6, r9
    ldr r6, [r7]
    add r7, r5, #0
    ldr r5, =4
    mul r8, r6, r5
    add r5, r7, r8
    str r4, [r5]
    b bb6_0
bb6_0:
    add sp, sp, #8
    pop {r4, r5, r6, r7, r8, r9, r10, lr}
    bx lr
    .pool

    .globl stack_pop
    .p2align 2
    .type stack_pop, %function
stack_pop:
    push {r4, r5, r6, r7, r8, r9, lr}
    sub sp, sp, #4
    Mov r4, r0
    add r5, r4, #0
    ldr r6, =0
    ldr r8, =4
    mul r7, r6, r8
    add r6, r5, r7
    ldr r5, [r6]
    add r6, r4, #0
    ldr r8, =4
    mul r7, r5, r8
    add r8, r6, r7
    ldr r5, [r8]
    add r6, r4, #0
    ldr r7, =0
    ldr r8, =4
    mul r9, r7, r8
    add r7, r6, r9
    ldr r8, [r7]
    sub r6, r8, #1
    add r7, r4, #0
    ldr r4, =0
    ldr r8, =4
    mul r9, r4, r8
    add r4, r7, r9
    str r6, [r4]
    b bb7_0
bb7_0:
    mov r0, r5
    add sp, sp, #4
    pop {r4, r5, r6, r7, r8, r9, lr}
    bx lr
    .pool

    .globl stack_peek
    .p2align 2
    .type stack_peek, %function
stack_peek:
    push {r4, r5, r6, r7, r8, lr}
    sub sp, sp, #4
    Mov r4, r0
    add r5, r4, #0
    ldr r6, =0
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, [r6]
    add r8, r4, #0
    ldr r7, =4
    mul r4, r5, r7
    add r5, r8, r4
    ldr r4, [r5]
    b bb8_0
bb8_0:
    mov r0, r4
    add sp, sp, #4
    pop {r4, r5, r6, r7, r8, lr}
    bx lr
    .pool

    .globl stack_size
    .p2align 2
    .type stack_size, %function
stack_size:
    push {r4, r5, r6, r7, lr}
    sub sp, sp, #4
    Mov r5, r0
    add r4, r5, #0
    ldr r5, =0
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, [r5]
    b bb9_0
bb9_0:
    b litpool9_0
    .pool
litpool9_0:
    mov r0, r4
    add sp, sp, #4
    pop {r4, r5, r6, r7, lr}
    bx lr
    .pool

    .globl eval_op
    .p2align 2
    .type eval_op, %function
eval_op:
    push {r4, r5, r6, r7, r8, r9, lr}
    sub sp, sp, #12
    Mov r6, r0
    Mov r4, r1
    Mov r5, r2
    ldr r7, =43
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
    bne bb10_0
    b bb10_1
bb10_0:
    add r6, r4, r5
    Mov r4, r6
    b bb10_10
bb10_1:
    ldr r7, =45
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
    bne bb10_2
    b bb10_3
bb10_2:
    sub r6, r4, r5
    Mov r4, r6
    b bb10_10
bb10_3:
    ldr r7, =42
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
    bne bb10_4
    b bb10_5
bb10_4:
    mul r6, r4, r5
    Mov r4, r6
    b bb10_10
bb10_5:
    b litpool10_0
    .pool
litpool10_0:
    ldr r7, =47
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
    bne bb10_6
    b bb10_7
bb10_6:
    sdiv r6, r4, r5
    Mov r4, r6
    b bb10_10
bb10_7:
    ldr r8, =37
    cmp r6, r8
    ldr r7, =0
    ldreq r7, =1
    mov r6, r7
    ldr r8, =0
    cmp r6, r8
    ldr r7, =0
    ldrne r7, =1
    ldr r8, =0
    cmp r6, r8
    bne bb10_8
    b bb10_9
bb10_8:
    sdiv r8, r4, r5
    mul r7, r8, r5
    sub r5, r4, r7
    Mov r4, r5
    b bb10_10
bb10_9:
    Ldr r4, =0
    b bb10_10
bb10_10:
    mov r0, r4
    add sp, sp, #12
    pop {r4, r5, r6, r7, r8, r9, lr}
    bx lr
    .pool

    .globl eval
    .p2align 2
    .type eval, %function
eval:
    push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    mov r11, sp
    ldr lr, =2060
    sub sp, sp, lr
    add r4, sp, #12
    ldr r5, =0
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =1
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =2
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =3
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =4
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =5
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =6
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =7
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =8
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =9
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =10
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =11
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =12
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =13
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =14
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =15
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =16
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =17
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =18
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =19
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =20
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =21
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =22
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =23
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =24
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =25
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =26
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =27
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =28
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =29
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =30
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =31
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =32
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =33
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =34
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =35
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =36
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =37
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =38
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =39
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =40
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =41
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =42
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =43
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =44
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =45
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =46
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =47
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =48
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =49
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =50
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =51
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =52
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =53
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =54
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =55
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =56
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =57
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =58
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =59
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =60
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =61
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =62
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =63
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =64
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =65
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =66
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =67
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =68
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =69
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    b litpool11_0
    .pool
litpool11_0:
    ldr r5, =70
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =71
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =72
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =73
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =74
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =75
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =76
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =77
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =78
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =79
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =80
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =81
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =82
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =83
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =84
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =85
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =86
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =87
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =88
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =89
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =90
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =91
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =92
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =93
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =94
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =95
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =96
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =97
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =98
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =99
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =100
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =101
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =102
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =103
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =104
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =105
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =106
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =107
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =108
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =109
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =110
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =111
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =112
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =113
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =114
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =115
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =116
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =117
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =118
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =119
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =120
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =121
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =122
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =123
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =124
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =125
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =126
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =127
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =128
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =129
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =130
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =131
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =132
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =133
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =134
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =135
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =136
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =137
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =138
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =139
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =140
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =141
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =142
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =143
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =144
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =145
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =146
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =147
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =148
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =149
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =150
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =151
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =152
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =153
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =154
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =155
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =156
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =157
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =158
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =159
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =160
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =161
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =162
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =163
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =164
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =165
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =166
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =167
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =168
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =169
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =170
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =171
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =172
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =173
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =174
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =175
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =176
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =177
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =178
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =179
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =180
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =181
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =182
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =183
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =184
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =185
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =186
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =187
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =188
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =189
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =190
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =191
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =192
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =193
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =194
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =195
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =196
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =197
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =198
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =199
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =200
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =201
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =202
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =203
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =204
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =205
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    b litpool11_1
    .pool
litpool11_1:
    add r4, sp, #12
    ldr r5, =206
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =207
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =208
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =209
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =210
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =211
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =212
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =213
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =214
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =215
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =216
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =217
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =218
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =219
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =220
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =221
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =222
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =223
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =224
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =225
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =226
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =227
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =228
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =229
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =230
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =231
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =232
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =233
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =234
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =235
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =236
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =237
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =238
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =239
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =240
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =241
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =242
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =243
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =244
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =245
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =246
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =247
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =248
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =249
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =250
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =251
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    add r4, sp, #12
    ldr r5, =252
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =253
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =254
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r0, =0
    str r0, [r5]
    add r4, sp, #12
    ldr r5, =255
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =0
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =1
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =2
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =3
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =4
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =5
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =6
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =7
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =8
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =9
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =10
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =11
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =12
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =13
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =14
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =15
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =16
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =17
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =18
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =19
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =20
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =21
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =22
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =23
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =24
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =25
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =26
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =27
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =28
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =29
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =30
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =31
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =32
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =33
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =34
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =35
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =36
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =37
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =38
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =39
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =40
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =41
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =42
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =43
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =44
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =45
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =46
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =47
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =48
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =49
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =50
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =51
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =52
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =53
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =54
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =55
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =56
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =57
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =58
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =59
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =60
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =61
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =62
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =63
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =64
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =65
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =66
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =67
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =68
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =69
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =70
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =71
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =72
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =73
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =74
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    b litpool11_2
    .pool
litpool11_2:
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =75
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =76
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =77
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =78
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =79
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =80
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =81
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =82
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =83
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =84
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =85
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =86
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =87
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =88
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =89
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =90
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =91
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =92
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =93
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =94
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =95
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =96
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =97
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =98
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =99
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =100
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =101
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =102
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =103
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =104
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =105
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =106
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =107
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =108
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =109
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =110
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =111
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =112
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =113
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =114
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =115
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =116
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =117
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =118
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =119
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =120
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =121
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =122
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =123
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =124
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =125
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =126
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =127
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =128
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =129
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =130
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =131
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =132
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =133
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =134
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =135
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =136
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =137
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =138
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =139
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =140
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =141
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =142
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =143
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =144
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =145
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =146
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =147
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =148
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =149
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =150
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =151
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =152
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =153
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =154
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =155
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =156
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =157
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =158
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =159
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =160
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =161
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =162
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =163
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =164
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =165
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =166
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =167
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =168
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =169
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =170
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =171
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =172
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =173
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =174
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =175
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =176
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =177
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =178
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =179
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =180
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =181
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =182
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =183
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =184
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =185
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =186
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =187
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =188
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =189
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =190
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =191
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =192
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =193
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r0, =0
    str r0, [r5]
    b litpool11_3
    .pool
litpool11_3:
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =194
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =195
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =196
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =197
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =198
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =199
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =200
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =201
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =202
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =203
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =204
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =205
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =206
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =207
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =208
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =209
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =210
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =211
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =212
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =213
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =214
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =215
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =216
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =217
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =218
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =219
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =220
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =221
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =222
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =223
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =224
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =225
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =226
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =227
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =228
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =229
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =230
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =231
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =232
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =233
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =234
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =235
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =236
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =237
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =238
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =239
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =240
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =241
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =242
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =243
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =244
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =245
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =246
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =247
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =248
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =249
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =250
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =251
    ldr r7, =4
    mul r6, r5, r7
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =252
    ldr r0, =4
    mul r6, r5, r0
    add r5, r4, r6
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =253
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =254
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr r0, =0
    str r0, [r5]
    ldr r4, =1036
    add r4, sp, r4
    ldr r5, =255
    ldr r6, =4
    mul r0, r5, r6
    add r5, r4, r0
    ldr r0, =0
    str r0, [r5]
    ldr lr, =Addr11_2
    ldr r4, [lr]
    ldr r4, [r4]
    ldr r5, =0
    cmp r4, r5
    ldr r0, =0
    ldrne r0, =1
    mov r4, r0
    ldr r0, =0
    cmp r4, r0
    ldr r5, =0
    ldrne r5, =1
    ldr r0, =0
    cmp r4, r0
    bne bb11_0
    b bb11_1
bb11_0:
    b litpool11_4
    .pool
litpool11_4:
    STM SP, {r0}
    bl panic
    Mov r5, r0
    b bb11_16
bb11_1:
    add r4, sp, #12
    ldr r5, =0
    ldr r6, =4
    mul r7, r5, r6
    add r5, r4, r7
    ldr lr, =Addr11_0
    ldr r0, [lr]
    ldr r0, [r0]
    STM SP, {r0}
    mov r0, r5
    ldr r1, [sp]
    bl stack_push
    LDM sp, {r0}
    STM SP, {r0}
    bl next_token
    b bb11_2
bb11_2:
    ldr lr, =Addr11_2
    ldr r5, [lr]
    ldr r5, [r5]
    ldr r0, =1
    cmp r5, r0
    ldr r6, =0
    ldreq r6, =1
    mov r5, r6
    ldr r0, =0
    cmp r5, r0
    ldr r6, =0
    ldrne r6, =1
    ldr r0, =0
    cmp r5, r0
    bne bb11_3
    b bb11_4
bb11_3:
    ldr lr, =Addr11_1
    ldr r4, [lr]
    ldr r4, [r4]
    mov r0, r4
    bl get_op_prec
    mov r5, r0
    ldr r7, =0
    cmp r5, r7
    ldr r6, =0
    ldreq r6, =1
    mov r5, r6
    ldr r0, =0
    cmp r5, r0
    ldr r6, =0
    ldrne r6, =1
    ldr r7, =0
    cmp r5, r7
    bne bb11_5
    b bb11_6
bb11_4:
    STM SP, {r0}
    bl next_token
    b bb11_13
bb11_5:
    b bb11_4
bb11_6:
    b litpool11_5
    .pool
litpool11_5:
    STM SP, {r0}
    bl next_token
    b bb11_7
bb11_7:
    ldr r5, =1036
    add r5, sp, r5
    ldr r6, =0
    ldr r0, =4
    mul r7, r6, r0
    add r6, r5, r7
    mov r0, r6
    bl stack_size
    mov r5, r0
    ldr r0, =0
    cmp r5, r0
    ldr r6, =0
    ldrne r6, =1
    ldr r7, =0
    cmp r5, r7
    bne bb11_10
    b bb11_9
bb11_8:
    ldr r5, =1036
    add r5, sp, r5
    ldr r6, =0
    ldr r0, =4
    mul r7, r6, r0
    add r6, r5, r7
    mov r0, r6
    bl stack_pop
    mov r5, r0
    add r6, sp, #12
    ldr r7, =0
    ldr r8, =4
    mul r9, r7, r8
    add r7, r6, r9
    mov r0, r7
    bl stack_pop
    mov r6, r0
    add r7, sp, #12
    ldr r8, =0
    ldr r10, =4
    mul r9, r8, r10
    add r8, r7, r9
    mov r0, r8
    bl stack_pop
    mov r7, r0
    add r8, sp, #12
    ldr r9, =0
    ldr r10, =4
    mul r0, r9, r10
    add r9, r8, r0
    mov r0, r5
    mov r1, r7
    mov r2, r6
    bl eval_op
    mov r8, r0
    mov r0, r9
    mov r1, r8
    bl stack_push
    b bb11_7
bb11_9:
    ldr r5, =1036
    add r5, sp, r5
    ldr r6, =0
    ldr r0, =4
    mul r7, r6, r0
    add r6, r5, r7
    mov r0, r6
    mov r1, r4
    bl stack_push
    ldr lr, =Addr11_2
    ldr r5, [lr]
    ldr r5, [r5]
    ldr r6, =0
    cmp r5, r6
    ldr r7, =0
    ldrne r7, =1
    mov r5, r7
    ldr r7, =0
    cmp r5, r7
    ldr r6, =0
    ldrne r6, =1
    ldr r7, =0
    cmp r5, r7
    bne bb11_11
    b bb11_12
bb11_10:
    ldr r5, =1036
    add r5, sp, r5
    ldr r6, =0
    ldr r7, =4
    mul r0, r6, r7
    add r7, r5, r0
    mov r0, r7
    bl stack_peek
    mov r6, r0
    mov r0, r6
    bl get_op_prec
    mov r5, r0
    mov r0, r4
    bl get_op_prec
    mov r7, r0
    cmp r5, r7
    ldr r6, =0
    ldrge r6, =1
    mov r5, r6
    ldr r7, =0
    cmp r5, r7
    ldr r6, =0
    ldrne r6, =1
    ldr r7, =0
    cmp r5, r7
    bne bb11_8
    b bb11_9
bb11_11:
    STM SP, {r0}
    bl panic
    Mov r5, r0
    b bb11_16
bb11_12:
    b litpool11_6
    .pool
litpool11_6:
    add r5, sp, #12
    ldr r6, =0
    ldr r7, =4
    mul r0, r6, r7
    add r6, r5, r0
    ldr lr, =Addr11_0
    ldr r5, [lr]
    ldr r5, [r5]
    mov r0, r6
    mov r1, r5
    bl stack_push
    bl next_token
    mov r5, r0
    b bb11_2
bb11_13:
    ldr r5, =1036
    add r5, sp, r5
    ldr r6, =0
    ldr r0, =4
    mul r7, r6, r0
    add r6, r5, r7
    mov r0, r6
    bl stack_size
    mov r5, r0
    ldr r7, =0
    cmp r5, r7
    ldr r6, =0
    ldrne r6, =1
    ldr r0, =0
    cmp r5, r0
    bne bb11_14
    b bb11_15
bb11_14:
    ldr r5, =1036
    add r5, sp, r5
    ldr r6, =0
    ldr r0, =4
    mul r7, r6, r0
    add r6, r5, r7
    mov r0, r6
    bl stack_pop
    mov r5, r0
    add r6, sp, #12
    ldr r7, =0
    ldr r8, =4
    mul r9, r7, r8
    add r0, r6, r9
    STM SP, {r0}
    ldr r0, [sp]
    bl stack_pop
    mov r6, r0
    ldr r0, [SP]
    add r7, sp, #12
    ldr r8, =0
    ldr r9, =4
    mul r0, r8, r9
    add r8, r7, r0
    mov r0, r8
    bl stack_pop
    mov r7, r0
    add r8, sp, #12
    ldr r9, =0
    ldr r0, =4
    mul r10, r9, r0
    add r9, r8, r10
    mov r0, r5
    mov r1, r7
    mov r2, r6
    bl eval_op
    mov r8, r0
    mov r0, r9
    mov r1, r8
    bl stack_push
    b bb11_13
bb11_15:
    add r5, sp, #12
    ldr r6, =0
    ldr r7, =4
    mul r0, r6, r7
    add r6, r5, r0
    mov r0, r6
    bl stack_peek
    mov r5, r0
    b bb11_16
bb11_16:
    mov r0, r5
    mov sp, r11
    pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    bx lr
    .pool
Addr11_0:
    .long ..num
Addr11_1:
    .long ..other
Addr11_2:
    .long ..cur_token

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
    mov r5, r0
    bl get_char
    mov r6, r0
    bl next_token
    mov r7, r0
    b bb12_0
bb12_0:
    b litpool12_0
    .pool
litpool12_0:
    ldr r7, =0
    cmp r5, r7
    ldr r6, =0
    ldrne r6, =1
    ldr r7, =0
    cmp r5, r7
    bne bb12_1
    b bb12_2
bb12_1:
    bl eval
    mov r6, r0
    mov r0, r6
    bl put_int
    ldr r0, =10
    bl put_char
    sub r6, r5, #1
    Mov r5, r6
    b bb12_0
bb12_2:
    ldr r0, =10
    bl put_char
    bl current_time
    mov r5, r0
    sub r6, r5, r4
    mov r0, r6
    bl put_int
    b bb12_3
bb12_3:
    ldr r0, =0
    mov sp, r11
    pop {r4, r5, r6, r7, r11, lr}
    bx lr
    .pool

    .type ..last_char, %object
    .data
    .globl ..last_char
    .p2align 2
..last_char:
    .long 32
    .size ..last_char, 4

    .type ..num, %object
    .comm ..num, 4, 4

    .type ..other, %object
    .comm ..other, 4, 4

    .type ..cur_token, %object
    .comm ..cur_token, 4, 4

