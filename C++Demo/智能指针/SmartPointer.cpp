//
//  SmartPointer.cpp
//  C++Demo
//
//  Created by lieon on 2020/11/11.
//  Copyright © 2020 lieon. All rights reserved.
//

#include "SmartPointer.hpp"
#include <iostream>
using namespace::std;

/**
 # 智能指针
 - 传统指针存在的问题
    - 需要手动管理内存
    - 容易发生内存泄露（忘记释放，出现异常等）
    - 释放之后产生野指针
 - 智能指针就是为了解决传统指针存在的问题
    - auto_ptr：属于c++98标准，在c++11中已经不推荐使用（有缺陷，比如不能用于数组）
    - shared_ptr：属于C++标准
    - unique_ptr：属于C++11标准
 
 ## 智能指针简单实现
 ```C++
 template<class T>
 class SmartPointer {
     T *m_pointer;
 public:
     SmartPointer(T *pointer): m_pointer(pointer) {}
     
     ~SmartPointer() {
         if (m_pointer == nullptr) {
             return;
         }
         delete m_pointer;
     }
     
     T* operator->() {
         return m_pointer;
     }
 };

 class Person {
 public:
     int m_age;
 };

 void testSmartPointer() {
     SmartPointer<Person> p(new Person());
     p->m_age = 0;
 }
 ```
 
 ## shared_ptr
 - 多个shared_ptr可以指向同一个对象，当最后一个shared_ptr在作用域范围内结束时，对象才被自动释放
 - 一个shared_ptr会对一个对象产生强引用（stong reference）
 - 每个对象都有个与之对用的强引用计数，记录着当前对象被多少个shared_ptr强引用着
    - 可以通过shared_ptr的use_count函数来获得强引用计数
 - 当有一个新的shared_ptr指针指向对象时，对象的强引用计数就会+1
 - 当有一个shared_ptr销毁时，对象的强引用计数就会-1
 - 当一个对象的强引用计数为0时(没有任何shared_ptr指向对象时)，对象就会自动销毁
 
 ```C++
 void testSharedPtr() {
     cout << "1" << endl;
     {
         shared_ptr<Person> p2;
         {
             shared_ptr<Person> p1(new Person());
             p2 = p1;
             cout << "2"  << " use_count: " << p1.use_count() << " " << p2.use_count() << endl; // 2 use_count: 2 2
         }
         cout << "3"  << " use_count: " << p2.use_count() << endl; // 3 use_count: 1
         
     }
     cout << "4" << endl;
 }
 ```
 ```
 执行结果：
     1
     Person()
     2 use_count: 2 2
     3 use_count: 1
     ~Person()
     4
 ```
 
 ## shared_ptr的注意点
 - 不要使用裸指针来初始化智能指针
 ```C++
     Person *p = new Person(); // Person()
     {
         shared_ptr<Person> p1(p); // ~Person()
     }
     {
         shared_ptr<Person> p2(p);
     } // ~Person()  *** error for object 0x100625cc0: pointer being freed was not allocated
 ```
 - 可以通过一个已存在的智能指针初始化一个新的智能指针
 ```C++
     {
         shared_ptr<Person> p1(new Person());
         shared_ptr<Person> p2(p1);
     }
 ```
 - shared_ptr的循环引用
 ```C++
 class Car;

 class Person {
 public:
     shared_ptr<Car> m_car = nullptr;
 };


 class Car {
 public:
     shared_ptr<Person> m_person = nullptr;
 };


 void testLoopReference() {
     shared_ptr<Person> person(new Person());
     shared_ptr<Car> car(new Car());
     person->m_car = car;
     car->m_person = person;
 }

 ```
 
 ## weak_ptr
 - weak_ptr会对一个对象产生弱引用
 - weak_ptr可以指向对象解决shared_ptr的循环引用问题
 ```C++
 
 class Car;

 class Person {
 public:
     shared_ptr<Car> m_car = nullptr;
     
     Person() {
         cout << " Person" << endl;
     }
     
     ~Person() {
         cout << " ~Person" << endl;
     }
 };


 class Car {
 public:
     weak_ptr<Person> m_person;// = nullptr;
     Car() {
         cout << " Car" << endl;
     }
     ~Car() {
         cout << " ~Car" << endl;
     }
 };


 void testLoopReference() {
     shared_ptr<Person> person(new Person());
     shared_ptr<Car> car(new Car());
     person->m_car = car;
     car->m_person = person;
     cout << " person: " << person.use_count() << endl;
     cout << " car: " << car.use_count() << endl;
 }
 ```
 ```
 执行结果:
 Person
 Car
 person: 1
 car: 2
 ~Person
 ~Car
 ```
 
 ## unique_ptr
 - unique_ptr 也会对一个对象产生强引用，它可以确保同一时间只有 1 个指针指向对象
 - unique_ptr 销毁时（作用域结束时），其指向的对象也就自动销毁了
 - 可以使用 std::move 函数转移 unique_ptr 的所有权
 */

template<class T>
class SmartPointer {
    T *m_pointer;
public:
    SmartPointer(T *pointer): m_pointer(pointer) {}
    
    ~SmartPointer() {
        if (m_pointer == nullptr) {
            return;
        }
        delete m_pointer;
    }
    
    T* operator->() {
        return m_pointer;
    }
};


void testSharedPtr() {
//    cout << "1" << endl;
//    {
//        shared_ptr<Person> p2;
//        {
//            shared_ptr<Person> p1(new Person());
//            p2 = p1;
//            cout << "2"  << " use_count: " << p1.use_count() << " " << p2.use_count() << endl; // 2 use_count: 2 2
//        }
//        cout << "3"  << " use_count: " << p2.use_count() << endl; // 3 use_count: 1
//
//    }
//    cout << "4" << endl;
    /**
     执行结果：
         1
         Person()
         2 use_count: 2 2
         3 use_count: 1
         ~Person()
         4
     */
    
   
   
}
class Car;

class Person {
public:
    shared_ptr<Car> m_car = nullptr;
    
    Person() {
        cout << " Person" << endl;
    }
    
    ~Person() {
        cout << " ~Person" << endl;
    }
};


class Car {
public:
    weak_ptr<Person> m_person;// = nullptr;
    Car() {
        cout << " Car" << endl;
    }
    ~Car() {
        cout << " ~Car" << endl;
    }
};


void testLoopReference() {
    shared_ptr<Person> person(new Person());
    shared_ptr<Car> car(new Car());
    person->m_car = car;
    car->m_person = person;
    cout << " person: " << person.use_count() << endl;
    cout << " car: " << car.use_count() << endl;
    
    /**
     Person
     Car
     person: 1
     car: 2
     ~Person
     ~Car
     */
}
