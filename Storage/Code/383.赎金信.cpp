/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */
/*
    用长度为26的vector记录字符出现的频次
    用unordered_map<char, int>也可以
*/
// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> mp(26, 0);
        for(auto& c: magazine){
            ++mp[c-'a'];
        }
        for(auto& r: ransomNote){
            if(mp[r-'a']==0){
                return false;
            }
            --mp[r-'a'];
        }
        return true;
    }
};
// @lc code=end

