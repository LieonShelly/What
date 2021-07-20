//
//  Observer.hpp
//  C++Demo
//
//  Created by lieon on 2021/6/10.
//  Copyright © 2021 lieon. All rights reserved.
//

#ifndef Observer_hpp
#define Observer_hpp

#include <stdio.h>
#include <vector>
using namespace std;

/**
 【例1】利用观察者模式设计一个程序，分析“人民币汇率”的升值或贬值对进口公司进口产品成本或出口公司的出口产品收入以及公司利润率的影响。

 分析：当“人民币汇率”升值时，进口公司的进口产品成本降低且利润率提升，出口公司的出口产品收入降低且利润率降低；当“人民币汇率”贬值时，进口公司的进口产品成本提升且利润率降低，出口公司的出口产品收入提升且利润率提升
 */
// 抽象观察者
struct Company {
    virtual void response(int number) = 0;
};

struct Rate {
protected:
    vector<Company*> companys;
    
public:
    
    void add(Company *company) {
        companys.push_back(company);
    }
    
    void remove(Company *company) {
        companys.push_back(company);
    }
    
    // 通知方法
    virtual void change(int number) = 0;
};

struct RMBRate: public Rate {
    
    void change(int number) override {
        for (Company * company : companys) {
            company->response(number);
        }
    }
};

// 具体观察者
struct ImportCompany: public Company {
    
    void response(int number) override {
        
    }
};

// 具体观察者
struct ExportCompany: public Company {
    
    void response(int number) override {
        
    }
};

class ObserverTest {
  
    void test() {
        ImportCompany *icmp = new ImportCompany();
        ExportCompany *ecmp = new ExportCompany();
        RMBRate * rate = new RMBRate();
        rate->add(icmp);
        rate->add(ecmp);
        rate->change(3);
    }
};
#endif /* Observer_hpp */
