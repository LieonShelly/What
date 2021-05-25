//
//  AStack.hpp
//  C++Demo
//
//  Created by lieon on 2021/1/11.
//  Copyright © 2021 lieon. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp
#include "ArrayList.hpp"
#include <stdio.h>

template<class E>
class AStack {
    ArrayList<E> *list { nullptr };
    
public:
    AStack() {
        list = new ArrayList<E>();
    }
    
    ~AStack() {
        if (list != nullptr) {
            delete list;
            list = nullptr;
        }
    }
    
    E top() {
        if (list->m_size > 0) {
            return list->get(list->m_size - 1);
        }
        return NULL;
    }
    
    void push(const E &element) {
        list->add(element);
    }
    
    E pop() {
        return list->removeAt(list->m_size - 1);
    }
    
    bool isEmpty() {
        return list->isEmpty();
    }
    
    void clear() {
        list->clear();
    }
    
    void printAll() {
        for (int i = 0; i < list->m_size; i++) {
            std::cout << list->get(i) << "\n" << std::endl;
        }
    }
    
};

#endif /* Stack_hpp */
