//
//  Fuzadu.cpp
//  C++Demo
//
//  Created by lieon on 2021/1/2.
//  Copyright © 2021 lieon. All rights reserved.
//

#include "Fuzadu.hpp"

int fib1(int n) {
    if (n <= 1) {
        return n;
    }
    return  fib1(n - 1) + fib1(n - 2);
}

int fib2(int n) {
    int first = 0;
    int second = 1;
    for (int i = 0; i < n - 1; i++) {
        int sum = first + second;
        first = second;
        second = sum;
    }
    return second;
}


