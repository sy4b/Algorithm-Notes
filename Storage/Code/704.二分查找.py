#
# @lc app=leetcode.cn id=704 lang=python3
#
# [704] 二分查找
#

# @lc code=start
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r= 0, len(nums)-1
        while l<r:
            m=l+(r-l)//2
            if nums[m]==target:
                return m
            elif nums[m]>target:
                r=m
            else:
                l=m+1
        if nums[l]!=target:
            return -1
        return l

# @lc code=end

