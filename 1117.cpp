/***************************************************
* Copyright (c) 2021 Roee Xu. All Rights Reserved
****************************************************
* File:     1117.cpp
* Author:   root
* Date:     2021-04-24 13:59:54
* Brief:
****************************************************/

class H2O {
public:
    // 氧气的计数
    int cntO;
    // 氢气的计数
    int cntH;
    mutex m;
    condition_variable cv;

    H2O() {
        cntO = 0;
        cntH = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lock(m);
        cv.wait(lock, [this]()
        {
            // 氢气最大是2
            return this->cntH < 2; // 当数量小于2时不会阻塞
        });
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        ++cntH;
        // 已经构成 H2O ，重置计数器
        if (cntH + cntO == 3)
        {
            cntH = 0;
            cntO = 0;
        }
        cv.notify_one();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lock(m);
        cv.wait(lock, [this]()
        {
            // 氧气最大是1
            return this->cntO < 1;
        });
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        ++cntO;
        // 已经构成 H2O ，重置计数器
        if (cntH + cntO == 3)
        {
            cntH = 0;
            cntO = 0;
        }
        cv.notify_one();
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */
