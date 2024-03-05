/*

Author : Manas Rawat 
Date : 05/03/2024
Problem : Minimum Length of String After Deleting Similar Ends
Difficulty : Medium 
Problem Link : https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/description/
Video Solution : NA

*/


class Solution {
public:
    int minimumLength(string s) {
        int i = 0;
        int j = (int)s.size() - 1;

        while(i < j and s[i] == s[j]){
            char x = s[i];

            while(i < s.size() and s[i] == x) ++i;
            while(j > -1 and s[j] == x) --j;
        }

        return max(0, j - i + 1);
    }
};
