/*
Author : Saransh Bangar
Date : 15/03/2024
Problem : Product of Array Except Self
Difficulty : Medium 
Problem Link : https://leetcode.com/problems/product-of-array-except-self/description/
Video Solution : NA
*/


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int n=nums.size();
        vector<int> l(n, 1), r(n, 1);
        int left=1;
        for (int i=0;i<n;i++)
        {
            l[i]=left;
            left*=nums[i];
        }
        int right=1;
        for (int i=n-1;i>=0;i--)
        {
            r[i]=right;
            right*=nums[i];
        }
        vector<int>result(n);
        for (int i=0;i<n;i++)
            result[i]=l[i]*r[i];
        return result;
    }
};
