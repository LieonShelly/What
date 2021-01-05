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
    List();
    virtual ~List();
    virtual void clear();
    virtual int getSize();
    virtual bool contains(Element element);
    virtual void add(Element element);
    virtual void insert(int index, Element element);
    virtual Element get(int index);
    virtual int indexOf(Element element);
    virtual int removeAt(int index);
};

#endif /* List_hpp */
