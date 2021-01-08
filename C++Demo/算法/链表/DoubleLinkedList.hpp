//
//  DoubleLinkedList.hpp
//  C++Demo
//
//  Created by lieon on 2021/1/7.
//  Copyright © 2021 lieon. All rights reserved.
//

#ifndef DoubleLinkedList_hpp
#define DoubleLinkedList_hpp

#include <stdio.h>
#include "AbstractList.hpp"

template <typename E>
class DoubleNode {
public:
    E element;
    DoubleNode<E>* prev { nullptr };
    DoubleNode<E>* next { nullptr };
    
    DoubleNode(E element, DoubleNode<E>* prev, DoubleNode<E>* next) {
        this->element = element;
        this->prev = prev;
        this->next = next;
    }
    
    ~DoubleNode() {
    }
};

template <typename E>
class DoubleLinkedList: public AbstractList<E> {

private:

    
    // 获取index位置对应的节点对象
    DoubleNode<E> & nodeAt(int index) {
        this->rangeCheck(index);
        if (index < this->m_size >> 1) {
            DoubleNode<E> *node = first;
            for (int i = 0; i < index; i++) {
                node = node->next;
            }
            return *node;
        } else {
            DoubleNode<E> *node = last;
            for (int i = this->m_size - 1; i > index; i--) {
                node = node->prev;
            }
            return *node;
        }
    }
    
public:
    DoubleNode<E> *first { nullptr };
    DoubleNode<E> *last { nullptr };
    
    DoubleLinkedList() {
        this->m_size = 0;
    }
    
    ~DoubleLinkedList() {
        clear();
    }
    
    void clear() override {
        this->m_size = 0;
        if (first != nullptr) {
            DoubleNode<E> *node = first->next;
            while (node != nullptr) {
                node = node->next;
                delete node->next;
            }
            delete first;
            first = nullptr;
        }
    }
    
    bool contains(const E &element) override {
        return false;
    }
    
    E& set(int index, const E &element) override {
        DoubleNode<E> &node = nodeAt(index);
        E& old = node.element;
        node.element = element;
        return old;
    }
    
    void insert(int index, const E &element) override {
        if (this->m_size == 0) { // 链表没得值
            DoubleNode<E> *node = new DoubleNode<E>(element, nullptr, nullptr);
            first = node;
            last = node;
        } else if (index == 0) { // 在头部插入
            DoubleNode<E> *oldFirst = first;
            DoubleNode<E> *node = new DoubleNode<E>(element, nullptr, oldFirst);
            oldFirst->prev = node;
            first = node;
        } else if (index == this->m_size) { // 在尾部插入
            DoubleNode<E> *oldLast = last;
            DoubleNode<E> *node = new DoubleNode<E>(element, oldLast, nullptr);
            oldLast->next = node;
            last = node;
        } else { // 在中间插入
            this->rangeCheckForAdd(index);
            DoubleNode<E> &oldCurrent = nodeAt(index);
            DoubleNode<E> *node = new DoubleNode<E>(element, oldCurrent.prev, &oldCurrent);
            oldCurrent.prev->next = node;
            oldCurrent.prev = node;
        }
        
        this->m_size++;
    }
    
    E& get(int index) override {
        return nodeAt(index).element;
    }
    
    int indexOf(const E &element) override {
        DoubleNode<E> * node = first;
        for (int i = 0; i < this->m_size; i++) {
            if (element == node->element) {
                return i;
            }
            node = node->next;
        }
        return -1;
    }
    
    E& removeAt(int index) override {
        this->rangeCheck(index);
        DoubleNode<E> &node = nodeAt(index);
        if (node.prev == nullptr) {
            DoubleNode<E> *oldFirst = first;
            first = node.next;
            node.next->prev = nullptr;
            delete oldFirst;
        } else if(node.next == nullptr) {
            DoubleNode<E> *oldlast = last;
            last = node.prev;
            node.prev->next = nullptr;
            delete oldlast;
        } else {
            DoubleNode<E> *oldPrev = node.prev;
            DoubleNode<E> *oldnext= node.next;
            node.prev->next = node.next;
            node.next->prev = node.prev;
            delete oldPrev;
            delete oldnext;
            oldPrev = nullptr;
            oldnext = nullptr;
        }
      
        this->m_size--;
        return node.element;
    }
    
    bool isEmpty() override {
        return this->m_size > 0;
    }
};

#endif /* DoubleLinkedList_hpp */
