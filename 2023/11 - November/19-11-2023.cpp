/*

Author : Manas Rawat
Date : 19/11/2023
Problem : Reduction Operations to Make the Array Elements Equal
Difficulty : Medium
Problem Link : https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/
Video Solution : https://youtu.be/XDVIRjRVKog

*/

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b){
            return a > b;    
        });
        
        int ans = 0;
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i - 1])
                ans += i;
        }
        
        return ans;
    }
};