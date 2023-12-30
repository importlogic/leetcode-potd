/*

Author : Manas Rawat
Date : 30/12/2023
Problem : Redistribute Characters to Make All Strings Equal
Difficulty : Easy
Problem Link : https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/
Video Solution : https://youtu.be/t7nO6EGvvfY

*/


class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> f(26, 0);
        
        for(auto i : words){
            for(auto j : i)
                ++f[j - 'a'];
        }
        
        bool ok = 1;
        
        for(int i = 0; i < 26; i++)
            ok = ok and !(f[i] % words.size());
        
        return ok;
    }
};