/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
 */

// @lc code=start
/*
    参考官解
    1. 双指针从两边检查
    2. 碰到不相等的字符，判断删除左边或右边字符后剩余字符串是否回文
*/
class Solution {
    bool helper(string& s, int l, int r){
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            ++l;
            --r;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int l=0, r=s.size()-1;
        while(l<r){
            if(s[l]!=s[r]){
                return helper(s, l+1, r) || helper(s, l, r-1);
            }
            ++l;
            --r;
        }
        return true;
    }
};
// @lc code=end

