#
# @lc app=leetcode.cn id=559 lang=python3
#
# [559] N 叉树的最大深度
#

# @lc code=start
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""
# py
class Solution:
    def maxDepth(self, root: 'Node') -> int:
        if not root:
            return 0
        Max=0
        for kids in root.children:
            Max=max(Max, self.maxDepth(kids))
        return Max+1

        
# @lc code=end

