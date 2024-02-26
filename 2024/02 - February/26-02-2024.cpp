/*

Author : Manas Rawat
Date : 26/02/2024
Problem : Same Tree
Difficulty : Easy 
Problem Link : https://leetcode.com/problems/same-tree/description/
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        function<bool(TreeNode *, TreeNode *)> dfs = [&](TreeNode * x, TreeNode * y) -> bool {
            if((x == nullptr) ^ (y == nullptr))
                return 0;

            if(!x)
                return 1;

            if(x -> val != y -> val)
                return 0;

            return dfs(x -> left, y -> left) and dfs(x -> right, y -> right); 
        };

        return dfs(p, q);
    }
};
