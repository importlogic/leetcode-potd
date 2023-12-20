/*

Author : Manas Rawat
Date : 20/12/2023
Problem : Buy Two Chocolates
Difficulty : Easy
Problem Link : https://leetcode.com/problems/buy-two-chocolates/
Video Solution : https://youtu.be/NLYvsBtoloM

*/


class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int mina, minb;
        mina = minb = 1e9;
        
        for(auto i : prices){
            if(i < mina){
                minb = mina;
                mina = i;
            }
            else if(i < minb){
                minb = i;
            }
        }
        
        return (money - (mina + minb) > -1) ? money - (mina + minb) : money;
    }
};