#
# @lc app=leetcode.cn id=242 lang=python3
#
# [242] 有效的字母异位词
#

# @lc code=start
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s)!=len(t):
            return False
        dict={}
        for c in s:
            if (c in dict) == False:
                dict[c]=1
            else:
                dict[c]+=1
        for c in t:
            if ((c in dict) ==False) or dict[c]==0:
                return False
            dict[c]-=1
        return True

# @lc code=end

