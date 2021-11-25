/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // map存储值、下标
        unordered_map<int,int> mp;
        // 数组长度
        int len=nums.size();
        for(int index=0;index<len;++index){
            if(mp.find(target-nums[index])==mp.end()){
                mp[nums[index]]=index;
            }else{
                return vector<int>{index, mp[target-nums[index]]};
            }
        }
        return vector<int>{};
    }
};
// @lc code=end

