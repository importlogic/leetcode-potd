/*

Author : Manas Rawat
Date : 25/11/2023
Problem : Sum of Absolute Differences in a Sorted Array
Difficulty : Medium
Problem Link : https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/
Video Solution : https://youtu.be/dnbR2VnrSp8

*/


class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> prefix(n, 0), suffix(n, 0);
        prefix[0] = nums[0];
        suffix[n - 1] = nums[n - 1];
        
        for(int i = 1; i < n; i++){
            prefix[i] = nums[i] + prefix[i - 1];
            suffix[n - i - 1] = nums[n - i - 1] + suffix[n - i];
        }
        
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            int left = i * nums[i] - (i ? prefix[i - 1] : 0);
            int right = ((i < n - 1) ? suffix[i + 1] : 0) - nums[i] * (n - i - 1);
            
            ans[i] = left + right;
        }
        
        return ans;
    }
};