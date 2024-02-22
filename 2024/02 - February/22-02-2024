/*

Author : Manas Rawat
Date : 22/02/2024
Problem : Find the Town Judge
Difficulty : Easy 
Problem Link : https://leetcode.com/problems/find-the-town-judge/description/
Video Solution : NA

*/


class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> ans(n, 0);

        for(auto i : trust) {
            ans[i[0] - 1] = -1;

            if(ans[i[1] - 1] > -1)
                ++ans[i[1] - 1];
        }

        for(int i = 0; i < n; i++){
            if(ans[i] == n - 1)
                return i + 1;
        } 

        return -1;
    }
};
