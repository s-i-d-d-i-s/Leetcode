/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
 */

// @lc code=start
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
    int solve(TreeNode* root,bool isLeft=false){
        if(root==nullptr)return 0;
        if(root->left == nullptr and root->right == nullptr){
            if(isLeft)return root->val;
            return 0;
        }
        return solve(root->left,true) + solve(root->right,false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return solve(root);
    }
};
// @lc code=end

