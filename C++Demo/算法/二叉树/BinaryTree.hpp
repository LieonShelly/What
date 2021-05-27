//
//  BinaryTree.hpp
//  C++Demo
//
//  Created by lieon on 2021/5/27.
//  Copyright © 2021 lieon. All rights reserved.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <stdio.h>
#include <exception>
#include <iostream>
#include <queue>

using namespace::std;

class Comparator {
public:
    virtual bool compare(int e1, int e2) = 0;
};

class Visitor {
public:
    bool(*callback)(int);
    bool isStop = false;
};

class TreeNode {
public:
    int element = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode *parent = nullptr;
    
public:
    TreeNode(int element, const TreeNode *parent) {
        this->element = element;
        this->parent = (TreeNode*)parent;
    }
    
    bool isLeaf() {
        return left == nullptr && right == nullptr;
    }
    
    bool hasTwoChildren() {
        return  left != nullptr && right != nullptr;
    }
    
};

class BinaryTree {
protected:
    int m_size;
    TreeNode  * root = nullptr;
    Comparator * comparator = nullptr;
    
    void elementNoNullCheck(int element) noexcept {
        
    }
    
    // 根据元素获取节点
    TreeNode *node(int element) {
        TreeNode *node = root;
        while (node != nullptr) {
            int cmp = comparator->compare(element, node->element);
            if (cmp == 0) {
                return node;
            } else if (cmp > 0) {
                node = node->right;
            } else {
                node = node->left;
            }
        }
        return nullptr;
    }
    
    /**
     前驱节点： 中序遍历的前一个节点，如果是二叉搜索树，前驱节点就是前一个比它小的节点
     */
    TreeNode * predecessor(TreeNode *node) {
        if (node == nullptr) {
            return nullptr;
        }
        // 前驱节点在左子树中当中 <left.right.right...>
        if (node->left == nullptr) {
            TreeNode * p = node->left;
            while (p->right != nullptr) {
                p = p->right;
            }
        }
        // 从父节点，祖父节点中寻找前驱节点
        while (node->parent != nullptr && node == node->parent->left) {
            node = node->parent;
        }
        return node->parent;
    }
    
    // 后继节点
    TreeNode* successor(TreeNode *node) {
        if (node == nullptr) {
            return nullptr;
        }
        // 前驱节点在左子树中
        TreeNode *p = node->right;
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
    BinaryTree(Comparator &comparator) {
        this->comparator = &comparator;
    }
    
    virtual int size() {
        return m_size;
    }
    
    virtual bool isEmpty() {
        return m_size == 0;
    }
    
    virtual void clear() {
        root = nullptr;
        m_size = 0;
    }
    
    virtual void preorderTraversal() {
        preoderTraversal(root);
    }
    
    virtual void preoderTraversal(TreeNode *node) {
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
    virtual void inorderTraseral() {
        inorderTraserval(root);
    }
    
    virtual void inorderTraserval(TreeNode *node) {
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
    virtual void postOrderTraversal() {
//        postOrderTraserval(root);
    }
    
    virtual void postOrderTraserval(TreeNode *node, Visitor &visitor) {
        if (node == nullptr || visitor.isStop) {
            return;
        }
        postOrderTraserval(node->left, visitor);
        postOrderTraserval(node->right, visitor);
        std::cout << node->element << std::endl;
        // 返回true， 表示停止遍历, 怎么停止？
        visitor.isStop =  visitor.callback((node->element));
        if (visitor.isStop) {
            return;
        }
        
    }
    
    // 层序遍历， 是重点，达到手写的程度
    virtual void levelTraversal() {
        if (root == nullptr) {
            return;
        }
        // 使用队列
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            TreeNode * head = queue.front();
            queue.pop();
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
    virtual int height() {
        // 迭代
        //        return height(root);
        // 层序遍历的方式获取高度
        int levelSize = 1;
        int height = 0;
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            TreeNode * head = queue.front();
            queue.pop();
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
        return height;
    }
    
    virtual int height(TreeNode *node) {
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
    
    virtual bool isComplete() {
        queue<TreeNode*> queue;
        queue.push(root);
        bool isLeaf = false;
        while (!queue.empty()) {
            TreeNode * head = queue.front();
            queue.pop();
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
    virtual void invert() {
        invert(root);
    }
    
    TreeNode *invert(TreeNode *node) {
        if (node == nullptr) {
            return node;
        }
        TreeNode *temp = node->left;
        node->left = node->right;
        node->right = temp;
        invert(node->left);
        invert(node->right);
        return node;
    }
    
};

#endif /* BinaryTree_hpp */
