#
# @lc app=leetcode.cn id=231 lang=python3
#
# [231] 2 的幂
#

# @lc code=start
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n<=0:
            return False
        if n==1:
            return True
        while n>1:
            if n%2!=0:
                return False
            n=n/2
        return True

# @lc code=end

