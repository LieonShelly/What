//
//  Command.hpp
//  C++Demo
//
//  Created by lieon on 2021/6/9.
//  Copyright © 2021 lieon. All rights reserved.
//

#ifndef Command_hpp
#define Command_hpp

#include <stdio.h>

#endif /* Command_hpp */
/**
 【例1】用命令模式实现客户去餐馆吃早餐的实例。
 
 分析：客户去餐馆可选择的早餐有肠粉、河粉和馄饨等，客户可向服务员选择以上早餐中的若干种，服务员将客户的请求交给相关的厨师去做。这里的点早餐相当于“命令”，服务员相当于“调用者”，厨师相当于“接收者”，所以用命令模式实现比较合适。
 首先，定义一个早餐类（Breakfast），它是抽象命令类，有抽象方法 cooking()，说明要做什么；
 再定义其子类肠粉类（ChangFen）、馄饨类（HunTun）和河粉类（HeFen），它们是具体命令类，实现早餐类的 cooking() 方法，但它们不会具体做，而是交给具体的厨师去做；
 具体厨师类有肠粉厨师（ChangFenChef）、馄饨厨师（HunTunChef）和河粉厨师（HeFenChef），他们是命令的接收者。
 */

// 抽象命令
class BreakFast {
    
public:
    virtual void cooking() = 0;
};
// 接收者
class ChanfenChief {
        
    
public:
    void cooking() {
        
    }
};

// 具体命令
class Chanfen: public BreakFast {
private:
    ChanfenChief *m_reciever = nullptr;
public:
    void cooking() override {
        m_reciever->cooking();
    }
};

// 接收者
class HundunChief {

public:
    void cooking() {
        
    }
};

// 具体命令
class Hundun: public BreakFast {
private:
    HundunChief *m_reciever = nullptr;
public:
    void cooking() override {
        m_reciever->cooking();
    }
};

/// 调用者：执行命令
class Waiter {
    Hundun * m_hundun = nullptr;
    Chanfen * m_chanfen = nullptr;
    
public:
    void chooseHundun() {
        m_hundun->cooking();
    }
    
    void chooseChanfen() {
        m_chanfen->cooking();
    }
};
