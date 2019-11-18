/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     1260.cpp
* Author:   roeexu
* Date:     2019-11-18 22:10:30
* Brief:
****************************************************/

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if (grid.empty() || grid[0].empty()) return grid;
        int m = grid.size(), n = grid[0].size(), sz = m * n, pos;
        vector<vector<int>> ans(m, vector<int>(n, 0));
        k = k % sz;
        pos = (sz - k) % sz;
        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c) {
                ans[r][c] = grid[pos / n][pos % n];
                pos = (pos + 1) % sz;
            }
        return ans;
    }

    // mine
    // vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
	// 	deque<int> line;
    //     for(auto x : grid)
    //         for(auto y : x)
    //             line.push_back(y);
    // int m = grid.size(), n = grid[0].size(), sz = m * n;
    // k = k % sz;
	// 	while(k-- > 0){
    //         line.push_front(line.back());
    //         line.pop_back();
    //     }
	// 	for (int i = 0, k = 0; i < grid.size(); ++i)
	// 		for (int j = 0; j < grid[i].size(); ++j)
	// 			grid[i][j] = line.at(k++);
	// 	return grid;
	// }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */
