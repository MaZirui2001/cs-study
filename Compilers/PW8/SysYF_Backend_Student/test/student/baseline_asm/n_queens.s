    .arch armv7ve 
    .text 
    .globl printans
    .p2align 2
    .type printans, %function
printans:
    push {r4, r5, r6, r7, r11, lr}
    mov r11, sp
    sub sp, sp, #4
    ldr r4, Addr0_1
    ldr r4, [r4]
    add r5, r4, #1
    push {r0}
    ldr r0, Addr0_1
    str r5, [r0]
    pop {r0}
    Ldr r4, =1
    b bb0_0
bb0_0:
    ldr r5, Addr0_2
    ldr r5, [r5]
    cmp r4, r5
    ldr r6, =0
    ldrle r6, =1
    mov r5, r6
    ldr r6, =0
    cmp r5, r6
    ldr r7, =0
    ldrne r7, =1
    ldr r6, =0
    cmp r5, r6
    bne bb0_1
    b bb0_2
bb0_1:
    ldr r5, Addr0_0
    ldr r6, =4
    mul r7, r4, r6
    add r6, r5, r7
    ldr r5, [r6]
    mov r0, r5
    bl put_int
    ldr r5, Addr0_2
    ldr r5, [r5]
    cmp r4, r5
    ldr r6, =0
    ldreq r6, =1
    mov r5, r6
    ldr r6, =0
    cmp r5, r6
    ldr r7, =0
    ldrne r7, =1
    ldr r6, =0
    cmp r5, r6
    bne bb0_3
    b bb0_4
bb0_2:
    b bb0_6
bb0_3:
    ldr r0, =10
    bl put_char
    b bb0_6
bb0_4:
    ldr r0, =32
    bl put_char
    b bb0_5
bb0_5:
    b litpool0_0
    .pool
litpool0_0:
    add r5, r4, #1
    Mov r4, r5
    b bb0_0
bb0_6:
    mov sp, r11
    pop {r4, r5, r6, r7, r11, lr}
    bx lr
    .pool
Addr0_0:
    .long ..ans
Addr0_1:
    .long ..sum
Addr0_2:
    .long ..n

    .globl f
    .p2align 2
    .type f, %function
f:
    push {r4, r5, r6, r7, r8, r9, r11, lr}
    mov r11, sp
    sub sp, sp, #8
    Mov r4, r0
    Ldr r5, =1
    b bb1_0
bb1_0:
    ldr r6, Addr1_1
    ldr r6, [r6]
    cmp r5, r6
    ldr r7, =0
    ldrle r7, =1
    mov r6, r7
    ldr r7, =0
    cmp r6, r7
    ldr r8, =0
    ldrne r8, =1
    ldr r7, =0
    cmp r6, r7
    bne bb1_1
    b bb1_2
bb1_1:
    ldr r6, Addr1_2
    ldr r7, =4
    mul r8, r5, r7
    add r7, r6, r8
    ldr r6, [r7]
    ldr r7, =1
    cmp r6, r7
    ldr r8, =0
    ldrne r8, =1
    mov r6, r8
    ldr r7, =0
    cmp r6, r7
    ldr r8, =0
    ldrne r8, =1
    ldr r7, =0
    cmp r6, r7
    bne bb1_3
    b bb1_4
bb1_2:
    b bb1_11
bb1_3:
    add r6, r4, r5
    ldr r7, Addr1_3
    ldr r8, =4
    mul r9, r6, r8
    add r6, r7, r9
    ldr r7, [r6]
    ldr r6, =0
    cmp r7, r6
    ldr r8, =0
    ldreq r8, =1
    mov r6, r8
    ldr r7, =0
    cmp r6, r7
    ldr r8, =0
    ldrne r8, =1
    ldr r7, =0
    cmp r6, r7
    bne bb1_5
    b bb1_6
bb1_4:
    add r6, r5, #1
    Mov r5, r6
    b bb1_0
bb1_5:
    b litpool1_0
    .pool
litpool1_0:
    ldr r6, Addr1_1
    ldr r6, [r6]
    add r7, r6, r4
    sub r6, r7, r5
    ldr r7, Addr1_4
    ldr r8, =4
    mul r9, r6, r8
    add r6, r7, r9
    ldr r7, [r6]
    ldr r6, =0
    cmp r7, r6
    ldr r8, =0
    ldreq r8, =1
    mov r6, r8
    ldr r7, =0
    cmp r6, r7
    ldr r8, =0
    ldrne r8, =1
    ldr r7, =0
    cmp r6, r7
    bne bb1_7
    b bb1_8
bb1_6:
    b bb1_4
bb1_7:
    ldr r6, Addr1_0
    ldr r7, =4
    mul r8, r4, r7
    add r7, r6, r8
    str r5, [r7]
    ldr r6, Addr1_1
    ldr r6, [r6]
    cmp r4, r6
    ldr r7, =0
    ldreq r7, =1
    mov r6, r7
    ldr r7, =0
    cmp r6, r7
    ldr r8, =0
    ldrne r8, =1
    ldr r7, =0
    cmp r6, r7
    bne bb1_9
    b bb1_10
bb1_8:
    b bb1_6
bb1_9:
    bl printans
    b bb1_10
bb1_10:
    ldr r6, Addr1_2
    ldr r7, =4
    mul r8, r5, r7
    add r7, r6, r8
    ldr r6, =1
    str r6, [r7]
    add r6, r4, r5
    ldr r7, Addr1_3
    ldr r8, =4
    mul r9, r6, r8
    add r6, r7, r9
    ldr r7, =1
    str r7, [r6]
    ldr r6, Addr1_1
    ldr r6, [r6]
    add r7, r6, r4
    sub r6, r7, r5
    ldr r7, Addr1_4
    ldr r8, =4
    mul r9, r6, r8
    add r6, r7, r9
    ldr r7, =1
    str r7, [r6]
    add r6, r4, #1
    mov r0, r6
    bl f
    ldr r6, Addr1_2
    ldr r7, =4
    mul r8, r5, r7
    add r7, r6, r8
    ldr r6, =0
    str r6, [r7]
    add r6, r4, r5
    ldr r7, Addr1_3
    ldr r8, =4
    mul r9, r6, r8
    add r6, r7, r9
    ldr r7, =0
    str r7, [r6]
    ldr r6, Addr1_1
    ldr r6, [r6]
    add r7, r6, r4
    sub r6, r7, r5
    ldr r7, Addr1_4
    ldr r8, =4
    mul r9, r6, r8
    add r6, r7, r9
    ldr r7, =0
    str r7, [r6]
    b bb1_8
bb1_11:
    b litpool1_1
    .pool
litpool1_1:
    mov sp, r11
    pop {r4, r5, r6, r7, r8, r9, r11, lr}
    bx lr
    .pool
Addr1_0:
    .long ..ans
Addr1_1:
    .long ..n
Addr1_2:
    .long ..row
Addr1_3:
    .long ..line1
Addr1_4:
    .long ..line2

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
    push {r0}
    ldr r0, Addr2_1
    str r6, [r0]
    pop {r0}
    ldr r0, =1
    bl f
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
    ldr r6, Addr2_0
    ldr r6, [r6]
    b bb2_3
bb2_3:
    mov r0, r6
    mov sp, r11
    pop {r4, r5, r6, r7, r8, r11, lr}
    bx lr
    .pool
Addr2_0:
    .long ..sum
Addr2_1:
    .long ..n

    .type ..ans, %object
    .comm ..ans, 200, 4

    .type ..sum, %object
    .bss
    .globl ..sum
    .p2align 2
..sum:
    .long 0
    .size ..sum, 4

    .type ..n, %object
    .comm ..n, 4, 4

    .type ..row, %object
    .comm ..row, 200, 4

    .type ..line1, %object
    .comm ..line1, 200, 4

    .type ..line2, %object
    .comm ..line2, 400, 4

