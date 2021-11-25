/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int len=nums.size();
        if(len<3)   return ans;
        sort(nums.begin(), nums.end());
        int left=0, right=len-1;
        unordered_map<int, int> mp;
        for(auto &n: nums)  ++mp[n];
        while(left+1<right){
            int l=nums[left], r=nums[right];
            --mp[l];
            --mp[r];
            int target=-(l+r);
            if(mp[target]>0){
                ans.push_back({l,r,target});
                --mp[target];
            }
            if(target<0){
                --right;
                ++mp[l];
            }else{
                ++left;
                ++mp[r];
            }
        }
        return ans;
    }
};
// @lc code=end

