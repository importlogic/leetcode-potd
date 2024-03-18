/*

Author : Manas Rawat 
Date : 18/03/2024
Problem : Minimum Number of Arrows to Burst Balloons
Difficulty : Medium 
Problem Link : https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/
Video Solution : NA

*/


class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b) {
            if(a[1] == b[1])
                return a[0] < b[0];
            return a[1] < b[1];
        });

        int ans = 0;
        long long last = -1e18;

        for(auto i : points) {
            if(i[0] <= last) continue;

            ++ans;
            last = i[1];
        }

        return ans;
    }
};
