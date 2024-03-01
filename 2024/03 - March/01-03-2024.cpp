/*

Author : Manas Rawat 
Date : 01/03/2024
Problem : Maximum Odd Binary Number
Difficulty : Easy 
Problem Link : https://leetcode.com/problems/maximum-odd-binary-number/description/
Video Solution : NA

*/


class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count = 0;
        for(auto i : s)
            count += i == '1';

        --count;
        for(int i = 0; i < s.size() - 1; i++){
            if(count){
                s[i] = '1';
                --count;
            }
            else{
                s[i] = '0';
            }
        }

        s.back() = '1';

        return s;
    }
};
