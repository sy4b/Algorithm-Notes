#
# @lc app=leetcode.cn id=230 lang=python3
#
# [230] 二叉搜索树中第K小的元素
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        ans=0
        def inOrder(root: TreeNode, cur: int, k: int):
            if root==None or cur>k:
                return
            inOrder(root.left, cur+1, k)
            if cur==k:
                ans=k
            inOrder(root.right, cur)
        inOrder(root)
        return ans
# @lc code=end

