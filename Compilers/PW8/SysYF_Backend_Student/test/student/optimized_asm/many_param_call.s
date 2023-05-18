    .arch armv7ve 
    .text 
    .globl testParam8
    .p2align 2
    .type testParam8, %function
testParam8:
    push {r4, r5, r6, r7, r8, r9, r10, lr}
    sub sp, sp, #24
    Mov r10, r0
    Mov r9, r2
    Mov r8, r3
    ldr r7, [sp, #56]
    ldr r6, [sp, #60]
    ldr r5, [sp, #64]
    ldr r4, [sp, #68]
    add r0, r10, r1
    sub r1, r0, r9
    sub r0, r1, r8
    sub r8, r0, r7
    add r7, r8, r6
    add r6, r7, r5
    add r5, r6, r4
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
    STMDB SP, {r0, r1, r2}
    Ldr r5, [sp, #-12]
    Ldr r2, [sp, #-8]
    Ldr r4, [sp, #-4]
    Mov r0, r3
    ldr r8, [sp, #92]
    ldr r10, [sp, #96]
    ldr r1, [sp, #100]
    ldr r9, [sp, #104]
    ldr r12, [sp, #116]
    ldr r6, [sp, #124]
    ldr r7, [sp, #132]
    add r3, r5, r2
    add r5, r3, r4
    add r4, r5, r0
    str r1, [sp]
    ldr r1, [sp, #88]
    add r0, r4, r1
    add r2, r0, r8
    add r0, r2, r10
    ldr r1, [sp]
    add r2, r0, r1
    sub r1, r2, r9
    str r2, [sp]
    ldr r2, [sp, #108]
    add r0, r1, r2
    ldr r2, [sp, #112]
    add r1, r0, r2
    add r0, r1, r12
    ldr r2, [sp, #120]
    add r1, r0, r2
    add r0, r1, r6
    ldr r2, [sp, #128]
    add r1, r0, r2
    add r0, r1, r7
    ldr r2, [sp]
    b bb1_0
bb1_0:
    add sp, sp, #52
    pop {r4, r5, r6, r7, r8, r9, r10, r12, lr}
    bx lr
    .pool

    .globl testParam32
    .p2align 2
    .type testParam32, %function
testParam32:
    push {r4, r5, r6, r7, r8, r9, r10, r12, lr}
    ldr lr, =144
    sub sp, sp, lr
    STMDB SP, {r0, r1, r2, r3}
    str r0, [sp, #128]
    str r1, [sp, #132]
    str r2, [sp, #136]
    str r3, [sp, #140]
    ldr r12, [sp, #196]
    ldr r10, [sp, #200]
    ldr r9, [sp, #204]
    ldr r8, [sp, #208]
    ldr r7, [sp, #212]
    ldr r6, [sp, #216]
    ldr r5, [sp, #220]
    ldr r4, [sp, #224]
    ldr r3, [sp, #228]
    ldr r2, [sp, #232]
    ldr r1, [sp, #236]
    ldr r0, [sp, #240]
    str r0, [sp]
    str r1, [sp, #4]
    ldr r0, [sp, #128]
    ldr r1, [sp, #132]
    add r0, r0, r1
    str r0, [sp, #96]
    ldr r1, [sp, #136]
    ldr r0, [sp, #96]
    add r0, r0, r1
    str r0, [sp, #100]
    ldr r1, [sp, #140]
    ldr r0, [sp, #100]
    add r0, r0, r1
    str r0, [sp, #104]
    ldr r1, [sp, #180]
    ldr r0, [sp, #104]
    add r0, r0, r1
    str r0, [sp, #108]
    ldr r1, [sp, #184]
    ldr r0, [sp, #108]
    add r0, r0, r1
    str r0, [sp, #112]
    ldr r1, [sp, #188]
    ldr r0, [sp, #112]
    add r0, r0, r1
    str r0, [sp, #116]
    ldr r1, [sp, #192]
    ldr r0, [sp, #116]
    add r0, r0, r1
    str r0, [sp, #120]
    ldr r0, [sp, #120]
    add r0, r0, r12
    str r0, [sp, #124]
    ldr r0, [sp, #124]
    add r12, r0, r10
    add r10, r12, r9
    add r9, r10, r8
    sub r8, r9, r7
    sub r7, r8, r6
    sub r6, r7, r5
    sub r5, r6, r4
    sub r4, r5, r3
    sub r3, r4, r2
    ldr r1, [sp, #4]
    sub r2, r3, r1
    ldr r0, [sp]
    sub r3, r2, r0
    str r0, [sp]
    ldr r0, [sp, #244]
    sub r1, r3, r0
    str r2, [sp]
    ldr r2, [sp, #248]
    sub r0, r1, r2
    ldr r2, [sp, #252]
    add r1, r0, r2
    str r0, [sp]
    ldr r0, [sp, #256]
    add r2, r1, r0
    str r1, [sp]
    ldr r1, [sp, #260]
    add r0, r2, r1
    str r2, [sp]
    ldr r2, [sp, #264]
    add r1, r0, r2
    ldr r2, [sp, #268]
    add r0, r1, r2
    ldr r2, [sp, #272]
    add r1, r0, r2
    ldr r2, [sp, #276]
    add r0, r1, r2
    str r1, [sp]
    ldr r1, [sp, #280]
    add r2, r0, r1
    str r0, [sp]
    ldr r0, [sp, #284]
    add r1, r2, r0
    str r2, [sp]
    ldr r2, [sp, #288]
    add r0, r1, r2
    ldr r2, [sp]
    b bb2_0
bb2_0:
    ldr lr, =144
    add sp, sp, lr
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
    mov r6, r0
    mov r0, r6
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
    mov r0, r6
    ldr r1, =1
    ldr r2, =2
    ldr r3, =3
    bl testParam16
    ADD sp, sp, #48
    mov r5, r0
    mov r0, r5
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
    mov r0, r5
    ldr r1, =1
    ldr r2, =2
    ldr r3, =3
    bl testParam32
    ADD sp, sp, #112
    mov r6, r0
    mov r0, r6
    bl put_int
    ldr r0, =10
    bl put_char
    bl current_time
    mov r6, r0
    sub r5, r6, r4
    mov r0, r5
    bl put_int
    b bb3_0
bb3_0:
    ldr r0, =0
    mov sp, r11
    pop {r4, r5, r6, r11, lr}
    bx lr
    .pool

