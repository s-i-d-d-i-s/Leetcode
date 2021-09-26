/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


class Solution {
public:
    ListNode * solve(ListNode *root,int skip=INT_MIN){
        if(root == nullptr)return nullptr;
        if(root->val == skip){
            return solve(root->next,skip);
        }
        if(root->next == nullptr){
            return root;
        }
        if(root->val == root->next->val){
            return solve(root->next,root->val);
        }
        root->next = solve(root->next);
        return root;   
    }
    ListNode* deleteDuplicates(ListNode* head) {
        return solve(head);
    }
};
// @lc code=end

