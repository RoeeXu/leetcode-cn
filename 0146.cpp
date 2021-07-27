/***************************************************
* Copyright (c) 2021 Roee Xu. All Rights Reserved
****************************************************
* File:     0146.cpp
* Author:   root
* Date:     2021-07-27 14:45:00
* Brief:
****************************************************/
 
class LRUCache {
public:
    struct Node {
        int k, v;
        Node* prev;
        Node* next;
        Node(): k(0), v(0), prev(NULL), next(NULL) {}
        Node(int a, int b): k(a), v(b), prev(NULL), next(NULL) {}
    };

    int n, N;
    Node *head, *tail;
    unordered_map<int, Node*> k_loc;

    LRUCache(int capacity) {
        N = capacity;
        n = 0;
        head = new Node();
        tail = new Node();
        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
        int ans = -1;
        if (k_loc.count(key))
        {
            Node *tmp = k_loc[key];
            ans = tmp->v;
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            head->next->prev = tmp;
            tmp->next = head->next;
            head->next = tmp;
            tmp->prev = head;
        }
        return ans;
    }
    
    void put(int key, int value) {
        if (k_loc.count(key))
        {
            Node *tmp = k_loc[key];
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            head->next->prev = tmp;
            tmp->next = head->next;
            head->next = tmp;
            tmp->prev = head;
            if (tmp->v != value)
                tmp->v = value;
        }
        else if (n < N)
        {
            Node *tmp = new Node(key, value);
            k_loc[key] = tmp;
            head->next->prev = tmp;
            tmp->next = head->next;
            head->next = tmp;
            tmp->prev = head;
            n++;
        }
        else
        {
            Node *tmp = new Node(key, value);
            k_loc[key] = tmp;
            head->next->prev = tmp;
            tmp->next = head->next;
            head->next = tmp;
            tmp->prev = head;
            tmp = tail->prev;
            tail->prev = tmp->prev;
            tmp->prev->next = tail;
            k_loc.erase(tmp->k);
            delete tmp;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

