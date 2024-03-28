/*

Author : Saransh Bangar
Date : 28/03/2024
Problem : Length of Longest Subarray With at Most K Frequency
Difficulty : Medium 
Problem Link : https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/
Video Solution : NA

*/


class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k)
    {
        int start=-1, end=0, ans=0;
        unordered_map<int, int>map;
        for(;end<nums.size();end++)
        {
            map[nums[end]]++;
            while(map[nums[end]]>k)
            {
                start++;
                map[nums[start]]--;
            }
            ans=max(ans, end-start);
        }
        return ans;
    }
};
