/*

Author : Manas Rawat
Date : 28/11/2023
Problem : Number of Ways to Divide a Long Corridor
Difficulty : Hard
Problem Link : https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/
Video Solution : https://youtu.be/pLlwTvzZOK0

*/


class Solution {
public:
    int numberOfWays(string corridor) {
        vector<int> points;
        const long long mod = 1e9 + 7;
        
        int n = corridor.size();
        int total = 0;
        int index = 0;
        
        while(index < n){
            if(corridor[index] == 'S')
                ++total;
            
            if(!(total & 1) and total){
                ++index;
                int count = 1;
                while(index < n and corridor[index] != 'S'){
                    ++count;
                    ++index;
                }
                
                if(index < n)
                    points.push_back(count);
            }
            else{
                ++index;
            }
        }
        
        if((total & 1) or (total == 0))
            return 0;
        else{
            long long ans = 1;
            
            for(auto i : points)
                ans = (ans * (long long)i) % mod;
            
            return ans;
        }
        
        return 0;
    }
};