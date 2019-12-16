/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     1104.cpp
* Author:   roeexu
* Date:     2019-12-16 11:19:00
* Brief:
****************************************************/

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int p = 0, x = label, v = 2;
        vector<int> res;
        while(label > 0)
        {
            p++;
            v <<= 1;
            v++;
            label >>= 1;
        }
        p--;
        v--;
        v >>= 1;
        res.push_back(x);
        while(x != 1)
        {
            x >>= 1;
            v--;
            v >>= 1;
            p--;
            x = v - x;
            res.push_back(x);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// class Solution:
//     def pathInZigZagTree(self, label: int) -> List[int]:
//         p = 0
//         x = label
//         while label > 0:
//             p += 1
//             label //= 2
//         p -= 1
//         res = [x]
//         while x != 1:
//             x //= 2
//             v = 2 ** p + 2 ** (p-1) - 1
//             p -= 1
//             x = v - x
//             res.append(x)
//         res.reverse()
//         return res

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

