/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
    vector<vector<int>> ans;
    vector<int> path;
    void backtrack(vector<int>& nums, vector<bool>& visited){
        if(path.size()==nums.size()){
            ans.push_back(path);
        }
        for(int i=0;i<nums.size();++i){
            if(visited[i]==false){
                path.push_back(nums[i]);
                visited[i]=true;
                backtrack(nums,visited);
                visited[i]=false;
                path.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int len=nums.size();
        vector<bool> visited(len, false);
        backtrack(nums, visited);
        return ans;
    }
};
// @lc code=end

