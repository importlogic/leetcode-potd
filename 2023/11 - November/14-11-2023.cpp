/*

Author : Manas Rawat
Date : 14/11/2023
Problem : Unique Length-3 Palindromic Subsequences
Difficulty : Medium
Problem Link : https://leetcode.com/problems/unique-length-3-palindromic-subsequences/
Video Solution : https://youtu.be/jbxyHCJJEfk

*/


class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);
        vector<vector<int>> pre(n, vector<int> (26, 0));
        
        for(int i = 0; i < n; i++){
            last[s[i] - 'a'] = i;
            first[s[n - i - 1] - 'a'] = n - i - 1;
            
            if(i > 0){
                for(int j = 0; j < 26; j++)
                    pre[i][j] = pre[i - 1][j];
            }
            
            pre[i][s[i] - 'a']++;
        }
        
        int ans = 0;
        
        for(int i = 0; i < 26; i++){
            if(first[i] == last[i])
                continue;
            
            for(int j = 0; j < 26; j++)
                ans += (pre[last[i] - 1][j] - pre[first[i]][j]) > 0;
        }
        
        return ans;
    }
};