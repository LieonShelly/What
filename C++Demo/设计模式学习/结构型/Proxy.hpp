//
//  Proxy.hpp
//  C++Demo
//
//  Created by lieon on 2021/5/30.
//  Copyright © 2021 lieon. All rights reserved.
//  代理模式

#ifndef Proxy_hpp
#define Proxy_hpp

#include <stdio.h>

// 抽象主题
class Subject {
public:
    virtual void request() = 0;
};

// 真实主题
class RealSubject: public Subject {
public:
    void request() override {
        printf("--RealSubject - request --");
    }
};

// 代理类：不直接使用RealObject访问，而是通过Proxy类间接访问
class Proxy: public Subject {
    RealSubject * m_subject = nullptr;
public:
    void request() override {
        m_subject->request();
    }
};

class Proxyytest {
    void test() {
        // 不直接使用RealObject调用request，而是通过Proxy类间接访问
        Proxy *proxy = new Proxy();
        proxy->request();
    }
};
#endif /* Proxy_hpp */
