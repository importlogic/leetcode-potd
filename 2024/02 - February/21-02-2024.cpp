/*

Author : Manas Rawat
Date : 21/02/2024
Problem : Bitwise AND of Numbers Range
Difficulty : Medium
Problem Link : https://leetcode.com/problems/bitwise-and-of-numbers-range/description/
Video Solution : NA

*/


class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        long long cur = 0;
        long long ans = 0;

        for(int i = 0; i < 31; i++){
            if((left >> i) & 1){
                int dx = right - left;
                int poss = (1 << i) - cur - 1;

                if(dx <= poss)
                    ans |= (1 << i);

                cur |= (1 << i);
            }
        }

        return ans;
    }
};