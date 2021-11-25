/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr) return l2;
        if(l2==nullptr) return l1;
        
        ListNode* dummy=new ListNode(0, nullptr), *p=dummy;
        while(l1!=nullptr && l2!=nullptr){
            if(l1->val < l2->val){
                p->next=l1;
                p=p->next;
                l1=l1->next;
            }else{
                p->next=l2;
                p=p->next;
                l2=l2->next;
            }
        }
        p->next=l1==nullptr?l2:l1;
        return dummy->next;
    }
};
// @lc code=end

