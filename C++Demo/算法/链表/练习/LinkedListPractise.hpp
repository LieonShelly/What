//
//  LinkedListPractise.hpp
//  C++Demo
//
//  Created by lieon on 2021/1/6.
//  Copyright © 2021 lieon. All rights reserved.
//

#ifndef LinkedListPractise_hpp
#define LinkedListPractise_hpp

#include <stdio.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode * node = head;
        while (node != nullptr && node->next != nullptr) {
            if (node->val == val) {
                return node->next;
            } if (node->next->next == nullptr && node->next->val == val) {
                node->next = nullptr;
                return head;
            } else if (node->next->val == val) {
                node->next = node->next->next;
                return head;
            }
            node = node->next;
        }
        return nullptr;
    }
    
    ListNode* nodeAt(int index, ListNode* head) {
        ListNode * node = head;
        for (int i = 0; i < index; i++) {
            node = node->next;
        }
        return node;
    }
};


#endif /* LinkedListPractise_hpp */
