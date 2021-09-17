/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
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
class BSTIterator {
public:
    stack<TreeNode *> stc;
    
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        // get the top most element of stack
        TreeNode *tmp = stc.top();
        stc.pop();
        // push all to the right of the popped node
        pushAll(tmp->right);
        return tmp->val;
    }
    
    bool hasNext() {
        return stc.size()>0;
    }
    // push all left elements till there is none
    void pushAll(TreeNode *root){
        while(root!=nullptr){
            stc.push(root);
            root=root->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

