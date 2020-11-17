//
//  Template.cpp
//  C++Demo
//
//  Created by lieon on 2020/11/10.
//  Copyright © 2020 lieon. All rights reserved.
//

#include "Template.hpp"
#include <iostream>

/**
 # 模板
 - 泛型，是一种将类型参数化以达到代码复用的技术，C++中使用模板来实现泛型
 - 模板的使用格式如下：
    - template<typename\class T>
    - tyname和class是等价的
 - 模板没有被使用时，是不会被实例化出来的
 - 模板的声明和实现如果分离到.h 和 .cpp中，会导致错误
 - 一般模板的声明和实现统一放到一个.hpp文件中
 ## 函数模板
 ```C++
 template<class T> void swapValues(T &v1, T &v2) {
     T temp = v1;
     v1 = v2;
     v2 = temp;
 }
 ```
 ## 多参数模板
 ```
 template<class T1, class T2>
 void display(const T1 &v1, const T2 &v2) {
     
 }

 ```
 
 ## 类模板
 ```C++
 template<class Item>
 class List {
     int m_size;
     int m_capacity;
     Item *m_data;
     
 public:
     List(int capacuty = 0);
     ~List();
     
     void add(Item value);
     Item get(int index);
     int size();
     void display();
 };


 template<class Item>
 void List<Item>::add(Item value) {
     if (m_size == this->m_capacity) {
         return;
     }
     m_data[m_size++] = value;
 }


 template<class Item>
 Item List<Item>::get(int index) {
     if (index < 0 || index >= m_size) {
         return NULL;
     }
     return m_data[index];
 }

 template<class Item>
 int List<Item>::size() {
     return m_size;
 }
 ```
 */


template<class T1, class T2>
void display(const T1 &v1, const T2 &v2) {
    
}
template<class Item>
class List {
    int m_size;
    int m_capacity;
    Item *m_data;
    
public:
    List(int capacuty = 0);
    ~List();
    
    void add(Item value);
    Item get(int index);
    int size();
    void display();
};


template<class Item>
void List<Item>::add(Item value) {
    if (m_size == this->m_capacity) {
        return;
    }
    m_data[m_size++] = value;
}


template<class Item>
Item List<Item>::get(int index) {
    if (index < 0 || index >= m_size) {
        return NULL;
    }
    return m_data[index];
}

template<class Item>
int List<Item>::size() {
    return m_size;
}

