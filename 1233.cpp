/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     1233.cpp
* Author:   root
* Date:     2019-12-03 00:33:13
* Brief:
****************************************************/

// mine
// struct FileSys {
//     bool exist;
//     unordered_map<string, FileSys*> s;
//     FileSys() : exist(false), s({}) {}
// };

class Solution {

    // best
    class Tree{
        public:
            Tree* next[26];
            bool f = false;
            bool end = false;
    };

public:
    // best 思路和 simple 一样，但是单个字符判断，效率高多了
    Tree* head = new Tree();
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> res;
        sort(folder.begin(),folder.end(),[&](const string& a,const string& b){return a.size() < b.size();});
        for(auto s : folder){
            if(!find(s)) {
                res.push_back(s);
                build(s);
            }
        }
        return res;
    }
    bool find(const string& s){
        auto cur = head;
        int i = 1;
            for(;i < s.size();i++){
                auto c = s[i];
                if(c == '/') {
                    if(cur -> end) return true;
                    else if(!cur -> f) return false;
                    continue;
                }
                int ascii = c - 'a';
                if(!cur -> next[ascii]) return cur -> end && s[i + 1] == '/';
                cur = cur -> next[ascii];
            }
        return cur -> end;
    }
    void build(const string& s){
        auto cur = head;
            for(int i = 1;i < s.size();i++){
                auto c = s[i];
                if(c == '/') {
                    cur -> f = true;
                    continue;
                }
                int ascii = c - 'a';
                if(!(cur -> next[ascii])) cur -> next[ascii] = new Tree();
                cur = cur -> next[ascii];
            }
            cur -> end = true;
    }

    // simple
    // vector<string> removeSubfolders(vector<string>& folder) {
    //     sort(folder.begin(),folder.end());
    //     vector<string> ans;
    //     ans.push_back(folder[0]);
    //     for(int i = 1; i < folder.size(); ++i){
    //         string father = ans.back() + "/", cur = folder[i];
    //         if(cur.find(father) == cur.npos) ans.push_back(cur);
    //     }
    //     return ans;
    // }

    // mine
    // void dfs(vector<string>& res, unordered_map<string, FileSys*>& filesys, string tmp)
    // {
    //     for(auto& p : filesys)
    //     {
    //         string t = tmp + '/' + p.first;
    //         if(p.second->exist) res.push_back(t);
    //         else dfs(res, p.second->s, t);
    //     }
    // }
    
    // vector<string> removeSubfolders(vector<string>& folder) {
    //     vector<string> res;
    //     unordered_map<string, FileSys*> filesys;
    //     for(auto& f : folder)
    //     {
    //         if(f.length() == 1) continue;
    //         if(f[f.length() - 1] != '/') f += '/';
    //         int p = 1, q = 0;
    //         string tmp;
    //         q = f.find('/', p);
    //         unordered_map<string, FileSys*>* A = &filesys;
    //         while(q != -1)
    //         {
    //             tmp = f.substr(p, q - p);
    //             if((*A).count(tmp) == 0) (*A)[tmp] = new FileSys();
    //             p = q + 1;
    //             q = f.find('/', p);
    //             if(q == -1) (*A)[tmp]->exist = true;
    //             else A = &((*A)[tmp]->s);
    //         }
    //     }
    //     dfs(res, filesys, "");
    //     return res;
    // }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

