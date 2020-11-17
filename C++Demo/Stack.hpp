//
//  Stack.hpp
//  C++Demo
//
//  Created by lieon on 2020/6/12.
//  Copyright © 2020 lieon. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp
typedef unsigned long Item;
#include <stdio.h>
class Stack {
private:
    enum { MAX = 10 };
    Item iiems[MAX];
    int top;
public:
    Stack();
    bool isEmpty() const;
    bool isfull() const;
    bool push(const Item &item);
    bool pop(Item &item);
};

#endif /* Stack_hpp */
