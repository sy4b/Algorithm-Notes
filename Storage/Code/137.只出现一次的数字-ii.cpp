/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
class Solution {
    /* 
    对每一位来看，只有1和0两种可能
    出现了三次的数字，最终那一位0或1的个数之和一定是3的倍数
    因此统计每一位上1的个数，如果不是3的整数，就可以确定这一位是1
     */
public:
    int singleNumber(vector<int>& nums) {
        // 答案
        int ans=0;
        // 对每一位进行操作
        for(int i=0;i<32;++i){
            // 统计这一位有多少个1
            int total=0;
            for(auto n: nums){
                total+=(n>>i)&1;
            }
            // 1出现次数不是三的倍数，这一位就是1
            if(total%3!=0){
                ans|=(1<<i);
            }
        }
        return ans;
    }
};
// @lc code=end

