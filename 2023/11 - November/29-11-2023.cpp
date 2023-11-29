/*

Author : Manas Rawat
Date : 29/11/2023
Problem : Number of 1 Bits
Difficulty : Easy
Problem Link : https://leetcode.com/problems/number-of-1-bits/
Video Solution : NA

*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcountll(n);
    }
};