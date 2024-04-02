/*

Author : Saransh Bangar
Date : 01/04/2024
Problem : Length of Last Word
Difficulty : Easy 
Problem Link : https://leetcode.com/problems/length-of-last-word/description/
Video Solution : NA

*/


class Solution {
public:
    int lengthOfLastWord(string s)
    {
        int len=0, i=s.size()-1;
        while (i>=0 && s[i]==' ')
            i--;
        while (i>=0 && s[i]!=' ')
        {
            len++;
            i--;
        }
        return len;
    }
};
