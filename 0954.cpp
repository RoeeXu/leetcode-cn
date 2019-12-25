/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0954.cpp
* Author:   root
* Date:     2019-12-26 07:18:03
* Brief:
****************************************************/

class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        map<int, int> save;
        map<int, int>::iterator it;
        int x, cnt;
        for(auto x : A)
        {
            if(save.count(x) > 0) save[x]++;
            else save[x] = 1;
        }
        for(auto& p : save) cout<<p.first<<" "<<p.second<<endl;
        while(save.size() > 0)
        {
            x = save.begin()->first;
            if(x == 0 && save[x] % 2 == 0) save.erase(x);
            else if(x > 0 && save.count(x * 2) > 0)
            {
                cnt = min(save[x], save[x * 2]);
                save[x] -= cnt;
                save[x * 2] -= cnt;
                if(save[x] == 0) save.erase(x);
                if(save[x * 2] == 0) save.erase(x * 2);
            }
            else if(x < 0 && x % 2 == 0 && save.count(x / 2) > 0)
            {
                cnt = min(save[x], save[x / 2]);
                save[x] -= cnt;
                save[x / 2] -= cnt;
                if(save[x] == 0) save.erase(x);
                if(save[x / 2] == 0) save.erase(x / 2);
            }
            else return 0;
        }
        return 1;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

