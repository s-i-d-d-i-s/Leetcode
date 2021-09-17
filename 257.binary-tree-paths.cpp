/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
    void solve(TreeNode *root,string &path,vector<string> &res){
        if(root==nullptr)return;
        string cur = to_string(root->val);
        path+=cur;
        if(root->left==nullptr and root->right==nullptr){
            res.push_back(path);
            for(int i=0;i<cur.length();i++) path.pop_back();
            return ;
        }
        path+="->";
        solve(root->left,path,res);
        solve(root->right,path,res);
        for(int i=0;i<cur.length()+2;i++) path.pop_back();
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string path;
        vector<string> res;
        solve(root,path);
        return res;
    }
};
// @lc code=end

