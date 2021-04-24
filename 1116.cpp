/***************************************************
* Copyright (c) 2021 Roee Xu. All Rights Reserved
****************************************************
* File:     1116.cpp
* Author:   root
* Date:     2021-04-24 13:36:20
* Brief:
****************************************************/

class ZeroEvenOdd {
private:
    int n;
    atomic<int> pro = 0;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        pro = 0;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; i++) {
            while (pro % 2 != 0) this_thread::yield();
            printNumber(0);
            pro++;
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            while (pro % 4 != 3) this_thread::yield();
            printNumber(i);
            pro++;
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            while (pro % 4 != 1) this_thread::yield();
            printNumber(i);
            pro++;
        }
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */
