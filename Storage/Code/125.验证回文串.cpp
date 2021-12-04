/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */
/*
        双指针
*/

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        int len=s.size();
        int left=0, right=len-1;
        while(left<right){
            if(!isalnum(s[left])){
                ++left;
                continue;
            }
            if(!isalnum(s[right])){
                --right;
                continue;
            }
            if(isalpha(s[left]) && !isalpha(s[right]) || !isalpha(s[left]) && isalpha(s[right])){
                return false;
            }else{
                if(tolower(s[left])!=tolower(s[right])){
                    return false;
                }
            }
            ++left;
            --right;
        }
        return true;
    }
};
// @lc code=end

