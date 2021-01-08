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

int main( int argc, char** argv ) {
    DoubleLinkedList<int> *list = new DoubleLinkedList<int>();
    list->add(0);
    list->add(1);
    list->add(2);
    list->add(3);
    list->add(4);
    list->add(5);
    list->add(6);
    list->add(7);
    
    list->removeAt(0);
    
    DoubleNode<int> *node = list->first;
    while (node != nullptr) {
        cout << node->element << endl;
        node = node->next;
    }
    return 0;
}
