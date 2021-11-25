/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
/* 
    双指针解法
    1. 数组已然有序，所以可以设置初始左右指针为首尾，然后：
        a. 和大于target，右指针左移
        b. 和小于target，左指针右移
    2. 注意这道题的下标从1开始
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0, right=numbers.size()-1;
        
        while(left<right){
            int sum=numbers[right]+numbers[left];
            if(sum==target) break;
            else if(sum<target){
                ++left;
            }else{
                --right;
            }
        }

        return vector<int>{left+1, right+1};
    }
};
// @lc code=end

