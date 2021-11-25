/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cost=prices[0];
        int ans=0;
        for(int i=1;i<prices.size();++i){
            // 不断更新最低的股价，然后计算利润
            ans=max(ans, prices[i]-cost);
            cost=min(cost, prices[i]);
        }
        return ans;
    }
};
// @lc code=end

