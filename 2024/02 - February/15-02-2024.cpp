/*

Author : Manas Rawat
Date : 15/02/2024
Problem : Find Polygon With the Largest Perimeter
Difficulty : Medium
Problem Link : https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/description/
Video Solution : https://youtu.be/a_Ibszsz2vU

*/


class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        long long ans = -1;
        long long pre = nums[0] + nums[1];
        
        for(int i = 2; i < n; i++){
            if(pre > nums[i]){
                ans = max(ans, pre + nums[i]);
            }
            
            pre += nums[i];
        }
        
        return ans;
    }
};