/*

Author : Manas Rawat
Date : 05/02/2024
Problem : First Unique Character in a String
Difficulty : Easy
Problem Link : https://leetcode.com/problems/first-unique-character-in-a-string/
Video Solution : https://youtu.be/tXCJ9kF8-hw

*/


class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> f(26, 0);

        for(auto i : s)
            ++f[i - 'a'];

        for(int i = 0; i < s.size(); i++){
            if(f[s[i] - 'a'] == 1)
                return i;
        }

        return -1;
    }
};