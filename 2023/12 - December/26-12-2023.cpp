/*

Author : Manas Rawat
Date : 26/12/2023
Problem : Number of Dice Rolls With Target Sum
Difficulty : Medium
Problem Link : https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
Video Solution : https://youtu.be/NIayybqPOpg

*/


class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int> (k * n + 1, 0));
        
        if(target > k * n)
            return 0;
        
        dp[n][target] = 1;
        
        const int mod = 1e9 + 7;
        
        for(int i = n - 1; i > -1; i--){
            for(int j = 0; j < k * i + 1; j++){

                for(int z = 1; z < k + 1; z++){
                    dp[i][j] = (dp[i][j] + dp[i + 1][j + z]) % mod;
                }
            }
        }
        
        return dp[0][0];
    }
};