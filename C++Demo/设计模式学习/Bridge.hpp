//
//  Bridge.hpp
//  C++Demo
//
//  Created by lieon on 2021/5/30.
//  Copyright © 2021 lieon. All rights reserved.
//

#ifndef Bridge_hpp
#define Bridge_hpp

#include <stdio.h>
#include <string>
using namespace std;

class Color {
public:
    virtual string getColor();
};

class Bag {
public:
    Color *color = nullptr;
    
    virtual void setColor(Color *color) {
        this->color = color;
    }
    
    virtual string getName() {
        return "bag";
    }
    
    virtual ~Bag() {
        delete color;
        color = nullptr;
    }
};

class Yellow: public Color {
    
    string getColor() override {
        return  "Yelloow";
    }
};

class Red: public Color {
    
    string getColor() override {
        return  "Red";
    }
};

class HandBag: public Bag {
    string getName() override {
        return "HandBag";
    }
};

class Wallet: public Bag {
    string getName() override {
        return "Wallet";
    }
};


class BagManage {
    void test() {
        Wallet().setColor(new Red());
        HandBag().setColor(new Yellow());
    }
};
#endif /* Bridge_hpp */
