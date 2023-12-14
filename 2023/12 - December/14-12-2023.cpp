/*

Author : Manas Rawat
Date : 14/12/2023
Problem : Difference Between Ones and Zeros in Row and Column
Difficulty : Medium
Problem Link : https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/
Video Solution : https://youtu.be/EkT2krlC-FY

*/


class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> rows(n, 0), cols(m, 0);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                rows[i] += grid[i][j];
                cols[j] += grid[i][j];
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                grid[i][j] = 2 * (rows[i] + cols[j]) - (n + m);
            }
        }
        
        return grid;
    }
};