/*

Author : Manas Rawat
Date : 24/02/2024
Problem : Find All People With Secret
Difficulty : Hard 
Problem Link : https://leetcode.com/problems/find-all-people-with-secret/description/
Video Solution : NA

*/


class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int> ans(n + 1, 1e9);
        ans[0] = 0;
        ans[firstPerson] = 0;

        vector<vector<pair<int,int>>> g(n + 1);

        for(auto i : meetings) {
            g[i[0]].emplace_back(i[1], i[2]);
            g[i[1]].emplace_back(i[0], i[2]);
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, firstPerson});
        pq.push({0, 0});

        while(!pq.empty()) {
            int node, time;
            tie(time, node) = pq.top();
            pq.pop();

            for(auto next : g[node]) {
                int child, ntime;
                tie(child, ntime) = next;

                if(ntime >= time and ans[child] > ntime) {
                    ans[child] = ntime;
                    pq.push({ntime, child});
                }
            }
        }

        vector<int> res;

        for(int i = 0; i < n + 1; i++)
            if(ans[i] < 1e9)
                res.push_back(i);

        return res;
    }
};
