//
//  InitList.cpp
//  C++Demo
//
//  Created by lieon on 2020/10/30.
//  Copyright © 2020 lieon. All rights reserved.
//

#include "InitList.hpp"
#include <iostream>

using namespace::std;

int myHeight() {
    cout << "myHeight()" << endl;
    return 180;
}

int myAge() {
    cout << "myAge()" << endl;
    return 30;
}

//struct Person {
//    int m_age;
//    int m_height;
//
//    Person() {
//        this->m_age = 0;
//        this->m_height = 0;
//    }
//
//   /** Person(int age, int height): m_height(height), m_age(m_height) {
//
//    }**/
//
//    Person(int age, int height): m_height(myHeight()), m_age(myAge()) {
//
//    }
//
//
//    void display() {
//        cout << "m_age is " << this->m_age << endl;
//        cout << "m_hqeight is " << this->m_height << endl;
//    }
//};
//

/**
 # 初始化列表
 ## 特点
    - 一种便捷的初始化成员变量的方式
    - 只能在构造函数中
     ```C++
      Person(int age, int height): m_age(age), m_height(height) {
           
       }
     ```
## 初始化列表与默认参数配合使用
    ```C++
     Person(int age = 0, int height = 0): m_age(age),   m_height(height) {
         
     }
    ```
### 如果函数的声明和实现是分离的
    - 初始化列表只能写在函数的实现中
    - 默认参数只能写在函数的声明中
 */
struct Person {
    int m_age;
    int m_height;
    
  /*  Person(int age, int height): m_age(age), m_height(height) {
        
    }
    */
    Person(int age = 0, int height = 0): m_age(age), m_height(height) {
        
    }

    
    Person(): Person(0, 0) {}
    /**
     Person() {
      // 初始化的是一个临时的对象
        Person(0, 0);
     }
     */
};


struct Student: public Person {
    // 调用父类的构造函数
    Student(int age, int height): Person(age, height) {
        
    }
};
