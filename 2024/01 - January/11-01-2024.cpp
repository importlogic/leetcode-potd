/*

Author : Manas Rawat
Date : 11/01/2024
Problem : Maximum Difference Between Node and Ancestor
Difficulty : Medium
Problem Link : https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
Video Solution : https://youtu.be/LZxShI1FwAw

*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        const int inf = 1e6;
        
        function<pair<int,int>(TreeNode *)> dfs = [&](TreeNode * node) -> pair<int,int> {
            if(!node)
                return {inf, -inf};
            
            pair<int,int> left = dfs(node -> left);
            pair<int,int> right = dfs(node -> right);
            
            int MIN = min(left.first, right.first);
            int MAX = max(left.second, right.second);
            
            if(node -> left or node -> right)
                ans = max({ans, abs(MIN - node -> val), abs(MAX - node -> val)});
            
            return {min(MIN, node -> val), max(MAX, node -> val)};
        };
        
        dfs(root);
        
        return ans;
    }
};