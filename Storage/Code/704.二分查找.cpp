/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1;
        // 找到第一个大于等于target的
        while(left<right){
            // 找第一个，所以向下取整
            int mid=left+((right-left)>>1);
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>target){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        if(nums[left]!=target){
            return -1;
        }
        return left;
    }
};
// @lc code=end

