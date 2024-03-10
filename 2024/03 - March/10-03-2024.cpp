/*

Author : Manas Rawat 
Date : 10/03/2024
Problem : Intersection of Two Arrays
Difficulty : Easy 
Problem Link : https://leetcode.com/problems/intersection-of-two-arrays/description/
Video Solution : NA

*/


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> x(1001), y(1001);

        for(auto i : nums1)
            ++x[i];
        for(auto i : nums2)
            ++y[i];

        vector<int> ans;

        for(int i = 0; i < 1001; i++){
            if(x[i] and y[i])
                ans.push_back(i);
        }

        return ans;
    }
};
