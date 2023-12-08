/*

Author : Manas Rawat
Date : 08/12/2023
Problem : Construct String from Binary Tree
Difficulty : Easy
Problem Link : https://leetcode.com/problems/construct-string-from-binary-tree/
Video Solution : https://youtu.be/UqIbvD4ktPw

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
    string tree2str(TreeNode* root) {
        if(!root)   
            return "";
        
        string ans = to_string(root -> val);
        
        if(root -> left and root -> right){
            ans += '(';
            ans += tree2str(root -> left);
            ans += ')';
            ans += '(';
            ans += tree2str(root -> right);
            ans += ')';
        }
        else if(root -> left){
            ans += '(';
            ans += tree2str(root -> left);
            ans += ')';
        }
        else if(root -> right){
            ans += "()(";
            ans += tree2str(root -> right);
            ans += ')';
        }
        
        return ans;
    }
};