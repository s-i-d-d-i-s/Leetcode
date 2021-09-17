/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    map<int,int> getidx;    
    
    TreeNode *solve(vector<int> &in,vector<int> &post,int l,int r,int &idx){
        if(l>r)return nullptr;
        TreeNode* cur = new TreeNode(post[idx--]);
        if(l==r){
            return cur;
        }
        int m = getidx[cur->val];
        // for post order, first call right
        // for pre order, first call left
        cur->right = solve(in,post,m+1,r,idx);
        cur->left = solve(in,post,l,m-1,idx);
        return cur;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        for(int i=0;i<inorder.size();i++){
            getidx[inorder[i]]=i;
        }
        int idx=postorder.size()-1;
        TreeNode* root = solve(inorder,postorder,0,inorder.size()-1,idx);
        return root;
    }
};
// @lc code=end

