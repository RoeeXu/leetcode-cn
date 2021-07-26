/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0046.cpp
* Author:   roee
* Date:     2019-11-18 23:59:45
* Brief:
****************************************************/

class Solution {
public:
    void helper(vector<vector<int>>& res, vector<int>& nums, int start)
    {
        if (start == nums.size())
        {
            res.emplace_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++)
        {
            swap(nums[start], nums[i]);
            helper(res, nums, start + 1);
            swap(nums[start], nums[i]);
        }
        return;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helper(res, nums, 0);
        return res;
    }
};

class Solution {
public:
    // demo
    void search(int& count, vector<int>& nums, vector<bool>& visit, vector<vector<int>>& res, vector<int>& tmp){
        if(count == nums.size())
        {
            res.push_back(tmp);
            return;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(!visit[i])
            {
                tmp.push_back(nums[i]);
                visit[i] = 1;
                count++;
                search(count, nums, visit, res, tmp);
                tmp.pop_back();
                visit[i] = 0;
                count--;
                
            }
        }
        return;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        int count = 0;
        int n = nums.size();
        if(n == 0) return res;
        vector<bool> visit(n, 0);
        search(count, nums, visit, res, tmp);
        return res;
        
    }

    // STL
    // int fraction(int x) {
    //     int s = 1;
    //     while(x > 1) s *= x--;
    //     return s;
    // }

    // vector<vector<int>> permute(vector<int>& nums) {
    //     vector<vector<int>> res;
    //     int n = fraction(nums.size());
    //     while(n > 0){
    //         res.push_back(nums);
    //         next_permutation(nums.begin(),nums.end());
    //         n--;
    //     }
    //     return res;
    // }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

