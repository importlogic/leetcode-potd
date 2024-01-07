/*

Author : Manas Rawat
Date : 06/01/2024
Problem : Maximum Profit in Job Scheduling
Difficulty : Hard
Problem Link : https://leetcode.com/problems/maximum-profit-in-job-scheduling/
Video Solution : https://youtu.be/IBSv87Sk-rw

*/


class job{
    public:
        int start, end, profit;
    
    job(int a, int b, int c){
        start = a;
        end = b;
        profit = c;
    }
};

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        
        vector<job> jobs;
        
        for(int i = 0; i < n; i++){
            job newJob(startTime[i], endTime[i], profit[i]);
            jobs.emplace_back(newJob);
        }
        
        sort(jobs.begin(), jobs.end(), [](job &a, job &b){
            return a.start < b.start;    
        });
            
        vector<int> dp(n + 1, 0);
        
        for(int i = n - 1; i > -1; i--){
            int take, notake;
            
            notake = dp[i + 1];
            
            int low = i; // low is always false
            int high = n; // high is always true
            
            while(low < high - 1){
                int mid = low + (high - low) / 2;
                
                if(jobs[mid].start >= jobs[i].end)
                    high = mid;
                else
                    low = mid;
            }
            
            take = jobs[i].profit + dp[high];
            
            dp[i] = max(take, notake);
        }
        
        return dp[0];
    }
};