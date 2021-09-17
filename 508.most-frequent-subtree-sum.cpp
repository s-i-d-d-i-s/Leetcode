/*
 * @lc app=leetcode id=508 lang=cpp
 *
 * [508] Most Frequent Subtree Sum
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
    map<int,int> freq;
    int solve(TreeNode *root){
        if(root == nullptr)return 0;
        int left = solve(root->left);
        int right = solve(root->right);
        freq[left+right+root->val]++;
        return left+right+root->val;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        solve(root);
        int maxi=0;
        for(auto x:freq){
            maxi = max(maxi,x.second);
        }
        vector<int> res;
        for(auto x:freq){
            if(x.second == maxi){
                res.push_back(x.first);
            }
        }
        return res;
    }
};
// @lc code=end

