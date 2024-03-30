/*

Author : Manas Rawat 
Date : 30/03/2024
Problem : Subarrays with K Different Integers
Difficulty : Hard 
Problem Link : https://leetcode.com/problems/subarrays-with-k-different-integers/description/
Video Solution : NA

*/


class Solution {
   public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        vector<int> f(nums.size() + 1, 0);

        int ans = 0;
        int l = 0;
        int r = 0;
        int cur = 0;

        while (r < nums.size()) {
            if (++f[nums[r++]] == 1) {
                k--;
            }

            if (k < 0) {
                --f[nums[l++]];
                k++;
                cur = 0;
            }

            if (k == 0) {
                while (f[nums[l]] > 1) {
                    --f[nums[l++]];
                    cur++;
                }
                ans += (cur + 1);
            }
        }
        return ans;
    }
};
