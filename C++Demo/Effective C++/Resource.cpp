//
//  Resource.cpp
//  C++Demo
//
//  Created by lieon on 2020/11/16.
//  Copyright © 2020 lieon. All rights reserved.
//

#include "Resource.hpp"
#include <iostream>


/**
 ## 在资源管理类中小心coping行为
 - 复制RAII（资源取得时机便是初始化时机）对象必须一并复制它所管理的资源，所以资源的copying行为决定RAII对象的copying行为
 - 普遍常见的RAII class copying行为是：抑制copying，施行引用计数法
 ## 在资源管理类中提供原始资源的访问
 - APIs往往要求访问原始资源（raw resource），所以每一个 RAII class应该提供一个“取得其所管理的资源”的方法 （比如智能指针重载了 operator-> ）
 - 对原始资源的访问可能由显式转换或隐式转换。一般而言显式转换比较安全
 ## 成对使用new和delete时要采用相同形式
 -  new -> delete
 - new[] -> delete[]
 ## 以独立语句将newed对象置入智能指针中
 ```C++
 std::shared_ptr<Person> p(new Person); // 以单独语句以存储智能指针存储newed所得对象
 
 ```
 # 设计与声明
 ## 条款18：让接口更容易被正确使用，不易被误用
 - 促进使用的办法包括接口的一致性，以及内置类型的行为兼容
 - 防止误用的方法包括建立新类型，限制类型上的操作，束缚对象值，以及消除客户的资源管理责任
 - shared_ptr支持定制型删除型（custom deleter）。这可防止DLL问题，可被用来自动解除互斥锁等等
 ```C++
 class Date {
 public:
     // 不推荐
     Date(int month, int day, int year) {}
     // 推荐使用
     Date(const Month &month, const Day &d, const Year &y) {}
 };
 ```
 


 */
class Person {
};
void testResource() {
    int age = 10;
    int score = 20;
    int *p = &age;
    const int *p0 = &age;
    int const *p1 = &age;
    int * const p2 = &age;
    const int * const p3 = &age;
    int const * const p4 = &age;

}

struct Day {
    explicit Day(int d) {};
};


struct Month {
    explicit Month(int m) {};
};


struct Year {
    explicit Year(int y) {};
};


class Date {
public:
    // 不推荐
    Date(int month, int day, int year) {}
    // 推荐使用
    Date(const Month &month, const Day &d, const Year &y) {}
};
