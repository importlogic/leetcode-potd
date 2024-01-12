/*

Author : Manas Rawat
Date : 12/01/2024
Problem : Determine if String Halves Are Alike
Difficulty : Easy
Problem Link : https://leetcode.com/problems/determine-if-string-halves-are-alike/
Video Solution : NA

*/


class Solution {
public:
    bool halvesAreAlike(string s) {
        auto gud = [&](char c) -> bool {
            return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
        };
        
        int n = s.size();
        
        int cur = 0;
        
        for(int i = 0; i < n / 2; i++){
            cur += gud(tolower(s[i]));
        }
        
        for(int i = n / 2; i < n; i++){
            cur -= gud(tolower(s[i]));
        }
        
        return cur == 0;
    }
};