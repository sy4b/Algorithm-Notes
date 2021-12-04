/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
/*
     将链表对半分开，后面一半做一个逆序，然后交织即可
     1. 将链表二分，常规操作：快慢指针
     2. 交织：依次取一个节点连接
*/
class Solution {
    // 递归反转链表
    ListNode* reverseList(ListNode* head){
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* newHead=reverseList(head->next);
        head->next->next=head;
        head->next=nullptr;
        return newHead;
    }
public:
    void reorderList(ListNode* head) {
        // 特殊判断：直接返回原链表的情况
        if(head->next==nullptr || head->next->next==nullptr){
            return;
        }
        // 快慢指针将链表二分
        ListNode *slow=head, *fast=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* head1=slow->next;
        slow->next=nullptr;
        // 翻转下半
        head1=reverseList(head1);
        // 交织串成新链表
        ListNode *l1=head, *l2=head1;
        while(l1!=nullptr && l2!=nullptr){
            ListNode *temp1=l1->next, *temp2=l2->next;
            l1->next=l2;
            l1=temp1;
            l2->next=l1;
            l2=temp2;
        }
    }
};
// @lc code=end

