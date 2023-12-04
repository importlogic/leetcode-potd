/*

Author : Manas Rawat
Date : 04/12/2023
Problem : Largest 3-Same-Digit Number in String
Difficulty : Easy
Problem Link : https://leetcode.com/problems/largest-3-same-digit-number-in-string/
Video Solution : https://youtu.be/bdVX9ovqQvs

*/


class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        
        for(int i = 0; i < num.size() - 2; i++){
            if(num[i] == num[i + 1] and num[i + 1] == num[i + 2])
                ans = max(ans, num.substr(i, 3));
        }
        
        return ans;
    }
};