/*

Author : Manas Rawat 
Date : 24/03/2024
Problem : Find the Duplicate Number
Difficulty : Medium 
Problem Link : https://leetcode.com/problems/find-the-duplicate-number/description
Video Solution : NA

*/


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n, 0);

        for(auto i : nums)  {
            if(f[i])
                return i;
            
            ++f[i];
        }

        return 0;
    }
};
