/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0116.cpp
* Author:   root
* Date:     2019-12-05 01:25:19
* Brief:
****************************************************/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    // best
    Node* connect(Node* root) {
        Node* leftMost = root;
        while (leftMost) {
            for (Node* cur = leftMost; cur; cur = cur->next) {
                if (cur->left) cur->left->next = cur->right;
                if (cur->right && cur->next) cur->right->next = cur->next->left;
            }
            leftMost = leftMost->left;
        }
        return root;
    }

    // better
    // Node* connect(Node* root) {
    //     if (root == nullptr) return nullptr;
    //     if (root->left == nullptr) return root; 
    //     else root->left->next = root->right;
    //     Node* cur = root->left->left;
    //     Node* pre = root->left;
    //     while (cur!=nullptr)
    //     {
    //         while (pre!=nullptr)
    //         {
    //             pre->left->next = pre->right;
    //             if (pre->next != nullptr) pre->right->next = pre->next->left;
    //             else pre->right->next = nullptr;
    //             pre = pre->next;
    //         }
    //         pre = cur;
    //         cur = cur->left;
    //     }
    //     return root;
    // }

    // mine
    // Node* connect(Node* root) {
    //     if(!root) return NULL;
    //     queue<Node*> q;
    //     q.push(root);
    //     int c = q.size();
    //     Node* pre;
    //     while(c > 0)
    //     {
    //         pre = q.front();
    //         if(pre->left)
    //         {
    //             q.push(pre->left);
    //             q.push(pre->right);
    //         }
    //         q.pop();
    //         for(int i = 1; i < c; i++)
    //         {
    //             pre->next = q.front();
    //             pre = q.front();
    //             if(pre->left)
    //             {
    //                 q.push(pre->left);
    //                 q.push(pre->right);
    //             }
    //             q.pop();
    //         }
    //         pre->next = NULL;
    //         c = q.size();
    //     }
    //     return root;
    // }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

