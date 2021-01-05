//
//  main.cpp
//  C++Demo
//
//  Created by lieon on 2020/6/2.
//  Copyright © 2020 lieon. All rights reserved.
//

#include <iostream>
#include "ArrayList.hpp"
#include <vector>

using namespace std;

class TestPerson {
    int m_age = 0;
public:
    TestPerson(int age): m_age(age) {}
    
    ~TestPerson() {
        std::cout << "~TestPerson" << std::endl;
    }
    
    bool operator==( TestPerson * obj) {
        return m_age == obj->m_age;
    }
};
int main( int argc, char** argv ) {
    ArrayList<TestPerson*> *list = new ArrayList<TestPerson*>();
    TestPerson *person = new TestPerson(10);
    TestPerson *person1 = new TestPerson(11);
    TestPerson *person2 = new TestPerson(13);
    list->add(person);
    list->add(person1);
    list->add(person2);
    int idx = list->indexOf(person2);
    std::cout << idx << std::endl;
    list->clear();
    return 0;
}
