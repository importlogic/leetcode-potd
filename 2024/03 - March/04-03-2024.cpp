/*

Author : Manas Rawat 
Date : 04/03/2024
Problem : Bag of Tokens
Difficulty : Medium 
Problem Link : https://leetcode.com/problems/bag-of-tokens/description/
Video Solution : NA

*/


class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        int i = 0;
        int j = n - 1;

        int sc = 0;
        sort(tokens.begin(), tokens.end());

        while(i <= j) {
            if(tokens[i] <= power) {
                power -= tokens[i++];
                ++sc;
            }
            else if(sc > 0 and i < j) {
                power += tokens[j--];
                --sc;
            }
            else{
                break;
            }
        }

        return sc;
    }
};
