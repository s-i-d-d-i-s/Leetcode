/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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

    TreeNode* solve(TreeNode *root){
        if(root == nullptr)return nullptr;
        if(root->left==nullptr and root->right == nullptr) return root;
        
        TreeNode *left = solve(root->left);
        TreeNode *right = solve(root->right);
        if(left!=nullptr and right!=nullptr){
            left->right = root->right;
            root->right = root->left;
            root->left=nullptr;
            return right;
        }else if(right != nullptr){
            return right;
        }else if(left!=nullptr){
            root->right=root->left;
            root->left=nullptr;
            return left;
        }
        return nullptr;
    }
    void flatten(TreeNode* root) {
        solve(root);
        return ;
    }
};
// @lc code=end

