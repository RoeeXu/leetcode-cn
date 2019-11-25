/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0085.cpp
* Author:   roeexu
* Date:     2019-11-25 15:55:58
* Brief:
****************************************************/

static auto s = [](){ ios::sync_with_stdio(false); cin.tie(0); return 0; }();

class Solution {
public:
    // dp best
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        int tmp, res = 0;
        vector<int> height(n, 0), left(n, 0), right(n, n);
        for(auto& line : matrix)
        {
            for(int i = 0; i < n; i++)
                if(line[i] == '1') height[i]++;
                else height[i] = 0;
            tmp = 0;
            for(int i = 0; i < n; i++)
                if(line[i] == '1') left[i] = max(left[i], tmp);
                else { left[i] = 0; tmp = i + 1; }
            tmp = n;
            for(int i = n - 1; i >= 0; i--)
                if(line[i] == '1') right[i] = min(right[i], tmp);
                else { right[i] = n; tmp = i; }
            for(int i = 0; i < n; i++)
                res = max(res, height[i] * (right[i] - left[i]));
        }
        return res;
    }

    // stack
    // int largestRectangleArea(vector<int>& heights) {
    //     stack<int> st;
    //     st.push(-1);
    //     int res = 0, tmp, light;
    //     for(int i = 0; i < heights.size(); i++)
    //     {
    //         if(st.size() == 1) { st.push(0); continue; }
    //         if(heights[i] > heights[st.top()]) st.push(i);
    //         else
    //         {
    //             while(st.top() != -1 && heights[st.top()] >= heights[i])
    //             {
    //                 tmp = st.top();
    //                 st.pop();
    //                 res = max(res, heights[tmp] * (i - st.top() - 1));
    //             }
    //             st.push(i);
    //         }
    //     }
    //     light = st.top();
    //     while(st.top() != -1)
    //     {
    //         tmp = st.top();
    //         st.pop();
    //         res = max(res, heights[tmp] * (light - st.top()));
    //     }
    //     return res;
    // }

    // int maximalRectangle(vector<vector<char>>& matrix) {
    //     int m = matrix.size();
    //     if(m == 0) return 0;
    //     int n = matrix[0].size();
    //     vector<vector<int>> H(m, vector<int>(n, 0));
    //     for(int j = 0; j < n; j++)
    //         for(int i = 0; i < m; i++)
    //             if(i == 0) H[0][j] = matrix[0][j] - '0';
    //             else if(matrix[i][j] == '0') continue;
    //             else H[i][j] += (H[i - 1][j] + 1);
    //     int res = 0;
    //     for(int i = 0; i < m; i++)
    //         res = max(res, largestRectangleArea(H[i]));
    //     return res;
    // }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

