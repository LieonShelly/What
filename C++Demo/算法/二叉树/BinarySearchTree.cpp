//
//  BinarySearchTree.cpp
//  C++Demo
//
//  Created by lieon on 2021/4/21.
//  Copyright © 2021 lieon. All rights reserved.
//

#include "BinarySearchTree.hpp"


BinarySearchTree::BinarySearchTree(Comparator &comparator):BinaryTree(comparator) {}

void BinarySearchTree::remove(TreeNode *node) {
    if (node == nullptr) {
        return;
    }
    this->m_size--;
    
    if (node->hasTwoChildren()) { // 度为2的节点
        // 找到后继节点
        TreeNode *s = successor(node);
        // 用后继点的值覆盖度为2的节点的值
        node->element = s->element;
        node = s;
    }
    // 删除node节点（此时node的度必然是1或者0）
    TreeNode *replacement = node->left != nullptr ? node->left : node->right;
    
    if (replacement != nullptr) { // node是度为1的节点
        // 更改parent
        replacement->parent = node->parent;
        // 更改parent的left，right的指向
        if (node->parent == nullptr) {
            this->root = replacement;
        } else if (node == node->parent->left) {
            node->parent->left = replacement;
        } else {
            node->parent->right = replacement;
        }
    } else if (node->parent == nullptr) { // node是叶子节点,并且是根节点
        this->root = nullptr;
    } else { // node是叶子节点，但不是根节点
        if (node == node->parent->left) {
            node->parent->left = nullptr;
        } else {
            node->parent->right = nullptr;
        }
    }
}

void BinarySearchTree::add(int element) {
    elementNoNullCheck(element);
    // 添加第一个节点
    if (this->root == nullptr) {
        this->root = new TreeNode(element, nullptr);
        this->m_size++;
        return;
    }
    // 添加的不是第一个节点
    // 找到父节点
    TreeNode *parent = this->root;
    TreeNode *node = this->root;
    int cmp = 0;
    while (node != nullptr) {
        cmp = this->comparator->compare(element, node->element);
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
    TreeNode *newNode = new TreeNode(element, (const TreeNode *)parent);
    if (cmp > 0) {
        parent->right = newNode;
    } else {
        parent->left = newNode;
    }
    this->m_size++;
}

void BinarySearchTree::remove(int element) {
    this->remove(this->node(element));
}
