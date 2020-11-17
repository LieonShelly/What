//
//  mian.c
//  C++Demo
//
//  Created by lieon on 2020/6/3.
//  Copyright © 2020 lieon. All rights reserved.
//

#include <stdio.h>
#include <string.h>

void arrayAndString() {
    // 二维数组
    int a[2][3] = {{1, 2, 3}, {3, 4, 5}};
    int b[2][3] = {1, 2, 3, 3, 4, 5 };
    // 字符串, C语言中没有String类型，用字符数组来存储字符串
    char c[3] = {'a', 'b', 'c'};
    char d[3] = "lie";
    char e[3] = {'1', '2', '\0'};
    // 字符串数组 一维数组中存放一个字符串，二维字符数组存放多个字符串
    char name[2][3] = {"ads", "ads"};
    // 字符处理函数
    // 1. strlen 测量字符串的个数
    int size = strlen("df");
    char s2[] = {'s', 's', '\0', '1', '2', '2', '\0'};
    strlen(s2);
    // strcpy 字符串拷贝
    strcpy(s2, "lmj");
    // strcat 字符串拼接
    strcat(s2, "OC");
    // strcmp 字符串比较
    strcmp(s2, c);
}

void pointer() {
    /**
     指针变量：用来存放变量地址的变量（间接引用）,首先将变量a的地址存放在另一个变量中，比如存放在变量b中。然后通过变量B来间接引用变量a。间接读写变量a的值
     指针变量是用来存放变量地址的。不要给它随意赋值一个常数
     */
    int *p;
    int a = 10;
    p = &a; // 将变量a的地址赋值给指针变量p，所以指针变量p指向变量a
    int *b = &a;
    // 指针运算符
    /// 1. 给指针指向的变量赋值
    char c = 10;
    *p = &c;
    *p = 9;
    /// 2. 取出指针指向变量的值
    char value = *p;
    /// 使用注意
    /// 在指针变量没有指向确定地址之前，不要对它所指的内容赋值
    /// 应该在指针变量指向一个确定的变量后再进行赋值
    printf("%lu\n - %lu\n", sizeof(p), sizeof(a));
}

// 指针的例子1
void swap(char *v1, char *v2) {
    char temp;
    temp = *v1;
    *v1 = *v2;
    *v2 = temp;
}

// 指针的例子2
int sumAndMinus(int v1, int v2, int *minus) {
    *minus = v1 - v2;
    return  v1 + v2;
}

// 指向一维数组元素的指针
/** 16bit 机器
 指针类型      p + 1 代表着p的值是多少
 char *p        1
 int *p         2
 float *p       4
 double *p      8
 */
void pointerToArray() {
    int a[4] = {1, 2, 3, 4};
    int *p = a; /// 定义一个int类型的指针，并指向数组的第0个元素
    p = &a[0]; // 让指针指向数组的第0个元素
    p = a; // 让指针指向数组的第0个元素
    int i;
    for (i = 0; i < 4; i++) {
        int value = *(p + i); // 等价于 *(p++), 不等于 a++, 数组名是个常量，不能进行赋值运算
        printf("a[%d] = %d \n", i, value);
    }
    // 遍历完毕后，指针变量p还是指向a[0],因为p值一直没有变过哦
    // a+1不一定代表着a值加2，究竟加多少，取决于数组的类型， a+1的计算方法与p+1的计算方法相同
    /**
     p是指针，a是一个数组:
     1> 如果p指向了一个数组元素，则p+1表示指向数组该元素的下一个元素。比如，假设p = &a[0]，则p+1表示a[1]的地址
     2> 对于不同类型的数组元素，p值的改变是不同的。如果数组元素为int类型，p+1代表着p的值加上2(16位环境下)
     3> 如果p的初值是&a[0]，那么
     - p+i和a+i都可以表示元素a[i]的地址，它们都指向数组的第i个元素。a代表数组首地址，a+i也是地址，它的计算方法与p+i相同
     - *(p+i)和*(a+i)都表示数组元素a[i]
     
     -虽然p+i和a+i都指向数组的第i个元素,但二者使用时还是有区别的。因为作为指针变量的p可以改变自身值，如p++,使p的值自增。而数组名a是一个代表数组首地址的常量，它的值是不能改变的，即a++是不合法的
     4> 引用一个数组元素可以有两种方法:
     下标法: 如a[i]
     指针法: 如*(p+i) 或 *(a+i)
     */
}

// 指针和字符串
void pointerAndString() {
    char *p;
    char s[] = "mj";
    p = s; // p = &s[0]
    for(; *p != '\0'; p++) {
        printf("%c - %p \n", *p, p);
    }
    //用指针直接指向一个字符串
    char *sp = "mj";
    long len = strlen(sp);
    printf("字符串长度:%lu\n", len);
    // 指针指向字符串的其他方式
    sp = "mj";
    /**
     还需要注意的是，下面的做法也是错误的：
     
     1 char *s = "mj";
     3 *s = "like";
     第3行代码犯了2个错误：
     第3行代码相当于把字符串"like"存进s指向的那一块内存空间，由第1行代码可以看出，s指向的是"mj"的首字符'm'，也就是说s指向的一块char类型的存储空间，只有1个字节，要"like"存进1个字节的空间内，肯定内存溢出
     由第1行代码可以看出，指针s指向的是字符串常量"mj"！因此是不能再通过指针来修改字符串内容的！就算是*s = 'A'这样"看起来似乎正确"的写法也是错误的，因为s指向的一个常量字符串，不允许修改它内部的字符。
     
     三、指针处理字符串的注意
     现在想将字符串"lmj"的首字符'l'改为'L'，解决方案是多种的
     
     1.第一种方案
     // 定义一个字符串变量"lmj"
     char a[] = "lmj";
     // 将字符串的首字符改为'L'
     *a = 'L';
     printf("%s", a);
     程序正常运行，输出结果：Lmj
     2. 应该有人能马上想到第二种方案
     char *p2 = "lmj"; /// 指向了一块字符串常量，正式因为是常量，所以它内部的字符是不允许修改的
     *p2 = 'L';
     printf("%s", p2);
     看起来似乎是可行的，但这是错误代码，错在第2行。首先看第1行，指针变量p2指向的是一块字符串常量，正因为是常量，所以它内部的字符是不允许修改的。
     */
    char a[] = "lmj"; // 定义的是一个字符串变量
    char *p2 = "lmj"; // 定义的是一个字符串常量, 不允许修改
}

// 返回指针的函数与指向函数的指针
char * uppper(char *str) {
    char *dest = str;
    while (*str != '\0') {
        if (*str >= 'a' && *str <= 'z') {
            *str -= 'a' - 'A';
        }
        str++;
    }
    return dest;
}

// 指向函数的指针
/**
 函数作为一段程序，在内存中也要占据部分存储空间，它也有一个起始地址，即函数的入口地址。函数有自己的地址，那就好办了，我们的指针变量就是用来存储地址的。因此，可以利用一个指针指向一个函数。其中，函数名就代表着函数的地址。
 */
int sumtest(int a, int b) {
    return a + b;
}
void pointerToFunc() {
    // 定一个指针变量p，指向sum函数
    int (*p)(int a, int b) = sumtest; // int (*p)(int, int) = sum; int(*p)() = sum;
    // 利用函数指针调用函数
    int result = (*p)(1, 1); // int result = p(1, 3);
    printf("%d\n", result);
}
/// 函数指针（指向函数的指针） int (*p)()
/// 指针函数（返回指针的函数） char * upper(char *s)
/// 指向函数的指针变量有两个用途
/// 1. 调用函数 2. 将函数作为参数在函数间传递

int minus(int a, int b) {
    return  a - b;
}

int mual(int a, int b) {
    return a * b;
}
void counting(int (*p)(int, int), int a, int b) {
    int result = p(a, b);
    printf("result: %d\n", result);
}

// 条件编译
#define MAX 11

void conditionComplie() {
#if MAX == 0
    printf("MAX is 0");
#elif MAX > 0
    printf("MAX ads");
#else
    printf("sdf");
#endif

#ifndef MAX
    #define MAX 11
#endif
    
#if !defined(MAX)
#endif
    
#ifdef MAX
    #define MIN 2
#endif

}

int main(int argc, const char * argv[]) {
    counting(minus, 3, 9);
    counting(sumtest, 3, 9);
    counting(mual, 3, 3);
    return 0;
}
