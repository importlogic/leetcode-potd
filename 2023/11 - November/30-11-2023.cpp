/*

Author : Manas Rawat
Date : 30/11/2023
Problem : Minimum One Bit Operations to Make Integers Zero
Difficulty : Hard
Problem Link : https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/
Video Solution : https://youtu.be/9o1f7AvzXLA

*/


class Solution {
public:
    int minimumOneBitOperations(int n) {
        int ans = 0;
        bool one = 0;
        
        for(int i = 31; i > -1; i--){
            if((n >> i) & 1){
                if(!one){
                    ans += 1 << i;
                    one = 1;
                }
                else{
                    one = 0;
                }
            }
            else{
                if(one){
                    ans += 1 << i;
                }
            }
        }
        
        return ans;
    }
};