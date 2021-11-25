/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    // O(n)解法
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX, curr=0;
        int left=0, right=0;
        while(right<nums.size()){
            curr+=nums[right];
            while(curr>=target){
                ans=min(ans, right-left+1);
                curr-=nums[left];
                ++left;
            }
            ++right;
        }
        return ans==INT_MAX?0:ans;
    }
};
// @lc code=end

