    .arch armv7ve 
    .text 
    .globl func
    .p2align 2
    .type func, %function
func:
    push {r4, r5, r6, r7, r8, r9, r10, r12, lr}
    ldr lr, =224
    sub sp, sp, lr
    str r0, [sp, #216]
    str r1, [sp, #220]
    str r0, [sp]
    str r1, [sp, #4]
    ldr r0, [sp, #216]
    ldr r1, [sp, #220]
    add r0, r0, r1
    str r0, [sp, #24]
    ldr r7, =1
    add r0, r7, #1
    str r0, [sp, #28]
    ldr r7, =2
    add r0, r7, #2
    str r0, [sp, #32]
    ldr r7, =3
    add r0, r7, #3
    str r0, [sp, #36]
    ldr r7, =4
    add r0, r7, #4
    str r0, [sp, #40]
    ldr r0, [sp, #28]
    add r0, r0, #1
    str r0, [sp, #44]
    ldr r0, [sp, #32]
    add r0, r0, #2
    str r0, [sp, #48]
    ldr r0, [sp, #36]
    add r0, r0, #3
    str r0, [sp, #52]
    ldr r0, [sp, #40]
    add r0, r0, #4
    str r0, [sp, #56]
    ldr r0, [sp, #44]
    add r0, r0, #1
    str r0, [sp, #60]
    ldr r0, [sp, #48]
    add r0, r0, #2
    str r0, [sp, #64]
    ldr r0, [sp, #52]
    add r0, r0, #3
    str r0, [sp, #68]
    ldr r0, [sp, #56]
    add r0, r0, #4
    str r0, [sp, #72]
    ldr r0, [sp, #60]
    add r0, r0, #1
    str r0, [sp, #76]
    ldr r0, [sp, #64]
    add r0, r0, #2
    str r0, [sp, #80]
    ldr r0, [sp, #68]
    add r0, r0, #3
    str r0, [sp, #84]
    ldr r0, [sp, #72]
    add r0, r0, #4
    str r0, [sp, #88]
    ldr r0, [sp, #76]
    add r1, r0, #1
    ldr r0, [sp, #80]
    add r7, r0, #2
    ldr r0, [sp, #84]
    add r9, r0, #3
    ldr r0, [sp, #88]
    add r0, r0, #4
    str r0, [sp, #92]
    add r6, r1, #1
    add r12, r7, #2
    add r4, r9, #3
    ldr r0, [sp, #92]
    add r5, r0, #4
    add r2, r6, #1
    add r3, r12, #2
    add r0, r4, #3
    add r10, r5, #4
    str r0, [sp]
    add r0, r2, #1
    str r0, [sp, #96]
    add r0, r3, #2
    str r0, [sp, #100]
    ldr r0, [sp]
    str r1, [sp]
    add r1, r0, #3
    str r1, [sp, #104]
    add r1, r10, #4
    str r1, [sp, #108]
    str r0, [sp, #4]
    ldr r1, [sp, #216]
    ldr r0, [sp, #220]
    sub r8, r1, r0
    add r0, r8, #10
    str r0, [sp, #112]
    add r0, r2, #1
    str r0, [sp, #116]
    add r0, r3, #2
    str r0, [sp, #120]
    ldr r0, [sp, #4]
    add r1, r0, #3
    str r1, [sp, #124]
    add r1, r10, #4
    str r1, [sp, #128]
    add r1, r6, #1
    str r1, [sp, #132]
    add r1, r12, #2
    str r1, [sp, #136]
    add r1, r4, #3
    str r1, [sp, #140]
    add r1, r5, #4
    str r1, [sp, #144]
    ldr r1, [sp]
    str r0, [sp]
    add r0, r1, #1
    str r0, [sp, #148]
    add r0, r7, #2
    str r0, [sp, #152]
    add r0, r9, #3
    str r0, [sp, #156]
    ldr r0, [sp, #92]
    add r0, r0, #4
    str r0, [sp, #160]
    ldr r0, [sp, #76]
    add r0, r0, #1
    str r0, [sp, #164]
    ldr r0, [sp, #80]
    add r0, r0, #2
    str r0, [sp, #168]
    ldr r0, [sp, #84]
    add r0, r0, #3
    str r0, [sp, #172]
    ldr r0, [sp, #88]
    add r0, r0, #4
    str r0, [sp, #176]
    ldr r0, [sp, #60]
    add r0, r0, #1
    str r0, [sp, #180]
    ldr r0, [sp, #64]
    add r0, r0, #2
    str r0, [sp, #184]
    ldr r0, [sp, #68]
    add r0, r0, #3
    str r0, [sp, #188]
    ldr r0, [sp, #72]
    add r0, r0, #4
    str r0, [sp, #192]
    ldr r0, [sp, #44]
    add r0, r0, #1
    str r0, [sp, #196]
    ldr r0, [sp, #48]
    add r0, r0, #2
    str r0, [sp, #200]
    ldr r0, [sp, #52]
    add r0, r0, #3
    str r0, [sp, #204]
    ldr r0, [sp, #56]
    add r0, r0, #4
    str r0, [sp, #208]
    ldr r0, [sp, #28]
    add r3, r0, #1
    ldr r0, [sp, #32]
    add r2, r0, #2
    ldr r0, [sp, #36]
    add r8, r0, #3
    ldr r0, [sp, #40]
    add r0, r0, #4
    str r0, [sp, #212]
    ldr r4, =1
    add r12, r4, #1
    ldr r4, =2
    add r6, r4, #2
    ldr r4, =3
    add r10, r4, #3
    ldr r4, =4
    add r9, r4, #4
    ldr r0, [sp, #116]
    add r4, r0, #1
    ldr r0, [sp, #120]
    add r7, r0, #2
    ldr r0, [sp, #124]
    add r5, r0, #3
    ldr r0, [sp, #128]
    add r1, r0, #4
    str r1, [sp]
    ldr r1, [sp, #112]
    add r0, r1, r4
    add r4, r0, r7
    add r7, r4, r5
    ldr r1, [sp]
    add r4, r7, r1
    sub r5, r4, r12
    sub r4, r5, r6
    sub r5, r4, r10
    sub r4, r5, r9
    add r5, r4, r3
    add r4, r5, r2
    add r5, r4, r8
    str r0, [sp]
    ldr r0, [sp, #212]
    add r4, r5, r0
    ldr r0, [sp, #196]
    sub r5, r4, r0
    ldr r0, [sp, #200]
    sub r4, r5, r0
    ldr r0, [sp, #204]
    sub r5, r4, r0
    ldr r0, [sp, #208]
    sub r4, r5, r0
    ldr r0, [sp, #180]
    add r5, r4, r0
    ldr r0, [sp, #184]
    add r4, r5, r0
    ldr r0, [sp, #188]
    add r5, r4, r0
    ldr r0, [sp, #192]
    add r4, r5, r0
    ldr r0, [sp, #164]
    sub r5, r4, r0
    ldr r0, [sp, #168]
    sub r4, r5, r0
    ldr r0, [sp, #172]
    sub r5, r4, r0
    ldr r0, [sp, #176]
    sub r4, r5, r0
    ldr r0, [sp, #148]
    add r5, r4, r0
    ldr r0, [sp, #152]
    add r4, r5, r0
    ldr r0, [sp, #156]
    add r5, r4, r0
    ldr r0, [sp, #160]
    add r4, r5, r0
    ldr r0, [sp, #132]
    sub r5, r4, r0
    ldr r0, [sp, #136]
    sub r4, r5, r0
    ldr r0, [sp, #140]
    sub r5, r4, r0
    ldr r0, [sp, #144]
    sub r4, r5, r0
    ldr r0, [sp, #116]
    add r5, r4, r0
    ldr r0, [sp, #120]
    add r4, r5, r0
    ldr r0, [sp, #124]
    add r5, r4, r0
    ldr r0, [sp, #128]
    add r4, r5, r0
    ldr r0, [sp]
    b bb0_0
bb0_0:
    mov r0, r4
    ldr lr, =224
    add sp, sp, lr
    pop {r4, r5, r6, r7, r8, r9, r10, r12, lr}
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
    ldr r5, =1
    add r6, r5, #18
    bl current_time
    mov r5, r0
    ldr r0, =10
    bl put_char
    sub r7, r5, r4
    mov r0, r7
    bl put_int
    ldr r0, =1
    mov r1, r6
    bl func
    mov r4, r0
    b bb1_0
bb1_0:
    b litpool1_0
    .pool
litpool1_0:
    mov r0, r4
    mov sp, r11
    pop {r4, r5, r6, r7, r11, lr}
    bx lr
    .pool

