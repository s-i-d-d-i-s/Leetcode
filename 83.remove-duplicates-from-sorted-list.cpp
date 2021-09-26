/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
    ListNode *solve(ListNode *root,int prev=-2000){
        if(root == nullptr )return root;
        if(root->val == prev){
            return solve(root->next,prev);
        }
        root->next = solve(root->next,root->val);
        return root;
    }
    ListNode* deleteDuplicates(ListNode* head) {
        return solve(head);
    }
};
// @lc code=end

