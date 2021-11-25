/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if(n==1)    return 1;
        if(n==2)    return 2;
        int a=1, b=2, c=0;  // a=dp[i-2],b=dp[i-1]
        for(int i=2;i<n;++i){
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }
};
// @lc code=end

