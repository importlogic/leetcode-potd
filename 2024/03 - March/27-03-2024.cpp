/*

Author : Saransh Bangar
Date : 27/03/2024
Problem : Subarray Product Less Than K
Difficulty : Medium
Problem Link : https://leetcode.com/problems/subarray-product-less-than-k/
Video Solution : NA

*/


class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k)
    {
        if (k<=1)
            return 0;
        int mult=1, ans=0, l=0;
        for (int r=0;r<nums.size();r++)
        {
            mult*=nums[r];
            while (mult>=k)
            {
                mult/=nums[l];
                l++;
            }
            ans+=r-l+1;
        }
        return ans;
    }
};
