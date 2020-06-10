/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     1405.cpp
* Author:   roeexu
* Date:     2020-06-10 19:55:25
* Brief:
****************************************************/
 
class Solution {
public:
    string pattern(vector<int> list) {
        string res = "";
        for(auto& c : list) res += c + 'a';
        return res;
    }
    
    string longestDiverseString(int a, int b, int c) {
        vector<pair<int, char>> take = {{a, 0}, {b, 1}, {c, 2}};
        sort(take.begin(), take.end());
        int x = take[0].first, y = take[1].first, z = take[2].first;
        int r = take[0].second, s = take[1].second, t = take[2].second;
        string p1 = pattern({t, t, s, t, t, r}), p2 = pattern({t, t, s, t, r}), p3 = pattern({t, t, s, r}), p4 = pattern({t, s, r});
        string q1 = pattern({t, t, s}), q2 = pattern({t, s});
        int n = z - y;
        string res = "";
        for(int i = 0; i < x; i++) {
            if(n >= 3) {
                res += p1;
                n -= 3;
            }
            else if(n == 2) {
                res += p2;
                n -= 2;
            }
            else if(n == 1) {
                res += p3;
                n -= 1;
            }
            else res += p4;
        }
        for(int i = 0; i < y - x; i++) {
            if(n >= 1) {
                res += q1;
                n -= 1;
            }
            else res += q2;
        }
        if(n >= 2) {res += t + 'a'; res += t + 'a';}
        else if(n == 1) res += t + 'a';
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

