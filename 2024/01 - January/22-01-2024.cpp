/*

Author : Manas Rawat
Date : 22/01/2024
Problem : Set Mismatch
Difficulty : Easy
Problem Link : https://leetcode.com/problems/set-mismatch/description/
Video Solution : NA

*/


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<bool> taken(1e4 + 10, 0);

        int n = nums.size();
        int sum = 0;
        vector<int> ans(2);

        for(int i = 0; i < n; i++){
            if(!taken[nums[i]]){
                sum += nums[i];
                taken[nums[i]] = 1;
            }
            else{
                ans[0] = nums[i];
            }
        }

        ans[1] = (n * (n + 1)) / 2 - sum;

        return ans;
    }
};