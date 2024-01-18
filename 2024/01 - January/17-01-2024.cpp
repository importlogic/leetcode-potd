/*

Author : Manas Rawat
Date : 17/01/2024
Problem : Unique Number of Occurrences
Difficulty : Easy
Problem Link : https://leetcode.com/problems/unique-number-of-occurrences/description/
Video Solution : https://youtu.be/neDNGPm_QDw

*/


class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        vector<int> f(1001, 0);
        int count = 1;

        for(int i = 1; i < arr.size(); i++){
            if(arr[i] != arr[i - 1]){
                if(f[count])
                    return 0;

                f[count] = 1;
                count = 1;
            }
            else{
                ++count;
            }
        }

        return !f[count];
    }
};