//
//  MemoryLayout.cpp
//  C++Demo
//
//  Created by lieon on 2020/11/17.
//  Copyright © 2020 lieon. All rights reserved.
//

#include "MemoryLayout.hpp"

/**
 # 内存布局
 - 代码区
 - 全局区
    - 存放全部变量，静态变量
    - 存放常量（字符串常量，const修饰的全局变量）
 - 栈区
    - 存放局部变量，函数参数
    - 栈区的数据有编译器管理开辟和释放
    - 注意：不要返回局部变量的地址
 - 堆区
    - 由程序员分配释放，当程序结束时，由操作系统回收
    - 在C++中主要利用new在堆去开辟内存, 利用delete释放
 # 引用
 - 相当于变量的别名
 - 引用必须初始化
 - 引用一旦初始化后，就不可以更改，本质是一个指针常量 (int * const p)
 
 ## 引用做返回值
 - 不要返回局部变量的引用
 - 函数调用可以作为左值
 
 ## 常量引用
 - 常量引用主要用来修饰形参，防止误操作,本质是（const int * const p）
 
 ```C++
 void show(const int &a) {
     a = 20; // ❌
 }
 ```
 
# 函数提高
 ## 函数的默认参数
  - 如果某个位置已经有了默认参数，那么这个位置往后，从左到右都必须有默认参数
  - 如果函数声明有默认参数，函数实现就不能有默认参数
 ```C++
 int func(int a = 10, int b = 20) {
     return a + b;
 }
 ```
 ## 函数重载注意事项
    - 函数重载：函数名相同，作用域相同，参数不同
    - 引用作为重载条件
    ```C++
     void func(int &a) { }
     void func (const int &a) { }
     void test() {
         int a = 10;
         func(a);// void func(int &a)
         const int b = 10;
         func(b); // void func (const int &a
         
     }
    ```
    - 函数重载碰到函数默认参数,会出现二义性，不知道该正确调用哪一个
    ```C++
     void func(int a = 0, int b = 10) { }

     void func(int a = 0) { }
    ```
 */


//void func(int a = 0, int b = 10) { }


void func(int a = 0) { }

/**
# 函数指针
 - 重点是指针，存储的是地址，存储的函数的入口地址
 ```C++
  void func(int a = 0) { }

  void test() {
      // 函数指针
      void (*p)(int) = func;
  }
 ```
 
 # 指针函数：
 - 重点是函数，返回值是指针
 
 ```C++
  // 指针函数
  int * funcP(int a = 0) {
      int *p = new int(10);
      return p;
  }

  void test() {
      // 指针函数
      int *p1 = funcP(0);
  }
 ```
 
 # 数组指针
 - 重点是指针，存储的是数组的地址
 ```C++
  int a[3][2] = {{10, 22}, {41, 26}, {71, 82}};
  int (*pa)[2];
  pa = a;
  int s = *(pa[2] + 1);
 ```
 
# 指针数组
 - 重点是数组，存储的是指针
 ```C++
  int *p1 = funcP(0);
  int *aa[2] = { p1, p1};
  int *pp = aa[1];
 ```
 */

// 指针函数
int * funcP(int a = 0) {
    int *p = new int(10);
    return p;
}

void testsdf() {
    // 函数指针
    void (*p)(int) = func;
    
    // 指针函数
    int *p1 = funcP(0);
    
    // 数组指针
    int a[3][2] = {{10, 22}, {41, 26}, {71, 82}};
    int (*pa)[2];
    pa = a;
    int s = *(pa[2] + 1);
    
    // 指针数组
    int *aa[2] = { p1, p1};
    int *pp = aa[1];
    
    printf("数组指针: %d - 指针数组: %d \n", s, *pp);
}


/**
 #### 构造函数的分类及调用
 - 按参数分类：有参构造和无参构造
 - 按类型分为: 普通构造和拷贝构造
 #### 三种调用方式
 - 括号法
    ```
    Person p = p(10);
    ```
 - 显示法
    ```
    Person p = Person(10);
    ```
 - 隐式转换法
    ```
    Person p = 10; // 相当于写了 Person p = Person(10)
    ```
 
 #### 构造函数调用规则
 - 默认情况下（有需要处理事的时候），c++编译器至少给一个类添加3个函数
    - 默认构造函数
    - 默认析构函数
    - 默认拷贝函数
 - 如果用户定义有参构造函数，c++不再提供默认无参构造函数，但是会提供默认的拷贝构造
 - 如果用户定义拷贝构造函数， c++不会再提供其他构造函数
 - 当其他类对象作为本类成员，构造时候先构造类对象，再构造自身，析构的顺序与构造相反
 
 ## 静态成员的访问方式
 - 通过类名访问
 ```C++
 Perosn::m_age = 30;
 ```
 - 通过对象访问
 ```C++
 Perosn p;
 p.m_age = 0;
 ```
 
 ## C++对象模型
 - 空对象占用的内存空间为：1：c++编译器会给每个空对象分配一个字节空间，是为了区分空对象占用内存的位置
 - 每个空对象也应该有一个独一无二的内存地址
 - 非空对象占用的内存空间为：所有非静态成员变量的内存总和
 
 ## this指针
 - 指向被调用的成员函数/变量所属的对象
 - 当形参和成员变量同名时i，可用this指针区分
 - 在类的非静态成员函数中返回对象本身，可使用 return *this
 - this指针的本质是指针常量，指针的指向不可以修改的
 
 ```C++
 class Perosn {
 public:
     static int m_age;
     
     Perosn& addAge(int age) {
         this->m_age = age;
         return  *this;
     }
 }
 
 void testPerson() {
     Perosn p;
     p.addAge(10).addAge(10).addAge(10);
 }

 ```
 
 ## const成员
 - this指针的本质是指针常量，指针的指向不可以修改的
 - 在成员函数后面添加const，修饰的是this指向，让指针指向的值不可以修改，常函数内不可以修改成员属性
 - 要在常函数中修改成员变量，可以给这个成员变量加上mutable关键字
 
 ## 友元
 */


class Perosn {
public:
    static int m_age;
    
    Perosn& addAge(int age) {
        this->m_age = age;
        return  *this;
    }
};

int Perosn::m_age = 0;

void testPerson() {
    Perosn p;
    p.m_age = 0;
    Perosn::m_age = 30;
    p.addAge(10).addAge(10).addAge(10);
}
