//
//  Strategy.hpp
//  C++Demo
//
//  Created by lieon on 2021/6/2.
//  Copyright © 2021 lieon. All rights reserved.
//  策略模式

#ifndef Strategy_hpp
#define Strategy_hpp

#include <stdio.h>
// 抽象策略类
struct Strategy {
    virtual void strategyMethod() = 0;
};

// 具体策略A
struct ConcreteStrayA: public Strategy {
    
    void strategyMethod() override {
        
    }
};

// 具体策略B
struct ConcreteStrayB: public Strategy {
    
    void strategyMethod() override {
        
    }
};

// 环境类
struct Context {
private:
    Strategy *m_strategy = nullptr;
public:
    void strategyMethod() {
        m_strategy->strategyMethod();
    }
};



#endif /* Strategy_hpp */
