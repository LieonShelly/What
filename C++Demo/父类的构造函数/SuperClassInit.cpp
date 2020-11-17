//
//  SuperClassInit.cpp
//  C++Demo
//
//  Created by lieon on 2020/10/30.
//  Copyright © 2020 lieon. All rights reserved.
//

#include "SuperClassInit.hpp"

/**
 # 父类的构造函数
 - 子类的构造函数默认会调用父类的无参构造函数
 - 如果子类的构造函数显示地调用了父类的有惨构造函数，就不会再去默认调用父类的无参构造函数
 - 如果父类缺少无参构造函数，子类的构造函数必须显式调用父类的有参构造函数
 
 # 继承体系下的构造函数示例
 ```C++
 struct Person {
     int m_age;
     
     Person(): Person(0) {}
     
     Person(int age): m_age(age) { }
 };


 struct Student: Person {
     int m_no;
     Student(): Student(0, 0) {
         
     }
     
     Student(int age, int no): Person(age), m_no(no) {
         
     }
 };

 ```
 */


struct Person {
    int m_age;
    
    Person(): Person(0) {}
    
    Person(int age): m_age(age) { }
};


struct Student: Person {
    int m_no;
    Student(): Student(0, 0) {
        
    }
    
    Student(int age, int no): Person(age), m_no(no) {
        
    }
};
