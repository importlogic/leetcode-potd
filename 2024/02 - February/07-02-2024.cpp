/*

Author : Manas Rawat
Date : 07/02/2024
Problem : Sort Characters By Frequency
Difficulty : Medium
Problem Link : https://leetcode.com/problems/sort-characters-by-frequency/description/
Video Solution : https://youtu.be/M-XCd3QzmuM

*/


class Solution {
public:
    string frequencySort(string s) {
        map<char, int> f;
        for(auto i : s)
            ++f[i];

        priority_queue<pair<int,char>> pq;

        for(auto i : f){
            pq.push({i.second, i.first});
        }

        string ans = "";
        while(!pq.empty()){
            int count;
            char c;
            tie(count, c) = pq.top();
            pq.pop();

            while(count--)
                ans += c;
        }

        return ans;
    }
};