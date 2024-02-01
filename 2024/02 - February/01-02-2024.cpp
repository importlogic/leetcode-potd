/*

Author : Manas Rawat
Date : 01/02/2024
Problem : Divide Array Into Arrays With Max Difference
Difficulty : Medium
Problem Link : https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/description/
Video Solution : https://youtu.be/_a_TUZ8UNd8

*/


class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for(int i = 0; i < nums.size(); i += 3){
            if(nums[i + 2] - nums[i] > k){
                ans.clear();
                return ans;
            }

            ans.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }

        return ans;
    }
};