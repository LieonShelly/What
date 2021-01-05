//
//  main.cpp
//  C++Demo
//
//  Created by lieon on 2020/6/2.
//  Copyright © 2020 lieon. All rights reserved.
//

#include <iostream>
#include "LinkedList.hpp"
#include <vector>

using namespace std;

class TestPerson {
public:
    int m_age = 0;
public:
    TestPerson(int age): m_age(age) {}
    
    virtual ~TestPerson() {
        std::cout << "~TestPerson" << std::endl;
    }
    void virtual eatTest() = 0;
};

class TestStudent: public TestPerson {
public:
    TestStudent(): TestPerson(10) {
        
    }
    void eatTest() override {
        cout << "TestStudent::eat" << endl;
    }
};


class TestGraduate: public TestStudent {
public:
    TestGraduate()  {
        
    }
    
    void eatTest() override {
        cout << "TestGraduate::eat" << endl;
    }
};

int main( int argc, char** argv ) {
    LinkedList<TestGraduate> *list = new LinkedList<TestGraduate>();
//    for (int index = 0 ; index < 11; index++) {
//        list->add(TestGraduate());
//    }
    list->add(TestGraduate());
//    int deleteIndex = 2;
    cout << list->get(0).m_age << endl;
//    list->removeAt(deleteIndex);
//    cout << list->get(deleteIndex) << endl;
    return 0;
}
