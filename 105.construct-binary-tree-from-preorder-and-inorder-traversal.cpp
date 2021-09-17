/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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


TreeNode* solve(vector<int> &pre,vector<int> &in,int l,int r,
    int &idx,vector<int> &getIdx){
    if(l>r)return nullptr;
    TreeNode *cur = new TreeNode(pre[idx++]);
    int ix = getIdx[cur->val+3000];
    cur->left = solve(pre,in,l,ix-1,idx,getIdx);
    cur->right = solve(pre,in,ix+1,r,idx,getIdx);
    return cur;
}
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        vector<int> getIdx(6001);
        for(int i=0;i<inorder.size();i++){
            getIdx[inorder[i]+3000]=i;
        }
        int idx=0;
        TreeNode* root = solve(preorder,inorder,0,preorder.size()-1,idx,getIdx);
        return root;
    }
};
// @lc code=end

