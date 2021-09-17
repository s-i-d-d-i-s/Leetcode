/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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

int solve(TreeNode *root,int &res){
    if(root == nullptr)return 0;
    int left = solve(root->left,res);
    int right = solve(root->right,res);
    int cur = max({root->val,root->val+left,root->val+right});
    res = max(res,cur);
    res = max(res,root->val+left+right);
    return cur;
}
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res =root->val;
        solve(root,res);
        return res;
    }
};
// @lc code=end

