//
//  Copy.cpp
//  C++Demo
//
//  Created by lieon on 2020/11/8.
//  Copyright © 2020 lieon. All rights reserved.
//

#include "Copy.hpp"
#include <iostream>
using namespace std;

/**
 # 浅拷贝，深拷贝
 - 编译器默认提供的拷贝是浅拷贝（shallow copy）
    - 将一个对象中所有成员变量的值拷贝到另一个对象
    - 如果对象某个成员变量是个指针，只会拷贝指针中存储的地址值，并不会拷贝指针指向的内存空间
    - 可能会导致堆空间多次free问题
 - 如果需要实现深拷贝（deep copy），就需要自定拷贝构造函数
    - 将指针类型的成员变量所指向的内存空间，拷贝到新的内存空间
 
 ```C++
 class Car {
     int m_price;
     char *m_name;

 public:
     Car(int price, const char *name) {
         m_name = new char[strlen(name) + 1] {};
         strcpy(m_name, name);
     }
     
     Car(const Car &car): m_price(car.m_price) {
         if (car.m_name == nullptr) {
             return;
         }
         strcpy(m_name, car.m_name);
     }
     
     ~Car() {
         if (m_name != nullptr) {
             delete[] m_name;
             m_name = nullptr;
         }
     }
 };


 void testCar() {
     Car car1(100, "bmw");
     
     // 将car1的内存空间（8个字节）覆盖car2的内存空间（8个字节）
     Car car2 = car1;
 }

 ```
 
 # 对象参数和返回值
 - 使用对象类型作为函数的参数或者返回值，可能会产生一些不必要的中间对象(多次调用了拷贝构造函数)
 
 ```C++
 
 void test1(Car car) {
     
 }

 Car test2() {
     Car car(20, "3");
     return car;
 }

 void testCar() {
     Car car1(100, "bmw"); //  Car(int price, const char *name)
     test1(car1); // Car(const Car &car)
     
     Car car2 = test2(); // Car(const Car &car)
     
     Car car3(30, "3");//  Car(int price, const char *name)
     car3 = test2(); // Car(const Car &car)

 }
 ```
 
 # 隐式构造
 - C++中存在隐式构造的现象：某些情况下，会隐式调用单参数的构造函数
 
 ```C++
 void test1(Car car) {
 
 }
 
 Car test2() {
    return 70;
 }
 
 void test() {
     Car car1 = 10; // Car(int price)
     Car car2(20); // Car(int price)
     car2 = 30; // Car(int price)
     test1(40); // Car(int price)
     Car car3 = test2(); // Car(int price)
 }
 
 ```
 - 可以通过关键字 ***explic**禁止调用隐式构造
```C++
 explicit Car(int price, const char *name) {
       m_name = new char[strlen(name) + 1] {};
       strcpy(m_name, name);
   }
```
 
 # 编译自动生成的构造函数
 - C++的编辑器在某些特定的情况下，会给类自动生成无参的构造函数，比如
    - 成员变量在声明的同时进行了初始化
    - 有定义虚函数
    - 虚继承了其他类
    - 包含了某些对象类型的成员，且这个成员有构造函数（编译器生成或自定义）
    - 父类有构造函数（编译器生成或自定义）
 - 总结一下
    - 对象创建后，需要做一些额外操作时（比如内存操作，函数调用），编译器一般都会为其自动生成无参的构造函数
 */

//class Car {
//    int m_price;
//    char *m_name;
//
//public:
//  explicit Car(int price, const char *name) {
//        m_name = new char[strlen(name) + 1] {};
//        strcpy(m_name, name);
//    }
//    
//    Car(const Car &car): m_price(car.m_price) {
//        if (car.m_name == nullptr) {
//            return;
//        }
//        strcpy(m_name, car.m_name);
//    }
//    
//    ~Car() {
//        if (m_name != nullptr) {
//            delete[] m_name;
//            m_name = nullptr;
//        }
//    }
//};
//
//
//void test1(Car car) {
//    
//}
//
//Car test2() {
//    Car car(20, "3");
//    return car;
//}
//
//void testCar() {
//    Car car1(100, "bmw"); //  Car(int price, const char *name)
//    test1(car1); // Car(const Car &car)
//    
//    Car car2 = test2(); // Car(const Car &car)
//    
//    Car car3(30, "3");//  Car(int price, const char *name)
//    car3 = test2(); // Car(const Car &car)
//
//}
