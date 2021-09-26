/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
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
    int prev = INT_MIN + 1e5;
    int res= INT_MAX;
    void solve(TreeNode *root){
        if(root == nullptr)return;
        solve(root->left);
        res = min (res,root->val-prev);
        prev=root->val;
        solve(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        solve(root);
        return res;
    }
};
// @lc code=end

