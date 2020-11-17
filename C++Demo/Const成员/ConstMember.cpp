//
//  ConstMember.cpp
//  C++Demo
//
//  Created by lieon on 2020/11/7.
//  Copyright © 2020 lieon. All rights reserved.
//

#include "ConstMember.hpp"
#include <iostream>

/**
 # const成员
 - const成员: 被const修饰的成员变量，非静态成员函数
 - const成员变量
    - 必须初始化（类内部初始化），可以在声明的时候直接初始化赋值
    - 非static的const成员变量还可以在初始化列表中初始化
 - const成员函数（非静态）
    - const关键字写在参数列表后面，函数的声明和实现必须带const
    - 内部不能修改费static成员变量
    - 内部只能调用 const 成员函数、 static 成员函数
    - 非const成员函数可以调用const成员函数
 - const成员函数和非const成员函数构成重载
    - 非const对象（指针）优先调用非const成员函数
 - const对象只能调用const成员函数，static函数
 
 ```C++
 class Car {
     const int mc_wheelsCount = 20;
 public:
     Car(): mc_wheelsCount(10) {};
     
     void run() const {
         std::cout << "run()" << std::cout;
     }
 };

 ```
 
 # 引用类型成员
 - 引用类型成员变量必须初始化(不考虑static情况)
    - 在声明的时候直接初始化
    - 通过初始化列表初始化
 
 ```C++
 class Car {
     int age;
     int m_price = age;
 
 public:
     Car(int &price): m_price(price) {};
 };
 ```
 */

class Car {
    const int mc_wheelsCount = 20;
    int age;
    int m_price = age;
public:
    Car(int &price): mc_wheelsCount(10), m_price(price) {};
    
    void run() const {
        std::cout << "run()" << std::endl;
    }
    
};
