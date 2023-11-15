/*

Author : Manas Rawat
Date : 15/11/2023
Problem : Maximum Element After Decreasing and Rearranging
Difficulty : Medium
Problem Link : https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/
Video Solution : https://youtu.be/v1fQIKkW_tE

*/


class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        
        for(int i = 1; i < arr.size(); i++){
            arr[i] = min(arr[i - 1] + 1, arr[i]);    
        }
        
        return arr.back();
    }
};