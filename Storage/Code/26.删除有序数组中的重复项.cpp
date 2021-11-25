/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len=nums.size();
        if(len<=1)  return len;
        int left=1, right=1;
        while(right<len){
            if(nums[right]!=nums[right-1]){
                nums[left]=nums[right];
                ++left;
            }
            ++right;
        }
        return left;
    }
};
// @lc code=end

