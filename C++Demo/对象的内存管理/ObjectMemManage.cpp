//
//  ObjectMemManage.cpp
//  C++Demo
//
//  Created by lieon on 2020/10/15.
//  Copyright © 2020 lieon. All rights reserved.
//

#include "ObjectMemManage.hpp"
#include <iostream>
using namespace std;

class Person {
    int m_age;
public:
    Person() {
        cout << "Person()" << endl;
        this->m_age = 0;
    }
    
    Person(int age) {
        cout << "Person(int age)" << endl;
        this->m_age = age;
    }
    
    ~Person() {
        cout << "~Person()" << endl;
    }
};

void testManage() {
    Person person;
    
    {
        Person person;
    }
    
    Person *p = new Person();
    delete p;
    
    Person *p1 = (Person*)malloc(sizeof(Person));
    free(p1);
}
