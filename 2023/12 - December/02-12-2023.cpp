/*

Author : Manas Rawat
Date : 02/12/2023
Problem : Find Words That Can Be Formed by Characters
Difficulty : Easy
Problem Link : https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/
Video Solution : https://youtu.be/2OCo6MOMb74

*/


class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> f(26, 0);
        
        for(auto i : chars)
            ++f[i - 'a'];
        
        int ans = 0;
        
        for(auto i : words){
            bool ok = 1;
            vector<int> left = f;
            
            for(auto j : i){
                if(!left[j - 'a']){
                    ok = 0;
                    break;
                }    
                
                --left[j - 'a'];
            }
            
            ans += ok ? i.size() : 0;
        }
        
        return ans;
    }
};