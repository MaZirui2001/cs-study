# HW 15-1

## 机器参数

* 机器配置：Lenovo ThinkPad X1 Carbon Gen 9，处理器11th Gen Intel® Core™ i7-1165G7 × 8
* 操作系统：Ubuntu22.10
* 编译器：gcc/g++ 12.2.0
* 编译选项：第一题中优化版使用了-O2，其他无特别选项

## test说明

test中一共有三个代码文件：

* bubblesort.cpp：第一题的示例C++程序
* bublesort-nooptimize.asm：第一题示例无优化汇编程序（完整版）
* bublesort-optimize.asm：第一题示例优化后汇编程序（完整版）

## Problem 1 

考核知识点：代码优化——尾递归的优化

### 题干

尾递归是我们在编写程序时经常会遇到的情况。对于尾递归，编译器可以做出一定的优化。如下这个程序递归求解了冒泡排序问题：

```c++
void bubblesort(int *a, int n){
    if(n == 0) return;
    else{
        int i;
        for(i = 0; i < n - 1; i++){
            if(a[i] > a[i+1]){
                a[i] ^= a[i+1];
                a[i+1] ^= a[i];
                a[i] ^= a[i+1];
            }
        }
        bubblesort(a, n - 1);
    }
}
```

这个程序位于test/problem1/bublesort.cpp中，在普通的编译选项编译的汇编结果中，我们可以看到明显的递归痕迹：（编译器为Ubuntu22.10平台中的gcc编译器，版本号12.2.0）

```assembly
_Z10bubblesortPii:
.LFB1761:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	
	... 
	
	call	_Z10bubblesortPii
	jmp	.L1
.L7:
	nop
.L1:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
```

这个程序通过调用后保存上下文，完成了递归的调用。但使用编译优化后结果如下：

```assembly
_Z10bubblesortPii:
.LFB1782:
	.cfi_startproc
	testl	%esi, %esi
	je	.L3
	leal	-1(%rsi), %r8d
	leaq	4(%rdi), %r9
	testl	%r8d, %r8d
	jle	.L18
	.p2align 4,,10
	.p2align 3
.L19:
	leal	-2(%rsi), %edx
	movq	%rdi, %rax
	leaq	(%r9,%rdx,4), %rsi
	.p2align 4,,10
	.p2align 3
.L8:
	movl	(%rax), %ecx
	movl	4(%rax), %edx
	cmpl	%edx, %ecx
	jle	.L7
	movl	%ecx, 4(%rax)
	movl	%edx, (%rax)
.L7:
	addq	$4, %rax
	cmpq	%rsi, %rax
	jne	.L8
.L9:
	movl	%r8d, %esi
	leal	-1(%rsi), %r8d
	testl	%r8d, %r8d
	jg	.L19
.L18:
	jne	.L9
.L3:
	ret
	.cfi_endproc
```

很明显看出，程序使用了一个跳转，跳转后并没有保存上下文，这就完成了尾递归的优化：

（1）请根据这个程序来分析，尾递归为什么可以做出这样的优化？

（2） 在程序中利用尾递归来完成计算可以大幅减少计算开销，请把/test/problem1/fact.cpp中的递归阶乘函数改为尾递归，并使用gcc来验证修改结果。

### 解答

（1） 由于尾递归之后不会再进行任何有意义的执行语句，因此局部数据都不需要继续使用，故不必保存程序当前状态。因此，尾递归后，当前活动记录可以被将要创建的活动记录覆盖，也就不必创建新的活动记录

（2） 程序如下：

```c++
int fact(int n, int pro){
    if(n == 0) return pro;
    else return fact(n - 1, pro * n);
}
```



## Problem 2

考察知识点：运行时存储空间的管理——段错误的原因

### 题干

在C语言编程时，我们经常会遇到引人注目的Segmentation fault (core dumped)，这时坐在电脑前的你可能会束手无策。本题将通过几个案例，来说明一部分Segmentation fault的原因。请先判断下列程序哪些会造成段错误，在可能造成段错误的每段程序下，写出段错误的原因；在不会造成段错误的每段程序下，写出运行的结果。

（1）

```c++
int a[100];
a[256] = 6666666;
```

（2）

```c++
char *p = "test";
strncpy(p, "abcdefghijklmn", 10);
printf("%s\n", p);
```

（3）

```c++
char p[2];
strncpy(p, "abcdefghigklmn", 10);
printf("%s\n", p);
```

（4）

```c++
int main(){
    main();
}
```

（5）

```c++
int *p = (int *)100;
*p = 100;
```

（6）

```c++
char *p = (char*) malloc(2 * sizeof(char));
strncpy(p, "abcdefghijklmn", 10);
cout << strcmp(p, "abcdefghij");
```

### 解答

（1）段错误，数组越界访问（访问非法地址）

（2）段错误，访问只读区域地址

（3）正确，结果是abcdefghij+未知的字符

（4）段错误，活动记录栈溢出

（5）段错误，访问了受保护的地址

（6）正确，结果为0（malloc出的空间是可以越界访问不报错的）