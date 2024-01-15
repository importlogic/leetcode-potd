/*

Author : Manas Rawat
Date : 15/01/2024
Problem : Find Players With Zero or One Losses
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/grinding-geek/1
Video Solution : https://youtu.be/Wn5JxNlf1yo

*/


class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> part(1e5 + 10, 0), lose(1e5 + 10, 0);

        for(auto i : matches){
            part[i[0]] = part[i[1]] = 1;

            ++lose[i[1]];
        }

        vector<vector<int>> ans(2);

        for(int i = 1; i < 1e5 + 10; i++){
            if(part[i]){
                if(lose[i] == 1)
                    ans[1].push_back(i);
                else if(lose[i] == 0)
                    ans[0].push_back(i);
            }
        }

        return ans;
    }
};