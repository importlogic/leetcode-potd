/*

Author : Manas Rawat
Date : 08/11/2023
Problem : Determine if a Cell Is Reachable at a Given Time
Difficulty : Medium
Problem Link : https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/
Video Solution : https://youtu.be/PWJuLPhyyqM

*/


class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int dx = abs(sx - fx);
        int dy = abs(sy - fy);
        
        int MIN = max(dx, dy);
        
        if(t < MIN)
            return 0;
        
        if(!dx and !dy and t == 1)
            return 0;
        
        return 1;   
    }
};