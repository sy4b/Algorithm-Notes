/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
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
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // BST满足对于任意一个节点，左子树的节点都比他小，右子树的节点都比他大
        TreeNode* ptr=root;
        while(ptr!=nullptr){            // 为空时说明找不到
            if(ptr->val == val){        // 找到
                return ptr;             
            }else if(ptr->val > val){   // 目标值比当前值小，往左边找
                ptr=ptr->left;
            }else{                      // 目标值比当前值大，往右边找
                ptr=ptr->right;
            }
        }
        return nullptr;
    }
};
// @lc code=end

