/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
/*
    对于一组字母异位词，排序后的结果相同
    1. 对单词进行排序，插入对应map中
    2. 依次取出即可
*/
class Solution {
    unordered_map<string, vector<string>> mp;
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        for(auto& s: strs){
            string temp=s;
            sort(s.begin(), s.end());
            mp[s].push_back(temp);
        }
        vector<vector<string>> ans;
        for(auto& p: mp){
            ans.push_back(p.second);
        }
        return ans;
    }
};
// @lc code=end

