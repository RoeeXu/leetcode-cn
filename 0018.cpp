/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0018.cpp
* Author:   roee
* Date:     2019-11-18 23:24:00
* Brief:
****************************************************/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        if (n < 4) return ans;
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i - 1] == nums[i])
                continue;
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
                break;
            if (nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target)
                continue;
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j - 1] == nums[j])
                    continue;
                if (nums[j] + nums[j + 1] + nums[j + 2] > target - nums[i])
                    break;
                if (nums[j] + nums[n - 2] + nums[n - 1] < target - nums[i])
                    continue;
                int l = j + 1;
                int r = n - 1;
                int tmp = target - nums[i] - nums[j];
                while (l < r) {
                    int sum = nums[l] + nums[r];
                    if (sum == tmp) {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        do { l++; } while (l < r && nums[l] == nums[l - 1]);
                        do { r--; } while (l < r && nums[r] == nums[r + 1]);
                    } else if (sum < tmp) {
                        l++;
                    } else {
                        r--;
                    }
                }
            }
        }
        return ans;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

