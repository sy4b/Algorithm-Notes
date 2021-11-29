/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
/*
    滑动窗口
    1. 移动右边界：窗口内没有重复字符
    2. 移动左边界：窗口内字符重复了，要去掉一些
*/

// @lc code=start
class Solution {
    // 检测窗口内是否没有重复
    bool helper(unordered_map<char,int>& mp){
        for(auto& p: mp){
            if(p.second>1){
                return false;
            }
        }
        return true;
    }
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int right=0, left=0, ans=0;
        while(right<s.size()){
            ++mp[s[right]];
            // 窗口内重复时，移动左边界缩小窗口
            while(!helper(mp)){
                --mp[s[left]];
                ++left;
            }
            ans=max(ans,right-left+1);
            ++right;
        }
        return ans;
    }
};
// @lc code=end

