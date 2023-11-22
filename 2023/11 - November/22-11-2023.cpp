/*

Author : Manas Rawat
Date : 22/11/2023
Problem : Diagonal Traverse II
Difficulty : Medium
Problem Link : https://leetcode.com/problems/diagonal-traverse-ii/
Video Solution : https://youtu.be/DvsqLBgkbgU

*/


class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size();
        // pos vector tells me the elements at the ith diagonal
        vector<vector<int>> pos(1e5 + 10);
        vector<int> ans;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < nums[i].size(); j++){
                pos[i + j].push_back(nums[i][j]);
            }
        }
        
        for(int i = 0; i < 1e5 + 10; i++){
            while(pos[i].size()){
                ans.push_back(pos[i].back());
                pos[i].pop_back();  
            }
        }
        
        return ans;
    }
};