/*

Author : Manas Rawat
Date : 10/12/2023
Problem : Transpose Matrix
Difficulty : Easy
Problem Link : https://leetcode.com/problems/transpose-matrix/
Video Solution : https://youtu.be/TCM8vxTiKmE

*/


class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n, m;
        n = matrix.size();
        m = matrix[0].size();
            
        vector<vector<int>> ans(m, vector<int> (n));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++)
                ans[i][j] = matrix[j][i];
        }
        
        return ans;
    }
};