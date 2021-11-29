/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
/*
    滑动窗口
    1. 什么时候移动右边界？窗口长度小于s2长度
    2. 什么时候移动左边界？窗口长度等于s2长度，判断完毕之后。因为更大的窗口不存在答案
*/
class Solution {
    // 判断频次
    bool helper(vector<int>& vec1, vector<int>& vec2){
        for(int i=0;i<26;++i){
            if(vec1[i]!=vec2[i]){
                return false;
            }
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        // 用26长度vector记录字符出现频次,a-z映射到0-25
        // vec1记录s1的，vec2记录窗口的
        vector<int> vec1(26, 0), vec2(26, 0);
        for(auto& c: s1){
            ++vec1[c-'a'];
        }
        // 滑动窗口
        int left=0, right=0;
        while(right<s2.size()){
            ++vec2[s2[right]-'a'];
            // 条件满足，移动左边界
            if(right-left+1==s1.size()){
                if(helper(vec1, vec2)){
                    return true;
                }
                --vec2[s2[left]-'a'];
                ++left;
            }
            ++right;
        }
        return false;
    }
};
// @lc code=end

