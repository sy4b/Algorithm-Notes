/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start

/*
    双指针法
    0. 特殊判断：长度小于3的数组肯定没有解
    1. 首先进行一个排序
    2. 从左到右搜索，固定一个最小值，我们在右边搜索满足要求的另外两个数。由于已经排序过，所以固定的最小值大于0时，已经不可能有答案了
    3. 关键：如何去重？因为已经排序过，所以搜索以及固定时需要跳过重复值，这在排列问题的回溯也常出现
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        vector< vector<int> > ans;
        if(nums.size() < 3) return ans; // 特判
        int n = nums.size();

        sort(nums.begin(), nums.end()); //排序
        for(int i = 0; i < n; i++)  // 枚举最小值
        {
            if(nums[i] > 0) return ans;
            if(i > 0 && nums[i] == nums[i-1]) continue;   // 最小元素去重！
            int l = i+1;
            int r = n-1;
            while(l < r)    // 枚举中间值和最大值
            {
                int x = nums[l] + nums[r] + nums[i];
                if(x == 0){ // 符合条件，存储，并且去重，双端都移到下一个位置
                    ans.push_back({ nums[i], nums[l], nums[r] });
                    while( l < r && nums[l] == nums[l+1]) l++; l++;
                    while( l < r && nums[r] == nums[r-1]) r--; r--;
                }
                else if(x > 0) // 大了就让右边最大值变小
                    r--;
                else        // 小了就让左边中间值变大
                    l++;
            }
        }
        return ans;
    }
};
// @lc code=end

