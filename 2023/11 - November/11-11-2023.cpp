/*

Author : Manas Rawat
Date : 11/11/2023
Problem : Design Graph With Shortest Path Calculator
Difficulty : Hard
Problem Link : https://leetcode.com/problems/design-graph-with-shortest-path-calculator/
Video Solution : https://youtu.be/gi7nyQUaa1s

*/


vector<vector<pair<int,int>>> g(101);

class Graph {
public:
    Graph(int n, vector<vector<int>>& edges) {
        for(int i = 0; i < n; i++)
            g[i].clear();
        
        for(auto i : edges){
            int x = i[0];
            int y = i[1];
            int w = i[2];
            
            g[x].emplace_back(y, w);
        }
    }
    
    void addEdge(vector<int> edge) {
        int x = edge[0];
        int y = edge[1];
        int w = edge[2];
        
        g[x].emplace_back(y, w);
    }
    
    int shortestPath(int node1, int node2) {
        vector<int> d(101, 1e9);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        pq.push({0, node1});
        d[node1] = 0;
        
        while(!pq.empty()){
            int cd, node;
            tie(cd, node) = pq.top();
            pq.pop();
            
            for(auto next : g[node]){
                int w, child;
                tie(child, w) = next;
                
                if(cd + w < d[child]){
                    d[child] = cd + w;
                    pq.push({d[child], child});
                }
            }
        }
        
        return d[node2] == 1e9 ? -1 : d[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */