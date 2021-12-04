/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
/*
    单调栈
    1. 保持栈底到栈顶呈现递减
    2. 栈内存储的是下标，方便计算
    3. 遇到高温时，把栈里所有低温都计算，出栈。最后把高温入栈
    4. 答案数组初始化为0
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<int> stk;
        for(int i=0;i<temperatures.size();++i){
            while(!stk.empty() && temperatures[stk.top()]<temperatures[i]){
                ans[stk.top()]=i-stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};
// @lc code=end

