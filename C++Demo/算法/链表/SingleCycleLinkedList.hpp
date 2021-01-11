//
//  SingleCycleLinkedList.hpp
//  C++Demo
//
//  Created by lieon on 2021/1/11.
//  Copyright © 2021 lieon. All rights reserved.
//

#ifndef SingleCycleLinkedList_hpp
#define SingleCycleLinkedList_hpp

#include <stdio.h>
#include "List.hpp"
#include "AbstractList.hpp"
#include "LinkedList.hpp"

#endif /* SingleCycleLinkedList_hpp */

template<typename E>
class SingleCycleLinkedList: public AbstractList<E> {
private:
    // 获取index位置对应的节点对象
    Node<E> & nodeAt(int index) {
        this->rangeCheck(index);
        Node<E> *node = first;
        for (int i = 0; i < index; i++) {
            node = node->next;
        }
        return *node;
    }
public:
    Node<E> *first { nullptr };
    
    SingleCycleLinkedList() {
        this->m_size = 0;
    }
    
    ~SingleCycleLinkedList() {
        clear();
    }
    
    void clear() override {
        this->m_size = 0;
        if (first != nullptr) {
            Node<E> *node = first->next;
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
        Node<E> &node = nodeAt(index);
        E& old = node.element;
        node.element = element;
        return old;
    }
    
    void insert(int index, const E &element) override {
        this->rangeCheckForAdd(index);
        if (index == this->m_size) { // (index == 0 && size == 0) || (index == size && size != 0)
            if (this->m_size == 0) { // (index == 0 && size == 0
                first = new Node<E>(element, nullptr);
                first->next = first;
            } else {
                Node<E> &prev = nodeAt(index - 1);
                Node<E> *node = new Node<E>(element, first);
                prev.next = node;
            }
        } else {
            if (index == 0) {
                Node<E> &last = nodeAt(this->m_size - 1);
                Node<E> *oldFirst = first;
                Node<E> *node = new Node<E>(element, oldFirst);
                last.next = node;
                first = node;
            } else {
                Node<E> &prev = nodeAt(index - 1);
                Node<E> *node = new Node<E>(element, prev.next);
                prev.next = node;
            }
        }
        this->m_size++;
    }
    
    E& removeAt(int index) override {
        this->rangeCheck(index);
        Node<E> *node = first;
        if (index == 0) { // 头部
            Node<E> &oldLast = nodeAt(this->m_size - 1);
            first = first->next;
            oldLast.next = first;
        } else if (index == this->m_size) { // 尾部
            Node<E> &prev = this->nodeAt(index - 1);
            node = prev.next;
            prev.next = first;
        } else {
            Node<E> &prev = this->nodeAt(index - 1);
            node = prev.next;
            prev.next = node->next;
        }
        this->m_size--;
        E &element = node->element;
        delete node;
        return element;
    }
    
    E& get(int index) override {
        return nodeAt(index).element;
    }
    
    int indexOf(const E &element) override {
        Node<E> * node = first;
        for (int i = 0; i < this->m_size; i++) {
            if (element == node->element) {
                return i;
            }
            node = node->next;
        }
        return -1;
    }

    bool isEmpty() override {
        return this->m_size > 0;
    }
    
    void printAll() {
        for (int i = 0; i < this->m_size; i++) {
            Node<E> &node = nodeAt(i);
            cout << node.element << "_" << node.next->element << endl;
        }
    }
};
