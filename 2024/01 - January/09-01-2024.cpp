/*

Author : Manas Rawat
Date : 09/01/2024
Problem : Leaf-Similar Trees
Difficulty : Easy
Problem Link : https://leetcode.com/problems/leaf-similar-trees/
Video Solution : https://youtu.be/P7gBx_vktgY

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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        deque<int> leaves;
        bool ans = 1;
        
        function<void(TreeNode*, bool)> traverse = [&](TreeNode * node, bool push) {
            if(!node)
                return;
            
            if(!(node -> left) and !(node -> right)){
                if(push){
                    leaves.push_back(node -> val);
                }
                else{
                    if(leaves.empty() or node -> val != leaves.front())
                        ans = 0;
                    
                    if(!leaves.empty())
                        leaves.pop_front();
                }
            }
            
            traverse(node -> left, push);
            traverse(node -> right, push);
        };
        
        traverse(root1, 1);
        traverse(root2, 0);
        
        return (ans and leaves.empty());
    }
};