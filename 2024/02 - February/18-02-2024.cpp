/*

Author : Manas Rawat
Date : 18/02/2024
Problem : Meeting Rooms III
Difficulty : Hard
Problem Link : https://leetcode.com/problems/meeting-rooms-iii/description/
Video Solution : https://youtu.be/7h047ZRAWhs

*/


class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<int> ans(n, 0);
        
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        priority_queue<long long, vector<long long>, greater<long long>> pq2;
        for(int i = 0; i < n; i++)
            pq.push({0, i});

        long long time = 0;
        for(int i = 0; i < meetings.size(); i++){
            time = max(time, (long long)meetings[i][0]);

            while(pq.size() and time >= pq.top().first){
                pq2.push(pq.top().second);
                pq.pop();
            }

            if(pq2.empty()){
                time = pq.top().first;
                while(pq.size() and time >= pq.top().first){
                    pq2.push(pq.top().second);
                    pq.pop();
                }                
            }

            int meet = pq2.top();
            pq2.pop();

            ++ans[meet];
            pq.push({time + meetings[i][1] - meetings[i][0], meet});
        }

        int room = 0;
        int MAX = 0;

        for(int i = 0; i < n; i++){
            if(ans[i] > MAX){
                MAX = ans[i];
                room = i;
            }
        }

        return room;
    }
};