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
#include "BinaryTree.hpp"

using namespace::std;

class BinarySearchTree: public BinaryTree {
private:
    // 删除传入的节点
    void remove(TreeNode *node);
    
public:
    BinarySearchTree(Comparator &comparator);
    
    void add(int element);
    
    void remove(int element);
};


#endif /* BinarySearchTree_hpp */
