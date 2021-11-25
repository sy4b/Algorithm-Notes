/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
class Solution {
    TreeNode* helper(TreeNode *root){
        if(root==nullptr)   return nullptr;
        auto left=helper(root->left), right=root->right;
        root->left=nullptr;
        root->right=left;
        TreeNode* p=left;
        while(p!=nullptr && p->right!=nullptr)   p=p->right;
        p->right=right;
        return root;
    }
public:
    void flatten(TreeNode* root) {
        helper(root);
    }
};
// @lc code=end

