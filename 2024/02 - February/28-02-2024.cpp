/*

Author : Manas Rawat
Date : 28/02/2024
Problem : Find Bottom Left Tree Value
Difficulty : Medium 
Problem Link : https://leetcode.com/problems/find-bottom-left-tree-value/description/
Video Solution : NA

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
    int findBottomLeftValue(TreeNode* root) {
        int d = 0;
        int ans = root -> val;

        function<void(TreeNode *, int)> dfs = [&](TreeNode * node, int cd) {
            if(!node)
                return;

            if(cd > d) {
                d = cd;
                ans = node -> val;
            }

            dfs(node -> left, cd + 1);
            dfs(node -> right, cd + 1);
        };

        dfs(root, 0);

        return ans;
    }
};
