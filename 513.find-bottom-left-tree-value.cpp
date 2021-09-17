/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
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
    int lvl=-1,res;
    void solve(TreeNode *root,int curLvl=0){
        if(root == nullptr)return;
        solve(root->left,curLvl+1);
        if(curLvl>lvl){
            lvl=curLvl;
            res=root->val;
        }
        solve(root->right,curLvl+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        solve(root);
        return res;
    }
};
// @lc code=end

