/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // 贪心，大的饼干分给胃口大的孩子
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        int index=s.size()-1;
        int ans=0;
        for(int i=g.size()-1;i>=0;--i){
            if(index>=0 && s[index]>=g[i]){
                ++ans;
                --index;
            }
        }
        return ans;
    }
};
// @lc code=end

