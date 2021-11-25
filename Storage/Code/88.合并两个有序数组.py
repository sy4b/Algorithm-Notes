#
# @lc app=leetcode.cn id=88 lang=python3
#
# [88] 合并两个有序数组
#

# @lc code=start
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        # 特判
        if n==0:
            return
        if m==0:
            for i in range(n):
                nums1[i]=nums2[i]
            return
        # 定义指针
        index1, index2, index = m-1, n-1, len(nums1)-1
        while index1>=0 or index2>=0:
            if index1<0:
                nums1[index]=nums2[index2]
                index2=index2-1
            elif index2<0:
                nums1[index]=nums1[index1]
                index1=index1-1
            elif nums1[index1]<nums2[index2]:
                nums1[index]=nums2[index2]
                index2=index2-1
            else:
                nums1[index]=nums1[index1]
                index1=index1-1
            index=index-1

# @lc code=end

