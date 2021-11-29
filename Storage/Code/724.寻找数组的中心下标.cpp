/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */
/*
    前缀和解法
    1. 计算数组之和
    2. 从左到右开始找，更新前缀和
*/
// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        for(const auto& n: nums){
            sum+=n;
        }
        int preSum=0;
        for(int i=0;i<nums.size();++i){
            if(2*preSum+nums[i]==sum){
                return i;
            }
            preSum+=nums[i];
        }
        return -1;
    }
};
// @lc code=end

