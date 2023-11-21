/*

Author : Manas Rawat
Date : 21/11/2023
Problem : Count Nice Pairs in an Array
Difficulty : Medium
Problem Link : https://leetcode.com/problems/count-nice-pairs-in-an-array/
Video Solution : https://youtu.be/P7ddJJxsbdI

*/


class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        map<int, int> f;
        long long ans = 0;
        const long long mod = 1e9 + 7;
        
        for(auto i : nums){
            string rev = to_string(i);
            reverse(rev.begin(), rev.end());
            int j = stoi(rev);
            
            ans = (ans + f[i - j]) % mod;
            ++f[i - j];
        }
        
        return ans;
    }
};