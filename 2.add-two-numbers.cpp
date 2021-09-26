/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *prev = head;
        int carry =0 ;
        while(l1 or l2){
            int v1 = l1?l1->val:0;
            int v2 = l2?l2->val:0;
            int val = v1+v2+carry;
            carry = val/10;
            prev->next = new ListNode(val%10);
            prev = prev->next;
            l1 = l1?l1->next:NULL;
            l2 = l2?l2->next:NULL;
        }
        if(carry>0){
            prev->next = new ListNode(carry);
        }
        head = head->next;
        return head;
    }
};
// @lc code=end

