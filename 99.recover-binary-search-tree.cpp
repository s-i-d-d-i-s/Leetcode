/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
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
TreeNode *pre;
TreeNode *first;
TreeNode *second;
void solve(TreeNode *root){
    if(root==nullptr)return ;
    solve(root->left);
    if(pre!=nullptr){
        if(pre->val>root->val){
            if(first==nullptr)
                first=pre;
            second=root;
        }
    }
    pre=root;
    solve(root->right);
}
class Solution {
public:
    void recoverTree(TreeNode* root) {
        first=nullptr;
        second=nullptr;
        pre=nullptr;
        solve(root);
        swap(first->val,second->val);
    }
};
// @lc code=end

