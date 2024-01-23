/*

Author : Manas Rawat
Date : 23/01/2024
Problem : Maximum Length of a Concatenated String with Unique Characters
Difficulty : Medium
Problem Link : https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/
Video Solution : https://youtu.be/-Y4hPWZZGAY

*/


class Solution {
public:
    int maxLength(vector<string>& arr) {
        int ans = 0;
        int n = arr.size();

        for(int i = 0; i < (1 << n); i++){
            int cur_ans = 0;
            vector<int> f(26, 0);

            for(int j = 0; j < n; j++){
                if((i >> j) & 1){
                    cur_ans += arr[j].size();

                    for(auto x : arr[j])
                        ++f[x - 'a'];
                }
            }

            bool ok = 1;
            for(auto x : f){
                if(x > 1){
                    ok = 0;
                    break;
                }
            }

            if(ok)
                ans = max(ans, cur_ans);
        }

        return ans;
    }
};