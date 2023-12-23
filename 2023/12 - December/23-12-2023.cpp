/*

Author : Manas Rawat
Date : 23/12/2023
Problem : Path Crossing
Difficulty : Easy
Problem Link : https://leetcode.com/problems/path-crossing/
Video Solution : https://youtu.be/DCyTR8uAcV8

*/


class Solution {
public:
    bool isPathCrossing(string path) {
        map<pair<int,int>, bool> vis;
        
        int cx, cy;
        cx = cy = 0;
        
        for(auto i : path){
            vis[{cx, cy}] = 1;
            
            if(i == 'N')
                --cx;
            else if(i == 'S')
                ++cx;
            else if(i == 'E')
                ++cy;
            else
                --cy;
            
            if(vis.count({cx, cy}))
                return 1;
        }
        
        return 0;
    }
};