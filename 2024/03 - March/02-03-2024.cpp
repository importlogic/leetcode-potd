/*

Author : Manas Rawat 
Date : 02/03/2024
Problem : Squares of a Sorted Array
Difficulty : Easy 
Problem Link : https://leetcode.com/problems/squares-of-a-sorted-array/description/
Video Solution : NA

*/


class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        int i = 0;
        int j = n - 1;
        int p = n - 1;

        while(i <= j) {
            if(abs(nums[i]) > nums[j]){
                ans[p--] = nums[i] * nums[i];
                ++i;
            }
            else{
                ans[p--] = nums[j] * nums[j];
                --j;
            }
        }

        return ans;
    }
};
