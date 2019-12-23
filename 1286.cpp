/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     1286.cpp
* Author:   roeexu
* Date:     2019-12-23 13:33:32
* Brief:
****************************************************/

class CombinationIterator {
public:
    vector<string> res;
    int index = 0;

    CombinationIterator(string characters, int combinationLength) {
        res.clear();
        string tmp = "";
        dfs(characters, combinationLength, tmp, 0);
        reverse(res.begin(), res.end());
    }

    void dfs(string& characters, int combinationLength, string& tmp, int pos) {
        if(tmp.length() == combinationLength) {res.push_back(tmp); return;}
        if(characters.length() == pos) return;
        dfs(characters, combinationLength, tmp, pos+1);
        tmp += characters[pos];
        dfs(characters, combinationLength, tmp, pos+1);
        tmp.pop_back();
        return;
    }
    
    string next() {
        string t = res[index];
        index++;
        return t;
    }
    
    bool hasNext() {
        if(res.size() > index) return 1;
        return 0;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

