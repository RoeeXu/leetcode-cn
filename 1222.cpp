/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     1222.cpp
* Author:   roeexu
* Date:     2019-11-29 13:34:26
* Brief:
****************************************************/

class Solution {
public:
    // vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
    //     int a = king[0], b = king[1], x, y;
    //     int s[8][2];
    //     for(int i = 0; i < 8; i++) for(int j = 0; j < 2; j++) s[i][j] = -1;
    //     for(auto& q : queens)
    //     {
    //         x = q[0], y = q[1];
    //         if(x == a && y > b && (s[0][0] == -1 || s[0][1] > y)) {s[0][0] = x; s[0][1] = y;}
    //         else if(x == a && y < b && (s[1][0] == -1 || s[1][1] < y)) {s[1][0] = x; s[1][1] = y;}
    //         else if(y == b && x > a && (s[2][0] == -1 || s[2][0] > x)) {s[2][0] = x; s[2][1] = y;}
    //         else if(y == b && x < a && (s[3][0] == -1 || s[3][0] < x)) {s[3][0] = x; s[3][1] = y;}
    //         else if(x + y == a + b && x - y > a - b && (s[4][0] == -1 || s[4][0] - s[4][1] > x - y)) {s[4][0] = x; s[4][1] = y;}
    //         else if(x + y == a + b && x - y < a - b && (s[5][0] == -1 || s[5][0] - s[5][1] < x - y)) {s[5][0] = x; s[5][1] = y;}
    //         else if(x - y == a - b && x + y > a + b && (s[6][0] == -1 || s[6][0] + s[6][1] > x + y)) {s[6][0] = x; s[6][1] = y;}
    //         else if(x - y == a - b && x + y < a + b && (s[7][0] == -1 || s[7][0] + s[7][1] < x + y)) {s[7][0] = x; s[7][1] = y;}
    //     }
    //     vector<vector<int>> res;
    //     for(int i = 0; i < 8; i++) if(s[i][0] != -1) res.push_back({s[i][0], s[i][1]});
    //     return res;
    // }

    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        int cb[8][8];
        for(int i=0;i<8;i++) for(int j=0;j<8;j++) cb[i][j]=0;
        for(int i=0;i<queens.size();i++) cb[queens[i][0]][queens[i][1]]=1;
        vector<vector<int> >ret;
        int dir[8][2]={{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
        int x,y;
        for(int i=0;i<8;i++){
            x=king[0];
            y=king[1];
            while(1){
                x+=dir[i][0];
                y+=dir[i][1];
                if(x>=8||x<0||y>=8||y<0) break;
                if(cb[x][y]==1){
                    ret.push_back({x, y});
                    break;
                }
            }
        }
        return ret;
    }

    // vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
    //     int row[8] = {0}, col[8] = {0}, cli[15] = {0}, ant[15] = {0}, x, y;
    //     for(auto& q : queens)
    //     {
    //         x = q[0];
    //         y = q[1];
    //         row[x] |= 1 << y;
    //         col[y] |= 1 << x;
    //         cli[7 - x + y] |= 1 << (x + y);
    //         ant[x + y] |= 1 << (7 - x + y);
    //     }
    //     x = king[0], y = king[1];
    //     vector<vector<int>> res;
    //     for(int i = y + 1; i < 8; i++)
    //         if(row[x] & 1 << i) {
    //             res.push_back({x, i});
    //             break;
    //         }
    //     for(int i = y - 1; i >= 0; i--)
    //         if(row[x] & 1 << i) {
    //             res.push_back({x, i});
    //             break;
    //         }
    //     for(int i = x - 1; i >= 0; i--)
    //         if(col[y] & 1 << i) {
    //             res.push_back({i, y});
    //             break;
    //         }
    //     for(int i = x + 1; i < 8; i++)
    //         if(col[y] & 1 << i) {
    //             res.push_back({i, y});
    //             break;
    //         }
    //     for(int i = 1; x + i < 8 && y + i < 8; i++)
    //         if(cli[7 - x + y] & 1 << (x + y + 2 * i)) {
    //             res.push_back({x + i, y + i});
    //             break;
    //         }
    //     for(int i = 1; x - i >= 0 && y - i >= 0; i++)
    //         if(cli[7 - x + y] & 1 << (x + y - 2 * i)) {
    //             res.push_back({x - i, y - i});
    //             break;
    //         }
    //     for(int i = 1; x + i < 8 && y - i >= 0; i++)
    //         if(ant[x + y] & 1 << (7 - x + y - 2 * i)) {
    //             res.push_back({x + i, y - i});
    //             break;
    //         }
    //     for(int i = 1; x - i >= 0 && y + i < 8; i++)
    //         if(ant[x + y] & 1 << (7 - x + y + 2 * i)) {
    //             res.push_back({x - i, y + i});
    //             break;
    //         }
    //     return res;
    // }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

