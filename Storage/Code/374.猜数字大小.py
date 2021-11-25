#
# @lc app=leetcode.cn id=374 lang=python3
#
# [374] 猜数字大小
#

# @lc code=start
# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num: int) -> int:

class Solution:
    def guessNumber(self, n: int) -> int:
        left, right=0, n
        while left<right:
            mid=left+(right-left)/2
            ans=guess(mid)
            if ans==0:
                return int(mid)
            elif ans>0:
                left=mid+1
            else:
                right=mid
        return int(left)
        
# @lc code=end

