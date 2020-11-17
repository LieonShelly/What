//
//  SuperPoiner.cpp
//  C++Demo
//
//  Created by lieon on 2020/10/30.
//  Copyright © 2020 lieon. All rights reserved.
//

#include "SuperPoiner.hpp"

/**
 # 父类指针、子类指针
 父类指针可以指向子类对象，是安全的（继承方式必须是public）
 子类指针指父类对象是不安全的
 ```C++
 class Person {
 public:
     int m_age;
 };

 class Student : public Person {
 public:
     int m_score;
 };

 void test() {
     Person *person = new Student();
     // 可以访问m_score， m_age; 安全
     person->m_age = 10;
     
     Student *stu = (Student*)new Person();
     // 访问不到 m_score， 不安全
     stu->m_score = 10;
 }

 ```
 */

class Person {
public:
    int m_age;
};

class Student : public Person {
public:
    int m_score;
};

void test1d() {
    Person *person = new Student();
    // 可以访问m_score， m_age; 安全
    person->m_age = 10;
    
    Student *stu = (Student*)new Person();
    // 访问不到 m_score， 不安全
    stu->m_score = 10;
}
