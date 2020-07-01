/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     1418.cpp
* Author:   roee
* Date:     2020-07-02 00:27:28
* Brief:
****************************************************/

class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        set<string> foods;
        map<int, unordered_map<string, int>> menuMap;
        for(auto& order: orders) {
            foods.insert(order[2]);
            menuMap[stoi(order[1])][order[2]]++;
        }
        unordered_map<string, int> title;         
        vector<vector<string>> menu(1 + menuMap.size(), vector<string>(1 + foods.size(), "0"));
        menu[0][0] = "Table";
        int index = 1;
        for(auto& food: foods) {
            menu[0][index] = food;
            title[food] = index++;
        }
        int i = 1;
        for(auto& [tableNum, tableOrder]: menuMap) {
            menu[i][0] = to_string(tableNum);
            for (auto& [foodName, foodCount]: tableOrder)
                menu[i][title[foodName]] = to_string(foodCount);
            i++;
        }
        return menu;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */
