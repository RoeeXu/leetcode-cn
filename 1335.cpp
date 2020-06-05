/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     1335.cpp
* Author:   roeexu
* Date:     2020-06-05 15:50:40
* Brief:
****************************************************/
 
// class Solution {
// public:
//     int minDifficulty(vector<int>& jobDifficulty, int d) {
//         int n = jobDifficulty.size();
//         vector<vector<int>> bd(n, vector<int>(n + 1));
//         for(int i = 0; i < n; i++)
//             for(int j = 0; j < n - i; j++)
//                 if(i == 0) bd[i][j] = jobDifficulty[j];
//                 else bd[i][j] = max(bd[i - 1][j], bd[i - 1][j + 1]);
//         vector<vector<int>> dp(d + 1, vector<int>(n, 1e9));
//         for(int i = 1; i <= d; i++)
//             for(int j = i - 1; j < n; j++)
//                 if(i == 1) dp[i][j] = bd[j][0];
//                 else for(int k = i - 2; k < j; k++) dp[i][j] = min(dp[i][j], dp[i - 1][k] + bd[j - k - 1][k + 1]);
//         return dp[d][n - 1] == 1e9 ? -1 : dp[d][n - 1];
//     }
// };

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int len=jobDifficulty.size();
        int **dp=new int*[len+1];
        for(int i=0;i<=len;i++)dp[i]=new int[d];
        for(int i=len-1,tempmax=INT_MIN;i>=0;i--){
            if(tempmax<jobDifficulty[i])tempmax=jobDifficulty[i];
            dp[i][d-1]=tempmax;
        }
        dp[len][d-1]=-1;
        for(int i=d-2;i>=0;i--){
            for(int j=0;j<len;j++){
                dp[j][i]=INT_MAX;
                int tempmax=INT_MIN;
                for(int k=j;k<len-1;k++){
                    if(tempmax<jobDifficulty[k])tempmax=jobDifficulty[k];
                    if(dp[k+1][i+1]!=-1&&dp[j][i]>tempmax+dp[k+1][i+1])dp[j][i]=tempmax+dp[k+1][i+1];
                }
                if(dp[j][i]==INT_MAX)dp[j][i]=-1;
               // cout<<j<<" "<<i<<" "<<dp[j][i]<<endl;
            }
            dp[len][i]=-1;
        }
        return dp[0][0];
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

