/*
 * @lc app=leetcode id=563 lang=cpp
 *
 * [563] Binary Tree Tilt
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

int solve(TreeNode* root,int &res){
    if(root==nullptr)return 0;
    int left = solve(root->left,res);
    int right = solve(root->right,res);
    res += (abs(left-right));
    return left+right+root->val;
}
class Solution {
public:
    int findTilt(TreeNode* root) {
        int res=0;
        solve(root,res);
        return res;
    }
};
// @lc code=end

