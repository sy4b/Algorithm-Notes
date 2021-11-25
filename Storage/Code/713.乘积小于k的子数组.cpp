/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于K的子数组
 */
/*
    滑动窗口
    1. 什么时候移动左边界？乘积大于等于k
    2. 什么时候移动右边界？乘积小于k
    3. left和right之间有right-left+1个数组
*/
// @lc code=start
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int ans=0;
        int left=0, right=0, curr=1;
        while(right<nums.size()){
            curr*=nums[right];
            while(curr>=k){
                curr/=nums[left];
                ++left;
            }
            ans+=right-left+1;
            ++right;
        }
        return ans;
    }
};
// @lc code=end

