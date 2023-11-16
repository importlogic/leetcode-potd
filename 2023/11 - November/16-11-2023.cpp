/*

Author : Manas Rawat
Date : 16/11/2023
Problem : Find Unique Binary String
Difficulty : Medium
Problem Link : https://leetcode.com/problems/find-unique-binary-string/
Video Solution : https://youtu.be/YEAJRiDYYkQ

*/


class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        vector<int> values;
        
        for(auto i : nums){
            string cur = i;
            reverse(cur.begin(), cur.end());
            
            int val = 0;
            for(int j = 0; j < cur.size(); j++)
                if(cur[j] == '1')
                    val += (1 << j);
            
            values.push_back(val);
        }
        
        sort(values.begin(), values.end());
        
        int ans = 0;
        
        for(auto i : values){
            if(i == ans)
                ++ans;
            else
                break;
        }
        
        string res = "";
        while(ans){
            if(ans & 1)
                res += '1';
            else
                res += '0';
            
            ans >>= 1;
        }
        
        while(res.size() < nums[0].size())
            res += '0';
    
        reverse(res.begin(), res.end());
        
        return res;
    }
};