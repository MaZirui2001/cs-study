# Lab 1 Report

## 实验内容

* 使用C语言和ARM汇编语言完成字符串排序：从键盘输入至少5个字符串，每个字符串的长度不小于10；经过排序之后，从小到大输出排序的结果。

## 实验代码解读

### 输入输出

```c++
#include <stdio.h>
#include <stdlib.h>
extern void string_sort(char* str[], int n);
int main(){
    char *str[100] = {NULL};
    int n;
    int i;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        str[i] = (char*)malloc(100 * sizeof(char));
        scanf("%s", str[i]);
    }
    string_sort(str, n);
    for(i = 0; i < n; i++){
        printf("%s\n", str[i]);
    }
    for(i = 0; i < n; i++){
        free(str[i]);
    }
    return 0;
}
```

这里我们使用了字符指针数组和动态内存分配来保存需要排序的字符串。每个字符串长度至多为99，最多容纳100个字符串，这符合实验的要求。

输入输出是一个较为基本的模块，在这里不赘述了。但我在输入输出时遇到了一些问题，详情请见“问题以及解决方案”。

### 字符串比较strcmp

字符串排序自然依赖字符串的比较函数。我们先使用C语言描述：

```c++
int strcmp(char* str1, char* str2){
    int i = 0;
    for(; str1[i] && str2[i]; i++){
        if(str1[i] < str2[i]) return -1;
        else if(str1[i] > str2[i]) return 1;
    }
    if(str1[i]) return 1;
    else if(str2[i]) return -1;
    return 0;
}
```

之后我们将其翻译为ARM汇编语言：

```assembly
; int strcmp(char* str1, char* str2)
    EXPORT strcmp
    AREA STRCMP, CODE, READONLY
strcmp 
    STMFD sp!, {r2-r7}      ; save regs
    mov v1, #0              ; i = 0
loop 
    ldrb v2, [a1, v1]       ; v2 = str1[i]
    ldrb v3, [a2, v1]       ; v3 = str2[i]
    cmp v2, #0              ; 
    beq compare             ; if(str1[i] == 0) go to compare 
    cmp v3, #0              ; compare str2[i] with 0
    beq compare             ; if(str2[i] == 0) go to compare

    cmp v2, v3              ; compare str1[i] with str2[i]
    blt return_minus1       ; if(str1[i] < str2[i]) go to return -1
    bgt return_1            ; if(str1[i] > str2[i]) go to return 1
    add v1, v1, #1          ; i++
    b loop                  ; go to loop

compare 
    cmp v2, #0              ; compare str1[i] with 0
    bne return_1            ; if(str1[i] != 0) str1 is bigger than str2, return 1
    cmp v3, #0              ; compare str2[i] with 0
    bne return_minus1       ; if(str2[i] != 0) str2 is bigger than str1, return -1

return_0 
    mov a1, #0              
    LDMFD sp!, {r2-r7}      ; restore regs 
    mov PC, LR              ; return 0

return_minus1 
    mov a1, #-1
    LDMFD sp!, {r2-r7}      ; restore regs
    mov PC, LR              ; return -1

return_1 
    mov a1, #1
    LDMFD sp!, {r2-r7}      ; restore regs
    mov PC, LR              ; return 1

    END
```

strcmp函数有两个参数：char *str1和char *str2，我们**使用a1寄存器来传递char *str1参数，用a2寄存器来传递char *str2参数。**再使用v1去保存迭代变量i的值，用v2，v3对两个字符串同一位置进行一一比较。

在比较的过程中，如果发现某位置值不相同，则直接对其进行比较，并进入return部分，**用a1寄存器来返回结果**。如果在一个字符串结束前都没有找到区别，那么就进入compare部分，来看哪个字符串更长，方法就是看当前i所指的位置哪一个字符串的字符不为0。如果两个串都为0，那么证明这两个字符串相等，用a1返回0即可。

**在函数进入时，我们使用STMFD指令保存寄存器，退出函数时，我们使用LDMFD恢复寄存器**。我们在整个程序中**保存了r2-r7的值**，并利用这几个寄存器来执行函数的运算，并**使用mov PC, LR来实现return的功能**。

### 字符串排序

本次排序我选择了冒泡排序，它实现起来简单且性能稳定。

我们依然先写出排序的C语言描述：

```c++
void string_sort(char *str[], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            int result = strcmp(str[j], str[j+1]);
            if(result == 1){
                char* tmp = str[j];
                str[j] = str[j+1];
                str[j+1] = tmp;
            }
        }
    }
}
```

之后，我们将其改写为ARM汇编语言：

```assembly
;void string_sort(char *str[], int n)
    EXPORT string_sort
    IMPORT strcmp
    AREA STRINGSORT, CODE, READONLY
string_sort
    STMFD sp!, {r2-r7, LR}
    sub sp, sp, #8          ; sp + 4: i, sp + 8: j
    mov v1, #0              ; v1 = 0
    str v1, [sp, #4]        ; i = 0

loop1
    ldr v1, [sp, #4]        ; ld i to v1
    cmp v1, a2              ; compare i with n
    bge return              ; for(i = 0; i < n; i++)

    mov v2, #0              ; v2 = 0
    str v2, [sp, #8]        ; j = 0

loop2
    ldr v1, [sp, #4]        ; v1 = i
    ldr v2, [sp, #8]        ; v2 = j
    sub v3, a2, v1          ; v3 = n - i
    sub v3, v3, #1          ; v3 = n - i - 1 

    cmp v2, v3              ; compare j with n - i - 1
    bge loop1_end           ; for(j = 0; j < n - i - 1; j++)

    STMFD sp!, {a1-a2}      ; save str, n
    add v4, a1, v2, LSL#2   ; v4 = str + j
    ldmia v4, {a1, a2}      ; a1 = str[j], a2 = str[j+1]
    bl strcmp               ; a1 = strcmp(str[j], str[j+1])
    mov v1, a1              ; v1 = result
    LDMFD sp!, {a1-a2}      ; restore str, n

    cmp v1, #1              ; if result < 1
    blt skip_swap           ; skip swap

    ldr v1, [v4, #4]        ; v1 = str[j+1]
    swp v1, v1, [v4]        ; str[j] = str[j+1]
    str v1, [v4, #4]        ; st str[j+1]

skip_swap
    ldr v2, [sp, #8]        ; ld j to v2
    add v2, v2, #1          ; j++
    str v2, [sp, #8]        ; st j to mem
    b loop2

loop1_end
    ldr v1, [sp, #4]        ; ld i to v1
    add v1, v1, #1          ; i++
    str v1, [sp, #4]        ; st i to mem
    b loop1             

return
    add sp, sp, #8          ; pop stack
    LDMFD sp!, {r2-r7, LR}  ; restore regs
    mov PC, LR              ; return 
    
    END
```

我们来仔细解读这个函数：

* 这个函数有两个参数：字符串数组char *str[]和字符串数组长度n，**我们用a1来传递前者，用a2来传递后者**

* 进入函数，我们依然适用STMFD来保存寄存器。之后，我们分配了8个字节的栈空间，用以存储两个4字节的迭代变量i，j。
* 在外层循环loop1前，我们将0存入i的地址，并**用v1将其加载出来**。之后我们用i的值和a2中存储的n来进行比较。如果i >= n，程序就直接返回。
* 如果i < n，则进入外层循环loop1，我们首先要将j置零，并**用v2来暂时保存j的值**。之后，我们**利用v3来保存n-i-1**的值，这个值我们不需要存储到栈里，因为它每次都需要重新计算。再用j和n-i-1进行比较，如果j >= n - i - 1，那么内层循环loop2结束，跳入skip_swap段，对i执行自增操作，并进行下一轮的外层循环。
* 如果j < n - i - 1，则执行内层循环loop2的执行语句。我们之前已经**用v1和v2暂存内存中i和j的值**，下面需要对两个字符串指针指向的字符串进行比较，而它们已经被存储在了内存中。我们先用STMFD来保存a1，a2的值，并**利用add指令锁定需要比较的两个字符串的地址，存入v4（v4+4即为j+1处地址）**，**利用ldmia指令连续加载出str[j]和str[j+1]并保存到a1和a2中**，之后调用strcmp函数进行比较。
* **strcmp的返回值被保存在a1中返回，我们先用v1保存住返回值**，并用LDMFD来恢复a1， a2中的值。之后我们对v1中的返回值进行判断，如果小于1（也就是-1或0），那么跳过交换阶段直接执行j自增的语句。
* 如果返回值是1，也就是需要进行交换，那我们只需要将指针数组中指针的的值交换一下就可以了，因为我们使用的是动态内存分配，没有必要把整个字符串进行移动。这里**用v1保存了str[j+1]，然后用swp指令实现str[j]存入str + j + 1地址的操作，最后将str[j+1]的值存入str + j这个地址就完成了交换。**
* 当外层循环loop1结束后，就进入了return部分。这个部分首先释放i和j的栈空间，之后用LDMFD回复寄存器，最后返回原函数

## 程序运行结果

![image-20221106192657305](C:\Users\MAdrid\AppData\Roaming\Typora\typora-user-images\image-20221106192657305.png)

这里的五个输入数据不仅包括了常规字符串，还包括了一个字符串是另一个字符串子串的情况，目的在于全面展示strcmp的正确性。

## 问题以及解决方案

1. C语言声明问题

   可能好久都没有接触过这种传统的编译器了，一直编译失败让我不知所措！最后苦思许久，发现原来这个编译器只能支持所有声明在前的C语言！一个for(int i = 0;......)都会出错！无奈只好把所有的声明放在了前面

2. 函数调用的压栈问题

   之前在string_sort函数中调用strcmp时，没有先保存寄存器状态再跳转，导致回main函数的地址丢失，程序陷入了死循环。后来经过改动，解决了这个问题。

## 实验总结

在本次实验中，我熟悉了ARM汇编语言，并掌握了ADS编程的方法。我体会到ARM指令集的很多神奇之处，比如可以顺序取好多个数出来，也很好奇ARM处理器的设计方法。希望后面有机会能够真正的接触一款ARM处理器，进行更深层次的学习！