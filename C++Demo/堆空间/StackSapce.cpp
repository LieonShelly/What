//
//  StackSapce.cpp
//  C++Demo
//
//  Created by lieon on 2020/10/14.
//  Copyright © 2020 lieon. All rights reserved.
//

#include "StackSapce.hpp"
#include <iostream>
using namespace std;

void test23() {
    // 申请4个字节的堆空间内存
    int *p = (int*)malloc(4);
    
    char *p1 = (char*)malloc(4);
    *p1 = 1;
    *(p1 + 1) = 2;
    p1[0] = 1;
    p1[1] = 2;
}

void test2() {
    int *p = new int;
    int *p2 = new int;
    
    delete p;
    delete p2;
}

void test3() {
    int * p = (int *)malloc(sizeof(int));
    p[0] = 10;
    p[1] = 10;
    p[2] = 10;
    p[3] = 10;
    free(p);
    
    int *p1 = new int[10];
    p1[0] = 30;
    p1[8] = 20;
    cout<< *p1 << " - " << p1[8] << endl;
    delete[] p1;
}

void test4() {
    int size = sizeof(int);
    int *p = (int*)malloc(size);
    memset(p, 0, size);
    cout << *p << endl;
    free(p);
}

void test6() {
    int *p1 = new int;
    // 初始化为0
    int *p2 = new int();
    //  初始化为5
    int *p3 = new int(5);
    // 没有初始化
    int *p4 = new int[3];
    // 全部元素初始化为0
    int *p5 = new int[3]();
    // 全部元素初始化为0
    int *p6 = new int[3]{};
    // 首元素初始化为5，其他元素初始化为0
    int *p7 = new int[3] {5 };
    
    cout << *p1 << endl;
    cout << *p2 << endl;
    cout << *p3 << endl;
    cout << *p4 << endl;
}

struct Person {
    int m_age;
    float m_height;
    string m_desc;
    
    Person() {
        
    }
};

//Person g_person;

void test7() {
    Person person;
    /// 调无参构造函数，如果没有实现无参构造函数，就会默认生成一个， 数值型的成员初始化为0（在windwos上直接显示没有初始化）
    int a = 3;
    int *pi = &a;
    Person *p = new Person();
    /// 调无参构造函数
    Person *p1 = new Person;
    cout << p -> m_height << endl;
    cout << p1 -> m_height << endl;
//    cout << g_person.m_desc.size() << endl;
    // 指针的值
    cout << pi << endl;
    /// 变量的地址
    cout << &a << endl;
    // 指针的地址
    cout << &pi << endl;
    // 指针变量指向的变量的值
    cout << *pi << endl;
    cout << a << endl;
    delete p;
}

