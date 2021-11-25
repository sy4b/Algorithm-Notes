/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
    
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len=strs.size();
        if(len==1)  return strs[0];
        string ans="";
        int index=0;
        while(true){
            if(index>=strs[0].size())    break;
            char ch=strs[0][index];
            bool bre=false;
            for(int i=1;i<len;++i){
                if(index>=strs[i].size()){
                    bre=true;
                    break;
                }
                if(strs[i][index]!=ch){
                    bre=true;
                    break;
                }
            }
            if(bre) break;
            ans+=ch;
            ++index;
        }
        return ans;
    }
};
// @lc code=end

