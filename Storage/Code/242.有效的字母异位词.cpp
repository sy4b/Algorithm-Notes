/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
/*
    出现unicode字符，使用unordered_map替换vector
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        int slen=s.size(), tlen=t.size();
        // 长度不等直接判否
        if(slen!=tlen){
            return false;
        }
        vector<int> svec(26, 0), tvec(26, 0);
        for(int i=0;i<slen;++i){
            ++svec[s[i]-'a'];
            ++tvec[t[i]-'a'];
        }
        for(int i=0;i<26;++i){
            if(svec[i]!=tvec[i]){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

