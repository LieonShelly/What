//
//  Others.cpp
//  C++Demo
//
//  Created by lieon on 2020/11/9.
//  Copyright © 2020 lieon. All rights reserved.
//

#include "Others.hpp"
#include <iostream>
using namespace std;

/**
 
 # 类型转换
 - C++中建议使用C++的类型转换符取代C风格的强制类型装换
 - C++中有4个类型转换符: static_cast, dynamin_cast, reinterpret_cast, const_cast
 
 - const_cast: 一般用于去掉const属性，将const转换成非const
    ```C++
     const Person *p1 = new Person();
     // p1->m_age = 20; 错误
     
     Person *p2 = const_cast<Person*>(p1);
     p2->m_age = 20;
    ```
 - dynamic_cast:一般用于多态类型的转换，有运行时安全检测
 
 ```C++
 class Person {
 public:
     int m_age = 0;
     virtual void run() {}
 };

 class Student: public Person { };

 class Car {};
 
 Student *stu1 = dynamic_cast<Student *>(p1); // NULL
 Student *stu2 = dynamic_cast<Student *>(p3);
 Car *car = dynamic_cast<Car *>(p1); // NULL
 ```
 - static_cast
    - 对比dynamic_cast，缺乏运行时安全检测
    - 不能交叉装换（不是统一继承体系的，无法转换）
    - 常用用于基础数据类型的转换，非const转成const
 ```C++
 Student *stu3 = static_cast<Student *>(p1); // NULL
 Student *stu4 = static_cast<Student *>(p3);
 
//    Car *car = static_cast<Car*>(p1); // 错误
 ```
 
- reinterpret_cast
    - 属于比较底层的强制转换，没有任何类型检查和格式转换
    - 可以交叉转换
    - 可以将指针和整数互相转换
 
 ```C++
 Student *stu5 = reinterpret_cast<Student *>(p1);
 Student *stu6 = reinterpret_cast<Student *>(p3);
 
 Car *car1 = reinterpret_cast<Car*>(p1);
 
 int *p = reinterpret_cast<int *>(100);
 int num = reinterpret_cast<long>(p);
 
 int i = 10;
 double d1 = reinterpret_cast<double &>(i);
 ```
 
 # 运算符重载
 - 运算符重载（操作符重载）:可以为运算符增加一些新的功能
 
 ```C++
 
 class Point {
 public:
     int m_x;
     int m_y;
     
     Point(int x, int y);
     Point(const Point &point);
     
     Point operator+(const Point &p1) const;
     Point operator-(const Point &p1) const;
     const Point operator-() const;
     Point &operator+=(const Point &point);
     Point &operator-=(const Point &point);
     bool operator==(const Point &point);
     bool operator!=(const Point &point);
    // 前置递增返回引用
     Point &operator++();
     // 后置递增返回值
     const Point operator++(int);
 };


 Point::Point(int x, int y): m_x(x), m_y(y) {}
 Point::Point(const Point &point): m_x(point.m_x), m_y(point.m_y) {}

 // 前++: 先加再用
 Point &Point::operator++() {
     m_x++;
     m_y++;
     return *this;
 }

 // 后++：先用再加
 const Point Point::operator++(int) {
     Point point(m_x, m_y);
     m_x++;
     m_y++;
     return point;
 }

 Point Point::operator+(const Point &point) const {
     return Point(m_x + point.m_x, m_y + point.m_y);
 }

 Point Point::operator-(const Point &p1) const {
     return Point(m_x - p1.m_x, m_y - p1.m_y);
 }

 const Point Point::operator-() const {
     return Point(-m_x, -m_y);
 }

 Point &Point::operator+=(const Point &point) {
     m_x += point.m_x;
     m_y += point.m_y;
     return *this;
 }

 Point &Point::operator-=(const Point &point) {
     m_x -= point.m_x;
     m_y -= point.m_y;
     return *this;
 }

 bool Point::operator==(const Point &point) {
     return m_x == point.m_x && m_y == point.m_y;
 }

 bool Point::operator!=(const Point &point) {
     return m_x != point.m_x && m_y != point.m_y;
 }

 ```
 - 调用父类的运算符重载函数
 ```C++
 class Person {
 public:
     int m_age = 0;
     
     Person &operator=(const Person &person) {
         this-> m_age = person.m_age;
         return *this;
     }
 };

 class Student: public Person {
 public:
     int m_score;
     
     Student &operator=(const Student &student) {
         Person::operator=(student);
         this->m_score = student.m_score;
         return *this;
     }
 };
 ```
 
 ## 仿函数
 - 仿函数：将一个对象当作一个函数一样来使用
 - 对比普通函数，它作为对象可以保存状态
 
 ```C++
 class Sum {
 public:
    int operator()(int a, int b) {
        return a + b;
     }
 };

 void testSum() {
     Sum sum;
     sum(1, 2);
 }
 ```
 
 ## 运算符重载注意点
 - 有些运算符不可以被重载，比如:
    - 对象成员访问运算符: .
    - 域运算符号: ::
    - 三目运算符: ? :
    - sizeof
 - 有些运算符只能重载为成员函数，比如:
    - 赋值运算符: =
    - 下标运算符：[]
    - 函数运算符: ()
    - 指针访问成员: ->
 */


class Sum {
public:
   int operator()(int a, int b) {
       return a + b;
    }
};

void testSum() {
    Sum sum;
    sum(1, 2);
}


class Person {
public:
    int m_age = 0;
    
    Person &operator=(const Person &person) {
        this-> m_age = person.m_age;
        return *this;
    }
};

class Student: public Person {
public:
    int m_score;
    
    Student &operator=(const Student &student) {
        Person::operator=(student);
        this->m_score = student.m_score;
        return *this;
    }
};

class Car {};

class Point {
    
public:
    int m_x;
    int m_y;
    
    Point(int x, int y);
    Point(const Point &point);
    
    Point operator+(const Point &p1) const;
    Point operator-(const Point &p1) const;
    const Point operator-() const;
    Point &operator+=(const Point &point);
    Point &operator-=(const Point &point);
    bool operator==(const Point &point);
    bool operator!=(const Point &point);
    Point &operator++();
    const Point operator++(int);
    Point &operator--();
    const Point operator--(int);
    Point &operator=(const Point &);
    // 函数调用符重载 - 仿函数
    Point &operator()(int, int);
};


Point::Point(int x, int y): m_x(x), m_y(y) {}
Point::Point(const Point &point): m_x(point.m_x), m_y(point.m_y) {}

// 前++: 先加再用
Point &Point::operator++() {
    m_x++;
    m_y++;
    return *this;
}

// 后++：先用再加
const Point Point::operator++(int) {
    Point point(m_x, m_y);
    m_x++;
    m_y++;
    return point;
}

Point Point::operator+(const Point &point) const {
    return Point(m_x + point.m_x, m_y + point.m_y);
}

Point Point::operator-(const Point &p1) const {
    return Point(m_x - p1.m_x, m_y - p1.m_y);
}

const Point Point::operator-() const {
    return Point(-m_x, -m_y);
}

Point &Point::operator+=(const Point &point) {
    m_x += point.m_x;
    m_y += point.m_y;
    return *this;
}

Point &Point::operator-=(const Point &point) {
    m_x -= point.m_x;
    m_y -= point.m_y;
    return *this;
}

bool Point::operator==(const Point &point) {
    return m_x == point.m_x && m_y == point.m_y;
}

bool Point::operator!=(const Point &point) {
    return m_x != point.m_x && m_y != point.m_y;
}

Point & Point::operator--() {
    this->m_x = this->m_x - 1;
    this->m_y = this->m_y - 1;
    return  *this;
}

const Point Point::operator--(int) {
    Point temp = *this;
    m_x = m_x - 1;
    m_y = m_y - 1;
    return temp;
}

Point &Point::operator=(const Point & point) {
    // 应该先判断是否属性在堆区，如果有先释放干净，再进行深拷贝
    /**
     if (m_age != nullptr) {
        delete m_age;
        m_age = nullptr;
     }
     */
    cout << m_x << m_y << endl;
    m_x = point.m_x;
    m_y = point.m_y;
    
    return *this;
}

Point &Point::operator()(int x, int y) {
    m_x = x;
    m_y = y;
    return *this;
}

void testPoint() {
    Point p0(3, 1);
    p0(40, 1);
    
}
