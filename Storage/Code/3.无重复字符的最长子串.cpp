/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=s.size();
        int left=0, right=0, ans=0;
        unordered_set<char> st;
        while(right<len){
            while(st.count(s[right])>0){
                st.erase(s[left]);
                ++left;
            }
            st.insert(s[right]);
            ans=max(ans, right-left+1);
            ++right;
        }
        return ans;
    }
};
// @lc code=end

