//
//  Stock00.hpp
//  C++Demo
//
//  Created by lieon on 2020/6/11.
//  Copyright © 2020 lieon. All rights reserved.
//

#ifndef Stock00_hpp
#define Stock00_hpp

#include <stdio.h>

#include <string>

class Stock {
private:
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot() {
        total_val = shares * share_val;
    }
public:
    void acquire(const std::string &co, long n, double pr);
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show();
    Stock();
    Stock(const std::string &co, long n, double pr);
    ~Stock();
};

class World {
    float mass;
    char name[20];
public:
    void tellall();
};
#endif /* Stock00_hpp */
