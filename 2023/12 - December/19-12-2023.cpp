/*

Author : Manas Rawat
Date : 19/12/2023
Problem : Image Smoother
Difficulty : Easy
Problem Link : https://leetcode.com/problems/image-smoother/
Video Solution : https://youtu.be/j-sqJdeV3TY

*/


class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();
        
        int dx[] = { -1 , 1 ,  0  , 0 , -1  , -1  ,  1  , 1  };
        int dy[] = { 0  , 0 , -1  , 1 , -1  ,  1  , -1  , 1  };

        //         { U  , D ,  L  , R , UL  , UR  , DL  , DR }
        
        auto valid = [&](int x, int y) -> bool {
            if(x < 0 or x >= n or y < 0 or y >= m)
                return 0;
            
            return 1;
        };
        
        vector<vector<int>> ans(n, vector<int> (m));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int sum = img[i][j];
                int count = 1;
                
                for(int p = 0; p < 8; p++){
                    int nx = i + dx[p];
                    int ny = j + dy[p];
                    
                    if(valid(nx, ny)){
                        sum += img[nx][ny];
                        ++count;
                    }
                }
                
                ans[i][j] = sum / count;
            }
        }
        
        return ans;
    }
};