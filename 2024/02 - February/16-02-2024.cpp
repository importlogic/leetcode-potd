/*

Author : Manas Rawat
Date : 16/02/2024
Problem : Least Number of Unique Integers after K Removals
Difficulty : Medium
Problem Link : https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/
Video Solution : https://youtu.be/cXQtnEQfvC8

*/


class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int, int> f;

        for(auto i : arr)
            ++f[i];

        vector<int> values;
        for(auto i : f)
            values.push_back(i.second);
        
        sort(values.begin(), values.end());

        int ans = values.size();

        for(auto i : values){
            if(i <= k){
                k -= i;
                --ans;
            }
            else
                break;
        }

        return ans;
    }
};