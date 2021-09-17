/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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

TreeNode* solve(vector<int> &nums,int l,int r){
    if(l>r)return nullptr;
    int m = (l+r)/2;
    TreeNode *cur = new TreeNode(nums[m]);
    if(l==r)return cur;
    cur->left = solve(nums,l,m-1);
    cur->right = solve(nums,m+1,r);
    return cur;
}
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* res = solve(nums,0,nums.size()-1);
        return res;
    }
};
// @lc code=end

