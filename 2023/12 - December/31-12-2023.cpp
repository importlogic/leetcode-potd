/*

Author : Manas Rawat
Date : 31/12/2023
Problem : Largest Substring Between Two Equal Characters
Difficulty : Easy
Problem Link : https://leetcode.com/problems/largest-substring-between-two-equal-characters/
Video Solution : https://youtu.be/AU0ZQ3vUVg0

*/


class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<vector<int>> f(26, {-1, -1});
        int n = s.size();
        
        for(int i = 0; i < n; i++){
            f[s[i] - 'a'][1] = i;
            f[s[n - i - 1] - 'a'][0] = n - i - 1;
        }
        
        int ans = -1;
        
        for(int i = 0; i < 26; i++)
            if(f[i][0] != -1)
                ans = max(ans, f[i][1] - f[i][0] - 1);
        
        return ans;
    }
};