/*

Author : Manas Rawat
Date : 27/12/2023
Problem : Minimum Time to Make Rope Colorful
Difficulty : Medium
Problem Link : https://leetcode.com/problems/minimum-time-to-make-rope-colorful/
Video Solution : https://youtu.be/uhBSJYY1Mw4

*/


class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        vector<vector<int>> dp(n + 1, vector<int> (27, 0));
        
        const int inf = 1e9;
        
        for(int i = n - 1; i > -1; i--){
            for(int j = 0; j < 27; j++){
                int remove, noremove;

                remove = neededTime[i] + dp[i + 1][j];
                noremove = dp[i + 1][colors[i] - 'a' + 1];
                
                if(colors[i] - 'a' + 1 == j)
                    dp[i][j] = remove;
                else
                    dp[i][j] = min(remove, noremove);
            }
        }
        
        return dp[0][0];
    }
};