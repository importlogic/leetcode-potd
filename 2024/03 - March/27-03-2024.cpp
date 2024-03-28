/*

Author : Manas Rawat 
Date : 27/03/2024
Problem : Subarray Product Less Than K
Difficulty : Medium 
Problem Link : https://leetcode.com/problems/subarray-product-less-than-k/description/?envType=daily-question&envId=2024-03-27
Video Solution : NA

*/


class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) return 0;
        double logK = log(k);
        int m = nums.size() + 1;
        vector<double> logsPrefixSum(m);

        for (int i = 0; i < nums.size(); i++) {
            logsPrefixSum[i + 1] = logsPrefixSum[i] + log(nums[i]);
        }

        int totalCount = 0;

        for (int currIdx = 0; currIdx < m; currIdx++) {
            int low = currIdx + 1, high = m;
            while (low < high) {
                int mid = low + (high - low) / 2;
                if (logsPrefixSum[mid] < logsPrefixSum[currIdx] + logK - 1e-9) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }
            totalCount += low - currIdx - 1;
        }

        return totalCount;
    }
};     
    
