//
//  NameSpace.cpp
//  C++Demo
//
//  Created by lieon on 2020/10/15.
//  Copyright © 2020 lieon. All rights reserved.
//

#include "NameSpace.hpp"

void test() {
    
}


namespace Lieon {
    namespace SS {
        int g_no;
        class Person {
            
        };
        void test121() {
        }
    }
        
    void test1231() {
        
    }
}

void test1233() {
    test();
    ::test();
    Lieon::SS::g_no = 30;
    using namespace Lieon;
    SS::g_no = 30;
    
    using namespace Lieon::SS;
    g_no = 40;
}
