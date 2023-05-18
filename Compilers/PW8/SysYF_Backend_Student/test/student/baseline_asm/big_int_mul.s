    .arch armv7ve 
    .text 
    .globl main
    .p2align 2
    .type main, %function
main:
    push {r4, r5, r6, r7, r8, r9, r10, r11, r12, lr}
    mov r11, sp
    ldr lr, =568
    sub sp, sp, lr
    bl current_time
    str r0, [sp, #556]
    add r5, sp, #36
    ldr r6, =0
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =1
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =1
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =2
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =2
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =3
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =3
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =4
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =4
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =5
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =5
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =6
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =6
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =7
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =7
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =8
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =8
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =9
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =9
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =10
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =1
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =11
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =2
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =12
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =3
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =13
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =4
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =14
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =5
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =15
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =6
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =16
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =7
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =17
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =8
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =18
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =9
    str r5, [r6]
    add r5, sp, #36
    ldr r6, =19
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    add r5, sp, #116
    ldr r6, =0
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =2
    str r5, [r6]
    add r5, sp, #116
    ldr r6, =1
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =3
    str r5, [r6]
    add r5, sp, #116
    ldr r6, =2
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =4
    str r5, [r6]
    add r5, sp, #116
    ldr r6, =3
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =2
    str r5, [r6]
    add r5, sp, #116
    ldr r6, =4
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =5
    str r5, [r6]
    add r5, sp, #116
    ldr r6, =5
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =7
    str r5, [r6]
    add r5, sp, #116
    ldr r6, =6
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =9
    str r5, [r6]
    add r5, sp, #116
    ldr r6, =7
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =9
    str r5, [r6]
    add r5, sp, #116
    ldr r6, =8
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    add r5, sp, #116
    ldr r6, =9
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =1
    str r5, [r6]
    add r5, sp, #116
    ldr r6, =10
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =9
    str r5, [r6]
    add r5, sp, #116
    ldr r6, =11
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =8
    str r5, [r6]
    add r5, sp, #116
    ldr r6, =12
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =7
    str r5, [r6]
    add r5, sp, #116
    ldr r6, =13
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =6
    str r5, [r6]
    add r5, sp, #116
    ldr r6, =14
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =4
    str r5, [r6]
    add r5, sp, #116
    ldr r6, =15
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =3
    str r5, [r6]
    add r5, sp, #116
    ldr r6, =16
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =2
    str r5, [r6]
    add r5, sp, #116
    ldr r6, =17
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =1
    str r5, [r6]
    add r5, sp, #116
    ldr r6, =18
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =2
    str r5, [r6]
    add r5, sp, #116
    ldr r6, =19
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =2
    str r5, [r6]
    ldr r5, =396
    add r5, sp, r5
    ldr r6, =0
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    ldr r5, =396
    add r5, sp, r5
    ldr r6, =1
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    ldr r5, =396
    add r5, sp, r5
    ldr r6, =2
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    ldr r5, =396
    add r5, sp, r5
    ldr r6, =3
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    ldr r5, =396
    add r5, sp, r5
    ldr r6, =4
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    ldr r5, =396
    add r5, sp, r5
    ldr r6, =5
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    ldr r5, =396
    add r5, sp, r5
    ldr r6, =6
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    ldr r5, =396
    add r5, sp, r5
    ldr r6, =7
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    ldr r5, =396
    add r5, sp, r5
    ldr r6, =8
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    ldr r5, =396
    add r5, sp, r5
    ldr r6, =9
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    ldr r5, =396
    add r5, sp, r5
    ldr r6, =10
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    ldr r5, =396
    add r5, sp, r5
    ldr r6, =11
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    ldr r5, =396
    add r5, sp, r5
    ldr r6, =12
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    ldr r5, =396
    add r5, sp, r5
    ldr r6, =13
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    ldr r5, =396
    add r5, sp, r5
    ldr r6, =14
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    ldr r5, =396
    add r5, sp, r5
    ldr r6, =15
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    ldr r5, =396
    add r5, sp, r5
    ldr r6, =16
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    ldr r5, =396
    add r5, sp, r5
    ldr r6, =17
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    ldr r5, =396
    add r5, sp, r5
    ldr r6, =18
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    ldr r5, =396
    add r5, sp, r5
    ldr r6, =19
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    ldr r5, =396
    add r5, sp, r5
    ldr r6, =20
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    ldr r5, =396
    add r5, sp, r5
    ldr r6, =21
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    ldr r5, =396
    add r5, sp, r5
    ldr r6, =22
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    ldr r5, =396
    add r5, sp, r5
    ldr r6, =23
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    ldr r5, =396
    add r5, sp, r5
    ldr r6, =24
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    ldr r5, =396
    add r5, sp, r5
    ldr r6, =25
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    ldr r5, =396
    add r5, sp, r5
    ldr r6, =26
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    ldr r5, =396
    add r5, sp, r5
    ldr r6, =27
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    ldr r5, =396
    add r5, sp, r5
    ldr r6, =28
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    ldr r5, =396
    add r5, sp, r5
    ldr r6, =29
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    ldr r5, =396
    add r5, sp, r5
    ldr r6, =30
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    ldr r5, =396
    add r5, sp, r5
    ldr r6, =31
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    ldr r5, =396
    add r5, sp, r5
    ldr r6, =32
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    ldr r5, =396
    add r5, sp, r5
    ldr r6, =33
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    ldr r5, =396
    add r5, sp, r5
    ldr r6, =34
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    ldr r5, =396
    add r5, sp, r5
    ldr r6, =35
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    ldr r5, =396
    add r5, sp, r5
    ldr r6, =36
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    ldr r5, =396
    add r5, sp, r5
    ldr r6, =37
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    ldr r5, =396
    add r5, sp, r5
    ldr r6, =38
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    ldr r5, =396
    add r5, sp, r5
    ldr r6, =39
    ldr r7, =4
    mul r8, r6, r7
    add r6, r5, r8
    ldr r5, =0
    str r5, [r6]
    str lr, [sp, #-8]
    push {r12}
    Ldr r12, =0
    str r12, [sp, #564]
    pop {r12}
    ldr lr, [sp, #-8]
    b bb0_0
bb0_0:
    b litpool0_0
    .pool
litpool0_0:
    ldr r6, =20
    str r0, [sp, #20]
    ldr r0, [sp, #560]
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
    add r4, sp, #36
    ldr r5, =4
    str r0, [sp, #20]
    ldr r0, [sp, #560]
    mul r6, r0, r5
    add r5, r4, r6
    ldr r4, [r5]
    add r5, sp, #196
    ldr r6, =4
    ldr r0, [sp, #560]
    mul r7, r0, r6
    add r6, r5, r7
    str r4, [r6]
    ldr r0, [sp, #560]
    add r4, r0, #1
    ldr r0, [sp, #20]
    str lr, [sp, #-8]
    str r4, [sp, #560]
    ldr lr, [sp, #-8]
    b bb0_0
bb0_2:
    str lr, [sp, #-8]
    push {r12}
    Ldr r12, =0
    str r12, [sp, #568]
    pop {r12}
    ldr lr, [sp, #-8]
    b bb0_3
bb0_3:
    ldr r7, =20
    str r0, [sp, #20]
    ldr r0, [sp, #564]
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
    add r4, sp, #116
    ldr r5, =4
    str r0, [sp, #20]
    ldr r0, [sp, #564]
    mul r6, r0, r5
    add r5, r4, r6
    ldr r4, [r5]
    ldr r5, =296
    add r5, sp, r5
    ldr r6, =4
    ldr r0, [sp, #564]
    mul r7, r0, r6
    add r6, r5, r7
    str r4, [r6]
    ldr r0, [sp, #564]
    add r4, r0, #1
    ldr r0, [sp, #20]
    str lr, [sp, #-8]
    str r4, [sp, #564]
    ldr lr, [sp, #-8]
    b bb0_3
bb0_5:
    ldr r7, =20
    add r8, r7, #20
    sub r7, r8, #1
    Ldr r8, =0
    b bb0_6
bb0_6:
    b litpool0_1
    .pool
litpool0_1:
    cmp r8, r7
    ldr r9, =0
    ldrle r9, =1
    mov r10, r9
    ldr r9, =0
    cmp r10, r9
    ldr r0, =0
    ldrne r0, =1
    ldr r9, =0
    cmp r10, r9
    bne bb0_7
    b bb0_8
bb0_7:
    ldr r4, =396
    add r4, sp, r4
    ldr r5, =4
    mul r6, r8, r5
    add r5, r4, r6
    ldr r4, =0
    str r4, [r5]
    add r4, r8, #1
    Mov r8, r4
    b bb0_6
bb0_8:
    ldr r9, =20
    sub r10, r9, #1
    str r10, [sp, #-8]
    Ldr r9, =0
    Mov r10, r7
    ldr r2, [sp, #-8]
    b bb0_9
bb0_9:
    ldr r3, =-1
    cmp r2, r3
    ldr r12, =0
    ldrgt r12, =1
    mov r3, r12
    ldr r12, =0
    cmp r3, r12
    ldr r4, =0
    ldrne r4, =1
    ldr r12, =0
    cmp r3, r12
    bne bb0_10
    b bb0_11
bb0_10:
    ldr r4, =296
    add r4, sp, r4
    ldr r0, =4
    mul r1, r2, r0
    add r0, r4, r1
    ldr r4, [r0]
    ldr r0, =20
    sub r1, r0, #1
    Mov r0, r1
    b bb0_12
bb0_11:
    ldr r4, =396
    add r4, sp, r4
    ldr r0, =0
    ldr r1, =4
    mul r3, r0, r1
    add r0, r4, r3
    ldr r4, [r0]
    ldr r0, =0
    cmp r4, r0
    ldr r1, =0
    ldrne r1, =1
    mov r4, r1
    ldr r0, =0
    cmp r4, r0
    ldr r1, =0
    ldrne r1, =1
    ldr r0, =0
    cmp r4, r0
    bne bb0_18
    b bb0_19
bb0_12:
    b litpool0_2
    .pool
litpool0_2:
    ldr r1, =-1
    cmp r0, r1
    ldr r3, =0
    ldrgt r3, =1
    mov r1, r3
    ldr r3, =0
    cmp r1, r3
    ldr r12, =0
    ldrne r12, =1
    ldr r3, =0
    cmp r1, r3
    bne bb0_13
    b bb0_14
bb0_13:
    ldr r9, =396
    add r9, sp, r9
    ldr r1, =4
    mul r3, r10, r1
    add r1, r9, r3
    ldr r9, [r1]
    add r1, sp, #196
    ldr r3, =4
    mul r12, r0, r3
    add r3, r1, r12
    ldr r1, [r3]
    mul r3, r4, r1
    add r1, r9, r3
    ldr r9, =10
    cmp r1, r9
    ldr r3, =0
    ldrge r3, =1
    mov r9, r3
    ldr r3, =0
    cmp r9, r3
    ldr r12, =0
    ldrne r12, =1
    ldr r3, =0
    cmp r9, r3
    bne bb0_15
    b bb0_16
bb0_14:
    add r1, r10, #20
    sub r3, r1, #1
    sub r1, r2, #1
    str r0, [sp, #-8]
    str r1, [sp, #-12]
    Mov r10, r3
    Mov r0, r4
    ldr r1, [sp, #-8]
    ldr r2, [sp, #-12]
    b bb0_9
bb0_15:
    ldr r9, =396
    add r9, sp, r9
    ldr r3, =4
    mul r12, r10, r3
    add r3, r9, r12
    str r1, [r3]
    sub r9, r10, #1
    ldr r3, =396
    add r3, sp, r3
    ldr r12, =4
    mul r5, r9, r12
    add r9, r3, r5
    ldr r5, [r9]
    ldr r9, =10
    sdiv r3, r1, r9
    add r9, r5, r3
    sub r5, r10, #1
    ldr r3, =396
    add r3, sp, r3
    ldr r12, =4
    mul r6, r5, r12
    add r5, r3, r6
    str r9, [r5]
    b bb0_17
bb0_16:
    ldr r9, =396
    add r9, sp, r9
    ldr r3, =4
    mul r12, r10, r3
    add r3, r9, r12
    str r1, [r3]
    b bb0_17
bb0_17:
    sub r9, r0, #1
    sub r3, r10, #1
    str r9, [sp, #-8]
    Mov r9, r1
    Mov r10, r3
    ldr r0, [sp, #-8]
    b bb0_12
bb0_18:
    b litpool0_3
    .pool
litpool0_3:
    ldr r4, =396
    add r4, sp, r4
    ldr r0, =0
    ldr r1, =4
    mul r3, r0, r1
    add r0, r4, r3
    ldr r4, [r0]
    mov r0, r4
    bl put_int
    b bb0_19
bb0_19:
    Ldr r4, =1
    b bb0_20
bb0_20:
    ldr r0, =20
    add r1, r0, #20
    sub r0, r1, #1
    cmp r4, r0
    ldr r1, =0
    ldrle r1, =1
    mov r0, r1
    ldr r1, =0
    cmp r0, r1
    ldr r3, =0
    ldrne r3, =1
    ldr r1, =0
    cmp r0, r1
    bne bb0_21
    b bb0_22
bb0_21:
    ldr r0, =396
    add r0, sp, r0
    ldr r1, =4
    mul r3, r4, r1
    add r1, r0, r3
    ldr r0, [r1]
    STM SP, {r0}
    ldr r0, [sp]
    bl put_int
    LDM sp, {r0}
    add r0, r4, #1
    Mov r4, r0
    b bb0_20
bb0_22:
    ldr r0, =10
    bl put_char
    STM SP, {r0}
    bl current_time
    str r2, [sp, #20]
    ldr r2, [sp, #556]
    sub r1, r0, r2
    STM SP, {r1}
    ldr r0, [sp]
    bl put_int
    LDM sp, {r1}
    ldr r2, [sp, #20]
    b bb0_23
bb0_23:
    ldr r0, =0
    mov sp, r11
    pop {r4, r5, r6, r7, r8, r9, r10, r11, r12, lr}
    bx lr
    .pool

