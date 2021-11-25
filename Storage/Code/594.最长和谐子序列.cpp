/*
 * @lc app=leetcode.cn id=594 lang=cpp
 *
 * [594] 最长和谐子序列
 */

// @lc code=start
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto i: nums){
            mp[i]++;
        }
        int ans=0;
        for(auto &m: mp){
            if(mp.find(m.first+1)!=mp.end()){
                int temp=mp[m.first]+mp[m.first+1];
                ans=max(ans, temp);
            }
        }
        return ans;
    }
};
// @lc code=end

