/*

Author : Manas Rawat
Date : 28/01/2024
Problem : Number of Submatrices That Sum to Target
Difficulty : Hard
Problem Link : https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/description/
Video Solution : https://youtu.be/djZOhN4_ABw

*/


class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> pre(n, vector<int> (m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                pre[i][j] = matrix[i][j];

                if(i > 0)
                    pre[i][j] += pre[i - 1][j];
                if(j > 0)
                    pre[i][j] += pre[i][j - 1];
                if(i > 0 and j > 0)
                    pre[i][j] -= pre[i - 1][j - 1];
            }
        }

        int ans = 0;

        for(int sx = 0; sx < n; sx++){
            for(int ex = sx; ex < n; ex++){
                for(int sy = 0; sy < m; sy++){
                    for(int ey = sy; ey < m; ey++){
                        int cur = pre[ex][ey];

                        if(sy > 0)
                            cur -= pre[ex][sy - 1];
                        if(sx > 0)
                            cur -= pre[sx - 1][ey];
                        if(sx > 0 and sy > 0)
                            cur += pre[sx - 1][sy - 1];

                        ans += cur == target;
                    }
                }
            }
        }

        return ans;
    }
};