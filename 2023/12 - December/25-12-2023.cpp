/*

Author : Manas Rawat
Date : 25/12/2023
Problem : Decode Ways
Difficulty : Medium
Problem Link : https://leetcode.com/problems/decode-ways/
Video Solution : NA

*/


class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        
        vector<int> dp(n + 1);
        dp[n] = 1;
        
        for(int i = n - 1; i > -1; i--){
            if(s[i] == '0'){
                dp[i] = 0;
            }
            else{
                dp[i] = dp[i + 1];
                
                if(i < n - 1 and stoi(s.substr(i, 2)) < 27)
                    dp[i] += dp[i + 2];
            }
        }
        
        return dp[0];
    }
};