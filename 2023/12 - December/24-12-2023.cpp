/*

Author : Manas Rawat
Date : 24/12/2023
Problem : Minimum Changes To Make Alternating Binary String
Difficulty : Easy
Problem Link : https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/
Video Solution : https://youtu.be/tHcQEvAPE68

*/


class Solution {
public:
    int minOperations(string s) {
        // start with 0
        
        int expect = 0;
        int ans1 = 0;
        
        for(auto i : s){
            ans1 += expect != (i - '0');
            
            expect ^= 1;
        }
        
        // start with 1
        
        expect = 1;
        int ans2 = 0;
        
        for(auto i : s){
            ans2 += expect != (i - '0');
            
            expect ^= 1;
        }
        
        return min(ans1, ans2);
    }   
};