/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr)return nullptr;
        // Node just before previous node
        ListNode *prev = nullptr;
        ListNode *one = head;
        while(one and one->next){
            // Get the second node
            ListNode *two = one->next;
            // Make current node point to its
            // child's child
            one->next = one->next->next;
            // Child points to its parent
            two->next = one;
            // if there is a previous node
            // it points to the child
            if(prev!=nullptr)
                prev->next = two;
            else
                head=two;                
            // the prev is updated
            prev = one;
            one=one->next;
        }
        return head;
    }
};
// @lc code=end

