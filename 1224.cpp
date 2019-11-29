/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     1224.cpp
* Author:   roeexu
* Date:     2019-11-29 13:37:41
* Brief:
****************************************************/

class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        vector<int> cnt(100001,0),fre(100001,0);    //cnt计算数字出现的频率，fre[i]=j表示有j个数字频率为i
        int maxcnt=0,ans=0;
        for(int i=0;i<nums.size();++i){
            int num=nums[i];
            ++cnt[num];
            ++fre[cnt[num]];
            maxcnt=max(maxcnt,cnt[num]);
            //第一、四种情况 || 第二种情况 （i+1就是目前的前缀数组长度）
            if((fre[maxcnt]==1&&1+fre[maxcnt-1]*(maxcnt-1)==i+1)||(fre[maxcnt]*maxcnt+1==i+1)) 
                ans=i+1;
        }
        if(maxcnt==1) return nums.size();  //第三种情况
        return ans;
    }
    
    // int maxEqualFreq(vector<int>& nums) {
    //     unordered_map<int, int> cnt, saver;
    //     int res = 1, n = nums.size(), x, y;
    //     for(int i = 0; i < n; i++)
    //     {
    //         x = nums[i];
    //         if(cnt.count(x) > 0)
    //         {
    //             y = cnt[x];
    //             saver[y] -= 1;
    //             if(saver[y] == 0) saver.erase(y);
    //             y += 1;
    //             cnt[x] += 1;
    //             if(saver.count(y) > 0) saver[y] += 1;
    //             else saver[y] = 1;
    //         }
    //         else
    //         {
    //             cnt[x] = 1;
    //             if(saver.count(1) > 0) saver[1] += 1;
    //             else saver[1] = 1;
    //         }
    //         if(saver.size() == 1 && i < n - 1) res = i + 2;
    //         if(saver.size() == 2)
    //         {
    //             int a, b, x, y;
    //             a = b = x = y = 0;
    //             for(auto& p : saver)
    //             {
    //                 if(a == 0) {a = p.first; x = p.second;}
    //                 else {b = p.first; y = p.second;}
    //             }
    //             if(a > b) {swap(a, b); swap(x, y);}
    //             if((b - a == 1 && y == 1) || (a == 1 && x == 1)) res = i + 1;
    //         }
    //     }
    //     return res;
    // }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

