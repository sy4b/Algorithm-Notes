#
# @lc app=leetcode.cn id=202 lang=python3
#
# [202] 快乐数
#

# @lc code=start
class Solution:

    def isHappy(self, n: int) -> bool:
        def newNum(n: int) -> int:
            ans=0
            while n>0:
                ans+=(n%10)**2
                n=n//10
            return ans
        dict={}
        while n>1:
            if n in dict:
                return False
            dict[n]=1
            n=newNum(n)
        return True
        
# @lc code=end

