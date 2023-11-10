/*

Author : Manas Rawat
Date : 10/11/2023
Problem : Restore the Array From Adjacent Pairs
Difficulty : Medium
Problem Link : https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/
Video Solution : https://youtu.be/l5Ds8Vqwcls

*/


class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int,set<int>> g;
        map<int,int> in;
        
        for(auto i : adjacentPairs){
            g[i[0]].insert(i[1]);
            g[i[1]].insert(i[0]);
            ++in[i[0]];
            ++in[i[1]];
        }
        
        int start = -1;
        
        for(auto i : in){
            if(i.second == 1){
                start = i.first;
                break;
            }
        }
        
        vector<int> ans;
        queue<int> q;
        q.push(start);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            ans.push_back(node);

            for(auto child : g[node]){
                q.push(child);
                g[child].erase(node);
            }
        }
        
        return ans;
    }
};