/*

Author : Manas Rawat
Date : 26/11/2023
Problem : Largest Submatrix With Rearrangements
Difficulty : Medium
Problem Link : https://leetcode.com/problems/largest-submatrix-with-rearrangements/
Video Solution : https://youtu.be/ipb6pj9kkcA

*/


class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int ans = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        
        int dp[n][m];
        for(int i = 0; i < m; i++)
            dp[0][i] = matrix[0][i];
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j]){
                    dp[i][j] = dp[i - 1][j] + 1;
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            vector<int> values(m);
            for(int j = 0; j < m; j++)
                values[j] = dp[i][j];
            
            sort(values.begin(), values.end(), [](int a, int b){
                return a > b;
            });
            
            for(int i = 0; i < m; i++){
                ans = max(ans, values[i] * (i + 1));
            }
        }
        
        return ans;
    }
};