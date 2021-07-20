//
//  FacadePattern.hpp
//  C++Demo
//
//  Created by lieon on 2021/6/1.
//  Copyright © 2021 lieon. All rights reserved.
//

#ifndef FacadePattern_hpp
#define FacadePattern_hpp

#include <stdio.h>

// 子系统
struct SubSystem01 {
  
    void method1() {
        
    }
};

// 子系统
struct SubSystem02 {
  
    void method2() {
        
    }
};
// 子系统
struct SubSystem03 {
  
    void method2() {
        
    }
};


// 外观角色
class Facade {
    
public:
    void method() {
        SubSystem01 sub01;
        SubSystem02 sub02;
        SubSystem03 sub03;
        sub01.method1();
        sub02.method2();
    }
};

#endif /* FacadePattern_hpp */
