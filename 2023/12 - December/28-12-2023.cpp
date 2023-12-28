/*

Author : Manas Rawat
Date : 28/12/2023
Problem : String Compression II
Difficulty : Hard
Problem Link : https://leetcode.com/problems/string-compression-ii/
Video Solution : https://youtu.be/u7b9avoQtbY

*/


int dp[110][110][27][110];

class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        int size = s.size() + 1;

        for(int p = 0; p < size + 1; p++){
            for(int q = 0; q < k + 1; q++){
                for(int r = 0; r < 27; r++){
                    for(int s = 0; s < size + 1; s++)
                        dp[p][q][r][s] = -1;
                }
            }    
        }
        
        function<int(int, int, int, int)> helper = [&](int cur_pos, int left_k, int last_char, int last_count) -> int {
            if(cur_pos == s.size())
                return 0;
            
            if(dp[cur_pos][left_k][last_char][last_count] != -1)
                return dp[cur_pos][left_k][last_char][last_count];

            int take, notake;
            take = notake = 1e9;
            
            int inc = last_count == 1 or last_count == 9 or last_count == 99;
            
            if(s[cur_pos] - 'a' == last_char){
                take = helper(cur_pos + 1, left_k, s[cur_pos] - 'a', last_count + 1) + inc;
            }
            else{
                take = helper(cur_pos + 1, left_k, s[cur_pos] - 'a', 1) + 1;
            }
            
            if(left_k > 0){
                notake = helper(cur_pos + 1, left_k - 1, last_char, last_count);
            }
            
        
            return dp[cur_pos][left_k][last_char][last_count] = min(take, notake);
        };
        
        return helper(0, k, 26, 0);
    }
};