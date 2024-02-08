/*

Author : Manas Rawat
Date : 08/02/2024
Problem : Perfect Squares
Difficulty : Medium
Problem Link : https://leetcode.com/problems/perfect-squares/description/
Video Solution : https://youtu.be/8zPDyIUG90Y

*/


class Solution {
public:
    int numSquares(int n) {
        const int inf = 1e9;
        vector<vector<int>> dp(102, vector<int> (n + 1, inf));

        for(int i = 0; i < 102; i++)
            dp[i][0] = 0;

        for(int i = 100; i > -1; i--){
            for(int j = 0; j < n + 1; j++){
                int take = inf, notake = inf;

                notake = dp[i + 1][j];

                if(i * i <= j)
                    take = 1 + dp[i][j - i * i];

                dp[i][j] = min(take, notake);
            }
        }

        return dp[0][n];
    }    
};