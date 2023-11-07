/*

Author : Manas Rawat
Date : 07/11/2023
Problem : Eliminate Maximum Number of Monsters
Difficulty : Medium
Problem Link : https://leetcode.com/problems/eliminate-maximum-number-of-monsters/
Video Solution : https://youtu.be/9btWEMlzMoE

*/

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        
        vector<int> time(n);
        
        for(int i = 0; i < n; i++){
            time[i] = (dist[i] + speed[i] - 1) / speed[i];
        }
        
        sort(time.begin(), time.end());
        
        int cur = 0;
        int ans = 0;
        
        for(auto i : time){
            if(cur < i){
                ++ans;
                ++cur;
            }
            else{
                break;
            }
        }
        
        return ans;
    }
};