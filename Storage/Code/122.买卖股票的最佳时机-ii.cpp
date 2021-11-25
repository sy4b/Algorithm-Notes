/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 贪心
        int ans=0;
        for(int i=0;i<prices.size()-1;++i){
            int temp=prices[i+1]-prices[i];
            if(temp>0){
                ans+=temp;
            }
        }
        return ans;
    }
};
// @lc code=end

