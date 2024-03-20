/*

Author : Saransh Bangar
Date : 19/03/2024
Problem : Task Scheduler
Difficulty : Medium 
Problem Link : https://leetcode.com/problems/task-scheduler/description/
Video Solution : NA

*/


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        int freq[26]={0};
        for (char &ch : tasks)
            freq[ch-'A']++;

        priority_queue<int> pq;
        for (int i=0; i < 26; i++)
            if (freq[i] > 0)
                pq.push(freq[i]);

        int time=0;
        while (!pq.empty())
        {
            int cycle=n + 1;
            vector<int> store;
            int taskCount=0;
            
            while (cycle-- && !pq.empty())
            {
                if (pq.top() > 1)
                    store.push_back(pq.top() - 1);

                pq.pop();
                taskCount++;
            }
            for (int &x : store)
                pq.push(x);
            time += (pq.empty() ? taskCount : n + 1);
        }
        return time;
    }
};
