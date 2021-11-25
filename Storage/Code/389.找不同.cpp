/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */

// @lc code=start
class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> vec(26,0);
        for(auto &c: s){
            ++vec[c-'a'];
        }
        for(auto &c: t){
            if(vec[c-'a']==0){
                return c;
            }
            --vec[c-'a'];
        }
        return ' ';
    }
};
// @lc code=end

