//
//  StaticMember.cpp
//  C++Demo
//
//  Created by lieon on 2020/11/5.
//  Copyright © 2020 lieon. All rights reserved.
//

#include "StaticMember.hpp"

/**
 # 静态成员
 - 被 **static**修饰的成员变量\函数
 - 可以通过对象（对象.静态成员）,对象指针(对象指针->静态成员), 类访问(类名::静态成员)
 - 静态成员变量
    - 存储在数据段（全局区，类似于全局变量），整个程序运行过程中只有一份内存
    - 对比全局变量，它可以设定访问权限（public, protected, private），达到局部共享的目的
    - 必须初始化，必须在类外部初始化，初始化不能带static，如果类的声明和实现分离（在实现的.cpp中初始化）
 - 静态成员函数
    - 内部不能使用this指针（this指针只能用在非静态成员函数内部）
    - 不能是虚函数（虚函数只能是非静态成员函数）
    - 内部不能访问非静态成员变量\函数，只能访问静态成员变量\函数
    - 非静态成员函数内部可以访问静态成员变量\函数
    - 构造函数，析构函数不能是静态
    - 当声明和实现分离时，实现不能带**static**
 
 ```C++
 class Car {
     int m_price;
     static int ms_count;
 public:
     static int getCount() {
         return ms_count;
     }
     
     Car(int price = 0): m_price(price) {
         ms_count++;
     }
     
     ~Car() {
         
     }
 };
 ```
 ## 静态成员经典应用 - 单例模式
 ```C++
 class Rocket {
 private:
     Rocket() { }
     static Rocket* ms_instace;
     
 public:
     static Rocket* shared() {
        // 严格要讲，这段代码需要考虑线程安全的问题
         if (ms_instace == nullptr) {
             ms_instace = new Rocket();
         }
         return ms_instace;
     }
 };

 Rocket* Rocket::ms_instace = nullptr;
 ```
 */

class Car {
    int m_price;
    static int ms_count;
public:
    static int getCount() {
        return ms_count;
    }
    
    Car(int price = 0): m_price(price) {
        ms_count++;
    }
    
    ~Car() {
        
    }
};


class Rocket {
private:
    static Rocket* ms_instace;
    Rocket() { }
    Rocket(const Rocket &rocket) { };
    Rocket &operator=(const Rocket &rocket) { return *this; };

public:
    static Rocket* shared() {
        // 严格要讲，这段代码需要考虑线程安全的问题
        if (ms_instace == nullptr) {
            ms_instace = new Rocket();
        }
        return ms_instace;
    }
};

Rocket* Rocket::ms_instace = nullptr;
