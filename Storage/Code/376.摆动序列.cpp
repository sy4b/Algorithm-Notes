/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int ans=1;
        int curDiff=0;  // 当前差值
        int lastDiff=0; // 上一个差值
        for(int i=0;i<nums.size()-1;++i){
            curDiff=nums[i+1]-nums[i];
            if(curDiff>0 && lastDiff<=0 || curDiff<0 && lastDiff>=0){
                ++ans;
                lastDiff=curDiff;
            }
        }
        return ans;
    }
};
// @lc code=end

