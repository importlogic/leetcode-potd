/*

Author : Manas Rawat
Date : 13/02/2024
Problem : Find First Palindromic String in the Array
Difficulty : Easy
Problem Link : https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/
Video Solution : https://youtu.be/klls5_9MYYs

*/


class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto s : words){
            bool ok = 1;
            int n = s.size();
            for(int i = 0; i < n / 2; i++)
                if(s[i] != s[n - i - 1]){
                    ok = 0;
                    break;
                }

            if(ok)
                return s;
        }

        return "";
    }
};