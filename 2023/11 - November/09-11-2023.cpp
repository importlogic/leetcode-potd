/*

Author : Manas Rawat
Date : 09/11/2023
Problem : Count Number of Homogenous Substrings
Difficulty : Medium
Problem Link : https://leetcode.com/problems/count-number-of-homogenous-substrings/
Video Solution : https://youtu.be/DHEhpRU3sC0

*/


class Solution {
public:
    int countHomogenous(string s) {
        const long long mod = 1e9 + 7;
        
        long long ans, cur;
        ans = 0;
        cur = 1;
        
        int n = s.size();
        
        for(int i = 1;  i < n; i++){
            if(s[i] != s[i - 1]){
                long long newval = (cur * (cur + 1)) / 2;
                newval = newval % mod;
                
                ans = (ans + newval) % mod;
                
                cur = 1;
            }
            else{
                ++cur;
            }
        }
        
        long long newval = (cur * (cur + 1)) / 2;
        newval = newval % mod;

        ans = (ans + newval) % mod; 
        
        return ans;
    }
};