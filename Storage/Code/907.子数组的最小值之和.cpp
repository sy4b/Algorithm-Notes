/*
 * @lc app=leetcode.cn id=907 lang=cpp
 *
 * [907] 子数组的最小值之和
 */

// @lc code=start
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long ans=0, base=1000000007;
        arr.push_back(0);
        // 递增单调栈
        stack<int> stk;
        for(int i=0;i<arr.size();++i){
            while(!stk.empty() && arr[stk.top()]>arr[i] ){
                int top=stk.top();
                stk.pop();
                int left=stk.empty()?top+1:top-stk.top();
                int right=i-top;
                ans+=(long) arr[top]*left*right%base;
                ans%=base;
            }
            stk.push(i);
        }
        return ans%base;
    }
};
// @lc code=end

