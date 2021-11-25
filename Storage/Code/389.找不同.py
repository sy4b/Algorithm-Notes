#
# @lc app=leetcode.cn id=389 lang=python3
#
# [389] 找不同
#

# @lc code=start
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        if len(s)==0:
            return t
        dict={}
        for i in range(len(s)):
            if (s[i] in dict)==False:
                dict[s[i]]=1
            else:
                dict[s[i]]+=1
        for i in range(len(t)):
            if((t[i] in dict)==False or dict[t[i]]==0):
                return t[i]
            else:
                dict[t[i]]-=1
        return ""

# @lc code=end

