/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
    bool helper(char c){
        if(c-'0'<0 || c-'0'>9){
            return false;
        }
        return true;
    }
public:
    int myAtoi(string s) {
        int index=0;
        int len=s.size();
        // 忽略前导空格
        while(index<len && s[index]==' '){
            ++index;
        }
        if(index==len)  return 0;
        // 符号
        int sign=1;
        if(s[index]=='-'){
            sign=-1;
            ++index;
        }
        // 非字母
        if(!helper(s[index])){
            return 0;
        }
        int ans=0;
        while(index<len && helper(s[index])){
            if(sign==1 && ((ans==INT_MAX/10 && (s[index]-'0')>INT_MAX%10) || (ans>INT_MAX/10))){
                return INT_MAX;
            }
            if(sign==-1 && ((ans>INT_MIN/10) || (ans==INT_MIN/10 &&(s[index]-'0')>INT_MIN%10))){
                return INT_MIN;
            }
            ans=ans*10+s[index]-'0';
            ++index;
        }
        return ans*sign;
    }
};
// @lc code=end

