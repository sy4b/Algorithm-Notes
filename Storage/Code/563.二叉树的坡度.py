#
# @lc app=leetcode.cn id=563 lang=python3
#
# [563] 二叉树的坡度
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self) -> None:
        self.ans=0
    
    def lastOrder(self, root: TreeNode)->int:
        if not root:
            return 0
        left=self.lastOrder(root.left)
        right=self.lastOrder(root.right)
        self.ans+=abs(left-right)
        return left+right+root.val

    def findTilt(self, root: TreeNode) -> int:
        self.lastOrder(root)
        return self.ans
# @lc code=end

