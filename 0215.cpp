/***************************************************
* Copyright (c) 2021 Roee Xu. All Rights Reserved
****************************************************
* File:     0215.cpp
* Author:   root
* Date:     2021-07-27 13:26:47
* Brief:
****************************************************/
 
// mine partition
class Solution {
public:
    int quick_select(vector<int>& a, int l, int r)
    {
        int i = rand() % (r - l + 1) + l;
        int x = a[i], t = r;
        swap(a[i], a[r]);
        for (int j = l; j < r; j++)
        {
            if (a[j] > x)
                swap(a[j--], a[--r]);
        }
        swap(a[r], a[t]);
        return r;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;
        int index = -1;
        k = r - k + 1;
        while (k != index)
        {
            index = quick_select(nums, l, r);
            if (index < k)
                l = index + 1;
            else if (index > k)
                r = index - 1;
        }
        return nums[k];
    }
};

// // STL sort
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end());
//         return nums[nums.size() - k];
//     }
// };

// // mine 小根堆
// class Solution {
// public:
//     void small_make(vector<int>& h)
//     {
//         int n = h.size();
//         for (int i = (n - 2) / 2; i >= 0; i--)
//             small_down(h, i);
//     }

//     void small_up(vector<int>& h, int p)
//     {
//         int n = h.size();
//         int left = 2 * p + 1, right = 2 * p + 2;
//         if (right < n && h[left] < h[p] && h[left] <= h[right])
//             swap(h[left], h[p]);
//         else if (right < n && h[right] < h[p] && h[left] >= h[right])
//             swap(h[right], h[p]);
//         else if (left < n && h[left] < h[p])
//             swap(h[left], h[p]);
//         else
//             return;
//         if (p) small_up(h, (p - 1) / 2);
//     }

//     void small_down(vector<int>& h, int p)
//     {
//         int n = h.size(), left = 2 * p + 1, right = 2 * p + 2;
//         if (right < n && h[left] < h[p] && h[left] <= h[right])
//         {
//             swap(h[left], h[p]);
//             small_down(h, left);
//         }
//         else if(right < n && h[right] < h[p] && h[left] >= h[right])
//         {
//             swap(h[right], h[p]);
//             small_down(h, right);
//         }
//         else if(left < n && h[left] < h[p])
//         {
//             swap(h[left], h[p]);
//         }
//     }

//     int findKthLargest(vector<int>& nums, int k) {
//         int n = nums.size();
//         int flag = 1;
//         if (k * 2 > n) // 求负，倒过来求第 n - k + 1 个最大的元素
//         {
//             flag = -1;
//             k = n - k + 1;
//             for (int i = 0; i < n; i++)
//                 nums[i] = -nums[i];
//         }
//         vector<int> h(nums.begin(), nums.begin() + k);
//         small_make(h);
//         for (int i = k; i < nums.size(); i++)
//         {
//             if (nums[i] > h[0])
//             {
//                 h[0] = nums[i];
//                 small_down(h, 0);
//             }
//         }
//         return flag * h[0];
//     }
// };

// // STL heap
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         vector<int> h;
//         for(auto x : nums)
//         {
//             if (h.size() < k)
//             {
//                 h.push_back(-x);
//                 push_heap(h.begin(), h.end());
//             }
//             else if(h[0] > -x)
//             {
//                 pop_heap(h.begin(), h.end());
//                 h[k - 1] = -x;
//                 push_heap(h.begin(), h.end());
//             }
//         }
//         return -h[0];
//     }
// };

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

