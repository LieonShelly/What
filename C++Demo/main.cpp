//
//  main.cpp
//  C++Demo
//
//  Created by lieon on 2020/6/2.
//  Copyright © 2020 lieon. All rights reserved.
//

#include <iostream>
#include "LinkedList.hpp"
#include "DoubleLinkedList.hpp"
#include <vector>
#include "ArrayList.hpp"
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

#include "SingleCycleLinkedList.hpp"

int main( int argc, char** argv ) {
    SingleCycleLinkedList<int> *list = new SingleCycleLinkedList<int>();
    list->add(0);
    list->add(1);
    list->add(2);
    list->add(3);
    list->add(4);
    list->add(5);
    list->add(6);
    list->add(7);

//    list->insert(0, 111);
//    list->insert(4, 444);
//    list->add(8);
    
//    list->removeAt(6);
//    list->removeAt(3);
    list->printAll();
    cout << "------------" << endl;
    return 0;
}
