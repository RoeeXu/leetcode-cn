/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0074.cpp
* Author:   root
* Date:     2019-11-22 02:21:33
* Brief:
****************************************************/

class Solution {
public:
    // logmn
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     if  (matrix.size() == 0 || matrix[0].size() == 0) return false;
    //     int m = matrix.size();
    //     int n = matrix[0].size();
    //     int i = 0, j = m * n - 1;
    //     while (i <= j) {
    //         int mid = i + ((j - i) >> 1);
    //         if (matrix[mid / n][mid % n] == target) return true;
    //         else if (matrix[mid / n][mid % n] > target) j = mid - 1;
    //         else i = mid + 1;
    //     }
    //     return false;
    // }

    // m + n
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return 0;
        int col = matrix[0].size() - 1, row = 0, m = matrix.size();
        while(col >= 0 && row < m)
        {
            if(matrix[row][col] == target) return 1;
            else if(matrix[row][col] > target) col--;
            else row++;
        }
        return 0;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

