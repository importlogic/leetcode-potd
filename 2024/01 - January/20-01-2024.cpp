/*

Author : Manas Rawat
Date : 20/01/2024
Problem : Sum of Subarray Minimums
Difficulty : Medium
Problem Link : https://leetcode.com/problems/sum-of-subarray-minimums/description/
Video Solution : https://youtu.be/05wcxHDjupg

*/


class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> order(n);
        long long ans = 0;
        const long long mod = 1e9 + 7;

        for(int i = 0; i < n; i++)
            order[i] = {arr[i], i};

        sort(order.begin(), order.end());

        function<void(int, int, int)> helper = [&](int low, int high, int pos) {
            int nextp = order[pos].second;

            while(nextp < low or nextp > high){
                nextp = order[++pos].second;
            }

            long long left = nextp - low + 1;
            long long right = high - nextp + 1;

            ans = (ans + (left * right * arr[nextp]) % mod) % mod;

            if(nextp > low)
                helper(low, nextp - 1, pos + 1);
            if(nextp < high)
                helper(nextp + 1, high, pos + 1);
        };

        helper(0, n - 1, 0);

        return ans;
    }
};