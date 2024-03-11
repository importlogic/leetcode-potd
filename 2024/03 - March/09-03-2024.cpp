/*
Author : Saransh Bangar
Date : 09/03/2024
Problem : Minimum Common Value
Difficulty : Easy 
Problem Link : https://leetcode.com/problems/minimum-common-value/description/
Video Solution : NA
*/


class Solution {
public:
    bool func(vector<int>& vec, int k)
    {
        int low=0, high=vec.size()-1;
        while (low<=high)
        {
            int mid=low+((high-low)/2);
            if (vec[mid]==k)
                return true;
            else if (vec[mid]>k)
                high=mid-1;
            else low=mid+1;
        }
        return false;
    }
    int getCommon(vector<int>& nums1, vector<int>& nums2)
    {
        int ans;
        for (int i=0, j=0;i<nums1.size() && j<nums2.size();)
        {
            if (nums1[i]>nums2[j])
            {
                if (func(nums1, nums2[j]))
                    return nums2[j];
                else j++;
            }
            else
            {
                if (func(nums2, nums1[i]))
                    return nums1[i];
                else i++;
            }
        }    
        return -1;
    }
};
