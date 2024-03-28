/*

Author : Manas Rawat 
Date : 28/03/2024
Problem : Length of Longest Subarray With at Most K Frequency
Difficulty : Medium 
Problem Link : https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/
Video Solution : NA

*/


class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0;
        int l = 0, r = 0;
        map<int, int> f;

        while(r < nums.size()) {
            ++f[nums[r]];

            while(f[nums[r]] > k){
                --f[nums[l]];
                if(f[nums[l]] == 0)
                    f.erase(nums[l]);

                ++l;
            }

            ans = max(r - l + 1, ans);
            ++r;
        }

        return ans;
    }
};
