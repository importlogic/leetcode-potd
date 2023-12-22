/*

Author : Manas Rawat
Date : 22/12/2023
Problem : Maximum Score After Splitting a String
Difficulty : Easy
Problem Link : https://leetcode.com/problems/maximum-score-after-splitting-a-string/
Video Solution : https://youtu.be/6C9LA8kJ5ms

*/


class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        vector<int> suf(n, 0);
        suf[n - 1] = s[n - 1] == '1';
        
        for(int i = n - 2; i > -1; i--){
            suf[i] = suf[i + 1]  + (s[i] == '1');
        }
        
        int zero = 0;
        int ans = 0;
        
        for(int i = 0; i < n - 1; i++){
            zero += s[i] == '0';
            
            ans = max(ans, zero + suf[i + 1]);
        }
        
        return ans;
    }
};