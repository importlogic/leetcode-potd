/*
Author : Saransh Bangar
Date : 08/03/2024
Problem : Count Elements With Maximum Frequency
Difficulty : Easy 
Problem Link : https://leetcode.com/problems/count-elements-with-maximum-frequency/description/
Video Solution : NA
*/


class Solution {
public:
    int maxFrequencyElements(vector<int>& nums)
    {
        vector<int> a(101, 0);

        int maxFreq = INT_MIN;
        for(int i=0; i<nums.size(); i++) {
            a[nums[i]] += 1;
            maxFreq = max(maxFreq, a[nums[i]]);
        }

        int count = 0;
        for(int i=0; i<nums.size(); i++)
            if(a[nums[i]] == maxFreq)
                count++;

        return count;
    }
};
