/*

Author : Manas Rawat
Date : 11/12/2023
Problem : Element Appearing More Than 25% In Sorted Array
Difficulty : Easy
Problem Link : https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/description/
Video Solution : https://youtu.be/h-AbzZY-nKo

*/


class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int need = n / 4;
        int count = 1;
        
        for(int i = 1; i < n; i++){
            if(arr[i] != arr[i - 1]){
                if(count > need)
                    return arr[i - 1];

                count = 1;
            }
            else{
                ++count;
            }
        }

        return arr[n - 1];
    }
};