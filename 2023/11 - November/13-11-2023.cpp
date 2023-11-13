/*

Author : Manas Rawat
Date : 13/11/2023
Problem : Sort Vowels in a String
Difficulty : Medium
Problem Link : https://leetcode.com/problems/sort-vowels-in-a-string/
Video Solution : https://youtu.be/-eTSYwxO2p0

*/


class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        sort(vowels.begin(), vowels.end());
        
        int n = s.size();
        vector<char> take;
        
        for(int i = 0; i < s.size(); i++){
            if(binary_search(vowels.begin(), vowels.end(), s[i]))
                take.push_back(s[i]);
        }
        
        sort(take.begin(), take.end(), [](char a, char b){
            return (int)a > (int)b;
        });
        
        for(int i = 0; i < s.size(); i++){
            if(binary_search(vowels.begin(), vowels.end(), s[i])){
                s[i] = take.back();
                take.pop_back();
            }
        }
        
        return s;
    }
};