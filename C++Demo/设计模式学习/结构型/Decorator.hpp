//
//  Decorator.hpp
//  C++Demo
//
//  Created by lieon on 2021/6/1.
//  Copyright © 2021 lieon. All rights reserved.
//

#ifndef Decorator_hpp
#define Decorator_hpp

#include <stdio.h>

class Component {
public:
    virtual void operation() = 0;
};

class ConcreteComponent: public Component {
    void operation() override {
        
    }
};

class Decorator: public Component {
public:
    Component *component = nullptr;
    
    void operation() override {
        component->operation();
    }
};

class ConcreteDecorator: public Decorator {
private:
    void addedFunction() {
        
    }
public:
    void operation() override {
        Decorator::operation();
        // 做一些额外的操作
        addedFunction();
    }
    
};

#endif /* Decorator_hpp */
