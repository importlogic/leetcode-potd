/*

Author : Manas Rawat
Date : 17/02/2024
Problem : Furthest Building You Can Reach
Difficulty : Medium
Problem Link : https://leetcode.com/problems/furthest-building-you-can-reach/description/
Video Solution : https://youtu.be/9sKP5QBCAa4

*/


class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();

        int low = 0;
        int high = n;

        auto check = [&](int p) -> bool {
            int rem_brick = bricks;
            vector<int> need;

            for(int i = 0; i < p; i++){
                if(heights[i + 1] > heights[i])
                    need.push_back(heights[i + 1] - heights[i]);
            }

            sort(need.begin(), need.end(), [](int a, int b){
                return a > b;
            });

            while(need.size() and rem_brick >= need.back()){
                rem_brick -= need.back();
                need.pop_back();
            }

            return ladders >= need.size();
        };

        while(low < high - 1){
            int mid = low + (high - low) / 2;

            if(check(mid))
                low = mid;
            else
                high = mid;
        }

        return low;
    }
};