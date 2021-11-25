/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */
/*
    滑动窗口
    1. 右边界怎么动？当前和小于target的时候右移
    2. 左边界怎么动？当前和大于target的时候左移
*/
// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX;
        int left=0, right=0, sum=0;
        while(right<nums.size()){
            sum+=nums[right];
            // 左窗口移动
            while(sum>=target){
                ans=min(ans, right-left+1);
                sum-=nums[left];
                ++left;
            }
            ++right;
        }
        // 无解时返回0
        return ans==INT_MAX?0:ans;
    }
};
// @lc code=end

