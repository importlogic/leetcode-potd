/*

Author : Manas Rawat
Date : 01/01/2024
Problem : Assign Cookies
Difficulty : Easy
Problem Link : https://leetcode.com/problems/assign-cookies/
Video Solution : https://youtu.be/QKWNyBV7GJ8

*/


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());
        
        int ans = 0;
        
        int child = 0, cookie = 0;
        
        while(cookie < s.size() and child < g.size()){
            if(g[child] <= s[cookie]){
                ++ans;
                ++child;
                ++cookie;
            }
            else{
                ++child;
            }
        }
        
        return ans;
    }
};