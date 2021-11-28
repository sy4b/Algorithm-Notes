/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
/*
    滑动窗口
    1. 窗口长度小于p长度，就可以移动右边界
    2. 窗口长度等于p长度，进行判断
    3. 窗口长度等于p长度，左边界右移
    4. 判断：记录字符频次，26长度的vector
*/

class Solution {
    // 比较窗口和字符频次，频次相等，是易位词，返回true
    bool helper(vector<int>& pvec, vector<int>& svec){
        for(int i=0;i<26;++i){
            if(pvec[i]!=svec[i]){
                return false;
            }
        }
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        int left=0, right=0;
        // 两个vec用来记录频次
        vector<int> ans, svec(26, 0), pvec(26, 0);
        for(auto &c: p){
            ++pvec[c-'a'];  // 注意'a'-'z'映射到0-25
        }

        while(right<s.size()){
            ++svec[s[right]-'a'];           // 记录右边界
            if(right-left+1==p.size()){     // 尝试滑动左边界
                if(helper(svec, pvec)){
                    ans.push_back(left);
                }
                --svec[s[left]-'a'];
                ++left;
            }
            ++right;                        // 移动右边界
        }

        return ans;

    }
};
// @lc code=end

