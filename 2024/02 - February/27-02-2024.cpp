/*

Author : Manas Rawat
Date : 27/02/2024
Problem : Diameter of Binary Tree 
Difficulty : Easy 
Problem Link : https://leetcode.com/problems/diameter-of-binary-tree/
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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;

        function<int(TreeNode *)> dfs = [&](TreeNode * node) -> int {
            if(!node)
                return 0;

            int left = dfs(node -> left);
            int right = dfs(node -> right);

            ans = max(ans, left + right);

            return max(left, right) + 1;
        };

        dfs(root);

        return ans;
    }
};
