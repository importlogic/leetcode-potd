/*

Author : Manas Rawat
Date : 18/01/2024
Problem :  Climbing Stairs
Difficulty : Easy
Problem Link : https://leetcode.com/problems/climbing-stairs/description/
Video Solution : https://youtu.be/Q_XYBvXg0fw

*/


class Solution {
public:
    int climbStairs(int n) {
        vector<int> fibo(n + 1);
        fibo[0] = fibo[1] = 1;

        for(int i = 2; i < n + 1; i++)
            fibo[i] = fibo[i - 1] + fibo[i - 2];

        return fibo[n];
    }
};