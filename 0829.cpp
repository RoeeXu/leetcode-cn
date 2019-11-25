/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0829.cpp
* Author:   root
* Date:     2019-11-25 16:22:50
* Brief:
****************************************************/

class Solution {    
public:
    // vector<int> g;
    // int res;
    
    // Solution() {
    //     bool s[35000] = {0};
    //     int p = 2, t;   
    //     while(p < 35000)
    //     {
    //         if(!s[p])
    //         {
    //             t = 2 * p;
    //             while(t < 35000)
    //             {
    //                 if(!s[t]) s[t] = 1;
    //                 t += p;
    //             }
    //         }
    //         p += 1;
    //     }
    //     for(int i = 3; i < 35000; i++)
    //         if(!s[i]) g.push_back(i);
    // }
    
    // void dfs(int& N, vector<pair<int, int>>& d, int& n, int p, long k)
    // {
    //     if(k > 35000 || k * k >= N) return;
    //     if(p == n)
    //     {
    //         res++;
    //         return;
    //     }
    //     int x = d[p].first, y = d[p].second, t = k;
    //     for(int i = 0; i <= y; i++)
    //     {
    //         dfs(N, d, n, p + 1, k);
    //         k *= x;
    //     }
    //     return;
    // }
    
    // int consecutiveNumbersSum(int N) {
    //     res = 1;
    //     int tmp = N;
    //     while((tmp & 1) == 0) tmp >>= 1;
    //     for(int i = 0; i < g.size(); i++)
    //     {
    //         if(tmp == 1) break;
    //         int e = 0;
    //         while(tmp % g[i] == 0)
    //         {
    //             tmp /= g[i];
    //             e++;
    //         }
    //         res *= e + 1;
    //     }
    //     if(tmp > 1) res <<= 1;
    //     return res;
    // }

    int consecutiveNumbersSum(int N) {
        while((N & 1) == 0) N >>= 1;
        int res = 1, d = 3;
        while(d * d <= N) 
        {
            int e = 0;
            while(N % d == 0) 
            {
                N /= d;
                e++;
            }
            res *= e + 1;
            d += 2;
        }
        if(N > 1) res <<= 1;
        return res;
    }
};
            
/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

