/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
<<<<<<< HEAD
        ListNode *slow=head;
        ListNode *fast=head;
        while(slow!= NULL and fast!= NULL){
            slow = slow->next;
            fast = fast->next;
            if(fast == NULL)return false;
            fast = fast->next;
            if(slow == fast) return true;
=======
        ListNode *slow = head;
        ListNode *fast = head;
        while(slow and fast){
            slow=slow->next;
            fast=fast->next;
            if(fast == nullptr)return false;
            fast = fast->next;
            if(slow == fast)return true;
>>>>>>> 25c9ca9ed758beefff9b77d5d034e44cc8c7ab5f
        }
        return false;
    }
};
// @lc code=end

