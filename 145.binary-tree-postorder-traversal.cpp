/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
void solve(TreeNode *root,vector<int> &res){
    if(root == nullptr)return; 
    solve(root->left,res);
    solve(root->right,res);
    res.push_back(root->val);
}
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        solve(root,res);
        return res;
    }
};
// @lc code=end

