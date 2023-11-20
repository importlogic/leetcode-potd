/*

Author : Manas Rawat
Date : 20/11/2023
Problem : Minimum Amount of Time to Collect Garbage
Difficulty : Medium
Problem Link : https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/
Video Solution : https://youtu.be/AdIUsCZKIQ0

*/


class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        
        int m, p, g;
        m = p = g = 0;
        
        int lastm, lastp, lastg;
        lastm = lastp = lastg = 0;
        
        for(int i = 1; i < n - 1; i++)
            travel[i] += travel[i - 1];
        
        for(int i = 0; i < n; i++){
            int dm, dp, dg;
            dm = dp = dg = 0;

            for(auto j : garbage[i]){
                dm += j == 'M';
                dp += j == 'P';
                dg += j == 'G';
            }
            
            m += dm;
            p += dp;
            g += dg;
            
            lastm = (dm > 0) ? i : lastm;
            lastp = (dp > 0) ? i : lastp;
            lastg = (dg > 0) ? i : lastg;
        }
        
        int ans = m + p + g;
        
        if(lastm)
            ans += travel[lastm - 1];
        if(lastp)
            ans += travel[lastp - 1];
        if(lastg)
            ans += travel[lastg - 1];
        
        return ans;
    }
};