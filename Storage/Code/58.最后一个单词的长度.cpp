/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int left, right=s.size()-1;
        while(s[right]==' '){
            --right;
        }
        left=right-1;
        while(left>=0 && s[left]!=' '){
            --left;
        }
        return right-left;
    }
};
// @lc code=end

