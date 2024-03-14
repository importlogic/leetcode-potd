/*
Author : Saransh Bangar
Date : 14/03/2024
Problem : Binary Subarrays With Sum
Difficulty : Medium 
Problem Link : https://leetcode.com/problems/binary-subarrays-with-sum/description/
Video Solution : NA
*/


class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal)
    {
        unordered_map<int, int>map;
        int sum=0, count=0;
        for (int i : nums)
        {
            sum+=i;
            if (sum==goal)
                count++;
            if (map.find(sum-goal)!=map.end())
                count+=map[sum-goal];
            map[sum]++;
        }
        return count;
    }
};
