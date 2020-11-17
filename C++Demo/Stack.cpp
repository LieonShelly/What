//
//  Stack.cpp
//  C++Demo
//
//  Created by lieon on 2020/6/12.
//  Copyright © 2020 lieon. All rights reserved.
//

#include "Stack.hpp"

Stack::Stack() {
    top = 0;
}

bool Stack::isEmpty() const {
    return top == 0;
}

bool Stack::isfull() const {
    return top == MAX;
}

bool Stack::push(const Item &item) {
    if (top < MAX) {
        this->iiems[top++] = item;
        return true;
    }
    return false;
}

bool Stack::pop(Item &item) {
    if (top > 0) {
        item = this->iiems[--top];
        return true;
    }
    return  false;
}
// *p p &p
