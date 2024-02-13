/*

Author : Manas Rawat
Date : 11/02/2024
Problem : Cherry Pickup II
Difficulty : Hard
Problem Link : https://leetcode.com/problems/cherry-pickup-ii/description/
Video Solution : https://youtu.be/8D1mZ4lX8PI

*/


class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int dp[n][m][m];

        for(int i = n - 1; i > -1; i--){
            for(int x = 0; x < m; x++){
                for(int y = 0; y < m; y++){
                    dp[i][x][y] = 0;

                    for(int p1 = -1; p1 < 2; p1++){
                        for(int p2 = -1; p2 < 2; p2++){
                            if(x + p1 > -1 and x + p1 < m and y + p2 > -1 and y + p2 < m){
                                int cur = grid[i][x];
                                
                                if(x != y)
                                    cur += grid[i][y];

                                if(i + 1 < n){
                                    cur += dp[i + 1][x + p1][y + p2];
                                }

                                dp[i][x][y] = max(dp[i][x][y], cur);
                            }
                        }
                    }
                }
            }
        }

        return dp[0][0][m - 1];
    }
};
Difficulty : Hard