/***************************************************
* Copyright (c) 2021 Roee Xu. All Rights Reserved
****************************************************
* File:     1115.cpp
* Author:   root
* Date:     2021-04-24 13:13:57
* Brief:
****************************************************/

class FooBar {
private:
    int n;
    atomic<bool> foo_done = false;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            while (foo_done) this_thread::yield();
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            foo_done = true;
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            while (!foo_done) this_thread::yield();
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            foo_done = false;
        }
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */
