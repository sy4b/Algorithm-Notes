/*
 * @lc app=leetcode.cn id=953 lang=cpp
 *
 * [953] 验证外星语词典
 */

// @lc code=start
/*
    map记录每个字母的次序，以供O(1)查找
*/
class Solution {
    unordered_map<char, int> mp;
    bool helper(string& s1, string& s2){
        int l1=s1.size(), l2=s2.size();
        int index=0;
        while(index<l1 || index<l2){
            char c1=index<l1?s1[index]:'0', c2=index<l2?s2[index]:'0';
            if(c1==c2){
                ++index;
                continue;
            }
            return mp[c1]<mp[c2];
        }
        return true;
    }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        // 记录字母的次序
        for(int i=0;i<order.size();++i){
            mp[order[i]]=i+1;
        }
        mp['0']=0;      // 空字符最高次序
        // 挨个检查排序
        for(int i=0;i<words.size()-1;++i){
            if(!helper(words[i], words[i+1])){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

