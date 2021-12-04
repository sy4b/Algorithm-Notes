/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */
/*
    先对数组排序，从大到小
    记录最后一位正数的坐标
    取反时从后往前取
*/
// @lc code=start
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend());
        
    }
};
// @lc code=end

