/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
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
    不允许反转链表，又为了对齐数位，使用两个栈
    使用头插法建立新链表，达成逆序
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 特殊判断
        if(l1->val==0 || l2->val==0){
            return l1->val==0?l2:l1;
        }
        // 使用栈将两个链表逆序，进行数位对齐
        stack<ListNode*> stk1, stk2;
        ListNode* p1=l1, *p2=l2;
        while(p1){
            stk1.push(p1);
            p1=p1->next;
        }while(p2){
            stk2.push(p2);
            p2=p2->next;
        }
        // 开始进行计算，使用头插法建立新链表
        ListNode *ans=new ListNode(0, nullptr);
        int carry=0;    // 储存进位
        while(!stk1.empty() || !stk2.empty()){
            int num1=stk1.empty()?0:stk1.top()->val;
            int num2=stk2.empty()?0:stk2.top()->val;
            int sum=num1+num2+carry;
            ListNode *node=new ListNode(sum%10, ans->next);
            ans->next=node;
            carry=sum/10;
            // 计算完一位后，进行出战操作
            if(stk1.empty()==false) stk1.pop();
            if(stk2.empty()==false) stk2.pop();
        }
        // 检查最后是否还有进位
        if(carry!=0){
            ListNode *node=new ListNode(carry, ans->next);
            ans->next=node;
        }
        return ans->next;
    }
};
// @lc code=end

