/*

Author : Manas Rawat
Date : 09/02/2024
Problem : Largest Divisible Subset
Difficulty : Medium
Problem Link : https://leetcode.com/problems/largest-divisible-subset/description/
Video Solution : https://youtu.be/nFJ5p7Gz1hM

*/


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> dp(n + 1, vector<int> (2, 0));

        for(int i = n - 1; i > -1; i--){
            dp[i][0] = 1;
            dp[i][1] = i;

            for(int j = i + 1; j < n; j++){
                if(nums[j] % nums[i] == 0 and 1 + dp[j][0] > dp[i][0]){
                    dp[i][0] = 1 + dp[j][0];
                    dp[i][1] = j;
                }
            }
        }

        int best = 0;
        int start = 0;

        for(int i = 0; i < n; i++){
            if(dp[i][0] > best){
                best = dp[i][0];
                start = i;
            }
        }

        vector<int> ans;
        while(best--){
            ans.push_back(nums[start]);
            start = dp[start][1];
        }   

        return ans;
    }
};