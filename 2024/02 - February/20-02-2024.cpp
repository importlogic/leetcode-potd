/*

Author : Manas Rawat
Date : 20/02/2024
Problem : Missing Number
Difficulty : Easy
Problem Link : https://leetcode.com/problems/missing-number/description/?envType=daily-question&envId=2024-02-20
Video Solution : NA

*/


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = nums.size();
        sum = (sum * (sum + 1)) / 2;

        for(auto i : nums)
            sum -= i;

        return sum;
    }
};