/*

Author : Manas Rawat
Date : 07/12/2023
Problem : Largest Odd Number in String
Difficulty : Easy
Problem Link : https://leetcode.com/problems/largest-odd-number-in-string/
Video Solution : https://youtu.be/8jsq5Hey_r0

*/


class Solution {
public:
    string largestOddNumber(string num) {
        string ans = "";
        vector<char> odd = {'1', '3', '5', '7', '9'};
        
        string cur = "";
        
        for(auto i : num){
            cur += i;
            
            if(binary_search(odd.begin(), odd.end(), i))
                ans = cur;
        }
        
        return ans;
    }
};