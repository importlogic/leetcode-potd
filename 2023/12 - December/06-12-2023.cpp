/*

Author : Manas Rawat
Date : 06/12/2023
Problem : Calculate Money in Leetcode Bank
Difficulty : Easy
Problem Link : https://leetcode.com/problems/calculate-money-in-leetcode-bank/
Video Solution : https://youtu.be/p-jpSVIIHo4

*/


class Solution {
public:
    int totalMoney(int n) {
        int day = 1;
        int week = 1;
        int ans = 0;
        
        while(day < n + 1){
            int i = 0; // the current day of the week
            
            while(i < 7 and day < n + 1){
                ans += week + i;
                ++day;
                ++i;
            }
            
            ++week;
        }
        
        return ans;
    }
};