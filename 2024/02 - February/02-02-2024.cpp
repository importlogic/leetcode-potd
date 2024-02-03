/*

Author : Manas Rawat
Date : 02/02/2024
Problem : Sequential Digits
Difficulty : Medium
Problem Link : https://leetcode.com/problems/sequential-digits/description/
Video Solution : https://youtu.be/RYLA6hDQ7lA

*/


class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        for(int start = 1; start < 10; start++){
            int cur = start + 1;
            int val = start;

            if(val >= low and val <= high)
                ans.push_back(val);

            for(; cur < 10; cur++){
                val *= 10;
                val += cur;


                if(val >= low and val <= high)
                    ans.push_back(val);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};