/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        stack<int> ans;
        int left=0, right=nums.size()-1;
        while(left<=right){
            if(abs(nums[left])>abs(nums[right])){
                ans.push(nums[left]*nums[left]);
                ++left;
            }else{
                ans.push(nums[right]*nums[right]);
                --right;
            }
        }
        vector<int> res;
        while(ans.empty()==false){
            res.push_back(ans.top());
            ans.pop();
        }
        return res;
    }
};
// @lc code=end

