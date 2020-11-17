//
//  Polymorphism.cpp
//  C++Demo
//
//  Created by lieon on 2020/10/30.
//  Copyright © 2020 lieon. All rights reserved.
//

#include <iostream>
#include "Polymorphism.hpp"
using namespace std;

/**
 # 多态
 - 默认情况下，编译器只会根据指针类型调用对应的函数，不存在多态
 
 ## 特性
 - 同一个操作作用于不同的对象，可以有不同的解释，产生不同的执行结果
 - 在运行时，可以识别出真正的对象类型，调用对应子类中的函数
 
 ## 多态的要素
 - 子类重写父类的成员函数（override）
 - 父类指针指向子类对象
 - 利用父类调用重写的成员函数
 
 ```C++
 class Animal {
 public:
     virtual void run() {
         cout << "Animal::run()" << endl;
     }
 };

 class Dog: public Animal {
 public:
     void run() override {
         cout << "Dog::run()" << endl;
     }
 };

 class ErHa: public Dog {
 public:
     void run() override {
         cout << "ErHa::run()" << endl;
     }
 };

 void test() {
     Dog *dog = new Dog();
     dog->run();
     
     Animal * animal0 = new Dog();
     animal0->run();
     
     Animal * animal1 = new ErHa();
     animal1->run();
 }
 
 # 虚函数
- C++中的多态通过虚函数（virtual function）来实现
 - 虚函数：被virtual修饰的成员函数
 - 只要在父类中声明为虚函数，子类中重写的函数也自动变成虚函数（也就是说子类可以省略virtual关键字）
 ## 虚表
 - 虚函数的实现原理是虚表，这个虚表里面存储着最终需要调用的函数地址，这个虚表也叫虚函数表
 
 ```C++
 class Animal {
 public:
     
     virtual void run() {
         cout << "Animal::run()" << endl;
     }
     
     virtual void speak() {
         cout <<"Animal::speak()" << endl;
     }
 };
 
 class Cat: public Animal {
 public:
     int m_life;
     Cat(): m_life(0) {}
     
     void run() override {
         cout << "Cat::run()" << endl;
     }
     
     void speak() override {
         // 先执行父类的成员函数
         Animal::speak();
         // 再执行自己的一些操作
         cout << "Cat::Speak()" << endl;
     }
     
 };
 ```
 - 所有的对象（不管在全局区，栈，堆）共用一份虚表

 - 具有虚函数的类，在对象创建时，会在其内存布局的时候，拿出4个字节的内存，用来存储该对象对应的函数虚表地址，x86环境中，一个虚函数地址占用4个字节。
 
 ## 虚表的汇编分析
     ```ASM
     // 调用Cat::run
     // 取出cat指针变量里面存储的地址值
     // eax里面存放的是cat对象的地址
     mov eax, dword ptr [cat]
     // 取出Cat对象的前面4个字节给edx
     // edx里面存储的是虚表的地址
     mov edx, dword ptr [eax]
     // 取出虚表中的前面4个字节给eax
     // eax存放的就是Cat::run的函数地址
     mov eax, dword ptr [edx]
     call eax
     
     // 调用Cat::speak
     // 取出cat指针变量里面存储的地址值
     // eax里面存放的是cat对象的地址
     mov eax, dword ptr [cat]
     // 取出Cat对象的前面4个字节给edx
     // edx里面存储的是虚表的地址
     mov edx, dword ptr [eax]
     // 取出虚表中的后面4个字节给eax
     // eax存放的就是Cat::speak的函数地址
     mov eax, dword ptr [edx]
     call eax
     ```
 
 ## 虚析构函数
 - 含有虚函数的类，应该将析构函数声明为虚函数（虚析构函数）
 - delete 父类指针时，才会调用子类的析构函数，保证析构的完整性
 
 ```C++
 class Animal {
 public:
     
     virtual void run() {
         cout << "Animal::run()" << endl;
     }
     
     virtual void speak() {
         cout <<"Animal::speak()" << endl;
     }
     
     virtual ~Animal() {
         
     }
 };


 class Cat: public Animal {
 public:
     int m_life;
     Cat(): m_life(0) {}
     
     void run() override {
         cout << "Cat::run()" << endl;
     }
     
     void speak() override {
         // 先执行父类的成员函数
         Animal::speak();
         // 再执行自己的一些操作
         cout << "Cat::Speak()" << endl;
     }
     
     ~Cat() {
         cout << "Cat::~Cat()" << endl;
     }
 };
 ```
 
 ## 纯虚函数
 - 定义：没有函数体且初始化为0的虚函数，用来定义接口规范
 - 抽象类
    - 含有虚函数的类，不可以实例化
    - 抽象类也可以包含非纯虚函数
    - 如果父类是抽象类，子类没有完全实现纯虚函数，那么这个子类依然是抽象类
 
 ```C++
 class Animal {
 public:
     
     virtual void run() = 0;
     
     virtual void speak() = 0;
     
     virtual ~Animal() {
         
     }
     
 };
 ```
 */

class Animal {
public:
    
    virtual void run() {
        cout << "Animal::run()" << endl;
    }
    
    virtual void speak() {
        cout <<"Animal::speak()" << endl;
    }
    
    virtual ~Animal() {
        
    }
    
};

class Dog: public Animal {
public:
    void run() override {
        cout << "Dog::run()" << endl;
    }
    
    ~Dog() {
        cout << "Dog::~Dog()" << endl;
    }
};

class ErHa: public Dog {
public:
    void run() override {
        cout << "ErHa::run()" << endl;
    }
    
    ~ErHa() {
        cout << "ErHa::~ErHa()" << endl;
    }
};

class Cat: public Animal {
public:
    int m_life;
    Cat(): m_life(0) {}
    
    void run() override {
        cout << "Cat::run()" << endl;
    }
    
    void speak() override {
        // 先执行父类的成员函数
        Animal::speak();
        // 再执行自己的一些操作
        cout << "Cat::Speak()" << endl;
    }
    
    ~Cat() {
        cout << "Cat::~Cat()" << endl;
    }
};


void Polymorphism::test() {
    Dog *dog = new Dog();
    dog->run();
    
    Animal * animal0 = new Dog();
    animal0->run();
    
    Animal * animal1 = new ErHa();
    animal1->run();
    
    Animal *animal2 = new Cat();
    /**
     // 调用Cat::run
     // 取出cat指针变量里面存储的地址值
     // eax里面存放的是cat对象的地址
     mov eax, dword ptr [cat]
     // 取出Cat对象的前面4个字节给edx
     // edx里面存储的是虚表的地址
     mov edx, dword ptr [eax]
     // 取出虚表中的前面4个字节给eax
     // eax存放的就是Cat::run的函数地址
     mov eax, dword ptr [edx]
     call eax
     */
    animal2->run();
    /**
     // 调用Cat::speak
     // 取出cat指针变量里面存储的地址值
     // eax里面存放的是cat对象的地址
     mov eax, dword ptr [cat]
     // 取出Cat对象的前面4个字节给edx
     // edx里面存储的是虚表的地址
     mov edx, dword ptr [eax]
     // 取出虚表中的后面4个字节给eax
     // eax存放的就是Cat::speak的函数地址
     mov eax, dword ptr [edx]
     call eax
     */
    animal2->speak();
 
}

