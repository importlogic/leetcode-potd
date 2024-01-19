/*

Author : Manas Rawat
Date : 19/01/2024
Problem : Minimum Falling Path Sum
Difficulty : Medium
Problem Link : https://leetcode.com/problems/minimum-falling-path-sum/description/
Video Solution : https://youtu.be/j1IRI_GgnbI

*/


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int dp[n][m];
        for(int i = 0; i < m; i++)
            dp[n - 1][i] = matrix[n - 1][i];

        for(int i = n - 2; i > -1; i--){
            for(int j = 0; j < m; j++){
                int best = dp[i + 1][j];

                if(j > 0)
                    best = min(dp[i + 1][j - 1], best);

                if(j < n - 1)
                    best = min(dp[i + 1][j + 1], best);

                dp[i][j] = best + matrix[i][j];
            }
        }

        return *min_element(dp[0], dp[0] + m);
    }
};