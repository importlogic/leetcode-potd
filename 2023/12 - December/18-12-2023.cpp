/*

Author : Manas Rawat
Date : 18/12/2023
Problem : Maximum Product Difference Between Two Pairs
Difficulty : Easy
Problem Link : https://leetcode.com/problems/maximum-product-difference-between-two-pairs/
Video Solution : https://youtu.be/EbNkxg9vJhs

*/


class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        return nums[n - 1] * nums[n - 2] - nums[0] * nums[1];
    }
};