/*

Author : Manas Rawat
Date : 31/01/2024
Problem : Daily Temperatures
Difficulty : Medium
Problem Link : https://leetcode.com/problems/daily-temperatures/
Video Solution : https://youtu.be/g4VZNMAussM

*/


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;

        int n = temperatures.size();

        vector<int> ans(n, 0);

        for(int i = n - 1; i > -1; i--){
            while(st.size() and st.top().first <= temperatures[i])
                st.pop();

            if(st.size() and st.top().first > temperatures[i])
                ans[i] = st.top().second - i;

            st.push({temperatures[i], i});
        }

        return ans;
    }
};