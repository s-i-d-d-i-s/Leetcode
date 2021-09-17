/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr){
            return res;
        }
        queue<pair<TreeNode*,int>> Q;
        Q.push({root,1});
        while(Q.size()>0){
            auto cur = Q.front();
            Q.pop();
            if(res.size()<cur.second){
                vector<int> lvl ;
                lvl.push_back(cur.first->val);
                res.push_back(lvl);
            }else{
                res[cur.second-1].push_back(cur.first->val);
            }
            if(cur.first->left != nullptr){
                Q.push({cur.first->left,cur.second+1});
            }
            if(cur.first->right != nullptr){
                Q.push({cur.first->right,cur.second+1});
            }
        }
        return res;
    }
};
// @lc code=end

