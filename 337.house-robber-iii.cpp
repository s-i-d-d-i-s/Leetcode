/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
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
    int solve(TreeNode *root,int &l,int &r){
        if(root == nullptr) return 0;
        // Result from GrandChild
        int l1=0,r1=0,l2=0,r2=0;
        l = solve(root->left,l1,r1);
        r = solve(root->right,l2,r2);  
        // answer is max between two childs
        // or all grandchilds
        return max(l+r,root->val + l1+l2+r1+r2);
    }
    int rob(TreeNode* root) {
        int l=0,r=0;
        return solve(root,l,r);
    }
};
// @lc code=end

