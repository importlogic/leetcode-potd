/*

Author : Manas Rawat
Date : 25/02/2024
Problem : Greatest Common Divisor Traversal
Difficulty : Hard 
Problem Link : https://leetcode.com/problems/greatest-common-divisor-traversal/description/
Video Solution : NA

*/


class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> g(n);

        int MAX = *max_element(nums.begin(), nums.end()) + 1;
        vector<vector<int>> pos(MAX);

        for(int i = 0; i < nums.size(); i++)
            pos[nums[i]].push_back(i);

        for(int i = 2; i < MAX; i++) {
            vector<int> cur;

            for(int j = i; j < MAX; j += i)
                for(auto x : pos[j])
                    cur.push_back(x);

            for(int j = 1; j < cur.size(); j++){
                g[cur[j]].push_back(cur[j - 1]);
                g[cur[j - 1]].push_back(cur[j]);
            }
        }

        vector<bool> vis(n, 0);
        int cc = 0;

        function<void(int)> dfs = [&](int node) {   
            vis[node] = 1;

            for(auto child : g[node]){
                if(!vis[child])
                    dfs(child);
            }
        };

        for(int i = 0; i < n; i++) {
            if(!vis[i]){
                ++cc;
                dfs(i);
            }
        }

        return cc == 1;
    }
};
