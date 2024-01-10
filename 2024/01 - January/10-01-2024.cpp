/*

Author : Manas Rawat
Date : 10/01/2024
Problem : Amount of Time for Binary Tree to Be Infected
Difficulty : Medium
Problem Link : https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/
Video Solution : https://youtu.be/Bqx8AbNzGE4

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
    int amountOfTime(TreeNode* root, int start) {
        int ans = 0;
        map<TreeNode *, int> height;
        height[nullptr] = 0;
        
        function<int(TreeNode *)> dfs1 = [&](TreeNode * node) -> int {
            if(!node)
                return -1;
            
            int left = dfs1(node -> left);
            int right = dfs1(node -> right);
            
            return height[node] = max(left, right) + 1;
        };
        
        function<void(TreeNode *, int)> dfs2 = [&](TreeNode * node, int prev) {
            if(!node)
                return;
            
            if(node -> val == start){
                ans = max(prev, height[node]);
                return;
            }
            
            int left = (node -> left) ? height[node -> left] + 1 : 0;
            int right = (node -> right) ? height[node -> right] + 1 : 0;
            
            dfs2(node -> left, 1 + max(prev, right));
            dfs2(node -> right, 1 + max(prev, left));
        };
        
        dfs1(root);
        dfs2(root, 0);
        
        return ans;
    }
};