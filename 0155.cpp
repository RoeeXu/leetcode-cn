/***************************************************
* Copyright (c) 2021 Roee Xu. All Rights Reserved
****************************************************
* File:     0155.cpp
* Author:   roeexu
* Date:     2021-02-18 21:12:15
* Brief:
****************************************************/
 
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> que;
    stack<int> minque;
    
    MinStack() {

    }
    
    void push(int x) {
        que.push(x);
        if (minque.empty()) {
            minque.push(x);
        } else if (minque.top() >= x) {
            minque.push(x);
        }
    }
    
    void pop() {
        int x = que.top();
        if (x == minque.top()) {
            minque.pop();
        }
        que.pop();
    }
    
    int top() {
        return que.top();
    }
    
    int getMin() {
        return minque.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

