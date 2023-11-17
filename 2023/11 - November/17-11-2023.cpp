/*

Author : Manas Rawat
Date : 17/11/2023
Problem : Minimize Maximum Pair Sum in Array
Difficulty : Medium
Problem Link : https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/
Video Solution : https://youtu.be/0H5B0VoarzI

*/


class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int ans = 0;
        for(int i = 0; i < n / 2; i++){
            ans = max(ans, nums[i] + nums[n - i - 1]);
        }
        
        return ans;
    }
};