//
//  Adapter.hpp
//  C++Demo
//
//  Created by lieon on 2021/5/31.
//  Copyright © 2021 lieon. All rights reserved.
//

#ifndef Adapter_hpp
#define Adapter_hpp

#include <stdio.h>

class Motor {
public:
    virtual void drive() = 0;
};

class ElectricMotor {
public:
    void electricDrive() {
        
    }
};

class OpticalMotor {
public:
    void opticalDrive() {
        
    }
};

class ElecticAdapter: public Motor {
private:
    ElectricMotor *motor = nullptr;
public:
    void drive() override {
        motor->electricDrive();
    }
};


class OpticalAdapter: public Motor {
private:
    OpticalMotor *motor = nullptr;
public:
    void drive() override {
        motor->opticalDrive();
    }
};

class AdapterTest {
public:
    void test() {
        Motor *motor = new OpticalAdapter();
        motor->drive();
    }
};

#endif /* Adapter_hpp */
