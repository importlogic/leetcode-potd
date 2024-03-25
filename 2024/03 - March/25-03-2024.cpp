/*

Author : Manas Rawat 
Date : 25/03/2024
Problem : Find All Duplicates in an Array
Difficulty : Medium 
Problem Link : https://leetcode.com/problems/find-all-duplicates-in-an-array/description/
Video Solution : NA

*/


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size() + 1;
        vector<int> f(n, 0);

        for(auto i : nums)
            ++f[i];

        for(int i = 1; i < n; i++)
            if(f[i] == 2)
                ans.push_back(i);

        return ans;
    }
};
