/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())  return false;
        vector<int> vec(26,0);
        for(auto &c: s){
            ++vec[c-'a'];
        }
        for(auto &c: t){
            if(vec[c-'a']==0){
                return false;
            }
            --vec[c-'a'];
        }
        return true;
    }
};
// @lc code=end

