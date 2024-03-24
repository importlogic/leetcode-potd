/*

Author : Saransh Bangar
Date : 24/03/2024
Problem : Find the Duplicate Number
Difficulty : Medium 
Problem Link : https://leetcode.com/problems/find-the-duplicate-number/description/
Video Solution : NA

*/


class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        int slow=nums[0];
        int fast=nums[0];
        do
        {
            slow=nums[slow];
            fast=nums[nums[fast]];
        } 
        while (slow!=fast);
            slow=nums[0];
        while (slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        return fast;
    }
};
