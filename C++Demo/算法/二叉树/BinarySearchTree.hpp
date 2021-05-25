//
//  BinarySearchTree.hpp
//  C++Demo
//
//  Created by lieon on 2021/4/21.
//  Copyright © 2021 lieon. All rights reserved.
//

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include <stdio.h>
#include <exception>
#include <iostream>
#include <queue>

using namespace::std;

template<typename E>
class Comparator {
public:
    virtual bool compare(E *e1, E *e2) = 0;
};

template<typename E>
class Visitor {
public:
    void(*callback)(E);
    bool isStop = false;
};

template<typename E>
class BinarySearchTree {
    template<typename Element>
    class Node {
    public:
        Element *element;
        Node<Element> *left;
        Node<Element> *right;
        Node<Element> *parent;
        
    public:
        Node(const Element *element, const Node<Element> *parent) {
            this->element = (Element*)element;
            this->parent = (Node<Element>*)parent;
        }
        
        bool isLeaf() {
            return left == nullptr && right == nullptr;
        }
        
        bool hasTwoChildren() {
            return  left != nullptr && right != nullptr;
        }

    };

private:
    int m_size;
    Node<E> * root;
    Comparator<E> * comparator;
    
    
    
    void elementNoNullCheck(E *element) noexcept {
        if (element == nullptr) {
            // 抛出异常
            throw "element can not be nullptr";
        }
    }
    
    // 比较方法
    int compare(E *e1, E *e2) {
        throw "e1 e2 can not be compare";
    }
    
    void remove(Node<E> *node) {
        if (node == nullptr) {
            return;
        }
        m_size--;
        if (node->hasTwoChildren()) { // 度为2的节点
            // 找到后继节点

        }
    }
    
    Node<E>* successor(Node<E> *node) {
        if (node == nullptr) {
            return nullptr;
        }
        // 前驱节点在左子树中
        Node<E> *p = node->right;
        if (p != nullptr) {
            while (p->left != nullptr) {
                return p = p->left;
            }
            return p;
        }
        // 从父节点，祖父节点中寻找前驱节点
        while (node->parent != nullptr && node == node->parent->right) {
            node = node->parent;
        }
        return node->parent;
    }
    
public:
    BinarySearchTree(Comparator<E> * comparator) {
        this->comparator = comparator;
    }
    
    int size() {
        return m_size;
    }
    
    bool isEmpty() {
        return m_size == 0;
    }
    
    void clear() {
        root = nullptr;
        m_size = 0;
    }
    
    void add(E *element) {
        elementNoNullCheck(element);
        // 添加第一个节点
        if (root == nullptr) {
            root = new Node<E>(element, nullptr);
            m_size++;
            return;
        }
        // 添加的不是第一个节点
        // 找到父节点
        Node<E> *parent = root;
        Node<E> *node = root;
        int cmp = 0;
        while (node != nullptr) {
            cmp = comparator->compare(element, node->element);
            parent = node;
            if (cmp > 0) {
                node = node->right;
            } else if (cmp < 0) {
                node = node->left;
            } else { // 相等
                node->element = element;
                return;
            }
        }
        // 看看新的节点插入到父节点的那个位置
        Node<E> *newNode = new Node<E>((const E *)element, (const Node<E> *)parent);
        if (cmp > 0) {
            parent->right = newNode;
        } else {
            parent->left = newNode;
        }
        m_size++;
    }
    
    void remove(E *element) {
        
    }
    
    void preorderTraversal() {
        preoderTraversal(root);
    }
    
    void preoderTraversal(Node<E> *node) {
        if (node == nullptr) {
            return;
        }
        std::cout << node->element << std::endl;
        preoderTraversal(node->left);
        preoderTraversal(node->right);
    }
    // 中序遍历
    /**
      升序： 左边节点 节点的值 右边节点
      降序： 右边节点 节点的值 左边节点
     */
    void inorderTraseral() {
        inorderTraserval(root);
    }
    
    void inorderTraserval(Node<E> *node) {
        if (node == nullptr) {
            return;
        }
        inorderTraserval(node->left);
        std::cout << node->element << std::endl;
        inorderTraserval(node->right);
    }
    
    /**
     后续遍历，根节点在最后
     */
    void postOrderTraversal() {
        postOrderTraserval(root);
    }
    
    void postOrderTraserval(Node<E> *node, const Visitor<E> &visitor) {
        if (node == nullptr || visitor.isStop) {
            return;
        }
        postOrderTraserval(node->left);
        postOrderTraserval(node->right);
        std::cout << node->element << std::endl;
        // 返回true， 表示停止遍历, 怎么停止？
        visitor.isStop =  visitor.callback(*(node->element));
        if (visitor.isStop) {
            return;
        }
        
    }
    // 层序遍历， 是重点，达到手写的程度
    
    void levelTraversal() {
        if (root == nullptr) {
            return;
        }
        // 使用队列
        queue<Node<E>*> queue;
        queue.push(root);
        while (!queue.empty()) {
            Node<E> * head = queue.pop();
            cout << head->element << endl;
            if (head->left != nullptr) {
                queue.push(head->left);
            }
            if (head->right != nullptr) {
                queue.push(head->right);
            }
        }
    }
    /**获取二叉树的高度
     - 迭代
     - 层序遍历
     */
    int height() {
        // 迭代
//        return height(root);
        // 层序遍历的方式获取高度
        int levelSize = 1;
        int height = 0;
        queue<Node<E>*> queue;
        queue.push(root);
        while (!queue.empty()) {
            Node<E> * head = queue.pop();
            levelSize--;
            cout << head->element << endl;
            if (head->left != nullptr) {
                queue.push(head->left);
            }
            if (head->right != nullptr) {
                queue.push(head->right);
            }
            // levelSize == 0 表明即将访问下一层
            if (levelSize == 0) {
                levelSize = queue.size();
                height++;
            }
        }
    }
    
    int height(Node<E> *node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + max(height(node->left), height(node->right));
    }
    
    // 是否是完全二叉树
//    bool isComplete() {
//        queue<Node<E>*> queue;
//        queue.push(root);
//        bool isLeaf = false;
//        while (!queue.empty()) {
//            Node<E> * head = queue.pop();
//            // 要求是叶子节点，但是它并不是
//            if (isLeaf && !head->isLeaf()) {
//                return false;
//            }
//            if (head->hasTwoChildren()) {
//                queue.push(head->left);
//                queue.push(head->right);
//            } else if (head->left == nullptr && head->right != nullptr) {
//                return false;
//            } else {
//                isLeaf = true;
//                if (head->left != nullptr) {
//                    queue.push(head->left);
//                }
//            }
//        }
//        return true;
//    }
    
    bool isComplete() {
        queue<Node<E>*> queue;
        queue.push(root);
        bool isLeaf = false;
        while (!queue.empty()) {
            Node<E> * head = queue.pop();
            // 要求是叶子节点，但是它并不是
            if (isLeaf && !head->isLeaf()) {
                return false;
            }
            if (head->left != nullptr) {
                queue.push(head->left);
            } else if (head->right != nullptr) {
                return false;
            }
            if (head->right != nullptr) {
                queue.push(head->right);
            } else {
                isLeaf = true;
            }
        }
        return true;
    }
    // 翻转二叉树: 将二叉树的所有子节点交换 遍历实现
    void invert() {
        invert(root);
    }
    
    Node<E> * invert(Node<E> *node) {
        if (node == nullptr) {
            return node;
        }
        Node<E> *temp = node->left;
        node->left = node->right;
        node->right = temp;
        invert(node->left);
        invert(node->right);
        return node;
    }
};
    
    

#endif /* BinarySearchTree_hpp */
