/*

Author : Manas Rawat
Date : 15/12/2023
Problem : Destination City
Difficulty : Easy
Problem Link : https://leetcode.com/problems/destination-city/
Video Solution : https://youtu.be/hjUj0hJWGH0

*/


class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string, int> ans;
        
        for(auto i : paths)
            ans[i[1]] = 1;
        
        for(auto i : paths)
            ans.erase(i[0]);
        
        return (*ans.begin()).first;
    }
};