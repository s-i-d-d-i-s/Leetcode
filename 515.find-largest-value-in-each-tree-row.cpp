/*
 * @lc app=leetcode id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
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
    vector<int> res;
    void solve(TreeNode *root,int lvl=1){
        if(root==nullptr)return;
        if(lvl>res.size()){
            res.push_back(root->val);
        }else{
            res[lvl-1]=max(root->val,res[lvl-1]);
        }
        solve(root->left,lvl+1);
        solve(root->right,lvl+1);
    }
    vector<int> largestValues(TreeNode* root) {
        solve(root);
        return res;
    }
};
// @lc code=end

