//
//  LinkedList.hpp
//  C++Demo
//
//  Created by lieon on 2021/1/4.
//  Copyright © 2021 lieon. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp
#include "List.hpp"
#include <stdio.h>
template<typename E>
class LinkedList: public List<E> {
    
    template<typename Element>
    class Node {
        Element element;
        Node<Element> *next { nullptr };
    };
    
private:
    int m_size;
    Node<E> *first { nullptr };
    
public:
    ~LinkedList() {
        
    }
    
    void clear() override {
        
    }
    
    int getSize() override {
        
    }
    
    bool contains(E element) override {
        
    }
    
    void add(E element) override {
        
    }
    
    void insert(int index, E element) override {
        
    }
    
    E get(int index) override {
        return nullptr;
    }
    
    int indexOf(E element) override {
        return 0;
    }
     
    int removeAt(int index) override {
        return 0;
    }
    
};

#endif /* LinkedList_hpp */
