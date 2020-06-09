/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     1024.cpp
* Author:   roeexu
* Date:     2020-06-09 15:38:18
* Brief:
****************************************************/
 
class Solution {
public:
    int videoStitching(vector<vector<int>> &clips, int T) {
        sort(clips.begin(), clips.end());
        int pos = 0, i = 0, cnt = 0;
        while(pos < T) {
            if(i == clips.size()) return -1;
            int max_right = INT_MIN;
            while(i < clips.size() && clips[i][0] <= pos)
                max_right = max(max_right, clips[i++][1]);
            if(max_right > pos) {
                pos = max_right;
                ++cnt;
            } 
            else return -1;
        }
        return cnt;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

