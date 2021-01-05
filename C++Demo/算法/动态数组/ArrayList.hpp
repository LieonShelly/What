//
//  ArrayList.hpp
//  C++Demo
//
//  Created by lieon on 2021/1/3.
//  Copyright © 2021 lieon. All rights reserved.
//

#ifndef ArrayList_hpp
#define ArrayList_hpp

#include <iostream>
using namespace std;

template<class Item>
class ArrayList {
    
private:
    int m_size = 0;
    Item *m_elements { nullptr };
    
    void ensureCapacity(int capacity) {
        int oldCap = m_size;
        if (oldCap >= capacity) {
            return;
        }
        int newCap = oldCap + (oldCap >> 1);
        Item *newElements = new Item[newCap];
        for (int index = 0; index < m_size; index++) {
            newElements[index] = m_elements[index];
        }
        m_elements = newElements;
    }
    
public:
    ArrayList(int capacity = 100) {
        ensureCapacity(capacity);
    }
    
    ~ArrayList() {
        delete[] m_elements;
        m_elements = nullptr;
    }
    
    void clear() {
        delete[] m_elements;
        m_size = 0;
    }
    
    int getSize() {
        return m_size;
    }
    
    bool contains(Item element) {
        return indexOf(element) != -1;
    }
    
    void add(Item element) {
        insert(m_size, element);
    }
    
    void insert(int index, Item element) {
        if (index < 0 || index > m_size) {
            throw "Out of bounds, index:" + std::string("%ld", index);
        }
        for (int i = m_size - 1; i > index; i--) {
            m_elements[i + 1] = m_elements[i];
        }
        m_elements[index] = element;
        m_size++;
    }
    
    Item get(int index) {
        if (index > m_size) {
            throw "Out of bounds";
        }
        return m_elements[index];
    }
    
    int indexOf(Item element) {
        for (int i = 0; i < m_size; i++) {
            if (element == m_elements[i]) {
                return i;
            }
        }
        return -1;
    }
    
    int removeAt(int index) {
        if (index < 0 || index >= m_size) {
            throw "Out of bounds";
        }
        int old = get(index);
        for (int i = index + 1; i < m_size; i++) {
            m_elements[i - 1] = m_elements[i];
        }
        m_elements[--m_size] = nullptr;
        return old;
    }
};


#endif /* ArrayList_hpp */
