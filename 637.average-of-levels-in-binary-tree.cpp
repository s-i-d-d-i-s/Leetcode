/*
 * @lc app=leetcode id=637 lang=cpp
 *
 * [637] Average of Levels in Binary Tree
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if(root == nullptr)return res;
        queue<TreeNode *> Q;
        Q.push(root);
        while(Q.size()>0){
            int cnt = Q.size();
            double sum = 0;
            for(int i=0;i<cnt;i++){
                auto node = Q.front();
                sum += node->val;
                Q.pop();
                if(node->left != nullptr)
                    Q.push(node->left);
                if(node->right != nullptr)
                    Q.push(node->right);
            }
            res.push_back(sum/(double)cnt);
        }
        return res;
    }
};
// @lc code=end

