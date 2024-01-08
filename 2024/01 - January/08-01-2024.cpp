/*

Author : Manas Rawat
Date : 08/01/2024
Problem : Range Sum of BST
Difficulty : Easy
Problem Link : https://leetcode.com/problems/range-sum-of-bst/
Video Solution : https://youtu.be/EBSxsMnbGHs

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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        
        function<void(TreeNode *)> traverse = [&](TreeNode * node) {
            if(!node)
                return;
            
            if(node -> val >= low and node -> val <= high){
                ans += node -> val;
                traverse(node -> left);
                traverse(node -> right);
            }
            else if(node -> val < low){
                traverse(node -> right);
            }
            else if(node -> val > high){
                traverse(node -> left);
            }
        };   
        
        traverse(root);
        
        return ans;
    }
};