/*

Author : Manas Rawat
Date : 26/01/2024
Problem : Out of Boundary Paths
Difficulty : Medium
Problem Link : https://leetcode.com/problems/out-of-boundary-paths/description/
Video Solution : https://youtu.be/ogD8C8FL0RA

*/


class Solution {
public:
    int findPaths(int n, int m, int maxMove, int startRow, int startColumn) {
        long long dp[n][m][maxMove + 1];
        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};

        const int mod = 1e9 + 7;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                dp[i][j][0] = 0;
        }

        auto inside = [&](int x, int y) -> bool {   
            if(x < 0 or x >= n or y < 0 or y >= m)
                return 0;
            
            return 1;
        };

        for(int k = 1; k < maxMove + 1; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    dp[i][j][k] = 0;

                    for(int d = 0; d < 4; d++){
                        int nx = i + dx[d];
                        int ny = j + dy[d];

                        if(inside(nx, ny)){
                            dp[i][j][k] = (dp[i][j][k] + dp[nx][ny][k - 1]) % mod;
                        }
                        else{
                            dp[i][j][k] = (dp[i][j][k] + 1) % mod;
                        }
                    }
                }
            }
        }

        return dp[startRow][startColumn][maxMove];
    }
};