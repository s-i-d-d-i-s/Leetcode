/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
    void reorderList(ListNode* head) {
        vector<ListNode*> stac;
        ListNode *cur = head;
        while(cur !=nullptr){
            stac.push_back(cur);
            cur = cur ->next;
        }
        int len = stac.size();
        cur = head;
        for(int i=0;i<len/2;i++){
            ListNode *last = stac.back();
            stac.pop_back();
            last->next = cur->next;
            cur->next=last;
            cur=last->next;
        }
        cur->next=nullptr;
        return ;
    }
};
// @lc code=end

