/*

Author : Manas Rawat
Date : 07/01/2024
Problem : Arithmetic Slices II - Subsequence
Difficulty : Hard
Problem Link : https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
Video Solution : https://youtu.be/mcoTTCwPmTk

*/


class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        
        vector<unordered_map<int,int>> dp(n);
        unordered_map<long long, vector<int>> pos;
        
        for(int i = 0; i < n; i++)
            pos[nums[i]].push_back(i);
        
        int ans = 0;
        
        function<int(int, long long)> helper = [&](int p, long long dx) -> int {
            if(dp[p].count(dx))
                return dp[p][dx];
            
            dp[p][dx] = 1;
            
            long long need = nums[p] + dx;
            
            int next = lower_bound(pos[need].begin(), pos[need].end(), p + 1) - pos[need].begin();
            
            for(int i = next; i < pos[need].size(); i++){
                dp[p][dx] += helper(pos[need][i], dx);
            }
            
            return dp[p][dx];
        };
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++)
                ans += helper(j, (long long)nums[j] - (long long)nums[i]) - 1;
        }    
        
        return ans;
    }
};