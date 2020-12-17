//
//  Inherience.cpp
//  C++Demo
//
//  Created by lieon on 2020/10/15.
//  Copyright © 2020 lieon. All rights reserved.
//

#include "Inherience.hpp"
/**
 # 继承
 ## 继承的方式有三种
 - 公共继承
 - 保护继承
 - 私有继承
 
 | 访问权限 | public | protected | private |
 | ------ | ------  | ------    |------ |
 | 对本类  | 可见    | 可见        | 可见 |
 | 对子类  | 可见    | 可见        | 不可见 |
 | 对外部(调用方)    | 可见 | 不可见  | 不可见 |
 
 ## 继承中的对象模型
 - 父类中所有的非静态成员属性都会被子类继承下去
 - 父类中私有成员属性是被编译器给隐藏了，因此访问不到，但确实被继承下去了
 ```C++
 struct Person {
 public:
     int m_A;
 protected:
     int m_age;
 private:
     int m_B;
 };

 struct Student: public Person {
     int m_no;
 };
 
 Student 对象占用16个字节
 ```
 
 ## 继承中构造和析构的顺序
  - 构造顺序：先构造父类，再构造子类
  - 析构：先析构子类，再析构父类
 
 ## 继承中访问同名的成员
  - 子类对象可以直接访问子类中同名成员
  - 子类对象加作用域可以访问父类同名成员
  - 当子类与父类拥有同名的成员函数，子类会隐藏父类中同名成员函数，加作用域可以访问到父类中同名函数
 
 ## 多继承
 */
struct Person {
public:
    int m_A;
protected:
    int m_age;
private:
    int m_B;
};

struct Student: public Person {
    int m_no;
};

struct GoodStudent: public Student {
    int m_money;
};



class Animal {
public:
    int m_age;
};

/**
 ```C++
 class Sleep: virtual public Animal { };

 class Tuo: virtual public Animal { };

 class SleepTuo: public Sleep, public Tuo { };

  Sleep 和 Tuo中通过虚继承存储的是一个vbptr（虚基类指针），该指针分别指向一个Sleep和Tuo的一个虚表，该虚表存储的是SleepTuo中一个地址偏移量
  ，通过该偏移量和vbptr的起始地址，得到最终指向的地址
  Sleep的vbptr指向: 0（起始值）+ 8（偏移量）= 8
  Sleep的vbptr指向: 4（起始值）+ 4（偏移量） = 8

 ```
 */
