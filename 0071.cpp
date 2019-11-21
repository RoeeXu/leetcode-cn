/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0071.cpp
* Author:   root
* Date:     2019-11-21 11:42:26
* Brief:
****************************************************/

class Solution {
public:
    // best
    string simplifyPath(string path) {
        string res, t;
        stringstream ss(path);
        vector<string> v;
        while(getline(ss, t, '/'))
        {
            if(t == "" || t == ".") continue;
            if(t == ".." && !v.empty()) v.pop_back();
            else if(t != "..") v.push_back(t);
        }
        for(auto& s : v) res += "/" + s;
        return res.empty() ? "/" : res;
    }

    // mine
    // string simplifyPath(string path) {
    //     vector<char> s;
    //     int n = path.length(), p = 0;
    //     char tmp1, tmp2;
    //     while(p < n)
    //     {
    //         if(s.size() == 0) s.push_back(path[p]);
    //         else
    //         {
    //             tmp1 = s[s.size() - 1];
    //             tmp2 = path[p];
    //             if(tmp1 == '/' && tmp2 == '/') ;
    //             else if(tmp1 == '.' && tmp2 == '/' && s.size() > 1 && s[s.size() - 2] != '.') s.pop_back();
    //             else if(tmp1 == '.' && tmp2 == '/' && s.size() < 2) s.pop_back();
    //             else s.push_back(path[p]);
    //         }
    //         p++;
    //     }
    //     if(s[s.size() - 1] != '/') s.push_back('/');
    //     stack<string> t;
    //     string r;
    //     for(int i = 1; i < s.size(); i++)
    //     {
    //         if(s[i] == '/')
    //         {
    //             if(r == ".." && t.size() != 0) t.pop();
    //             else if(r != ".." && r != ".") t.push(r);
    //             r = "";
    //         }
    //         else r += s[i];
    //     }
    //     while(t.size() > 0)
    //     {
    //         r = '/' + t.top() + r;
    //         t.pop();
    //     }
    //     if(r.length() == 0) return "/";
    //     return r;
    // }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

