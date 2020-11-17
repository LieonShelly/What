//
//  PropertyInit.cpp
//  C++Demo
//
//  Created by lieon on 2020/10/15.
//  Copyright © 2020 lieon. All rights reserved.
//

#include "PropertyInit.hpp"

struct Person {
    int m_age;
    
};

void testMemset() {
    int *p = new int();
    // 将每个字节设置为1 0000 0001 0000 0001 0000 0001 0000 0001
    memset(p, 1, 4);
    
    int *pi = (int *)malloc(8);
    // 0000 0000 0000 0000 0000 0000 0000 0101
    *pi = 5;
    free(p);
    cout << *p << endl;
    cout << *pi << endl;
}

// 全局区（成员变量初始化为0）
Person gg_person;

void testInitPerson() {
    // 栈空间（成员变量初始化为0）
    Person person;
    // 堆空间（成员变量初始化为0）
    Person *p1 = new Person;
    Person *p2 = new Person();
    cout << "g_person " << gg_person.m_age << endl;
    cout << "person " << person.m_age << endl;
    cout << "p1 " << p1->m_age << endl;
    cout << "p2 " << p2->m_age << endl;
}
