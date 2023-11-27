/*

Author : Manas Rawat
Date : 27/11/2023
Problem : Knight Dialer
Difficulty : Medium
Problem Link : https://leetcode.com/problems/knight-dialer/
Video Solution : https://youtu.be/1nUmbFuRHmI

*/


class Solution {
public:
    int knightDialer(int n) {
        vector<vector<long long>> dp(n, vector<long long> (10, 0));
        
        for(int i = 0; i < 10; i++)
            dp[n - 1][i] = 1;
        
        const long long mod = 1e9 + 7;
        
        vector<vector<int>> go = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
        
        for(int i = n - 2; i > -1; i--){
            for(int j = 0; j < 10; j++){
                for(auto next : go[j]){
                    dp[i][j] = (dp[i][j] + dp[i + 1][next]) % mod;
                }
            }
        }
        
        long long ans = 0;
        
        for(int i = 0; i < 10; i++){
            ans = (ans + dp[0][i]) % mod;
        }
        
        return ans;
    }
};