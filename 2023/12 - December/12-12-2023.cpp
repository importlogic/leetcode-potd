/*

Author : Manas Rawat
Date : 12/12/2023
Problem : Maximum Product of Two Elements in an Array
Difficulty : Easy
Problem Link : https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
Video Solution : https://youtu.be/frNimr1LdXs

*/


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int first, second;
        first = second = 0;

        for(auto i : nums){
            if(i > first){
                second = first;
                first = i;
            }
            else if(i > second){
                second = i;
            }
        }

        return (first - 1) * (second - 1);
    }
};