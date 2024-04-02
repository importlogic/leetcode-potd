/*

Author : Saransh Bangar
Date : 02/04/2024
Problem : Isomorphic Strings
Difficulty : Easy 
Problem Link : https://leetcode.com/problems/isomorphic-strings/description/
Video Solution : NA

*/


class Solution {
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.length()!=t.length())
            return false;
        unordered_map<char, char>charMap;
        for (int i=0;i<s.length();i++)
        {
            if (charMap.find(s[i])==charMap.end())
            {
                for (auto it:charMap)
                {
                    if (it.second==t[i])
                        return false;
                }
                charMap[s[i]]=t[i];
            }
            else
            {
                if (charMap[s[i]]!=t[i])
                    return false;
            }
        }
        return true;
    }
};
