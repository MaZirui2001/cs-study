    .arch armv7ve 
    .text 
    .globl testParam8
    .p2align 2
    .type testParam8, %function
testParam8:
    push {r4, r5, r6, r7, r8, r9, r10, lr}
    sub sp, sp, #24
    STMDB SP, {r0}
    Ldr r4, [sp, #-4]
    Mov r5, r1
    Mov r6, r2
    Mov r7, r3
    ldr r8, [sp, #56]
    ldr r9, [sp, #60]
    ldr r10, [sp, #64]
    ldr r0, [sp, #68]
    add r1, r4, r5
    sub r4, r1, r6
    sub r5, r4, r7
    sub r4, r5, r8
    add r5, r4, r9
    add r4, r5, r10
    add r5, r4, r0
    b bb0_0
bb0_0:
    mov r0, r5
    add sp, sp, #24
    pop {r4, r5, r6, r7, r8, r9, r10, lr}
    bx lr
    .pool

    .globl testParam16
    .p2align 2
    .type testParam16, %function
testParam16:
    push {r4, r5, r6, r7, r8, r9, r10, r12, lr}
    sub sp, sp, #52
    STMDB SP, {r0, r1, r2, r3}
    Ldr r4, [sp, #-16]
    Ldr r5, [sp, #-12]
    Ldr r1, [sp, #-8]
    Ldr r2, [sp, #-4]
    ldr r3, [sp, #88]
    ldr r12, [sp, #92]
    ldr r0, [sp, #96]
    ldr r10, [sp, #100]
    ldr r9, [sp, #104]
    ldr r8, [sp, #108]
    ldr r6, [sp, #112]
    add r7, r4, r5
    add r4, r7, r1
    add r5, r4, r2
    add r4, r5, r3
    add r5, r4, r12
    add r4, r5, r0
    add r5, r4, r10
    sub r4, r5, r9
    add r5, r4, r8
    add r4, r5, r6
    str r0, [sp]
    ldr r0, [sp, #116]
    add r5, r4, r0
    ldr r0, [sp, #120]
    add r4, r5, r0
    ldr r0, [sp, #124]
    add r5, r4, r0
    ldr r0, [sp, #128]
    add r4, r5, r0
    ldr r0, [sp, #132]
    add r5, r4, r0
    ldr r0, [sp]
    b bb1_0
bb1_0:
    mov r0, r5
    add sp, sp, #52
    pop {r4, r5, r6, r7, r8, r9, r10, r12, lr}
    bx lr
    .pool

    .globl testParam32
    .p2align 2
    .type testParam32, %function
testParam32:
    push {r4, r5, r6, r7, r8, r9, r10, r12, lr}
    sub sp, sp, #116
    STMDB SP, {r0, r1, r2}
    Ldr r4, [sp, #-12]
    Ldr r5, [sp, #-8]
    Ldr r12, [sp, #-4]
    ldr r2, [sp, #152]
    ldr r1, [sp, #156]
    ldr r0, [sp, #160]
    ldr r10, [sp, #164]
    ldr r9, [sp, #168]
    ldr r8, [sp, #172]
    ldr r6, [sp, #176]
    add r7, r4, r5
    add r4, r7, r12
    add r5, r4, r3
    add r4, r5, r2
    add r5, r4, r1
    add r4, r5, r0
    add r5, r4, r10
    add r4, r5, r9
    add r5, r4, r8
    add r4, r5, r6
    str r0, [sp]
    ldr r0, [sp, #180]
    add r5, r4, r0
    ldr r0, [sp, #184]
    sub r4, r5, r0
    ldr r0, [sp, #188]
    sub r5, r4, r0
    ldr r0, [sp, #192]
    sub r4, r5, r0
    ldr r0, [sp, #196]
    sub r5, r4, r0
    ldr r0, [sp, #200]
    sub r4, r5, r0
    ldr r0, [sp, #204]
    sub r5, r4, r0
    ldr r0, [sp, #208]
    sub r4, r5, r0
    ldr r0, [sp, #212]
    sub r5, r4, r0
    ldr r0, [sp, #216]
    sub r4, r5, r0
    ldr r0, [sp, #220]
    sub r5, r4, r0
    ldr r0, [sp, #224]
    add r4, r5, r0
    ldr r0, [sp, #228]
    add r5, r4, r0
    ldr r0, [sp, #232]
    add r4, r5, r0
    ldr r0, [sp, #236]
    add r5, r4, r0
    ldr r0, [sp, #240]
    add r4, r5, r0
    ldr r0, [sp, #244]
    add r5, r4, r0
    ldr r0, [sp, #248]
    add r4, r5, r0
    ldr r0, [sp, #252]
    add r5, r4, r0
    ldr r0, [sp, #256]
    add r4, r5, r0
    ldr r0, [sp, #260]
    add r5, r4, r0
    ldr r0, [sp]
    b bb2_0
bb2_0:
    mov r0, r5
    add sp, sp, #116
    pop {r4, r5, r6, r7, r8, r9, r10, r12, lr}
    bx lr
    .pool

    .globl main
    .p2align 2
    .type main, %function
main:
    push {r4, r5, r6, r11, lr}
    mov r11, sp
    sub sp, sp, #4
    bl current_time
    mov r4, r0
    ldr r12 ,=7
    push {r12}
    ldr r12 ,=6
    push {r12}
    ldr r12 ,=5
    push {r12}
    ldr r12 ,=4
    push {r12}
    ldr r0, =0
    ldr r1, =1
    ldr r2, =2
    ldr r3, =3
    bl testParam8
    ADD sp, sp, #16
    mov r5, r0
    mov r0, r5
    bl put_int
    ldr r12 ,=5
    push {r12}
    ldr r12 ,=4
    push {r12}
    ldr r12 ,=3
    push {r12}
    ldr r12 ,=2
    push {r12}
    ldr r12 ,=1
    push {r12}
    ldr r12 ,=0
    push {r12}
    ldr r12 ,=9
    push {r12}
    ldr r12 ,=8
    push {r12}
    ldr r12 ,=7
    push {r12}
    ldr r12 ,=6
    push {r12}
    ldr r12 ,=5
    push {r12}
    ldr r12 ,=4
    push {r12}
    mov r0, r5
    ldr r1, =1
    ldr r2, =2
    ldr r3, =3
    bl testParam16
    ADD sp, sp, #48
    mov r6, r0
    mov r0, r6
    bl put_int
    ldr r12 ,=1
    push {r12}
    ldr r12 ,=0
    push {r12}
    ldr r12 ,=9
    push {r12}
    ldr r12 ,=8
    push {r12}
    ldr r12 ,=7
    push {r12}
    ldr r12 ,=6
    push {r12}
    ldr r12 ,=5
    push {r12}
    ldr r12 ,=4
    push {r12}
    ldr r12 ,=3
    push {r12}
    ldr r12 ,=2
    push {r12}
    ldr r12 ,=1
    push {r12}
    ldr r12 ,=0
    push {r12}
    ldr r12 ,=9
    push {r12}
    ldr r12 ,=8
    push {r12}
    ldr r12 ,=7
    push {r12}
    ldr r12 ,=6
    push {r12}
    ldr r12 ,=5
    push {r12}
    ldr r12 ,=4
    push {r12}
    ldr r12 ,=3
    push {r12}
    ldr r12 ,=2
    push {r12}
    ldr r12 ,=1
    push {r12}
    ldr r12 ,=0
    push {r12}
    ldr r12 ,=9
    push {r12}
    ldr r12 ,=8
    push {r12}
    ldr r12 ,=7
    push {r12}
    ldr r12 ,=6
    push {r12}
    ldr r12 ,=5
    push {r12}
    ldr r12 ,=4
    push {r12}
    mov r0, r6
    ldr r1, =1
    ldr r2, =2
    ldr r3, =3
    bl testParam32
    ADD sp, sp, #112
    mov r5, r0
    mov r0, r5
    bl put_int
    ldr r0, =10
    bl put_char
    bl current_time
    mov r5, r0
    sub r6, r5, r4
    mov r0, r6
    bl put_int
    b bb3_0
bb3_0:
    ldr r0, =0
    mov sp, r11
    pop {r4, r5, r6, r11, lr}
    bx lr
    .pool

