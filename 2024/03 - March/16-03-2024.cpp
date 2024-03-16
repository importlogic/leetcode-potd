/*

Author : Manas Rawat 
Date : 16/03/2024
Problem : Contiguous Array
Difficulty : Medium 
Problem Link : https://leetcode.com/problems/contiguous-array/description/
Video Solution : NA

*/


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);

        pre[0] = nums[0] == 1 ? 1 : -1;

        for(int i = 1; i < n; i++){
            pre[i] = pre[i - 1];
            pre[i] += nums[i] == 1 ? 1 : -1;
        }

        unordered_map<int, int> first;
        first[0] = -1;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(first.find(pre[i]) != first.end())
                ans = max(ans, i - first[pre[i]]);
            else
                first[pre[i]] = i;
        }

        return ans;
    }
};
