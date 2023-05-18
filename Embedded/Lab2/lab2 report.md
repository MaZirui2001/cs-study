# Lab 2 Report

PB20111623 马子睿

## 实验内容

* 在linux平台上面安装arm-linux-工具链
* 编译一个自己的arm-linux-gcc编译器

## 工具链的安装

我在本地配置了Ubuntu22.10双系统，在其上安装了arm-linux工具链。

### 安装过程

* 使用wget下载arm-none-linux-gnueabi-gcc安装包

  wget命令为

  ```bash
  wget http://www.codesourcery.com/sgpp/lite/arm/portal/package4571/public/arm-none-linux-gnueabi/arm-2009q1-203-arm-none-linux-gnueabi-i686-pc-linux-gnu.tar.bz2
  ```

* 我将其安装到了`/usr/local/arm`路径下，并增加交叉编译工具路径：

  ```bash
  export PATH=$PATH:/usr/local/arm/bin/
  ```

* 之后为了让命令名，我们用链接来创建命令别名：

  ```bash
  sudo ln -s /usr/local/arm/bin/arm-none-linux-gnueabi-gcc /usr/bin/arm-linux-gcc
  sudo ln -s /usr/local/arm/bin/arm-none-linux-gnueabi-as /usr/bin/arm-linux-as
  sudo ln -s /usr/local/arm/bin/arm-none-linux-gnueabi-ld /usr/bin/arm-linux-ld
  ```

* 最后使用命令来验证：

  ![image-20221121161256017](/home/madrid/snap/typora/76/.config/Typora/typora-user-images/image-20221121161256017.png)

### 正确性验证

我们使用C语言编写一个数组左移k位的程序如下：

```c++
#include <stdio.h>
int a[10];
int gcd(int a, int b){
    int c = a % b;
    while(c){
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}
void shift_left(int k, int n){
    int d = gcd(n, k);
    int x, t, i, j;
    for(i = 0; i < d; i++){
        x = a[i];
        t = i;
        for(j = 0; j < n / d - 1; j++){
            a[t] = a[(t + k) % n];
            t = (t + k) % n;
        }
        a[t] = x;
    }
}
int main(){
    int n, k;
    int i, j;
    scanf("%d %d", &n, &k);
    // int *a = new int[n];
    for(i = 0; i < n; i++){
        scanf("%d", a+i);
    }
    shift_left(k, n);
    for(i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
```

使用命令将其编译为可执行文件：

```bash
arm-linux-gcc -march=armv7-a shift_left.c -o shift_left_arm
```

同时使用gcc命令将其编译为可执行文件：

```bash
gcc stringsort.c -o stringsort_gcc64
```

使用readelf来比较这两个可执行文件的差异:

gcc编译出来的可执行文件ELF头部：

```
ELF 头：
  Magic：   7f 45 4c 46 02 01 01 00 00 00 00 00 00 00 00 00 
  类别:                              ELF64
  数据:                              2 补码，小端序 (little endian)
  Version:                           1 (current)
  OS/ABI:                            UNIX - System V
  ABI 版本:                          0
  类型:                              DYN (Position-Independent Executable file)
  系统架构:                          Advanced Micro Devices X86-64
  版本:                              0x1
  入口点地址：               0x10c0
  程序头起点：          64 (bytes into file)
  Start of section headers:          14208 (bytes into file)
  标志：             0x0
  Size of this header:               64 (bytes)
  Size of program headers:           56 (bytes)
  Number of program headers:         13
  Size of section headers:           64 (bytes)
  Number of section headers:         31
  Section header string table index: 30
```

arm-gcc编译出来的可执行文件ELF头部：

```
ELF 头：
  Magic：   7f 45 4c 46 01 01 01 00 00 00 00 00 00 00 00 00 
  类别:                              ELF32
  数据:                              2 补码，小端序 (little endian)
  Version:                           1 (current)
  OS/ABI:                            UNIX - System V
  ABI 版本:                          0
  类型:                              EXEC (可执行文件)
  系统架构:                          ARM
  版本:                              0x1
  入口点地址：               0x8414
  程序头起点：          52 (bytes into file)
  Start of section headers:          3468 (bytes into file)
  标志：             0x5000002, Version5 EABI, <unknown>
  Size of this header:               52 (bytes)
  Size of program headers:           32 (bytes)
  Number of program headers:         8
  Size of section headers:           40 (bytes)
  Number of section headers:         31
  Section header string table index: 28
```

其中主要区别如下：

* ELF头部分：

  * 类别：arm-linux-gcc是32位编译器，而本机中的gcc是64位编译器
  * 系统架构：arm-linux-gcc编译出ARM架构的可执行文件，而gcc编译出AMD X86_64架构的可执行文件
  * 入口点地址：arm-linux-gcc的入口地址是0x8414，而gcc的入口地址是0x10c0

  | 不同点     | arm-gcc | gcc        |
  | ---------- | ------- | ---------- |
  | 类别       | 32位    | 64位       |
  | 系统架构   | ARM     | AMD X86_64 |
  | 入口点地址 | 0x8414  | 0x10c0     |
  | 头部开始节 | 14208   | 3468       |
  | 头大小     | 64bytes | 52bytes    |
  | 程序头大小 | 56bytes | 32bytes    |
  | 程序头数量 | 13      | 8          |
  | 节头大小   | 64bytes | 40bytes    |
  | 节头数量   | 31      | 31         |

* 分段

  ARM下的分段更少，只有8段。而gcc编译的代码分段更多，有13段：

  ARM：

  ```
   Section to Segment mapping:
    段节...
     00     .ARM.exidx 
     01     
     02     .interp 
     03     .interp .note.ABI-tag .hash .dynsym .dynstr .gnu.version .gnu.version_r .rel.dyn .rel.plt .init .plt .text .fini .rodata .ARM.extab .ARM.exidx .eh_frame 
     04     .init_array .fini_array .jcr .dynamic .got .data .bss 
     05     .dynamic 
     06     .note.ABI-tag 
     07   
  ```

  X86_64:

  ```
   Section to Segment mapping:
    段节...
     00     
     01     .interp 
     02     .interp .note.gnu.property .note.gnu.build-id .note.ABI-tag .gnu.hash .dynsym .dynstr .gnu.version .gnu.version_r .rela.dyn .rela.plt 
     03     .init .plt .plt.got .plt.sec .text .fini 
     04     .rodata .eh_frame_hdr .eh_frame 
     05     .init_array .fini_array .dynamic .got .data .bss 
     06     .dynamic 
     07     .note.gnu.property 
     08     .note.gnu.build-id .note.ABI-tag 
     09     .note.gnu.property 
     10     .eh_frame_hdr 
     11     
     12     .init_array .fini_array .dynamic .got 
  ```

  整体而言，**ARM生成的程序更精简，分段也较少，单从编译角度，运行效率相对较高**。

## 编译一个自己的arm-linux-gcc编译器

**在这里，我选择了更好的aarch64编译器，也就是arm64编译器，来替代arm-linux-gcc**

### 修改gcc源码

在编译arm编译器前，我先使用了普通的gcc的源码尝试修改，其中在gcc-11的gcc.c文件的第7458行，我找到了输出gcc输出版本信息的代码，并进行了修改：

```c++
  if (! strncmp (version_string, compiler_version, n)
      && compiler_version[n] == 0)
    fnotice (file, "gcc version %s %s\n", version_string,
	     pkgversion_string);
  else
    fnotice (file, "gcc driver version %s %sexecuting gcc version %s\n",
	     version_string, pkgversion_string, compiler_version);
  fnotice (file, "gcc @MAdrid ThinkPad Computer Science of USTC\n");
}
```

可以看到，这里我已经加入了一行个人信息的输出。

### 编译binutils

首先我们需要编译binutils，构建交叉汇编器、交叉链接器。在准备好源码和必要的前置工具后，执行如下命令：

```bash
../binutils-2.38/configure --prefix=/opt/cross --target=aarch64-linux --disable-multilib
make -j4
make install
```

编译后目录如下：

![image-20221121174431258](/home/madrid/snap/typora/76/.config/Typora/typora-user-images/image-20221121174431258.png)

### 安装Linux内核头文件

这一步是为了允许交叉编译器编译的程序能够进行系统调用，使用如下命令：

```bash
make ARCH=arm64 INSTALL_HDR_PATH=/opt/cross/aarch64-linux headers_install
```

### 编译gcc

下面就是编译gcc了。这里需要选择gcc的目标架构，用如下命令：

```bash
../gcc-11.1.0/configure --prefix=/opt/cross --target=aarch64-linux --enable-languages=c,c++,fortran,objc,obj-c++ --disable-multilib
make -j8 all-gcc
make install-gcc
```

编译后，目录结构如下：

![image-20221121175033219](/home/madrid/snap/typora/76/.config/Typora/typora-user-images/image-20221121175033219.png)

这一步之后，/opt/cross中已经有了arm架构的gcc。之后的所有步骤，都需要把默认编译器改为这个刚刚编译完成的gcc

### 编译glibc文件和启动文件

下载glibc后，执行如下命令来编译：

```bash
../glibc-2.33/configure --prefix=/opt/cross/aarch64-linux --build=$MACHTYPE --host=aarch64-linux --target=aarch64-linux --with-headers=/opt/cross/aarch64-linux/include --disable-multilib libc_cv_forced_unwind=yes
make install-bootstrap-headers=yes install-headers
make csu/subdir_lib
install csu/crt1.o csu/crti.o csu/crtn.o /opt/cross/aarch64-linux/lib
aarch64-linux-gcc -nostdlib -nostartfiles -shared -x c /dev/null -o /opt/cross/aarch64-linux/lib/libc.so
touch /opt/cross/aarch64-linux/include/gnu/stubs.h
```

之后执行 `./configure --help`查看详细信息：

![image-20221121175533080](/home/madrid/snap/typora/76/.config/Typora/typora-user-images/image-20221121175533080.png)

### 编译和编译器支持库、标准C库、C++库

先来编译编译器支持库：

```bash
make -j8 all-target-libgcc
make install-target-libgcc
```

再来编译标准C库和C++库

```bash
make -j8
make install
```

到这里，aarch64-linux-gcc就全部编译完毕了。

### 正确性验证

* 输出个人信息：

  ![image-20221121175937534](/home/madrid/snap/typora/76/.config/Typora/typora-user-images/image-20221121175937534.png)

* 这里我们使用一个用C++编写的字符串排序，来验证正确性：

  ```c++
  #include<iostream>
  #include <string>
  using namespace std;
  void string_sort(string str[], int n){
      for(int i = 0; i < n; i++){
          for(int j = 0; j < n - i - 1; j++){
              if(str[j] > str[j+1]){
                  swap(str[j], str[j+1]);
              }
          }
      }
  }
  int main(){
      string str[100];
      int n;
      cin >> n;
      for(int i = 0; i < n; i++){
          cin >> str[i];
      }
      string_sort(str, n);
      for(int i = 0; i < n; i++){
          cout << str[i];
      }
      return 0;
  }
  ```
  
  使用aarch命令来编译：
  
  ```bash
  aarch64-linux-g++ stringsort.cpp -o stringsort
  ```
  
  readelf的结果如下（节选）：
  
  ```c++
  ELF 头：
    Magic：   7f 45 4c 46 02 01 01 00 00 00 00 00 00 00 00 00 
    类别:                              ELF64
    数据:                              2 补码，小端序 (little endian)
    Version:                           1 (current)
    OS/ABI:                            UNIX - System V
    ABI 版本:                          0
    类型:                              EXEC (可执行文件)
    系统架构:                          AArch64
    版本:                              0x1
    入口点地址：               0x400cc0
    程序头起点：          64 (bytes into file)
    Start of section headers:          18896 (bytes into file)
    标志：             0x0
    Size of this header:               64 (bytes)
    Size of program headers:           56 (bytes)
    Number of program headers:         9
    Size of section headers:           64 (bytes)
    Number of section headers:         38
    Section header string table index: 37
  ...
  
  Version symbols section '.gnu.version' contains 22 entries:
   地址：0x00000000004008bc  Offset: 0x0008bc  Link: 5 (.dynsym)
    000:   0 (*本地*)       2 (GLIBCXX_3.4.21)    3 (GLIBCXX_3.4)   2 (GLIBCXX_3.4.21) 
    004:   2 (GLIBCXX_3.4.21)    4 (GLIBC_2.17)    2 (GLIBCXX_3.4.21)    3 (GLIBCXX_3.4)
    008:   4 (GLIBC_2.17)    2 (GLIBCXX_3.4.21)    2 (GLIBCXX_3.4.21)    3 (GLIBCXX_3.4)
    00c:   4 (GLIBC_2.17)    1 (*全局*)      6 (GCC_3.0)       1 (*全局*)   
    010:   1 (*全局*)      3 (GLIBCXX_3.4)   3 (GLIBCXX_3.4)   3 (GLIBCXX_3.4)
    014:   5 (CXXABI_1.3)    3 (GLIBCXX_3.4)
  
  Version needs section '.gnu.version_r' contains 3 entries:
   地址：0x00000000004008e8  Offset: 0x0008e8  Link: 6 (.dynstr)
    000000: Version: 1  文件：libgcc_s.so.1  计数：1
    0x0010:   Name: GCC_3.0  标志：无  版本：6
    0x0020: Version: 1  文件：libc.so.6  计数：1
    0x0030:   Name: GLIBC_2.17  标志：无  版本：4
    0x0040: Version: 1  文件：libstdc++.so.6  计数：3
    0x0050:   Name: CXXABI_1.3  标志：无  版本：5
    0x0060:   Name: GLIBCXX_3.4  标志：无  版本：3
    0x0070:   Name: GLIBCXX_3.4.21  标志：无  版本：2
  
  Displaying notes found in: .note.ABI-tag
    所有者            Data size   Description
    GNU                  0x00000010       NT_GNU_ABI_TAG (ABI version tag)
      OS: Linux, ABI: 3.7.0
  ```
  
  可以看到，这确实是一个AArch64架构的程序，这个arrch64-linux-g++的构建是正确的。

## 实验总结

通过本次实验，我有了如下收获：

* 学会建立了一个完善的arm交叉编译工具链，为上板测试做好了准备
* 学会自己编译一个完整的arm交叉编译工具链

