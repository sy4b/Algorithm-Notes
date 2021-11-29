/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int preSum=0, ans=0;
        mp[0]=1;    // 必须记录一个0，可能第一个元素就满足题目要求
        for(int i=0;i<nums.size();++i){
            preSum+=nums[i];    // 更新前缀和
            // 查找map是否有k-preSum
            if(mp[preSum-k]!=0){
                ans+=mp[preSum-k];
            }
            ++mp[preSum];
        }
        return ans;
    }
};
// @lc code=end

