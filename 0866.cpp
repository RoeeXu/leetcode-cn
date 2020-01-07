/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     0866.cpp
* Author:   roeexu
* Date:     2020-01-07 15:49:36
* Brief:
****************************************************/
 
class Solution {
public:
    bool p[15000];
    int lower;
    
    Solution() {
        memset(p, 1, sizeof(p));
        p[0] = 0;
        p[1] = 0;
        lower = 2;
    }
    
    void update_prime(int upper) {
        if(upper <= lower) return;
        for(int i = lower; i < upper; i++) {
            int m = i << 1;
            while(m < upper) {
                if(p[m]) p[m] = 0;
                m += i;
            }
        }
        lower = upper;
    }
    
    bool isprime(int x) {
        int upper = (int)sqrt(x) + 1;
        if(upper > lower) update_prime(upper);
        for(int i = 2; i < upper; i++)
            if(p[i] && x % i == 0) return 0;
        return 1;
    }
    
    int gen_palindrome(int x) {
        int tmp = x, y = x / 10;
        while(tmp != 0) {
            y *= 10;
            y += tmp % 10;
            tmp /= 10;
        }
        return y;
    }
    
    int primePalindrome(int N) {
        if (N <= 2)       return 2;
        else if (N <= 3)  return 3;
        else if (N <= 5)  return 5;
        else if (N <= 7)  return 7;
        else if (N <= 11) return 11;
        int k = 0, tmp = N, s = N, pal = N;
        while(tmp != 0) {
            if(k % 2) s /= 10;
            k++;
            tmp /= 10;
        }
        for(int i = s; i < s * 100; i++) {
            pal = gen_palindrome(i);
            if(pal >= N && isprime(pal)) break;
        }
        return pal;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

