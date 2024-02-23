/*

Author : Manas Rawat
Date : 23/02/2024
Problem : Cheapest Flights Within K Stops
Difficulty : Medium 
Problem Link : https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
Video Solution : NA

*/


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int inf = 1e9;
        vector<vector<int>> d(n, vector<int> (k + 2, inf));

        vector<vector<pair<int,int>>> g(n);
        for(auto i : flights) {
            g[i[0]].emplace_back(i[1], i[2]);
        }

        d[src][0] = 0;
        priority_queue<pair<int,pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int, int>>>> pq;
        pq.push({0, {src, 0}});

        while(!pq.empty()) {
            int cd = pq.top().first;
            int node, ck;
            tie(node, ck) = pq.top().second;

            pq.pop();

            if(ck == k + 1) 
                continue;

            for(auto next : g[node]) {
                int child, w;
                tie(child, w) = next;

                if(cd + w < d[child][ck + 1]) {
                    d[child][ck + 1] = cd + w;
                    pq.push({d[child][ck + 1], {child, ck + 1}});
                }
            }
        }

        int ans = *min_element(d[dst].begin(), d[dst].end());

        return ans == 1e9 ? -1 : ans;
    }
};
