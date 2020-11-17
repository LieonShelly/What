//
//  Inherience.cpp
//  C++Demo
//
//  Created by lieon on 2020/10/15.
//  Copyright © 2020 lieon. All rights reserved.
//

#include "Inherience.hpp"

struct Person {
    int m_age;
};

struct Student: Person {
    int m_no;
};

struct GoodStudent: Student {
    int m_money;
};


