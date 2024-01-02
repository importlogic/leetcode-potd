/*

Author : Manas Rawat
Date : 02/01/2024
Problem : Convert an Array Into a 2D Array With Conditions
Difficulty : Medium
Problem Link : https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/
Video Solution : https://youtu.be/Zywrn_9zLKU

*/


class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> f;
        
        for(auto i : nums)
            ++f[i];
        
        int size = 0;
        
        for(auto i : f)
            size = max(size, i.second);
        
        vector<vector<int>> ans(size);
        
        for(auto i : f){
            for(int j = 0; j < i.second; j++)
                ans[j].push_back(i.first);
        }
        
        return ans;
    }
};