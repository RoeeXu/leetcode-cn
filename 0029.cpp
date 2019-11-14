/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0029.cpp
* Author:   roeexu
* Date:     2019/11/14 11:16:11
* Brief:
****************************************************/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
        long long m = abs((long long)dividend), n = abs((long long)divisor), res = 0;
		int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
		if (n == 1) return sign == 1 ? m : -m;
		while (m >= n) {
			long long t = n, p = 1;
			while (m >= (t << 1)) {
				p <<= 1;
				t <<= 1;
			}
			res += p;
			m -= t;
		}
		return sign > 0 ? res : -res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

