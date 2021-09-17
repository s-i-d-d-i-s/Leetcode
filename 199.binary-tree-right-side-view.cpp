/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root==nullptr)return res;
        queue<TreeNode*> Q;
        Q.push(root);
        while(Q.size()>0){
            int cnt = Q.size();
            res.push_back(Q.front()->val);
            for(int i=0;i<cnt;i++){
                auto cur = Q.front();
                Q.pop();
                if(cur->right){
                    Q.push(cur->right);
                }
                if(cur->left){
                    Q.push(cur->left);
                }
            }
        }   
        return res;
    }
};
// @lc code=end

