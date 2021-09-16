/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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

bool solve(TreeNode* left,TreeNode* right){
    if(left == nullptr and right==nullptr){
        return true;
    }
    if(left==nullptr or right==nullptr){
        return false;
    }
    
    if(left->val == right->val){
        return solve(left->left,right->right) &&
               solve(left->right,right->left);
    }
    return false;
}
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)return true;
        return solve(root->left,root->right);
    }
};
// @lc code=end

