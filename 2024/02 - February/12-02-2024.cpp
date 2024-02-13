/*

Author : Manas Rawat
Date : 12/02/2024
Problem : Majority Element
Difficulty : Easy
Problem Link : https://leetcode.com/problems/majority-element/description/
Video Solution : https://youtu.be/CDBFHIhjHBU

*/


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> f;

        for(auto i : nums){
            ++f[i];
        }

        for(auto i : f){
            if(i.second > nums.size() / 2){
                return i.first;
            }
        }

        return 0;
    }
};f