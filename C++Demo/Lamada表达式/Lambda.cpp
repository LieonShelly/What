//
//  Lambda表达式.cpp
//  C++Demo
//
//  Created by lieon on 2020/11/10.
//  Copyright © 2020 lieon. All rights reserved.
//

#include "Lambda.hpp"
#include <iostream>

/**
 # Lambda表达式
  - 有点类似于JavaScript中的闭包，iOS中的Block， 本质就是函数
  - 完整结构: [capture list](param list)mutable exception-> return type { function body }
    - capture list: 捕获外部变量列表
    - param list：形参列表，不能使用默认参数，不能省略参数名
    - mutable: 用来说明是否可以修改捕获的变量
    - exception: 异常设定
    - return type：返回值类型
    - function body: 函数体
  - 有时可以省略部分结构
    - [capture list](param list)-> return type { function body }
    - [capture list](param list) { function body }
    - [capture list] { function body }
 ```C++
 
 int (*p1)(int, int) = [](int v1, int v2) -> int {
     return  v1 + v2;
 };

 auto p2 = [](int v1, int v2) {
     return v1 + v2;
 };

 auto p3 = [](int v1, int v2) {
     return v1 - v2;
 }(20, 30);


 int exec(int a, int b, int(*func)(int, int)) {
     if (func == nullptr) {
         return 0;
     }
     return func(a, b);
 }
 ```
 - Lambda表达式 外部变量捕获
    ```C++
     int a = 10;
     int b = 20;
     // 值捕获
     auto func1 = [a, b] {
         std::cout<< a << std::endl;
         std::cout<< b << std::endl;
     };
     a = 11;
     b = 30;
     func1(); // 10, 20
    ```
    ```C++
     int a = 10;
     int b = 20;
     // 隐式捕获
     auto func2 = [=] {
         std::cout<< a << std::endl;
         std::cout<< b << std::endl;
     };
     a = 11;
     b = 30;
     func2(); // 10, 20
     ```
     ```C++
     int a = 10;
     int b = 20;
     // a是值捕获，其余变量是地址捕获
     auto func3 = [&, a] {
         std::cout<< a << std::endl;
         std::cout<< b << std::endl;
     };
     a = 11;
     b = 30;
     func3(); // 30, 10
     ```
     ```C++
     int a = 10;
     int b = 20;
     // a 是引用捕获，b是值捕获
     auto func4 = [&a, b] {
         std::cout<< a << std::endl;
         std::cout<< b << std::endl;
     };
     a = 11;
     b = 30;
     func4(); // 11, 20
     ```
     ```C++
     int a = 10;
     int b = 20;
     // 隐式捕获（地址捕获）
     auto func5 = [&] {
         std::cout<< a << std::endl;
         std::cout<< b << std::endl;
     };
     a = 11;
     b = 30;
     func5(); // 11, 30
     ```
     ```C++
     int a = 10;
     int b = 20;
     // a是地址捕获，其余变量是值捕获
     auto func6 = [=, &a] {
         std::cout<< a << std::endl;
         std::cout<< b << std::endl;
     };
     a = 11;
     b = 30;
     func6(); // 20, 11
    ```
 
 - Lambda 表达式 mutable
     ```C++
     int a = 10;
     auto func = [a]() mutable {
         std::cout << ++a << std::endl;
     };
     func(); // 11
     std::cout << a << std::endl; // 10
     ```
 */


int (*p1)(int, int) = [](int v1, int v2) -> int {
    return  v1 + v2;
};

auto p2 = [](int v1, int v2) {
    return v1 + v2;
};

auto p3 = [](int v1, int v2) {
    return v1 - v2;
}(20, 30);


int exec(int a, int b, int(*func)(int, int)) {
    if (func == nullptr) {
        return 0;
    }
    return func(a, b);
}

void testLambda() {
    int a = 10;
    int b = 20;
    // 值捕获
    auto func1 = [a, b] {
        std::cout<< a << std::endl;
        std::cout<< b << std::endl;
    };
    a = 11;
    b = 30;
    func1(); // 10, 20
    
    // 隐式捕获
    auto func2 = [=] {
        std::cout<< a << std::endl;
        std::cout<< b << std::endl;
    };
    a = 11;
    b = 30;
    func2(); // 10, 20
    
    // a是值捕获，其余变量是地址捕获
    auto func3 = [&, a] {
        std::cout<< a << std::endl;
        std::cout<< b << std::endl;
    };
    a = 11;
    b = 30;
    func3(); // 10, 40
    
    // a 是引用捕获，b是值捕获
    auto func4 = [&a, b] {
        std::cout<< a << std::endl;
        std::cout<< b << std::endl;
    };
    a = 11;
    b = 30;
    func4(); // 11, 20
    
    // 隐式捕获（地址捕获）
    auto func5 = [&] {
        std::cout<< a << std::endl;
        std::cout<< b << std::endl;
    };
    a = 11;
    b = 30;
    func5(); // 11, 30
    
    // a是地址捕获，其余变量是值捕获
    auto func6 = [=, &a] {
        std::cout<< a << std::endl;
        std::cout<< b << std::endl;
    };
    a = 11;
    b = 30;
    func6(); // 30, 11
    
}

void testMutable() {
    int a = 10;
    auto func = [a]() mutable {
        std::cout << ++a << std::endl;
    };
    func(); // 11
    std::cout << a << std::endl; // 10
}
