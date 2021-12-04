/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
// /*
//     迭代法
//     需要记录前一个节点、当前节点以及下一个节点
// */
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode *cur=head, *pre=nullptr;
//         while(cur!=nullptr){
//             ListNode* next=cur->next;
//             cur->next=pre;
//             pre=cur;
//             cur=next;
//         }
//         return pre;
//     }
// };

/*
    递归法
    1. 可以看做后序遍历
    2. 拆分成子问题，当前节点和后面其他完成翻转的链表交换次序，因此是后序遍历的框架
    3. 递归终止条件：当前节点为空或已经是最后一个节点
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* newHead=reverseList(head->next);
        head->next->next=head;
        head->next=nullptr;
        return newHead;
    }
};
// @lc code=end

