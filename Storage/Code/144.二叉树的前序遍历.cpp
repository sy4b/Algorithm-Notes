/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/* 递归
class Solution {
    vector<int> ans;
    void preOrder(TreeNode* root){
        if(root==nullptr)   return;
        ans.push_back(root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        preOrder(root);
        return ans;
    }
};
*/

// 迭代法
class Solution{
public:
    vector<int> preorderTraversal(TreeNode* root){
        vector<int> ans;
        if(root==nullptr)   return ans;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            auto top=stk.top();
            stk.pop();
            // 处理根节点
            ans.push_back(top->val);
            // 先入右节点，再入左，这样出栈就是先左
            if(top->right)  stk.push(top->right);
            if(top->left)   stk.push(top->left);
        }
        return ans;
    }
};
// @lc code=end

