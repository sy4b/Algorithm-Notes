/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    将链表后半部分翻转，挨个比较
    空间O(1)
*/
class Solution {
    // 递归翻转链表
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
    bool isPalindrome(ListNode* head) {
        // 特殊判断
        if(head->next==nullptr){
            return true;
        }
        // 快慢指针分割链表
        ListNode *slow=head, *fast=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=slow->next;
        slow->next=nullptr;
        // 翻转后半部分
        fast=reverseList(fast);
        while(head!=nullptr && fast!=nullptr){
            if(head->val != fast->val){
                return false;
            }
            head=head->next;
            fast=fast->next;
        }
        return true;
    }
};
// @lc code=end

