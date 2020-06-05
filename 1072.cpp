/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     1072.cpp
* Author:   roeexu
* Date:     2020-06-05 18:45:32
* Brief:
****************************************************/
 
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> m;
        int res = 0;
        for(auto& k : matrix){
            string s;
            int d = 1 ^ k[0];
            for(auto x : k) s += (d ^ x) +'0';
            ++m[s];
            res = max(res, m[s]);
        }
        return res;
    }
//     string bin2str(vector<int>& l) {
//         string s = "";
//         for(auto& b : l)
//             if(b) s += '1';
//             else s += '0';
//         return s;
//     }
    
//     int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
//         int m = matrix.size(), n = matrix[0].size();
//         unordered_map<string, int> d;
//         for(auto& x : matrix){
//             string y = bin2str(x);
//             if(!d.count(y)) d[y] = 0;
//             d[y]++;
//         }
//         int res = 0;
//         for(auto& t : d) {
//             string k = t.first;
//             string g = "";
//             for(auto& c : k)
//                 if(c == '1') g += '0';
//                 else g += '1';
//             if(d.count(g)) res = max(res, d[k] + d[g]);
//             else res = max(res, d[k]);
//         }
//         return res;
//     }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

