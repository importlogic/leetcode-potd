/*

Author : Manas Rawat
Date : 19/02/2024
Problem : Power of Two
Difficulty : Easy
Problem Link : https://leetcode.com/problems/power-of-two/description/
Video Solution : NA

*/


class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n and !(n & (n - 1LL));
    }
};