/*

Author : Manas Rawat
Date : 05/01/2024
Problem : Longest Increasing Subsequence
Difficulty : Medium
Problem Link : https://leetcode.com/problems/longest-increasing-subsequence/
Video Solution : https://youtu.be/cvm3rvd8Pfw

*/


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n, 1e5);
        
        for(int i = 0; i < n; i++){
            int p = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
            
            if(p < n)
                dp[p] = min(dp[p], nums[i]);
        }
        
        for(int i = n - 1; i > -1; i--){
            if(dp[i] < 1e5)
                return i + 1;
        }
        
        return 0;
    }
};