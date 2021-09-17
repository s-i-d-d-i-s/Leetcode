/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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

void solve(TreeNode *root,int &res,int cur){
    if(root==nullptr)return;
    if(root->left == nullptr and root->right == nullptr){
        res += (cur*10 + root->val);
        return;
    }
    solve(root->left,res,cur*10+root->val);
    solve(root->right,res,cur*10+root->val);
    return;
}
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int res=0;
        solve(root,res,0);
        return res;
    }
};
// @lc code=end

