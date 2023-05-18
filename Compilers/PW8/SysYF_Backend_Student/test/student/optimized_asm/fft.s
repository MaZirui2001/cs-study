    .arch armv7ve 
    .text 
    .globl multiply
    .p2align 2
    .type multiply, %function
multiply:
    push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    mov r11, sp
    sub sp, sp, #12
    Mov r4, r0
    Mov r6, r1
    ldr r5, =0
    cmp r6, r5
    ldr r7, =0
    ldreq r7, =1
    mov r5, r7
    ldr r8, =0
    cmp r5, r8
    ldr r7, =0
    ldrne r7, =1
    ldr r8, =0
    cmp r5, r8
    bne bb0_0
    b bb0_1
bb0_0:
    Ldr r4, =0
    b bb0_6
bb0_1:
    ldr r5, =1
    cmp r6, r5
    ldr r7, =0
    ldreq r7, =1
    mov r5, r7
    ldr r8, =0
    cmp r5, r8
    ldr r7, =0
    ldrne r7, =1
    ldr r8, =0
    cmp r5, r8
    bne bb0_2
    b bb0_3
bb0_2:
    ldr r7, =998244353
    sdiv r6, r4, r7
    ldr r7, =998244353
    mul r8, r6, r7
    sub r6, r4, r8
    Mov r4, r6
    b bb0_6
bb0_3:
    ldr r7, =2
    sdiv r8, r6, r7
    mov r0, r4
    mov r1, r8
    bl multiply
    mov r7, r0
    add r8, r7, r7
    ldr r9, =998244353
    sdiv r7, r8, r9
    ldr r9, =998244353
    mul r10, r7, r9
    sub r7, r8, r10
    ldr r9, =2
    sdiv r8, r6, r9
    ldr r10, =2
    mul r9, r8, r10
    sub r8, r6, r9
    ldr r6, =1
    cmp r8, r6
    ldr r10, =0
    ldreq r10, =1
    mov r6, r10
    ldr r9, =0
    cmp r6, r9
    ldr r8, =0
    ldrne r8, =1
    ldr r9, =0
    cmp r6, r9
    bne bb0_4
    b bb0_5
bb0_4:
    add r8, r7, r4
    ldr r7, =998244353
    sdiv r4, r8, r7
    ldr r7, =998244353
    mul r9, r4, r7
    sub r4, r8, r9
    Mov r5, r7
    b bb0_6
bb0_5:
    b litpool0_0
    .pool
litpool0_0:
    Mov r5, r7
    Mov r4, r7
    b bb0_6
bb0_6:
    mov r0, r4
    mov sp, r11
    pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    bx lr
    .pool

    .globl power
    .p2align 2
    .type power, %function
power:
    push {r4, r5, r6, r7, r8, r9, r11, lr}
    mov r11, sp
    sub sp, sp, #12
    Mov r4, r0
    Mov r6, r1
    ldr r5, =0
    cmp r6, r5
    ldr r7, =0
    ldreq r7, =1
    mov r5, r7
    ldr r8, =0
    cmp r5, r8
    ldr r7, =0
    ldrne r7, =1
    ldr r8, =0
    cmp r5, r8
    bne bb1_0
    b bb1_1
bb1_0:
    Ldr r5, =1
    b bb1_4
bb1_1:
    ldr r7, =2
    sdiv r5, r6, r7
    mov r0, r4
    mov r1, r5
    bl power
    mov r7, r0
    mov r0, r7
    mov r1, r7
    bl multiply
    mov r5, r0
    ldr r8, =2
    sdiv r7, r6, r8
    ldr r8, =2
    mul r9, r7, r8
    sub r7, r6, r9
    ldr r6, =1
    cmp r7, r6
    ldr r8, =0
    ldreq r8, =1
    mov r6, r8
    ldr r8, =0
    cmp r6, r8
    ldr r7, =0
    ldrne r7, =1
    ldr r8, =0
    cmp r6, r8
    bne bb1_2
    b bb1_3
bb1_2:
    mov r0, r5
    mov r1, r4
    bl multiply
    mov r6, r0
    Mov r4, r5
    Mov r5, r6
    b bb1_4
bb1_3:
    Mov r4, r5
    b bb1_4
bb1_4:
    mov r0, r5
    mov sp, r11
    pop {r4, r5, r6, r7, r8, r9, r11, lr}
    bx lr
    .pool

    .globl memmove
    .p2align 2
    .type memmove, %function
memmove:
    push {r4, r5, r6, r7, r8, r9, r10, lr}
    sub sp, sp, #28
    Mov r4, r0
    Mov r6, r1
    Mov r5, r2
    Mov r7, r3
    Ldr r8, =0
    b bb2_0
bb2_0:
    b litpool2_0
    .pool
litpool2_0:
    cmp r8, r7
    ldr r0, =0
    ldrlt r0, =1
    mov r9, r0
    ldr r10, =0
    cmp r9, r10
    ldr r0, =0
    ldrne r0, =1
    ldr r10, =0
    cmp r9, r10
    bne bb2_1
    b bb2_2
bb2_1:
    add r9, r5, #0
    ldr r0, =4
    mul r10, r8, r0
    add r0, r9, r10
    ldr r9, [r0]
    add r10, r6, r8
    add r0, r4, #0
    ldr r1, =4
    mul r2, r10, r1
    add r10, r0, r2
    str r9, [r10]
    add r0, r8, #1
    Mov r8, r0
    b bb2_0
bb2_2:
    b bb2_3
bb2_3:
    mov r0, r8
    add sp, sp, #28
    pop {r4, r5, r6, r7, r8, r9, r10, lr}
    bx lr
    .pool

    .globl fft
    .p2align 2
    .type fft, %function
fft:
    push {r4, r5, r6, r7, r8, r9, r10, r11, r12, lr}
    mov r11, sp
    sub sp, sp, #56
    Mov r5, r0
    str r1, [sp, #44]
    Mov r6, r2
    Mov r7, r3
    ldr r0, =1
    cmp r6, r0
    ldr r1, =0
    ldreq r1, =1
    mov r0, r1
    ldr r2, =0
    cmp r0, r2
    ldr r1, =0
    ldrne r1, =1
    ldr r2, =0
    cmp r0, r2
    bne bb3_0
    b bb3_1
bb3_0:
    Ldr r2, =1
    b bb3_11
bb3_1:
    Ldr r10, =0
    b bb3_2
bb3_2:
    b litpool3_0
    .pool
litpool3_0:
    cmp r10, r6
    ldr r1, =0
    ldrlt r1, =1
    mov r0, r1
    ldr r2, =0
    cmp r0, r2
    ldr r1, =0
    ldrne r1, =1
    ldr r2, =0
    cmp r0, r2
    bne bb3_3
    b bb3_4
bb3_3:
    ldr r1, =2
    sdiv r0, r10, r1
    ldr r1, =2
    mul r2, r0, r1
    sub r0, r10, r2
    ldr r2, =0
    cmp r0, r2
    ldr r1, =0
    ldreq r1, =1
    mov r0, r1
    ldr r2, =0
    cmp r0, r2
    ldr r1, =0
    ldrne r1, =1
    ldr r2, =0
    cmp r0, r2
    bne bb3_5
    b bb3_6
bb3_4:
    ldr r0, Addr3_0
    ldr r1, =0
    ldr r3, =4
    mul r2, r1, r3
    add r1, r0, r2
    STM SP, {r0, r1}
    mov r0, r5
    ldr r1, [sp, #44]
    ldr r2, [sp, #4]
    mov r3, r6
    bl memmove
    LDMIB SP, {r1}
    ldr r2, =2
    sdiv r1, r6, r2
    STM SP, {r0, r1, r2}
    mov r0, r7
    mov r1, r7
    bl multiply
    LDMIB SP, {r1, r2}
    mov r2, r0
    ldr r0, [SP]
    STM SP, {r0, r1, r2}
    mov r0, r5
    ldr r1, [sp, #44]
    ldr r2, [sp, #4]
    ldr r3, [sp, #8]
    bl fft
    LDMIB SP, {r1, r2}
    mov r8, r0
    ldr r0, [SP]
    ldr r1, =2
    sdiv r2, r6, r1
    str r0, [sp, #20]
    ldr r0, [sp, #44]
    add r1, r0, r2
    ldr r3, =2
    sdiv r2, r6, r3
    STM SP, {r0, r1, r2, r3}
    mov r0, r7
    mov r1, r7
    bl multiply
    LDMIB SP, {r1, r2, r3}
    mov r3, r0
    ldr r0, [SP]
    STM SP, {r0, r1, r2, r3}
    mov r0, r5
    ldr r1, [sp, #4]
    ldr r2, [sp, #8]
    ldr r3, [sp, #12]
    bl fft
    LDMIB SP, {r1, r2, r3}
    mov r9, r0
    ldr r0, [SP]
    ldr r0, [sp, #20]
    Ldr r8, =1
    Ldr r9, =0
    b bb3_8
bb3_5:
    str r0, [sp, #20]
    ldr r0, [sp, #44]
    add r1, r10, r0
    add r0, r5, #0
    ldr r3, =4
    mul r2, r1, r3
    add r1, r0, r2
    ldr r0, [r1]
    ldr r2, =2
    sdiv r1, r10, r2
    ldr r2, Addr3_0
    ldr r4, =4
    mul r3, r1, r4
    add r1, r2, r3
    str r0, [r1]
    b bb3_7
bb3_6:
    str r0, [sp, #20]
    ldr r0, [sp, #44]
    add r1, r10, r0
    add r0, r5, #0
    ldr r2, =4
    mul r3, r1, r2
    add r1, r0, r3
    ldr r0, [r1]
    ldr r2, =2
    sdiv r1, r6, r2
    ldr r2, =2
    sdiv r3, r10, r2
    add r2, r1, r3
    ldr r1, Addr3_0
    ldr r3, =4
    mul r9, r2, r3
    add r2, r1, r9
    str r0, [r2]
    b bb3_7
bb3_7:
    b litpool3_1
    .pool
litpool3_1:
    add r0, r10, #1
    Mov r10, r0
    b bb3_2
bb3_8:
    ldr r1, =2
    sdiv r0, r6, r1
    cmp r9, r0
    ldr r1, =0
    ldrlt r1, =1
    mov r0, r1
    ldr r2, =0
    cmp r0, r2
    ldr r1, =0
    ldrne r1, =1
    ldr r2, =0
    cmp r0, r2
    bne bb3_9
    b bb3_10
bb3_9:
    str r1, [sp, #20]
    ldr r1, [sp, #44]
    add r0, r1, r9
    add r1, r5, #0
    ldr r2, =4
    mul r3, r0, r2
    add r0, r1, r3
    ldr r10, [r0]
    str r1, [sp, #20]
    ldr r1, [sp, #44]
    add r0, r1, r9
    ldr r1, =2
    sdiv r2, r6, r1
    add r1, r0, r2
    add r0, r5, #0
    ldr r2, =4
    mul r3, r1, r2
    add r1, r0, r3
    ldr r0, [r1]
    STM SP, {r0, r1}
    mov r0, r8
    ldr r1, [sp]
    bl multiply
    LDMIB SP, {r1}
    mov r1, r0
    ldr r0, [SP]
    add r4, r10, r1
    ldr r3, =998244353
    sdiv r1, r4, r3
    ldr r12, =998244353
    mul r3, r1, r12
    sub r1, r4, r3
    str r0, [sp, #20]
    ldr r0, [sp, #44]
    add r2, r0, r9
    add r3, r5, #0
    ldr r12, =4
    mul r4, r2, r12
    add r2, r3, r4
    str r1, [r2]
    ldr r0, [sp, #20]
    STM SP, {r0, r1}
    mov r0, r8
    ldr r1, [sp]
    bl multiply
    LDMIB SP, {r1}
    mov r1, r0
    ldr r0, [SP]
    sub r0, r10, r1
    ldr r2, =998244353
    add r1, r0, r2
    ldr r2, =998244353
    sdiv r0, r1, r2
    ldr r3, =998244353
    mul r2, r0, r3
    sub r0, r1, r2
    str r0, [sp, #20]
    ldr r0, [sp, #44]
    add r2, r0, r9
    ldr r1, =2
    sdiv r3, r6, r1
    add r1, r2, r3
    add r2, r5, #0
    ldr r10, =4
    mul r3, r1, r10
    add r1, r2, r3
    ldr r0, [sp, #20]
    str r0, [r1]
    STM SP, {r0}
    mov r0, r8
    mov r1, r7
    bl multiply
    add r1, r9, #1
    Mov r8, r0
    Mov r9, r1
    b bb3_8
bb3_10:
    Mov r0, r8
    Mov r1, r9
    Ldr r2, =0
    b bb3_11
bb3_11:
    mov r0, r2
    mov sp, r11
    pop {r4, r5, r6, r7, r8, r9, r10, r11, r12, lr}
    bx lr
    .pool
Addr3_0:
    .long ..temp

    .globl main
    .p2align 2
    .type main, %function
main:
    push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    mov r11, sp
    sub sp, sp, #20
    bl current_time
    mov r4, r0
    ldr r5, Addr4_1
    ldr r6, =0
    ldr r1, =4
    mul r0, r6, r1
    add r1, r5, r0
    STM SP, {r1}
    ldr r0, [sp]
    bl get_int_array
    LDM SP, {r1}
    mov r5, r0
    ldr r6, Addr4_2
    ldr r7, =0
    ldr r0, =4
    mul r1, r7, r0
    add r0, r6, r1
    STM SP, {r0}
    ldr r0, [sp]
    bl get_int_array
    mov r6, r0
    ldr r0, [SP]
    ldr r0, =1
    push {r1}
    ldr r1, Addr4_0
    str r0, [r1]
    pop {r1}
    b bb4_0
bb4_0:
    ldr r7, Addr4_0
    ldr r7, [r7]
    add r1, r5, r6
    sub r0, r1, #1
    cmp r7, r0
    ldr r8, =0
    ldrlt r8, =1
    mov r7, r8
    ldr r0, =0
    cmp r7, r0
    ldr r8, =0
    ldrne r8, =1
    ldr r0, =0
    cmp r7, r0
    bne bb4_1
    b bb4_2
bb4_1:
    b litpool4_0
    .pool
litpool4_0:
    ldr r7, Addr4_0
    ldr r7, [r7]
    ldr r1, =2
    mul r0, r7, r1
    push {r1}
    ldr r1, Addr4_0
    str r0, [r1]
    pop {r1}
    b bb4_0
bb4_2:
    ldr r7, Addr4_1
    ldr r8, =0
    ldr r9, =4
    mul r0, r8, r9
    add r8, r7, r0
    ldr r1, Addr4_0
    ldr r1, [r1]
    ldr r7, Addr4_0
    ldr r7, [r7]
    ldr r0, =998244352
    sdiv r10, r0, r7
    STM SP, {r0, r1}
    ldr r0, =3
    mov r1, r10
    bl power
    LDMIB SP, {r1}
    STM SP, {r0, r1}
    mov r0, r8
    ldr r1, =0
    ldr r2, [sp, #4]
    ldr r3, [sp]
    bl fft
    LDMIB SP, {r1}
    mov r7, r0
    ldr r0, [SP]
    ldr r9, Addr4_2
    ldr r8, =0
    ldr r0, =4
    mul r10, r8, r0
    add r8, r9, r10
    ldr r9, Addr4_0
    ldr r9, [r9]
    ldr r10, Addr4_0
    ldr r10, [r10]
    ldr r1, =998244352
    sdiv r0, r1, r10
    STM SP, {r0, r1}
    ldr r0, =3
    ldr r1, [sp]
    bl power
    LDMIB SP, {r1}
    mov r1, r0
    ldr r0, [SP]
    STM SP, {r0, r1}
    mov r0, r8
    ldr r1, =0
    mov r2, r9
    ldr r3, [sp, #4]
    bl fft
    LDMIB SP, {r1}
    Ldr r7, =0
    b bb4_3
bb4_3:
    ldr r0, Addr4_0
    ldr r0, [r0]
    cmp r7, r0
    ldr r9, =0
    ldrlt r9, =1
    mov r8, r9
    ldr r0, =0
    cmp r8, r0
    ldr r9, =0
    ldrne r9, =1
    ldr r0, =0
    cmp r8, r0
    bne bb4_4
    b bb4_5
bb4_4:
    ldr r8, Addr4_1
    ldr r1, =4
    mul r0, r7, r1
    add r1, r8, r0
    ldr r8, [r1]
    ldr r9, Addr4_2
    ldr r0, =4
    mul r1, r7, r0
    add r0, r9, r1
    ldr r1, [r0]
    STM SP, {r1}
    mov r0, r8
    ldr r1, [sp]
    bl multiply
    LDM SP, {r1}
    mov r9, r0
    ldr r8, Addr4_1
    ldr r1, =4
    mul r0, r7, r1
    add r10, r8, r0
    str r9, [r10]
    add r0, r7, #1
    Mov r7, r0
    b bb4_3
bb4_5:
    ldr r8, Addr4_1
    ldr r7, =0
    ldr r0, =4
    mul r1, r7, r0
    add r7, r8, r1
    ldr r8, Addr4_0
    ldr r8, [r8]
    ldr r1, Addr4_0
    ldr r1, [r1]
    ldr r0, =998244352
    sdiv r9, r0, r1
    ldr r1, =998244352
    sub r0, r1, r9
    STM SP, {r0}
    ldr r0, =3
    ldr r1, [sp]
    bl power
    mov r9, r0
    ldr r0, [SP]
    STM SP, {r0}
    mov r0, r7
    ldr r1, =0
    mov r2, r8
    mov r3, r9
    bl fft
    Ldr r7, =0
    b bb4_6
bb4_6:
    b litpool4_1
    .pool
litpool4_1:
    ldr r8, Addr4_0
    ldr r8, [r8]
    cmp r7, r8
    ldr r0, =0
    ldrlt r0, =1
    mov r8, r0
    ldr r0, =0
    cmp r8, r0
    ldr r9, =0
    ldrne r9, =1
    ldr r0, =0
    cmp r8, r0
    bne bb4_7
    b bb4_8
bb4_7:
    ldr r8, Addr4_1
    ldr r0, =4
    mul r9, r7, r0
    add r0, r8, r9
    ldr r9, [r0]
    ldr r8, Addr4_0
    ldr r8, [r8]
    STM SP, {r0}
    mov r0, r8
    ldr r1, =998244351
    bl power
    STM SP, {r0}
    mov r0, r9
    ldr r1, [sp]
    bl multiply
    mov r8, r0
    ldr r0, [SP]
    ldr r9, Addr4_1
    ldr r0, =4
    mul r1, r7, r0
    add r10, r9, r1
    str r8, [r10]
    add r0, r7, #1
    Mov r7, r0
    b bb4_6
bb4_8:
    add r0, r5, r6
    sub r5, r0, #1
    ldr r6, Addr4_1
    ldr r7, =0
    ldr r0, =4
    mul r8, r7, r0
    add r0, r6, r8
    STM SP, {r0}
    mov r0, r5
    ldr r1, [sp]
    bl put_int_array
    LDM sp, {r0}
    ldr r0, =10
    bl put_char
    STM SP, {r1}
    bl current_time
    LDM SP, {r1}
    mov r1, r0
    sub r0, r1, r4
    STM SP, {r0}
    ldr r0, [sp]
    bl put_int
    LDM sp, {r0}
    b bb4_9
bb4_9:
    ldr r0, =0
    mov sp, r11
    pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    bx lr
    .pool
Addr4_0:
    .long ..d
Addr4_1:
    .long ..a
Addr4_2:
    .long ..b

    .type ..d, %object
    .comm ..d, 4, 4

    .type ..temp, %object
    .comm ..temp, 8388608, 4

    .type ..a, %object
    .comm ..a, 8388608, 4

    .type ..b, %object
    .comm ..b, 8388608, 4

    .type ..c, %object
    .comm ..c, 8388608, 4

