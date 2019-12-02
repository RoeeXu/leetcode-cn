/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0096.cpp
* Author:   roeexu
* Date:     2019-12-02 21:05:57
* Brief:
****************************************************/

class Solution {
public:
    int numTrees(int n) {
        long C = 1;
        for (int i = 0; i < n; ++i) C = C * 2 * (2 * i + 1) / (i + 2);
        return (int) C;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

