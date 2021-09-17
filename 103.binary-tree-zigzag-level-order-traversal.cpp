/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr)return res;
        deque<TreeNode*> Q;
        Q.push_back(root);
        bool rev=1;
        while(Q.size()>0){
            int cnt = Q.size();
            vector<int> level;
            for(int i=0;i<cnt;i++){
                if(rev){
                    auto cur = Q.front(); 
                    if(cur!=nullptr){
                        level.push_back(cur->val);
                        Q.push_back(cur->left);
                        Q.push_back(cur->right);
                    }
                    Q.pop_front();
                }else{
                    auto cur = Q.back(); 
                    Q.pop_back();
                    if(cur!=nullptr){
                        level.push_back(cur->val);
                        Q.push_front(cur->right);
                        Q.push_back(cur->left);
                    }   
                    
                }
            }
            if(level.size()!=0) res.push_back(level);
            rev^=1;
        }
        return res;
    }
};
// @lc code=end

