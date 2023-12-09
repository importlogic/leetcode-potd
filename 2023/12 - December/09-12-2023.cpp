/*

Author : Manas Rawat
Date : 09/12/2023
Problem : Binary Tree Inorder Traversal
Difficulty : Easy
Problem Link : https://leetcode.com/problems/binary-tree-inorder-traversal/
Video Solution : https://youtu.be/z8JxFCli6aQ

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        
        function<void(TreeNode *)> traverse = [&](TreeNode * node) {
            if(!node)
                return;
            
            traverse(node -> left);
            inorder.push_back(node -> val);
            traverse(node -> right);
        };
        
        traverse(root);
        
        return inorder;
    }
};