/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left=0, right=0;
        int len=nums.size();
        while(right<len){
            if(left==right && nums[left]!=val){
                ++left;
                ++right;
            }else if(nums[right]==val){
                ++right;
            }else{
                nums[left]=nums[right];
                ++left;
                ++right;
            }
        }
        return left;
    }
};
// @lc code=end

