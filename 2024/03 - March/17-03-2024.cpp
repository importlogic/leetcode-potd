/*

Author : Saransh Bangar
Date : 17/03/2024
Problem : Insert Interval
Difficulty : Medium 
Problem Link : https://leetcode.com/problems/insert-interval/description/
Video Solution : NA

*/


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        vector<vector<int>>ans;
        int i=0;
        while (i<intervals.size() && intervals[i][1]<newInterval[0]) 
        {
            ans.push_back(intervals[i]);
            i++;
        }
        while (i<intervals.size() && intervals[i][0]<=newInterval[1])
        {
            newInterval[0]=min(newInterval[0], intervals[i][0]);
            newInterval[1]=max(newInterval[1], intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);
        while (i<intervals.size())
        {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};
