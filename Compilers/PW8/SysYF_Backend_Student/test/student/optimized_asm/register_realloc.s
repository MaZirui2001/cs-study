    .arch armv7ve 
    .text 
    .globl func
    .p2align 2
    .type func, %function
func:
    push {r4, r5, r6, r7, r8, r9, r10, r12, lr}
    ldr lr, =256
    sub sp, sp, lr
    Mov r5, r1
    str r1, [sp]
    add r1, r0, r5
    str r1, [sp, #16]
    ldr r2, =1
    add r1, r2, #1
    ldr r3, =2
    add r2, r3, #2
    ldr r4, =3
    add r3, r4, #3
    ldr r6, =4
    add r4, r6, #4
    str r0, [sp]
    add r0, r1, #1
    str r0, [sp, #20]
    add r12, r2, #2
    add r9, r3, #3
    add r10, r4, #4
    ldr r0, [sp, #20]
    add r0, r0, #1
    str r0, [sp, #24]
    add r0, r12, #2
    str r0, [sp, #28]
    add r0, r9, #3
    str r0, [sp, #32]
    add r0, r10, #4
    str r0, [sp, #36]
    ldr r0, [sp, #24]
    add r0, r0, #1
    str r0, [sp, #40]
    ldr r0, [sp, #28]
    add r0, r0, #2
    str r0, [sp, #44]
    ldr r0, [sp, #32]
    add r0, r0, #3
    str r0, [sp, #48]
    ldr r0, [sp, #36]
    add r0, r0, #4
    str r0, [sp, #52]
    ldr r0, [sp, #40]
    add r8, r0, #1
    ldr r0, [sp, #44]
    add r0, r0, #2
    str r0, [sp, #56]
    ldr r0, [sp, #48]
    add r6, r0, #3
    ldr r0, [sp, #52]
    add r0, r0, #4
    str r0, [sp, #60]
    add r0, r8, #1
    str r0, [sp, #64]
    ldr r0, [sp, #56]
    add r0, r0, #2
    str r0, [sp, #68]
    add r0, r6, #3
    str r0, [sp, #72]
    ldr r0, [sp, #60]
    add r7, r0, #4
    ldr r0, [sp, #64]
    add r0, r0, #1
    str r0, [sp, #76]
    ldr r0, [sp, #68]
    add r0, r0, #2
    str r0, [sp, #80]
    ldr r0, [sp, #72]
    add r0, r0, #3
    str r0, [sp, #84]
    add r0, r7, #4
    str r0, [sp, #88]
    ldr r0, [sp, #76]
    add r0, r0, #1
    str r0, [sp, #92]
    ldr r0, [sp, #80]
    add r0, r0, #2
    str r0, [sp, #96]
    ldr r0, [sp, #84]
    add r0, r0, #3
    str r0, [sp, #100]
    ldr r0, [sp, #88]
    add r0, r0, #4
    str r0, [sp, #104]
    ldr r0, [sp]
    str r1, [sp]
    sub r1, r0, r5
    str r1, [sp, #108]
    ldr r1, [sp, #108]
    add r1, r1, #10
    str r1, [sp, #112]
    ldr r1, [sp, #76]
    add r1, r1, #1
    str r1, [sp, #116]
    ldr r1, [sp, #80]
    add r1, r1, #2
    str r1, [sp, #120]
    ldr r1, [sp, #84]
    add r1, r1, #3
    str r1, [sp, #124]
    ldr r1, [sp, #88]
    add r1, r1, #4
    str r1, [sp, #128]
    ldr r1, [sp, #64]
    add r1, r1, #1
    str r1, [sp, #132]
    ldr r1, [sp, #68]
    add r0, r1, #2
    ldr r1, [sp, #72]
    add r1, r1, #3
    str r1, [sp, #136]
    add r1, r7, #4
    str r1, [sp, #140]
    add r7, r8, #1
    ldr r1, [sp, #56]
    add r8, r1, #2
    add r5, r6, #3
    ldr r1, [sp, #60]
    add r6, r1, #4
    ldr r1, [sp, #40]
    add r1, r1, #1
    str r1, [sp, #144]
    ldr r1, [sp, #44]
    add r1, r1, #2
    str r1, [sp, #148]
    ldr r1, [sp, #48]
    add r1, r1, #3
    str r1, [sp, #152]
    ldr r1, [sp, #52]
    add r1, r1, #4
    str r1, [sp, #156]
    ldr r1, [sp, #24]
    add r1, r1, #1
    str r1, [sp, #160]
    ldr r1, [sp, #28]
    add r1, r1, #2
    str r1, [sp, #164]
    ldr r1, [sp, #32]
    add r1, r1, #3
    str r1, [sp, #168]
    ldr r1, [sp, #36]
    add r1, r1, #4
    str r1, [sp, #172]
    ldr r1, [sp, #20]
    add r1, r1, #1
    str r1, [sp, #176]
    add r1, r12, #2
    str r1, [sp, #180]
    add r12, r9, #3
    add r9, r10, #4
    ldr r1, [sp]
    add r10, r1, #1
    str r0, [sp]
    add r0, r2, #2
    str r0, [sp, #184]
    add r1, r3, #3
    add r2, r4, #4
    ldr r4, =1
    add r3, r4, #1
    ldr r0, =2
    str r0, [sp, #236]
    ldr r0, [sp, #236]
    add r4, r0, #2
    ldr r0, =3
    str r0, [sp, #240]
    ldr r0, [sp, #240]
    add r0, r0, #3
    str r0, [sp, #188]
    ldr r0, =4
    str r0, [sp, #244]
    ldr r0, [sp, #244]
    add r0, r0, #4
    str r0, [sp, #192]
    ldr r0, [sp, #116]
    add r0, r0, #1
    str r0, [sp, #196]
    ldr r0, [sp, #120]
    add r0, r0, #2
    str r0, [sp, #200]
    ldr r0, [sp, #124]
    add r0, r0, #3
    str r0, [sp, #204]
    ldr r0, [sp, #128]
    add r0, r0, #4
    str r0, [sp, #208]
    str r1, [sp, #4]
    ldr r0, [sp, #112]
    ldr r1, [sp, #196]
    add r0, r0, r1
    str r0, [sp, #212]
    ldr r1, [sp, #200]
    ldr r0, [sp, #212]
    add r0, r0, r1
    str r0, [sp, #216]
    ldr r1, [sp, #204]
    ldr r0, [sp, #216]
    add r0, r0, r1
    str r0, [sp, #220]
    ldr r1, [sp, #208]
    ldr r0, [sp, #220]
    add r0, r0, r1
    str r0, [sp, #224]
    ldr r0, [sp, #224]
    sub r0, r0, r3
    str r0, [sp, #228]
    ldr r0, [sp, #228]
    sub r3, r0, r4
    ldr r0, [sp, #188]
    sub r0, r3, r0
    str r0, [sp, #232]
    ldr r1, [sp, #192]
    ldr r0, [sp, #232]
    sub r4, r0, r1
    add r3, r4, r10
    ldr r0, [sp, #184]
    add r4, r3, r0
    ldr r1, [sp, #4]
    add r3, r4, r1
    add r4, r3, r2
    ldr r0, [sp, #176]
    sub r1, r4, r0
    ldr r0, [sp, #180]
    sub r2, r1, r0
    sub r1, r2, r12
    sub r2, r1, r9
    ldr r0, [sp, #160]
    add r1, r2, r0
    ldr r0, [sp, #164]
    add r2, r1, r0
    ldr r0, [sp, #168]
    add r1, r2, r0
    ldr r0, [sp, #172]
    add r2, r1, r0
    ldr r0, [sp, #144]
    sub r1, r2, r0
    ldr r0, [sp, #148]
    sub r2, r1, r0
    ldr r0, [sp, #152]
    sub r1, r2, r0
    ldr r0, [sp, #156]
    sub r2, r1, r0
    add r1, r2, r7
    add r2, r1, r8
    add r1, r2, r5
    add r3, r1, r6
    ldr r0, [sp, #132]
    sub r2, r3, r0
    ldr r0, [sp]
    sub r1, r2, r0
    str r2, [sp]
    ldr r2, [sp, #136]
    sub r0, r1, r2
    ldr r2, [sp, #140]
    sub r1, r0, r2
    ldr r2, [sp, #116]
    add r0, r1, r2
    str r1, [sp]
    ldr r1, [sp, #120]
    add r2, r0, r1
    str r0, [sp]
    ldr r0, [sp, #124]
    add r1, r2, r0
    str r2, [sp]
    ldr r2, [sp, #128]
    add r0, r1, r2
    ldr r2, [sp]
    b bb0_0
bb0_0:
    ldr lr, =256
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
    ldr r6, =1
    add r5, r6, #18
    bl current_time
    mov r6, r0
    ldr r0, =10
    bl put_char
    sub r7, r6, r4
    mov r0, r7
    bl put_int
    ldr r0, =1
    mov r1, r5
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

