/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     0990.cpp
* Author:   roee
* Date:     2020-07-02 01:58:28
* Brief:
****************************************************/

class Solution {
public:
    int pre[26];
    
    int find(int x) {
        while(pre[pre[x]] != pre[x]) pre[x] = pre[pre[x]];
        return pre[x];
    }
    
    void join(int x, int y) {
        int h1 = find(x), h2 = find(y);
        if(h1 < h2) pre[h2] = h1;
        else pre[h1] = h2;
    }
    
    bool equationsPossible(vector<string>& equations) {
        for(int i = 0; i < 26; i++) pre[i] = i;
        for(auto& e : equations)
            if(e[1] == '=')
                join(e[0] - 'a', e[3] - 'a');
        for(auto& e : equations)
            if(e[1] == '!')
                if(find(e[0] - 'a') == find(e[3] - 'a'))
                    return false;
        return true;
    }
};


/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */
