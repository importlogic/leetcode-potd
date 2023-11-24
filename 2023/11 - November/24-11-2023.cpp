/*

Author : Manas Rawat
Date : 24/11/2023
Problem : Maximum Number of Coins You Can Get
Difficulty : Medium
Problem Link : https://leetcode.com/problems/maximum-number-of-coins-you-can-get/
Video Solution : https://youtu.be/AAhEjr6OVho

*/


class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end(), [](int a, int b){
            return a > b;    
        });
        
        int ans = 0;
        
        for(int i = 1; i < piles.size(); i += 2){
            ans += piles[i];
            piles.pop_back();
        }
        
        return ans;
    }
};