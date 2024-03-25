/*

Author : Saransh Bangar
Date : 25/03/2024
Problem : Find All Duplicates in an Array
Difficulty : Medium 
Problem Link : https://leetcode.com/problems/find-all-duplicates-in-an-array/description/
Video Solution : NA

*/



class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        vector<int>ans;
        for (int i=0;i<nums.size()-1;i++)
        {
            if (nums[i]==nums[i+1])
                ans.push_back(nums[i]);
        }
        return ans;    
    }
};
