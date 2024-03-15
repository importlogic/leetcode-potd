/*

Author : Manas Rawat 
Date : 15/03/2024
Problem : Product of Array Except Self
Difficulty : Medium 
Problem Link : https://leetcode.com/problems/product-of-array-except-self/description/
Video Solution : NA

*/


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        unordered_map<int, int> f;
        for(auto i : nums)
            ++f[i];

        int n = nums.size();
        vector<int> ans(n);

        for(int i = 0; i < n; i++){
            ans[i] = 1;

            for(auto x : f) {
                ans[i] *= pow(x.first, x.second - (nums[i] == x.first));
            }
        }

        return ans;
    }
};
