/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // 二分模板
        // 找第一个大于等于target的位置
        int left=0, right=nums.size()-1;
        // 特殊判断
        if(target>nums[right])  return right+1;
        while(left<right){
            int mid=left+((right-left)>>1);
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>target){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        return left;
    }
};
// @lc code=end

