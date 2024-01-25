/*

Author : Manas Rawat
Date : 25/01/2024
Problem : Longest Common Subsequence
Difficulty : Medium
Problem Link : https://leetcode.com/problems/longest-common-subsequence/description/
Video Solution : https://youtu.be/CIHmh14hkMM

*/


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        int dp[n + 1][m + 1];

        for(int i = 0; i < m + 1; i++)
            dp[n][i] = 0;
        for(int i = 0; i < n + 1; i++)
            dp[i][m] = 0;

        for(int i = n - 1; i > -1; i--){
            for(int j = m - 1; j > -1; j--){
                if(text1[i] == text2[j]){
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                else{
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        return dp[0][0];
    }
};