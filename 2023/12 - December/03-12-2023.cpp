/*

Author : Manas Rawat
Date : 03/12/2023
Problem : Minimum Time Visiting All Points
Difficulty : Easy
Problem Link : https://leetcode.com/problems/minimum-time-visiting-all-points/
Video Solution : https://youtu.be/pIcsoQ5MoRQ

*/


class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        
        for(int i = 1; i < points.size(); i++){
            int dx = abs(points[i][0] - points[i - 1][0]);
            int dy = abs(points[i][1] - points[i - 1][1]);
            
            ans += max(dx, dy);
        }
        
        return ans;
    }
};