/*

Author : Manas Rawat 
Date : 26/03/2024
Problem : First Missing Positive
Difficulty : Hard 
Problem Link : https://leetcode.com/problems/first-missing-positive/description/
Video Solution : NA

*/


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for (auto& num : nums) {
            if (num <= 0) num = n + 1;
        }

        for (auto& num : nums) {
            int index = abs(num) - 1;
            if (index < n) nums[index] = -abs(nums[index]);
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) return (i + 1);
        }
        
        return (n + 1);        
    }
};
