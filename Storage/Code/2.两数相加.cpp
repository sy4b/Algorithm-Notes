/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
        if(l1->val == 0 && l1->next==nullptr)    return l2;
        if(l2->val == 0 && l2->next==nullptr)    return l1;
        ListNode *dummy=new ListNode(0,nullptr), *p=dummy;
        int carry=0;
        while(l1 || l2){
            int val1=l1?l1->val:0;
            int val2=l2?l2->val:0;
            int sum=val1+val2+carry;
            p->next=new ListNode(sum%10, nullptr);
            p=p->next;
            carry=sum/10;
            l1=l1!=nullptr?l1->next:nullptr;
            l2=l2!=nullptr?l2->next:nullptr;
        }
        if(carry!=0) p->next=new ListNode(carry);
        return dummy->next;
    }
};
// @lc code=end

