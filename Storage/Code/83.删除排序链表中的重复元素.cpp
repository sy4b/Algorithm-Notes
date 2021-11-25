/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr)   return head;
        ListNode *left=head, *right=head;
        while(right!=nullptr){
            if(left->val == right->val){
                right=right->next;
            }else{
                left->next=right;
                left=left->next;
                right=right->next;
            }
        }
        left->next=right;
        return head;
    }
};
// @lc code=end

