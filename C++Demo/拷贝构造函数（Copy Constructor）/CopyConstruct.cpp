//
//  CopyConstruct.cpp
//  C++Demo
//
//  Created by lieon on 2020/11/8.
//  Copyright © 2020 lieon. All rights reserved.
//

#include "CopyConstruct.hpp"
/**
 # 拷贝构造函数
- 拷贝构造函数是一种构造函数
- 当利用已存在的对象创建一个新的对象时（类似于拷贝），就会调用新对象的拷贝构造函数进行初始化
- 拷贝构造函数的格式固定的，接收一个const引用作为参数
 
 ```C++
 class Car {
     int m_price;
     int m_length;
     
 public:
     
     Car(int price, int length = 0): m_price(price), m_length(length) {}
     
     Car(const Car &car) {
         m_price = car.m_price;
         m_length = car.m_length;
     }
 };
 ```
 ## 调用父类的拷贝函数
 
 ```C++
 class Person {
     int m_age;
     
 public:
     Person(int age = 0): m_age(age) {}
     
     Person(const Person &person): m_age(person.m_age) {}
 };

 class Student: public Person {
     int m_score;
     
 public:
     Student(int age = 0, int score = 0): Person(age), m_score(score) { }
     Student(const Student &student): Person(student), m_score(student.m_score) { }
 };

 ```
 
 ```C++
 void test() {
     Car car1(10);
     Car car2(100, 5);
     
     // 利用car2对象创建car3对象，会调用car3对象的拷贝构造函数进行初始化
     Car car3(car2);
     
     Car car4 = car2; // 等价于 Car car4(car2)
     
     Car car5(100, 100);
     Car car6;
     // 这里复制操作，直接将car5的8个字节数据拷贝到car3的8个字节
     // 但是这个并不会创建新对象，所以不会调用拷贝函数
     car6 = car5;
     car6.m_length = car5.m_length;
     car6.m_price = car5.m_price;
 }

 ```
 */
//
//class Car {
//public:
//    int m_price;
//    int m_length;
//    Car(int price = 0, int length = 0): m_price(price), m_length(length) {}
//    
//    Car(const Car &car) {
//        m_price = car.m_price;
//        m_length = car.m_length;
//    }
//};
//
//class Person {
//    int m_age;
//    
//public:
//    Person(int age = 0): m_age(age) {}
//    
//    Person(const Person &person): m_age(person.m_age) {}
//};
//
//class Student: public Person {
//    int m_score;
//    
//public:
//    Student(int age = 0, int score = 0): Person(age), m_score(score) { }
//    Student(const Student &student): Person(student), m_score(student.m_score) { }
//};
//
//
//void test() {
//    Car car1(10);
//    Car car2(100, 5);
//    
//    // 利用car2对象创建car3对象，会调用car3对象的拷贝构造函数进行初始化
//    Car car3(car2);
//    
//    Car car4 = car2; // 等价于 Car car4(car2)
//    
//    Car car5(100, 100);
//    Car car6;
//    // 这里复制操作，直接将car5的8个字节数据拷贝到car3的8个字节
//    // 但是这个并不会创建新对象，所以不会调用拷贝函数
//    car6 = car5;
//    car6.m_length = car5.m_length;
//    car6.m_price = car5.m_price;
//}
