/*

Author : Manas Rawat
Date : 27/01/2024
Problem : K Inverse Pairs Array
Difficulty : Hard
Problem Link : https://leetcode.com/problems/k-inverse-pairs-array/description/
Video Solution : https://youtu.be/-O-YUrcrvH4

*/


class Solution {
public:
    int kInversePairs(int n, int k) {
        const long long mod = 1e9 + 7;

        vector<vector<long long>> dp(n + 1, vector<long long> (k + 1, 1));

        for(int i = 1; i < n + 1; i++){
            for(int j = 1; j < k + 1; j++){
                int MAX = j;
                int MIN = j - (i - 1);

                dp[i][j] = (dp[i][j - 1] + (dp[i - 1][MAX] - (MIN > 0 ? dp[i - 1][MIN - 1] : 0) + mod)) % mod;
            }
        }

        return (dp[n][k] - (k > 0 ? dp[n][k - 1] : 0) + mod) % mod;
    }
};