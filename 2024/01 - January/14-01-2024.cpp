/*

Author : Manas Rawat
Date : 14/01/2024
Problem : Determine if Two Strings Are Close
Difficulty : Medium
Problem Link : https://leetcode.com/problems/determine-if-two-strings-are-close/description/
Video Solution : https://youtu.be/v70hGCpmMz8

*/


class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> need(26, 0), have(26, 0);
        
        for(auto i : word1)
            ++need[i - 'a'];
        for(auto i : word2)
            ++have[i - 'a'];
        
        for(int i = 0; i < 26; i++){
            if(need[i] == have[i])
                continue;
            
            for(int j = i + 1; j < 26; j++){
                if(need[i] == have[j] and have[i] and have[j]){
                    swap(have[i], have[j]);
                    break;
                }
            }
        }
        
        return need == have;
    }
};