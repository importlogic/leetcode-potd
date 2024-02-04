/*

Author : Manas Rawat
Date : 04/02/2024
Problem : Minimum Window Substring
Difficulty : Hard
Problem Link : https://leetcode.com/problems/minimum-window-substring/description/
Video Solution : https://youtu.be/QayR_0AdzT4

*/


class Solution {
public:
    string minWindow(string s, string t) {
        int best = 1e9, start = 0;
        int l = 0, r = 0;

        unordered_map<char,int> fs, ft;

        for(auto i : t)
            ++ft[i];

        while(r < s.size()){
            ++fs[s[r++]];

            while(1){
                bool ok = 1;

                for(auto x : ft){
                    if(fs[x.first] < x.second){
                        ok = 0;
                        break;
                    }
                }

                if(!ok)
                    break;

                if(r - l < best){
                    best = r - l;
                    start = l;
                }

                --fs[s[l++]];
            }
        }

        if(best == 1e9)
            return "";
        else
            return s.substr(start, best);
    }
};