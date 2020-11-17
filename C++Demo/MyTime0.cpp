//
//  MyTime0.cpp
//  C++Demo
//
//  Created by lieon on 2020/6/12.
//  Copyright © 2020 lieon. All rights reserved.
//

#include "MyTime0.hpp"

Time::Time() {
    hours = minutes = 0;
}

Time::Time(int h, int m) {
    hours = h;
    minutes = m;
}

void Time::addMin(int m) {
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

void Time::addHr(int h) {
    hours = h;
}

void Time::reset(int h, int m) {
    hours = h;
    minutes = m;
}

// 加法
Time Time::operator +(const Time &t) const {
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

void Time::show() const {
    std::cout << "hours " << hours;
}
