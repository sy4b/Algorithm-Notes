/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 */

// @lc code=start
class Solution {
public:

    vector<int> nums;   // 扰乱前的数组
    int n;              // 数组长度

    Solution(vector<int>& _nums):nums(_nums), n(_nums.size()) {
    }
    
    vector<int> reset() {
        return nums;
    }
    
    vector<int> shuffle() {
        vector<int> ans = nums;
        for (int i = 0; i < n; i ++) {
            swap(ans, i, i + (rand() % (n - i)));   // 生成[i,n-1)范围内的随机数，交换
        }
        return ans;
    }

    // swap
    void swap(vector<int> &num, int a, int b) {
        auto tmp = num[a];
        num[a] = num[b];
        num[b] = tmp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end

