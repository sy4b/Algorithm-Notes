/*
 * @lc app=leetcode.cn id=859 lang=cpp
 *
 * [859] 亲密字符串
 */

// @lc code=start
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        // 长度
        int len_s=s.size(), len_g=goal.size();
        // 字符串长度不等或者为1，false
        if(len_g!=len_s || len_s==1)    return false;
        // 记录字符
        vector<int> vec1(26,0), vec2(26,0);
        int diffNum=0;              // 记录不同的个数
        bool helper=false;
        for(int i=0;i<len_s;++i){
            if(s[i]!=goal[i]){
                if(diffNum==2)  return false;   // 两处以上
                ++diffNum;
            }
            ++vec1[s[i]-'a'];
            ++vec2[goal[i]-'a'];
            if(vec1[s[i]-'a']==2)   helper=true;
        }
        // 只有一处不等，false
        if(diffNum==1)  return false;
        // 相等的字符串，需要判断是否所有字符都只出现一次
        // abc abc false
        if(diffNum==0){
            return helper;
        }
        if(diffNum==2){
            // ab cd false 频次不等
            if(vec1!=vec2){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

