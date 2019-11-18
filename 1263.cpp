/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     1263.cpp
* Author:   roeexu
* Date:     2019-11-18 22:28:53
* Brief:
****************************************************/

typedef pair<int, int> ii;
const int d[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int N = 20;
int flag[N][N][N][N];

struct Node {
    int px, py, bx, by;
};

class Solution {
public:
    int minPushBox(vector<vector<char>>& a) {
        int n = a.size(), m = a[0].size();
        int px, py, bx, by, tx, ty;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == 'S') {
                    px = i;
                    py = j;
                    a[i][j] = '.';
                } else if (a[i][j] == 'T') {
                    tx = i;
                    ty = j;
                    a[i][j] = '.';
                } else if (a[i][j] == 'B') {
                    bx = i;
                    by = j;
                    a[i][j] = '.';
                }
            }
        }
        memset(flag, 255, sizeof(flag));
        deque<Node> Q;
        Q.push_back({px, py, bx, by});
        flag[px][py][bx][by] = 0;
        while (!Q.empty()) {
            auto [px, py, bx, by] = Q.front();
            if (bx == tx && by == ty) return flag[px][py][bx][by];
            Q.pop_front();
            for (int k = 0; k < 4; ++k) {
                int nx = px + d[k][0];
                int ny = py + d[k][1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || a[nx][ny] != '.') continue;
                if (nx == bx && ny == by) continue;
                if (flag[nx][ny][bx][by] >= 0) continue;
                flag[nx][ny][bx][by] = flag[px][py][bx][by];
                Q.push_front({nx, ny, bx, by});
            }
            if (abs(px - bx) + abs(py - by) == 1) {
                int k;
                for (k = 0; k < 4; ++k) {
                    int nx = px + d[k][0];
                    int ny = py + d[k][1];
                    if (nx == bx && ny == by) break;
                }
                int nbx = bx + d[k][0];
                int nby = by + d[k][1];
                if (!(nbx < 0 || nbx >= n || nby < 0 || nby >= m || a[nbx][nby] != '.') && flag[bx][by][nbx][nby] < 0) {
                    flag[bx][by][nbx][nby] = flag[px][py][bx][by] + 1;
                    Q.push_back({bx, by, nbx, nby});
                }
            }
        }
        return -1;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */
