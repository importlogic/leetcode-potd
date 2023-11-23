/*

Author : Manas Rawat
Date : 23/11/2023
Problem : Arithmetic Subarrays
Difficulty : Medium
Problem Link : https://leetcode.com/problems/arithmetic-subarrays/
Video Solution : https://youtu.be/ky4fJPAupP4

*/


class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans(l.size(), 0);
        
        for(int i = 0; i < l.size(); i++){
            if(r[i] - l[i] + 1 > 1){
                ans[i] = 1;
                vector<int> copy = nums;
                sort(copy.begin() + l[i], copy.begin() + r[i] + 1);
                
                int dx = copy[l[i] + 1] - copy[l[i]];
                
                for(int j = l[i] + 2; j < r[i] + 1; j++){
                    if(copy[j] - copy[j - 1] != dx){
                        ans[i] = 0;
                        break;
                    }
                }
            }            
        }
        
        return ans;
    }
};