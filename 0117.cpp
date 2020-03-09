/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     0117.cpp
* Author:   roeexu
* Date:     2020-03-09 11:27:32
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
    Node* connect(Node* root) {
        if(root == NULL)
            return root;
        if(root->left && root->right)
            root->left->next = root->right;
        Node* now = NULL;
        if(root->left)
            now = root->left;
        if(root->right)
            now = root->right;
        
        Node* temp = root->next;
        while(now && temp) {
            if(temp->left) {
                now->next = temp->left;
                break;
            }
            if(temp->right) {
                now->next = temp->right;
                break;
            }    
            temp = temp->next;
        }
        connect(root->right);
        connect(root->left);
        return root;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

