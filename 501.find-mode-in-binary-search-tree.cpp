/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
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
    int prev=INT_MIN,cnt=0,mode=0;
    void solve(TreeNode *root,vector<int> &res){
        if(root == nullptr)return ;
        solve(root->left,res);
        if(root->val == prev)
            cnt++;
        else
            cnt=1;
        if(cnt > mode){
            res.clear();
            res.push_back(root->val);
            mode = cnt;
        }else if(cnt == mode){
            res.push_back(root->val);
        }
        prev = root->val;
        solve(root->right,res);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        solve(root,res);
        return res;
    }
};
// @lc code=end

