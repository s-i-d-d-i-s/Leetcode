/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr)return nullptr;
        if(key < root->val){
            root->left = deleteNode(root->left,key);
        }else if(key > root->val){
            root->right = deleteNode(root->right,key);
        }else{
            // leaf node
            if(root->left == nullptr and root->right==nullptr){
                delete(root);
                return nullptr;
            }
            // 1-child
            if(root->left == nullptr or root->right==nullptr){
                TreeNode *sav=root->left==nullptr?root->right:root->left;
                delete(root);
                return sav;
            }
            // 2-child
            // Find minimum in right subtree
            TreeNode *tmp = root->right;
            while(tmp -> left){
                tmp = tmp->left;
            }
            // swap its value with current node
            root->val = tmp->val;
            // remove that minimum in right subtree
            root->right = deleteNode(root->right,root->val); 
        }
        return root;
    }
};
// @lc code=end

