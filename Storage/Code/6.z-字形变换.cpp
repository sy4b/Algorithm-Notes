/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)  return s;
        vector<string> vec(numRows,"");
        int index1=0;
        int index2=0;
        bool grow, fall;
        while(index1<s.size()){
            if(index2==0){
                grow=true;
                fall=false;
            }
            if(index2==numRows-1){
                grow=false;
                fall=true;
            }
            vec[index2].push_back(s[index1]);
            ++index1;
            if(grow){
                index2++;
            }
            if(fall){
                index2--;
            }
        }
        string ans="";
        for(int i=0;i<numRows;++i){
            ans+=vec[i];
        }
        return ans;
    }
};
// @lc code=end

