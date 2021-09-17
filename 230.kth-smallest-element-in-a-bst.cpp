/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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

void solve(TreeNode *root,int &k,int &res){
    if(root == nullptr )return;
    solve(root->left,k,res);
    if(k==1){
        res=root->val;
    }
    k--;
    solve(root->right,k,res);
}
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int res;
        solve(root,k,res);
        return res;
    }
};
// @lc code=end

