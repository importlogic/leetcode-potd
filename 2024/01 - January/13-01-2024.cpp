/*

Author : Manas Rawat
Date : 13/01/2024
Problem : Minimum Number of Steps to Make Two Strings Anagram
Difficulty : Medium
Problem Link : https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/
Video Solution : https://youtu.be/wOsf_MWR2to

*/


class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> f(26, 0);
        
        for(auto i : s)
            ++f[i - 'a'];
        for(auto i : t)
            --f[i - 'a'];
        
        int ans = 0;
        
        for(int i = 0; i < 26; i++){
            ans += f[i] < 0 ? -f[i] : 0;
        }
        
        return ans;
    }
};