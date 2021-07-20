//
//  Flyweight.hpp
//  C++Demo
//
//  Created by lieon on 2021/6/1.
//  Copyright © 2021 lieon. All rights reserved.
//

#ifndef Flyweight_hpp
#define Flyweight_hpp
#include <map>
#include <string>
#include <stdio.h>

// 非享元角色
class UnsharedConcreteFlywieght {
    
};

// 抽象享元角色
class Flyweight {
    
public:
    virtual void operation(UnsharedConcreteFlywieght state);
};

// 具体享元角色
class ConcreteFlyweight: public Flyweight {
    
public:
    ConcreteFlyweight(std::string key) {
        
    }
    
    void operation(UnsharedConcreteFlywieght state) override {
        
    }
};

// 享元工厂角色
class FlyweightFactory {
private:
    std::map<std::string, Flyweight*> maps;
    
public:
    Flyweight* getFlyweight(std::string key) {
        Flyweight* flyweight = maps.at(key);
        if (flyweight == nullptr) {
            flyweight = new ConcreteFlyweight(key);
            maps[key] = flyweight;
        } else {
            
        }
        return flyweight;
    }
};

class FlyweightTest {
    void test() {
        FlyweightFactory *facotry = new FlyweightFactory();
        facotry->getFlyweight("a");
        facotry->getFlyweight("a");
        facotry->getFlyweight("b");
        facotry->getFlyweight("key");
    }
};

#endif /* Flyweight_hpp */
