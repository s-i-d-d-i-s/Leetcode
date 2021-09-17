/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
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
    // map to check if previous prefix is present
    map<int,int> mp;
    int res=0,cur=0;
    void solve(TreeNode *root,int targetSum){
        if(root == nullptr)return;
        // add current node to total prefix
        cur += root->val;
        // value of left prefix need to get targetSum
        int need=cur-targetSum;
        // if this previous prefix was there, add +1 to res
        if(mp.find(need)!=mp.end())
            res+=mp[need];
        // add this prefix to map
        mp[cur]++;
        // recurse on both subtree
        solve(root->left,targetSum);
        solve(root->right,targetSum);
        // remove the current prefix from
        // map and current prefix
        mp[cur]--;
        cur -= root->val;
        return ;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr)return 0;
        mp[0]++;
        solve(root,targetSum);
        return res;
    }
};
// @lc code=end

