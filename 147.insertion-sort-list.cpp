/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *prev = new ListNode(-6000,head);

        while(prev!=nullptr){
            ListNode *j = prev;
            ListNode *mini =j;
            while(j->next!=nullptr){
                if(j->next->val < mini->next->val){
                    mini=j;
                }
                j=j->next;
            }

        }
    }
};
// @lc code=end

