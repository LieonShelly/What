//
//  MyTime0.hpp
//  C++Demo
//
//  Created by lieon on 2020/6/12.
//  Copyright © 2020 lieon. All rights reserved.
//

#ifndef MyTime0_hpp
#define MyTime0_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int h, int m = 0);
    void addMin(int m);
    void addHr(int h);
    void reset(int h = 0, int m = 0);
//    Time sum(const Time &t) const;
    Time operator+(const Time & t) const;
    void show() const;
};

#endif /* MyTime0_hpp */
