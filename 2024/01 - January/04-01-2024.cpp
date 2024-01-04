/*

Author : Manas Rawat
Date : 04/01/2024
Problem : Minimum Number of Operations to Make Array Empty
Difficulty : Medium
Problem Link : https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/
Video Solution : https://youtu.be/HOB5HwnkIrE

*/


class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        
        unordered_map<int,int> f;
        
        for(auto i : nums)
            ++f[i];
        
        for(auto i : f){
            if(i.second % 3 == 0){
                ans += i.second / 3;
            }
            else if(i.second % 3 == 2){
                ++ans;
                ans += (i.second - 2) / 3;
            }
            else{
                if(i.second == 1)
                    return -1;
                
                ans += 2;
                ans += (i.second - 4) / 3;
            }
        }
        
        return ans;
    }
};