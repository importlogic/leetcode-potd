/*

Author : Manas Rawat
Date : 05/12/2023
Problem : Count of Matches in Tournament
Difficulty : Easy
Problem Link : https://leetcode.com/problems/count-of-matches-in-tournament/
Video Solution : https://youtu.be/JiW3FskET9o

*/


class Solution {
public:
    int numberOfMatches(int n) {
        int ans = 0;
        
        while(n > 1){
            ans += n / 2;
            n = (n / 2) + (n & 1);
        }
        
        return ans;
    }
};