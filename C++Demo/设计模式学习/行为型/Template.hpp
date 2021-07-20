//
//  Template.hpp
//  C++Demo
//
//  Created by lieon on 2021/6/2.
//  Copyright © 2021 lieon. All rights reserved.
//

#ifndef Template_hpp
#define Template_hpp

#include <stdio.h>

// 抽象类
class AbstractClass {
public:
    virtual  void method() {
        specificMethod1();
        specificMethod2();
    }
    
    virtual void specificMethod1() {
        
    }
    
    virtual void specificMethod2() {
        
    }
};

// 具体子类
class ConcreteClass: public AbstractClass {
    void specificMethod1() override {
        printf("specificMethod1");
    }
    
    void specificMethod2() override {
        printf("specificMethod2");
    }
};
#endif /* Template_hpp */
