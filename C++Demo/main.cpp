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
    LinkedList<int> *list = new LinkedList<int>();
    for (int index = 1 ; index < 11; index++) {
        list->add(index);
    }
    Node<int> *node = list->reverseList();
    bool has = list->hasCycle();
    cout << has << endl;
    while (node != nullptr) {
        cout << node->element << endl;
        node = node->next;
    }
    return 0;
}
