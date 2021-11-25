/*
 * @lc app=leetcode.cn id=563 lang=cpp
 *
 * [563] 二叉树的坡度
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
    int ans=0;
    // 每个节点要做什么事？
    // 要先知道左子树的和，右子树的和，计算坡度，然后返回自己这棵树的和
    // 因此确定后序遍历
    // 查找过程中不断计算坡度
    int lastOrder(TreeNode* root){
        // base case
        if(root==nullptr)   return 0;
        //
        int left=lastOrder(root->left), right=lastOrder(root->right);
        ans+=abs(left-right);
        return left+right+root->val;
    }
public:
    int findTilt(TreeNode* root) {
        lastOrder(root);
        return ans;
    }
};
// @lc code=end

