/*

Author : Manas Rawat
Date : 01/12/2023
Problem : Check If Two String Arrays are Equivalent
Difficulty : Easy
Problem Link : https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
Video Solution : https://youtu.be/FR1m1oNwpPA

*/


class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a, b;
        a = "";
        b = "";
        
        for(auto i : word1)
            a += i;
        
        for(auto i : word2)
            b += i;
        
        return a == b;
    }
};