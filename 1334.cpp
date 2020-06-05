/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     1334.cpp
* Author:   roeexu
* Date:     2020-06-05 14:54:33
* Brief:
****************************************************/
 
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> board(n, vector<int>(n, 10001));
        for(auto& e : edges) if(e[2] <= distanceThreshold) board[e[0]][e[1]] = board[e[1]][e[0]] = e[2];
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = i + 1; j < n; j++) {
                    int z = board[i][k] + board[k][j];
                    if(z <= distanceThreshold && z < board[i][j])
                        board[i][j] = board[j][i] = z;
                }
        int idx = -1, num = n + 1, cnt = 0;
        for(int i = 0; i < n; i++) {
            cnt = 0;
            for(int j = 0; j < n; j++) if(board[i][j] <= distanceThreshold) cnt++;
            if(cnt <= num) {
                num = cnt;
                idx = i;
            }
        }
        return idx;
    }
};

// class Solution {
// public:
//     map<int, map<int, int>> graph;
    
//     int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
//         for(auto& e : edges) {
//             int x = e[0], y = e[1], w = e[2];
//             if(w > distanceThreshold) continue;
//             if(!graph.count(x)) graph[x] = {};
//             if(!graph.count(y)) graph[y] = {};
//             graph[x][y] = w;
//             graph[y][x] = w;
//         }
//         int idx = -1, res = 1e9;
//         for(int node = 0; node < n; node++) {
//             int r = findShortNum(n, node, distanceThreshold);
//             if(r <= res) {
//                 idx = node;
//                 res = r;
//             }
//         }
//         return idx;
//     }
    
//     int findShortNum(int n, int node, int threshold) {
//         vector<int> d(n, 1e9);
//         d[node] = 0;
//         set<int> v;
//         deque<int> q;
//         q.push_back(node);
//         while(q.size() > 0) {
//             int x = q.front();
//             q.pop_front();
//             v.insert(x);
//             if(!graph.count(x)) continue;
//             for(auto& t : graph[x]) {
//                 int y = t.first, w = t.second, z = d[x] + w;
//                 if(d[y] > z && z <= threshold) {
//                     d[y] = z;
//                     q.push_back(y);
//                 }
//             }
//         }
//         int r = 0;
//         for(auto& x : d) if(x <= threshold) r++;
//         return r;
//     }
// };

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

