//
//  MultiInheritence.cpp
//  C++Demo
//
//  Created by lieon on 2020/11/2.
//  Copyright © 2020 lieon. All rights reserved.
//

#include "MultiInheritence.hpp"
#include <iostream>
using  namespace::std;
/**
 # 多继承
 ## C++允许一个类可以有多个父类
 ```C++
 class Student {
 public:
     int m_score;
     
     void study() {
        cout << "Student::study" << endl;
     }
 };

 class Workder {
 public:
     int m_salary;
     
     void work() {
         cout << "Workder::work" << endl;
     }
 };

 class Undergraduate: public Student, public Workder {
 public:
     int m_grade;
     
     void play() {
         cout << "Undergraduate::play" << endl;
     }
 };

 ## 多继承体系下的构造函数调用
 ```C++
 class Undergraduate: public Student, public Workder {
 public:
     int m_grade;
     
     Undergraduate(int grade, int score, int salary): Student(score), Workder(salary) {
         m_grade = grade;
     }
 };

 ```
 
 ## 多继承-虚函数
 - 如果子类继承多个父类都有虚函数，那么子类对象就会产生对应的多张虚表
 
## 同名函数，同名成员变量
 
 ```C++
 
 
 class Student {
 public:
     int m_score;
     int m_age;
 };

 class Workder {
 public:
     int m_salary;
     int m_age;
 };

 class Undergraduate: public Student, public Workder {
 public:
     int m_grade;
     int m_age;
     Undergraduate(int grade, int score, int salary): Student(score), Workder(salary) {
         m_grade = grade;
     }
 };
 
 void test() {
     Undergraduate ug(10, 10, 1);
     ug.Student::eat();
     ug.Workder::eat();
     ug.eat();
     
     ug.Student::m_age = 29;
     ug.Workder::m_age = 29;
     ug.m_age = 29;
 }
 ```
 
 ## 菱形继承
 - 菱形继承带来的问题
    - 最低下子类从基类继承的成员变量冗余，重复
    - 最低子类无法访问基类的成员，有二义性
 
 ```C++
     class Person {
         int m_age;
     };

     class Student: public Person {
     public:
         int m_score;
     };

     class Workder: public Person {
     public:
         int m_salary;
     };

     class Undergraduate: public Student, public Workder {
     public:
         int m_grade;
     };
 ```
 
 ## 虚继承
 - 虚继承可以解决菱形继承问题
 - Person称为**虚基类**
 - Workder的虚表存储的内容有
    - 虚表指针与本类起始的偏移量（一般是0）
    - 虚基类第一个成员与本类起始的偏移量
 
 ```c++
 class Student: virtual public Person {
 public:
     int m_score;
 };

 class Workder: virtual public Person {
 public:
     int m_salary;
 };
 
class Undergraduate: public Student, public Workder {
 public:
     int m_grade;
 };

 ```
 */

class Person {
    int m_age;
};

class Student: virtual public Person {
public:
    int m_score;
};

class Workder: virtual public Person {
public:
    int m_salary;
};

class Undergraduate: public Student, public Workder {
public:
    int m_grade;
};


