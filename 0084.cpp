/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0084.cpp
* Author:   root
* Date:     2019-11-25 01:31:38
* Brief:
****************************************************/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        st.push(-1);
        int res = 0, tmp, light;
        for(int i = 0; i < heights.size(); i++)
        {
            if(st.size() == 1) { st.push(0); continue; }
            if(heights[i] > heights[st.top()]) st.push(i);
            else
            {
                while(st.top() != -1 && heights[st.top()] >= heights[i])
                {
                    tmp = st.top();
                    st.pop();
                    res = max(res, heights[tmp] * (i - st.top() - 1));
                }
                st.push(i);
            }
        }
        light = st.top();
        while(st.top() != -1)
        {
            tmp = st.top();
            st.pop();
            res = max(res, heights[tmp] * (light - st.top()));
        }
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

