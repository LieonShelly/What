//
//  Stock00.cpp
//  C++Demo
//
//  Created by lieon on 2020/6/11.
//  Copyright © 2020 lieon. All rights reserved.
//

#include "Stock00.hpp"
#include <iostream>

void Stock::acquire(const std::string &co, long n, double pr) {
    company = co;
    if (n < 0) {
        shares = 0;
    } else {
        shares = n;
        share_val = pr;
        set_tot();
    }
}

void Stock::buy(long num, double price) {
    if (num < 0) {
        std::cout << "Numbers of share purchased can't be negative" << std::endl;
    } else {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price) {
    using namespace std;
    if (num < 0) {
        std::cout << "Numbers of share purchased can't be negative" << std::endl;
    } else if (num > shares) {
        std::cout << "Numbers of share purchased can't be negative" << std::endl;
    } else {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price) {
    share_val = price;
    set_tot();
}

void Stock::show() {
    std::cout << "company:" << company
    <<  "shares:" << shares << "\n"
    <<  "shares price: $:" << share_val
    <<  "total worth: $" << total_val
    << std::endl;
}

Stock::Stock() {
    
}

Stock::~Stock() {
    
}

Stock::Stock(const std::string &co, long n, double pr) {
    company = co;
    if (n < 0) {
        shares = 0;
    } else {
        shares = n;
        share_val = pr;
        set_tot();
    }
}
