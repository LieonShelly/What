//
//  AbstractList.hpp
//  C++Demo
//
//  Created by lieon on 2021/1/5.
//  Copyright © 2021 lieon. All rights reserved.
//

#ifndef AbstractList_hpp
#define AbstractList_hpp
#include "List.hpp"
#include <stdio.h>
#include <string>
template<typename Element>
class AbstractList: public List<Element> {
public:
    AbstractList() {
        m_size = 0;
    }
    ~AbstractList() {
        
    }
    virtual void add(const Element &element) override {
        this->insert(m_size, element);
    }
    struct Enum {
        enum {
            ELEMENT_NOT_FOUND = -1
        };
    };
protected:
  
    int m_size = 0;
    
    virtual int getSize() override {
        return m_size;
    }
    
    virtual bool isEmpty() override {
        return m_size > 0;
    }
    
    virtual bool contains(const Element &element) override {
        return this->indexOf(element) != Enum::ELEMENT_NOT_FOUND;
    }
    
  
    virtual void outOfBounds(int index) {
        throw std::string("Index: %d Size: %d outOfBounds", index, m_size);
    }
    
    virtual void rangeCheck(int index) {
        if (index < 0 || index >= m_size) {
            outOfBounds(index);
        }
    }
    
    virtual void  rangeCheckForAdd(int index) {
        if (index < 0 || index > m_size) {
            outOfBounds(index);
        }
    }
};

#endif /* AbstractList_hpp */
