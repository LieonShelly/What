//
//  STL.cpp
//  C++Demo
//
//  Created by lieon on 2020/11/23.
//  Copyright © 2020 lieon. All rights reserved.
//

#include "STL.hpp"
#include <iostream>
#include <vector>
using namespace std;

class Person {
public:
    int  m_age = 0;
    Person(int age):m_age(age) {}
};

void testVector() {
    // 容器
    std::vector<int> v;
    // 插入元素
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);

    // 遍历元素
    vector<int>::iterator itBegin = v.begin(); // 起始迭代器
    vector<int>::iterator itEnd = v.end();// 结束迭代器
    while (itBegin != itEnd) {
        cout << *itBegin << endl;
        itBegin++;
    }
    
    vector<Person> vp;
    vp.push_back(Person(10));
    vp.push_back(Person(10));
    vp.push_back(Person(10));
    vp.push_back(Person(10));
    for(vector<Person>::iterator it = vp.begin(); it != vp.end(); it++) {
        cout << (*it).m_age << endl;
    }
    vector<Person*> vpp;
    vpp.push_back(new Person(10));
    vpp.push_back(new Person(10));
    for (vector<Person*>::iterator it = vpp.begin(); it != vpp.end(); it++) {
        cout << (*it)->m_age << endl;
    }
    

}

/**
 # String容器
 */
void testString() {
    string str;
    string str2(str);
    string str3 = "abs";
    string str4(10, 'a');
}
