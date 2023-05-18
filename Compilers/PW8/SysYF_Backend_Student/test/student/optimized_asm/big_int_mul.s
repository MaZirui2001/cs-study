    .arch armv7ve 
    .text 
    .globl main
    .p2align 2
    .type main, %function
main:
    push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    mov r11, sp
    ldr lr, =556
    sub sp, sp, lr
    bl current_time
    mov r4, r0
    add r5, sp, #36
    ldr r0, =0
    ldr r6, =4
    mul r1, r0, r6
    add r0, r5, r1
    ldr r1, =1
    str r1, [r0]
    add r5, sp, #36
    ldr r0, =1
    ldr r1, =4
    mul r6, r0, r1
    add r0, r5, r6
    ldr r1, =2
    str r1, [r0]
    add r5, sp, #36
    ldr r0, =2
    ldr r2, =4
    mul r1, r0, r2
    add r0, r5, r1
    ldr r1, =3
    str r1, [r0]
    add r5, sp, #36
    ldr r0, =3
    ldr r6, =4
    mul r1, r0, r6
    add r0, r5, r1
    ldr r1, =4
    str r1, [r0]
    add r5, sp, #36
    ldr r0, =4
    ldr r1, =4
    mul r2, r0, r1
    add r0, r5, r2
    ldr r1, =5
    str r1, [r0]
    add r5, sp, #36
    ldr r0, =5
    ldr r2, =4
    mul r1, r0, r2
    add r0, r5, r1
    ldr r1, =6
    str r1, [r0]
    add r5, sp, #36
    ldr r0, =6
    ldr r2, =4
    mul r1, r0, r2
    add r0, r5, r1
    ldr r1, =7
    str r1, [r0]
    add r5, sp, #36
    ldr r0, =7
    ldr r2, =4
    mul r1, r0, r2
    add r0, r5, r1
    ldr r1, =8
    str r1, [r0]
    add r5, sp, #36
    ldr r0, =8
    ldr r1, =4
    mul r2, r0, r1
    add r0, r5, r2
    ldr r1, =9
    str r1, [r0]
    add r5, sp, #36
    ldr r0, =9
    ldr r1, =4
    mul r2, r0, r1
    add r0, r5, r2
    ldr r1, =0
    str r1, [r0]
    add r5, sp, #36
    ldr r0, =10
    ldr r2, =4
    mul r1, r0, r2
    add r0, r5, r1
    ldr r1, =1
    str r1, [r0]
    add r5, sp, #36
    ldr r0, =11
    ldr r1, =4
    mul r2, r0, r1
    add r0, r5, r2
    ldr r1, =2
    str r1, [r0]
    add r5, sp, #36
    ldr r0, =12
    ldr r2, =4
    mul r1, r0, r2
    add r0, r5, r1
    ldr r1, =3
    str r1, [r0]
    add r5, sp, #36
    ldr r0, =13
    ldr r2, =4
    mul r1, r0, r2
    add r0, r5, r1
    ldr r1, =4
    str r1, [r0]
    add r5, sp, #36
    ldr r0, =14
    ldr r2, =4
    mul r1, r0, r2
    add r0, r5, r1
    ldr r1, =5
    str r1, [r0]
    add r5, sp, #36
    ldr r0, =15
    ldr r2, =4
    mul r1, r0, r2
    add r0, r5, r1
    ldr r1, =6
    str r1, [r0]
    add r5, sp, #36
    ldr r0, =16
    ldr r2, =4
    mul r1, r0, r2
    add r0, r5, r1
    ldr r1, =7
    str r1, [r0]
    add r5, sp, #36
    ldr r0, =17
    ldr r2, =4
    mul r1, r0, r2
    add r0, r5, r1
    ldr r1, =8
    str r1, [r0]
    add r5, sp, #36
    ldr r0, =18
    ldr r2, =4
    mul r1, r0, r2
    add r0, r5, r1
    ldr r1, =9
    str r1, [r0]
    add r5, sp, #36
    ldr r0, =19
    ldr r6, =4
    mul r1, r0, r6
    add r0, r5, r1
    ldr r1, =0
    str r1, [r0]
    add r5, sp, #116
    ldr r0, =0
    ldr r6, =4
    mul r1, r0, r6
    add r0, r5, r1
    ldr r1, =2
    str r1, [r0]
    add r5, sp, #116
    ldr r0, =1
    ldr r1, =4
    mul r2, r0, r1
    add r0, r5, r2
    ldr r1, =3
    str r1, [r0]
    add r5, sp, #116
    ldr r0, =2
    ldr r6, =4
    mul r1, r0, r6
    add r0, r5, r1
    ldr r1, =4
    str r1, [r0]
    add r5, sp, #116
    ldr r0, =3
    ldr r6, =4
    mul r1, r0, r6
    add r0, r5, r1
    ldr r1, =2
    str r1, [r0]
    add r5, sp, #116
    ldr r0, =4
    ldr r6, =4
    mul r1, r0, r6
    add r0, r5, r1
    ldr r1, =5
    str r1, [r0]
    add r5, sp, #116
    ldr r0, =5
    ldr r2, =4
    mul r1, r0, r2
    add r0, r5, r1
    ldr r1, =7
    str r1, [r0]
    add r5, sp, #116
    ldr r0, =6
    ldr r1, =4
    mul r2, r0, r1
    add r0, r5, r2
    ldr r1, =9
    str r1, [r0]
    add r5, sp, #116
    ldr r0, =7
    ldr r1, =4
    mul r2, r0, r1
    add r0, r5, r2
    ldr r1, =9
    str r1, [r0]
    add r5, sp, #116
    ldr r0, =8
    ldr r1, =4
    mul r2, r0, r1
    add r0, r5, r2
    ldr r1, =0
    str r1, [r0]
    add r5, sp, #116
    ldr r0, =9
    ldr r1, =4
    mul r2, r0, r1
    add r0, r5, r2
    ldr r1, =1
    str r1, [r0]
    add r5, sp, #116
    ldr r0, =10
    ldr r1, =4
    mul r2, r0, r1
    add r0, r5, r2
    ldr r1, =9
    str r1, [r0]
    add r5, sp, #116
    ldr r0, =11
    ldr r1, =4
    mul r2, r0, r1
    add r0, r5, r2
    ldr r1, =8
    str r1, [r0]
    add r5, sp, #116
    ldr r0, =12
    ldr r1, =4
    mul r2, r0, r1
    add r0, r5, r2
    ldr r1, =7
    str r1, [r0]
    add r5, sp, #116
    ldr r0, =13
    ldr r1, =4
    mul r2, r0, r1
    add r0, r5, r2
    ldr r1, =6
    str r1, [r0]
    add r5, sp, #116
    ldr r0, =14
    ldr r1, =4
    mul r2, r0, r1
    add r0, r5, r2
    ldr r1, =4
    str r1, [r0]
    add r5, sp, #116
    ldr r0, =15
    ldr r1, =4
    mul r2, r0, r1
    add r0, r5, r2
    ldr r1, =3
    str r1, [r0]
    add r5, sp, #116
    ldr r0, =16
    ldr r1, =4
    mul r2, r0, r1
    add r0, r5, r2
    ldr r1, =2
    str r1, [r0]
    add r5, sp, #116
    ldr r0, =17
    ldr r1, =4
    mul r2, r0, r1
    add r0, r5, r2
    ldr r1, =1
    str r1, [r0]
    add r5, sp, #116
    ldr r0, =18
    ldr r1, =4
    mul r2, r0, r1
    add r0, r5, r2
    ldr r1, =2
    str r1, [r0]
    add r5, sp, #116
    ldr r0, =19
    ldr r1, =4
    mul r2, r0, r1
    add r0, r5, r2
    ldr r1, =2
    str r1, [r0]
    ldr r5, =396
    add r5, sp, r5
    ldr r0, =0
    ldr r2, =4
    mul r1, r0, r2
    add r0, r5, r1
    ldr r1, =0
    str r1, [r0]
    ldr r5, =396
    add r5, sp, r5
    ldr r0, =1
    ldr r1, =4
    mul r2, r0, r1
    add r0, r5, r2
    ldr r1, =0
    str r1, [r0]
    ldr r5, =396
    add r5, sp, r5
    ldr r0, =2
    ldr r1, =4
    mul r6, r0, r1
    add r0, r5, r6
    ldr r1, =0
    str r1, [r0]
    ldr r5, =396
    add r5, sp, r5
    ldr r0, =3
    ldr r6, =4
    mul r1, r0, r6
    add r0, r5, r1
    ldr r1, =0
    str r1, [r0]
    ldr r5, =396
    add r5, sp, r5
    ldr r0, =4
    ldr r2, =4
    mul r1, r0, r2
    add r0, r5, r1
    ldr r1, =0
    str r1, [r0]
    ldr r5, =396
    add r5, sp, r5
    ldr r0, =5
    ldr r1, =4
    mul r2, r0, r1
    add r0, r5, r2
    ldr r1, =0
    str r1, [r0]
    ldr r5, =396
    add r5, sp, r5
    ldr r0, =6
    ldr r2, =4
    mul r1, r0, r2
    add r0, r5, r1
    ldr r1, =0
    str r1, [r0]
    ldr r5, =396
    add r5, sp, r5
    ldr r0, =7
    ldr r1, =4
    mul r2, r0, r1
    add r0, r5, r2
    ldr r1, =0
    str r1, [r0]
    ldr r5, =396
    add r5, sp, r5
    ldr r0, =8
    ldr r1, =4
    mul r2, r0, r1
    add r0, r5, r2
    ldr r1, =0
    str r1, [r0]
    ldr r5, =396
    add r5, sp, r5
    ldr r0, =9
    ldr r2, =4
    mul r1, r0, r2
    add r0, r5, r1
    ldr r1, =0
    str r1, [r0]
    ldr r5, =396
    add r5, sp, r5
    ldr r0, =10
    ldr r2, =4
    mul r1, r0, r2
    add r0, r5, r1
    ldr r1, =0
    str r1, [r0]
    ldr r5, =396
    add r5, sp, r5
    ldr r0, =11
    ldr r1, =4
    mul r2, r0, r1
    add r0, r5, r2
    ldr r1, =0
    str r1, [r0]
    ldr r5, =396
    add r5, sp, r5
    ldr r0, =12
    ldr r1, =4
    mul r2, r0, r1
    add r0, r5, r2
    ldr r1, =0
    str r1, [r0]
    ldr r5, =396
    add r5, sp, r5
    ldr r0, =13
    ldr r1, =4
    mul r2, r0, r1
    add r0, r5, r2
    ldr r1, =0
    str r1, [r0]
    ldr r5, =396
    add r5, sp, r5
    ldr r0, =14
    ldr r6, =4
    mul r1, r0, r6
    add r0, r5, r1
    ldr r1, =0
    str r1, [r0]
    ldr r5, =396
    add r5, sp, r5
    ldr r0, =15
    ldr r1, =4
    mul r2, r0, r1
    add r0, r5, r2
    ldr r1, =0
    str r1, [r0]
    ldr r5, =396
    add r5, sp, r5
    ldr r0, =16
    ldr r1, =4
    mul r2, r0, r1
    add r0, r5, r2
    ldr r1, =0
    str r1, [r0]
    ldr r5, =396
    add r5, sp, r5
    ldr r0, =17
    ldr r1, =4
    mul r2, r0, r1
    add r0, r5, r2
    ldr r1, =0
    str r1, [r0]
    ldr r5, =396
    add r5, sp, r5
    ldr r0, =18
    ldr r2, =4
    mul r1, r0, r2
    add r0, r5, r1
    ldr r1, =0
    str r1, [r0]
    ldr r5, =396
    add r5, sp, r5
    ldr r0, =19
    ldr r2, =4
    mul r1, r0, r2
    add r0, r5, r1
    ldr r1, =0
    str r1, [r0]
    ldr r5, =396
    add r5, sp, r5
    ldr r0, =20
    ldr r2, =4
    mul r1, r0, r2
    add r0, r5, r1
    ldr r1, =0
    str r1, [r0]
    ldr r5, =396
    add r5, sp, r5
    ldr r0, =21
    ldr r2, =4
    mul r1, r0, r2
    add r0, r5, r1
    ldr r1, =0
    str r1, [r0]
    ldr r5, =396
    add r5, sp, r5
    ldr r0, =22
    ldr r2, =4
    mul r1, r0, r2
    add r0, r5, r1
    ldr r1, =0
    str r1, [r0]
    ldr r5, =396
    add r5, sp, r5
    ldr r0, =23
    ldr r1, =4
    mul r2, r0, r1
    add r0, r5, r2
    ldr r1, =0
    str r1, [r0]
    ldr r5, =396
    add r5, sp, r5
    ldr r0, =24
    ldr r1, =4
    mul r6, r0, r1
    add r0, r5, r6
    ldr r1, =0
    str r1, [r0]
    ldr r5, =396
    add r5, sp, r5
    ldr r0, =25
    ldr r1, =4
    mul r2, r0, r1
    add r0, r5, r2
    ldr r1, =0
    str r1, [r0]
    ldr r5, =396
    add r5, sp, r5
    ldr r0, =26
    ldr r2, =4
    mul r1, r0, r2
    add r0, r5, r1
    ldr r1, =0
    str r1, [r0]
    ldr r5, =396
    add r5, sp, r5
    ldr r0, =27
    ldr r2, =4
    mul r1, r0, r2
    add r0, r5, r1
    ldr r1, =0
    str r1, [r0]
    ldr r5, =396
    add r5, sp, r5
    ldr r0, =28
    ldr r1, =4
    mul r2, r0, r1
    add r0, r5, r2
    ldr r1, =0
    str r1, [r0]
    ldr r5, =396
    add r5, sp, r5
    ldr r0, =29
    ldr r2, =4
    mul r1, r0, r2
    add r0, r5, r1
    ldr r1, =0
    str r1, [r0]
    ldr r5, =396
    add r5, sp, r5
    ldr r0, =30
    ldr r6, =4
    mul r1, r0, r6
    add r0, r5, r1
    ldr r1, =0
    str r1, [r0]
    ldr r5, =396
    add r5, sp, r5
    ldr r0, =31
    ldr r1, =4
    mul r2, r0, r1
    add r0, r5, r2
    ldr r1, =0
    str r1, [r0]
    ldr r5, =396
    add r5, sp, r5
    ldr r0, =32
    ldr r2, =4
    mul r1, r0, r2
    add r0, r5, r1
    ldr r1, =0
    str r1, [r0]
    ldr r5, =396
    add r5, sp, r5
    ldr r0, =33
    ldr r1, =4
    mul r2, r0, r1
    add r0, r5, r2
    ldr r1, =0
    str r1, [r0]
    ldr r5, =396
    add r5, sp, r5
    ldr r0, =34
    ldr r1, =4
    mul r2, r0, r1
    add r0, r5, r2
    ldr r1, =0
    str r1, [r0]
    ldr r5, =396
    add r5, sp, r5
    ldr r0, =35
    ldr r1, =4
    mul r2, r0, r1
    add r0, r5, r2
    ldr r1, =0
    str r1, [r0]
    ldr r5, =396
    add r5, sp, r5
    ldr r0, =36
    ldr r1, =4
    mul r2, r0, r1
    add r0, r5, r2
    ldr r1, =0
    str r1, [r0]
    ldr r5, =396
    add r5, sp, r5
    ldr r0, =37
    ldr r2, =4
    mul r1, r0, r2
    add r0, r5, r1
    ldr r1, =0
    str r1, [r0]
    ldr r5, =396
    add r5, sp, r5
    ldr r0, =38
    ldr r1, =4
    mul r2, r0, r1
    add r0, r5, r2
    ldr r1, =0
    str r1, [r0]
    ldr r5, =396
    add r5, sp, r5
    ldr r0, =39
    ldr r1, =4
    mul r2, r0, r1
    add r0, r5, r2
    ldr r1, =0
    str r1, [r0]
    Ldr r2, =0
    b bb0_0
bb0_0:
    b litpool0_0
    .pool
litpool0_0:
    ldr r0, =20
    cmp r2, r0
    ldr r1, =0
    ldrlt r1, =1
    mov r6, r1
    ldr r1, =0
    cmp r6, r1
    ldr r0, =0
    ldrne r0, =1
    ldr r1, =0
    cmp r6, r1
    bne bb0_1
    b bb0_2
bb0_1:
    add r6, sp, #36
    ldr r0, =4
    mul r1, r2, r0
    add r0, r6, r1
    ldr r6, [r0]
    add r7, sp, #196
    ldr r0, =4
    mul r1, r2, r0
    add r0, r7, r1
    str r6, [r0]
    add r0, r2, #1
    Mov r2, r0
    b bb0_0
bb0_2:
    Ldr r5, =0
    b bb0_3
bb0_3:
    ldr r1, =20
    cmp r5, r1
    ldr r0, =0
    ldrlt r0, =1
    mov r6, r0
    ldr r1, =0
    cmp r6, r1
    ldr r0, =0
    ldrne r0, =1
    ldr r1, =0
    cmp r6, r1
    bne bb0_4
    b bb0_5
bb0_4:
    add r6, sp, #116
    ldr r0, =4
    mul r1, r5, r0
    add r0, r6, r1
    ldr r6, [r0]
    ldr r7, =296
    add r7, sp, r7
    ldr r1, =4
    mul r0, r5, r1
    add r1, r7, r0
    str r6, [r1]
    add r0, r5, #1
    Mov r5, r0
    b bb0_3
bb0_5:
    ldr r1, =20
    add r0, r1, #20
    sub r5, r0, #1
    Ldr r2, =0
    b bb0_6
bb0_6:
    b litpool0_1
    .pool
litpool0_1:
    cmp r2, r5
    ldr r0, =0
    ldrle r0, =1
    mov r7, r0
    ldr r1, =0
    cmp r7, r1
    ldr r0, =0
    ldrne r0, =1
    ldr r1, =0
    cmp r7, r1
    bne bb0_7
    b bb0_8
bb0_7:
    ldr r7, =396
    add r7, sp, r7
    ldr r0, =4
    mul r1, r2, r0
    add r0, r7, r1
    ldr r1, =0
    str r1, [r0]
    add r0, r2, #1
    Mov r2, r0
    b bb0_6
bb0_8:
    ldr r0, =20
    sub r1, r0, #1
    Mov r2, r5
    Ldr r3, =0
    Mov r5, r1
    b bb0_9
bb0_9:
    ldr r0, =-1
    cmp r5, r0
    ldr r1, =0
    ldrgt r1, =1
    mov r10, r1
    ldr r1, =0
    cmp r10, r1
    ldr r0, =0
    ldrne r0, =1
    ldr r1, =0
    cmp r10, r1
    bne bb0_10
    b bb0_11
bb0_10:
    ldr r0, =296
    add r0, sp, r0
    ldr r1, =4
    mul r6, r5, r1
    add r1, r0, r6
    ldr r6, [r1]
    ldr r1, =20
    sub r0, r1, #1
    Mov r9, r3
    Mov r7, r2
    Mov r8, r0
    b bb0_12
bb0_11:
    ldr r5, =396
    add r5, sp, r5
    ldr r0, =0
    ldr r2, =4
    mul r1, r0, r2
    add r2, r5, r1
    ldr r0, [r2]
    ldr r2, =0
    cmp r0, r2
    ldr r1, =0
    ldrne r1, =1
    mov r5, r1
    ldr r1, =0
    cmp r5, r1
    ldr r0, =0
    ldrne r0, =1
    ldr r1, =0
    cmp r5, r1
    bne bb0_18
    b bb0_19
bb0_12:
    b litpool0_2
    .pool
litpool0_2:
    ldr r0, =-1
    cmp r8, r0
    ldr r1, =0
    ldrgt r1, =1
    mov r10, r1
    ldr r1, =0
    cmp r10, r1
    ldr r0, =0
    ldrne r0, =1
    ldr r1, =0
    cmp r10, r1
    bne bb0_13
    b bb0_14
bb0_13:
    ldr r0, =396
    add r0, sp, r0
    ldr r2, =4
    mul r1, r7, r2
    add r2, r0, r1
    ldr r10, [r2]
    add r0, sp, #196
    ldr r1, =4
    mul r2, r8, r1
    add r3, r0, r2
    ldr r1, [r3]
    mul r0, r6, r1
    add r9, r10, r0
    ldr r1, =10
    cmp r9, r1
    ldr r0, =0
    ldrge r0, =1
    mov r10, r0
    ldr r1, =0
    cmp r10, r1
    ldr r0, =0
    ldrne r0, =1
    ldr r1, =0
    cmp r10, r1
    bne bb0_15
    b bb0_16
bb0_14:
    add r1, r7, #20
    sub r0, r1, #1
    sub r1, r5, #1
    Mov r3, r9
    Mov r2, r0
    Mov r5, r1
    Mov r9, r8
    b bb0_9
bb0_15:
    ldr r0, =396
    add r0, sp, r0
    ldr r1, =4
    mul r2, r7, r1
    add r1, r0, r2
    str r9, [r1]
    sub r0, r7, #1
    ldr r1, =396
    add r1, sp, r1
    ldr r3, =4
    mul r2, r0, r3
    add r10, r1, r2
    ldr r0, [r10]
    ldr r1, =10
    sdiv r2, r9, r1
    add r10, r0, r2
    sub r0, r7, #1
    ldr r1, =396
    add r1, sp, r1
    ldr r3, =4
    mul r2, r0, r3
    add r0, r1, r2
    str r10, [r0]
    b bb0_17
bb0_16:
    ldr r0, =396
    add r0, sp, r0
    ldr r1, =4
    mul r2, r7, r1
    add r1, r0, r2
    str r9, [r1]
    b bb0_17
bb0_17:
    sub r0, r8, #1
    sub r1, r7, #1
    Mov r7, r1
    Mov r8, r0
    b bb0_12
bb0_18:
    b litpool0_3
    .pool
litpool0_3:
    ldr r5, =396
    add r5, sp, r5
    ldr r0, =0
    ldr r2, =4
    mul r1, r0, r2
    add r2, r5, r1
    ldr r0, [r2]
    STM SP, {r0}
    ldr r0, [sp]
    bl put_int
    LDM sp, {r0}
    b bb0_19
bb0_19:
    Ldr r5, =1
    b bb0_20
bb0_20:
    ldr r0, =20
    add r1, r0, #20
    sub r0, r1, #1
    cmp r5, r0
    ldr r1, =0
    ldrle r1, =1
    mov r6, r1
    ldr r1, =0
    cmp r6, r1
    ldr r0, =0
    ldrne r0, =1
    ldr r1, =0
    cmp r6, r1
    bne bb0_21
    b bb0_22
bb0_21:
    ldr r0, =396
    add r0, sp, r0
    ldr r2, =4
    mul r1, r5, r2
    add r6, r0, r1
    ldr r0, [r6]
    STM SP, {r0}
    ldr r0, [sp]
    bl put_int
    LDM sp, {r0}
    add r0, r5, #1
    Mov r5, r0
    b bb0_20
bb0_22:
    ldr r0, =10
    bl put_char
    STM SP, {r0}
    bl current_time
    sub r1, r0, r4
    STM SP, {r1}
    ldr r0, [sp]
    bl put_int
    LDM sp, {r1}
    b bb0_23
bb0_23:
    ldr r0, =0
    mov sp, r11
    pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    bx lr
    .pool

