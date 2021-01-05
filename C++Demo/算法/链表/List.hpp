//
//  List.hpp
//  C++Demo
//
//  Created by lieon on 2021/1/4.
//  Copyright © 2021 lieon. All rights reserved.
//

#ifndef List_hpp
#define List_hpp

#include <stdio.h>

template<class Element>
class List {
public:
    List() {};
    virtual ~List() {};
    virtual void clear() = 0;
    virtual int getSize() = 0;
    virtual bool contains(const Element &element) = 0;
    virtual void add(const Element &element) = 0;
    virtual void insert(int index, const Element &element) = 0;
    virtual Element& get(int index) = 0;
    virtual int indexOf(const Element &element) = 0;
    virtual Element& removeAt(int index) = 0;
    virtual bool isEmpty() = 0;
    virtual Element& set(int index, const Element &element) = 0;
};

#endif /* List_hpp */
